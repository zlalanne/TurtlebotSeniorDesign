#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"
#include "std_msgs/UInt8MultiArray.h"
#include "matrix_encoder/encoder.h"
#include "costmap_2d/costmap_2d_ros.h"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;


/*
 * this code should create a node called encoder that subscribes to whatever to
 * whatever topics necessary to gather information about the robot's position,   * orientation, and nearby obstacles.
 */

/*
 *    USEFUL METHODS
 *
 *    DEFINED FOR COSTMAP_2D_ROS
 *    unsigned int getSizeInCellsX() const; // returns the x size of the costmap in cells
 *    unsigned int getSizeInCellsY() const; // returns the y size of the costmap in cells
 *    double getResolution() const; // returns the resolution of the costmap in meters
 *
 *    DEFINED FOR COSTMAP_2D
 *    unsigned char getCost(unsigned int mx, unsigned int my) const; // Get the cost of a cell in the costmap
 *    const unsigned char* getCharMap() const; // return an immutable pointer to the underlying unsigned char array used as the costmap
 *    getSizeInCellsX() & getSizeInCellsY() also defined for costmap_2d
 *    double getSizeInMetersX() & getSizeInMetersY()
 *    double getOriginX()[getOriginY()] // return the x origin of the costmap
 *
 *    HOW INDEXING INTO ARRAY IS DONE!
 *    inline unsigned int getIndex(unsigned int mx, unsigned int my) const{
 *       return my * size_x_ + mx;
 *    }
 *    so about what we expected, the index goes from left to right, top to bottom
 *    inline void indexToCells(unsigned int index, unsigned int& mx, unsigned int& my) const{
 *       my = index / size_x_;
 *       mx = index - (my * size_x_);
 *    }
 *
 */


namespace matrix_encoder {

  MatrixEncoder::MatrixEncoder(std::string name, tf::TransformListener& tf) :
  tf_(tf), encoder_costmap_ros(NULL), charArray(NULL), map_print_thread_(NULL) { 

    ros::NodeHandle nh;   // move_base also has a private node handler private_nh

    // This needs to happen before we start fooling around with logger levels. Otherwise the level we set may be overwritten by a configuration file
    ROSCONSOLE_AUTOINIT;  
    log4cxx::LoggerPtr my_logger = log4cxx::Logger::getLogger(ROSCONSOLE_DEFAULT_NAME);
    // Set the logger for this package to output all statements
    my_logger->setLevel(ros::console::g_level_lookup[ros::console::levels::Debug]);
  
    // create the ros wrapper for the encoder's costmap... and initialize a pointer we'll use with the underlying map
    encoder_costmap_ros = new costmap_2d::Costmap2DROS("encoder_costmap", tf_);
    encoder_costmap_ros->pause(); // prevent the costmap from updating
    encoder_costmap_ros->start(); // start updating the costmap

 //   encoder_costmap_ros->getCostmapCopy(costmap);
//    charArray = costmap.getCharMap();

    unsigned int numXcells = encoder_costmap_ros->getSizeInCellsX();
    unsigned int numYcells = encoder_costmap_ros->getSizeInCellsY();
    ROS_INFO("Size of map in cells is %d, %d", numXcells, numYcells);

    unsigned int sizeX = costmap.getSizeInMetersX();
    unsigned int sizeY = costmap.getSizeInMetersY();
    ROS_INFO("Size of map in meters is %d X %d", sizeX, sizeY);

    // Creating publisher object that publishes UInt16 on obstacledata topic
    obstacledata_pub = nh.advertise<std_msgs::UInt16>("obstacledata",1000);
    
    // Creating publisher object that publishes UInt8MultiArray on guidata topic
    guidata_pub = nh.advertise<std_msgs::UInt8MultiArray>("guidata",1000);
    
    count = 0;  
    
    double map_print_frequency = 4;  // hopefully this will make the thread run every 10 seconds?
    map_print_thread_ = new boost::thread(boost::bind(&matrix_encoder::MatrixEncoder::mapPrintLoop, this, map_print_frequency));
    // GOING TO TRY ADDING A PERIODIC THREAD THAT WILL PRINT COSTMAP DATA
    double heading_print_frequency = 1;
    // heading_print_thread = new boost::thread(boost::bind(&matrix_encoder::MatrixEncoder::headingPrintLoop, this, heading_print_frequency));
  }

  void MatrixEncoder::headingPrintLoop(double frequency) {
    ros::NodeHandle nh;
    ros::Rate r(frequency);
    double RobotPoseX;
    double RobotPoseY;
    double RobotPoseTheta;
    double yaw,pitch,roll;
    while(nh.ok()) {

       if (!encoder_costmap_ros->getRobotPose(robotPose)) {
         ROS_ERROR("Could not get robot pose!");
       }
       tf::Quaternion q;
       q = robotPose.getRotation();
       btMatrix3x3(q).getEulerYPR(yaw,pitch,roll);
       RobotPoseX = robotPose.getOrigin().x();
       RobotPoseY = robotPose.getOrigin().y();
       RobotPoseTheta = -yaw;

       ROS_WARN("Robot's pose is x: %g  y: %g theta: %g", RobotPoseX, RobotPoseY, RobotPoseTheta);

       r.sleep();
    }
  }

void RotateAroundRobot(const unsigned char* charArray, unsigned char* rotatedArray, int numx, int numy, int robotx, int roboty, double robotangle); 
void MatrixEncoder::mapPrintLoop(double frequency) {
    // this loop should print out some version of the costmap data
    ros::NodeHandle nh;
    ros::Rate r(frequency);
    while(nh.ok()) {
        ROS_INFO("print loop running");
        encoder_costmap_ros->updateMap(); // force map update
        //encoder_costmap_ros->getCostmapCopy(costmap);
      
        encoder_costmap_ros->getCostmapWindowCopy(2,2,costmap);
        charArray = costmap.getCharMap();
        unsigned int sumObstacles = 0;
        //unsigned int numCellsX = encoder_costmap_ros->getSizeInCellsX();
        //unsigned int numCellsY = encoder_costmap_ros->getSizeInCellsY();
        unsigned int numCellsX = costmap.getSizeInCellsX();
        unsigned int numCellsY = costmap.getSizeInCellsY();
      
        /*for (int index = 0; index < (numCellsX * numCellsY); index++) {
            if (charArray[index] == 254) {
            sumObstacles++;
            }
        }*//*
        for(int i = 0; i<numCellsY; i++) {
            ostringstream w;
            for(int j=0; j<numCellsX; j++) {
                if (charArray[(numCellsY - i - 1)*numCellsX + j] > 250 && charArray[(numCellsY - i - 1)*numCellsX + j] < 255) {
                    if((i%2) == 0 && (j%2) == 0) {
                        w << 1 << " ";
                    }
                    sumObstacles++;
                }
                else {
                    if((i%2) == 0 && (j%2) == 0) {
                        if( ((i == numCellsX/2) && (j == numCellsY/2)) ||
                                ((i == numCellsX/2 + 1) && (j == numCellsY/2)) ||
                                ((i == numCellsX/2) && (j == numCellsY/2 + 1)) ||
                                ((i == numCellsX/2 + 1) && (j == numCellsY/2 + 1)) )
                            w << "x ";
                        else 
                            w << 0 << " ";
                    }

                }
            }
            if((i%2) == 0) {
       //         ROS_INFO(w.str().c_str());
            }
      }*/
      //ROS_INFO("Current number of obstacles: %d", sumObstacles);
     //ros::spinOnce();

      double RobotPoseX;
      double RobotPoseY;
      double RobotPoseTheta;
      double yaw,pitch,roll;
      if (!encoder_costmap_ros->getRobotPose(robotPose)) {
         ROS_ERROR("Could not get robot pose!");
       }
       tf::Quaternion q;
       q = robotPose.getRotation();
       btMatrix3x3(q).getEulerYPR(yaw,pitch,roll);
      // RobotPoseX = robotPose.getOrigin().x();
      // RobotPoseY = robotPose.getOrigin().y();
       RobotPoseX = numCellsX / 2;
       RobotPoseY = numCellsY / 2;
       RobotPoseTheta = yaw;
      ROS_INFO("X Coordinate: %g, Y Coordinate: %g, Theta: %g", RobotPoseX, RobotPoseY, yaw*180.0/3.1415926);

       unsigned char rotatedArray[16];

       RotateAroundRobot(charArray, rotatedArray, numCellsX, numCellsY, (int) RobotPoseX, (int) RobotPoseY, RobotPoseTheta);
      
      unsigned short data = 0;
	/*for(i = 0; i < 16; i++){
          if(rotatedArray[i] == 254){
            data |= (0x01 << i);
          }
        }*/

      int index = 0;
      for(int i=3; i>=0; i--) {
        for(int j=0; j<4; j++) {
            if(rotatedArray[i*4+j] != 254) {
                data |= (0x01 << index);
            }
            index++;
        }
      }
      // Setting message data
      msg.data = data;

      // Publish the message
      obstacledata_pub.publish(msg);

      // Clearing the data in the array
      msgGUIData.data.clear();

      // First two elements are array dimensions
      msgGUIData.data.push_back(numCellsX);
      msgGUIData.data.push_back(numCellsY);
      
      // Pushing theta
      unsigned short theta;
      if((yaw*180.0/3.1415926) < 0){
          theta = (unsigned short) (360.0 + (yaw*180.0/3.1415926));
      } else {
          theta = (unsigned short) (yaw*180.0/3.1415926);
      }
      ROS_INFO("theta = %d",theta);
      msgGUIData.data.push_back((unsigned char)( (theta & 0xFF00) >> 8));
      msgGUIData.data.push_back((unsigned char) theta & 0x00FF);


      // Filling in the data

        for(int i = 0; i<numCellsY; i++) {
            for(int j=0; j<numCellsX; j++) {
                msgGUIData.data.push_back(charArray[(numCellsY - i - 1)*numCellsX + j]);
            }
        }
//      for(int i = 0; i < numCellsX*numCellsY; i++){
  //      msgGUIData.data.push_back(charArray[i]);
    //  }

      // Publish the message
      guidata_pub.publish(msgGUIData);

      r.sleep();
    }
  }  

}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "encoder");

  tf::TransformListener tf(ros::Duration(10));  // need to investigate what this does
  matrix_encoder::MatrixEncoder matrix_encoder("matrix_encoder", tf);

  while(ros::ok()) {
    
    ros::spinOnce();
  
  }

  return 0;
}
//rotated array needs to be dimensions of 4x4
//unit test - 10x10 map, subset 81x81 around robot
//253 = inflated obstacles, 254 = lethal, 255 = no info, 0 = free space
void matrix_encoder::RotateAroundRobot(const unsigned char* charArray, unsigned char* rotatedArray, int numx, int numy, int robotx, int roboty, double robotangle){
        //set robot as 0,0 by doing x - robot for x values and robot - y for y values
        //if robot is 4,5 then 0,0 is actually -4,5
        //              7,6 is actually 3,-1
        //double robotangle = 0.0;
        //int robotx = 2;
        //int roboty = 3;
        //cout << robotangle << endl;
        //int numx = 10;
        //int numy = 10;
        //unsigned char rotatedArray[16] = {};
        /*unsigned char charArray[100] = {255,255,255,255,255,0,0,0,0,0,
                                        254,254,254,254,254,0,0,0,0,0,
                                        253,253,253,253,253,0,0,0,0,0,
                                        252,252,252,252,252,0,0,0,0,0,
                                        251,251,251,251,251,0,0,0,0,0,
                                        250,250,250,250,250,0,0,0,0,0,
                                        249,249,249,249,249,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0};*/
        unsigned char subsetArray[81][81];
        unsigned char tempArray[115][115];
        //initialize subset array
        for(int i = 0; i < 81*81; ++i)
                subsetArray[i/81][i%81] = 255;
        for(int i = 0; i < 115*115; ++i)
                tempArray[i/115][i%115] = 255;

        //using 2 because of 5x5
        for(int r = roboty - ((81-1)/2); (r < numy) && (r <= roboty + ((81-1)/2)); r++)
        {
                for(int c = robotx - ((81-1)/2); (c < numx) && (c <= robotx + ((81-1)/2)); c++)
                {
                        //cout << "r = " << r << "  c = " << c << endl;
                        if( (r < 0) || (c < 0) || (r > numy - 1) || (c > numx - 1) )
                                continue;
                        //cout << "-- r = " << r - (roboty - 2) << "  c = " << c - (robotx - 2) << endl;
                        subsetArray[r - (roboty - ((81-1)/2))][c - (robotx - ((81-1)/2))] = charArray[r*numx + c];
                }
        }
        //cout << "subsetDone" << endl;
        //radians. rotate to 90 degrees
        double angle =  -1.57079 + robotangle;
        //cout << angle << endl;
        for(int i = 0; i < 81*81; ++i)
        {
                float x = i%81; //0 to 4
                float y = i/81; //0 to 4, need to map to -2 to 2
                x = x-((81-1)/2);
                y = y-((81-1)/2);

                float newy = x*sin(angle) + y*cos(angle); //-4 to 4
                float newx = x*cos(angle) - y*sin(angle); //-4 to 4
                newy = newy + ((115-1)/2);
                newx = newx + ((115-1)/2);
                //cout << "sin = " << sin(angle) << "  cos = " << cos(angle) << endl;
                //cout << "newy = " << newy << "  newx = " << newx << endl;
                tempArray[(int)round(newy)][(int)round(newx)] = subsetArray[i/81][i%81];
        }
/*        cout << "rotate done" << endl;
        for(int i = 0; i < 115*115; ++i){
                if(i % 115 == 0)
                        cout << endl;
                char things = tempArray[i/115][i%115] + '0' + 7;
                cout << things;
        }
        cout << endl;
*/
        int tnumx = 115;
                         
        float i_tnumx = 115.0/4; //dont change 4
        int cut;
        if(i_tnumx - (int)(115.0/4) >= 0.5)
                cut = (tnumx + 2)/4;
        else
                cut = tnumx/4;
        for(int i = 0; i < 4*cut; i += cut){
                for(int j = 0; j < 4*cut; j+= cut){
                        int count = 0;
                        for(int k = i; k < i+cut; ++k){
                                for(int m = j; m < j+cut; ++m){
                                        if(m >= tnumx || k >= tnumx)
                                                continue;
                                        if(tempArray[k][m] == 254){
//                                                cout << "k, m " << k << ", " << m << "  " << (i/cut)*4 + (j/cut) << endl;
                                                  count++;
                                        }
                                }
                        }
                        if(count > (40))
                                rotatedArray[(i/cut)*4 + (j/cut)] = 254;
                }
        }
/*        for(int i = 0; i < 16; ++i){
                char things = rotatedArray[i] + '0' + 7;
                cout << things;
                if(i == 3 || i == 7 || i == 11 || i == 15)
                        cout << endl;
        }
*/
	return;
}


