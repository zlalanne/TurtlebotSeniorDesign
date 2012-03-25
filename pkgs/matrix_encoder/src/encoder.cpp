#include "ros/ros.h"
#include "std_msgs/String.h"
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
    bool static_map_holder;
    nh.param("static_map",static_map_holder,false);

    costmap_2d::Costmap2DROS* encoder_costmap_ros2 = new costmap_2d::Costmap2DROS("junk_costmap", tf_);
    // create the ros wrapper for the encoder's costmap... and initialize a pointer we'll use with the underlying map
    encoder_costmap_ros = new costmap_2d::Costmap2DROS("encoder_costmap", tf_);
    encoder_costmap_ros->pause(); // prevent the costmap from updating
    encoder_costmap_ros->start(); // start updating the costmap
    encoder_costmap_ros->updateMap(); // force a map update with new sensor data
    encoder_costmap_ros->getCostmapCopy(costmap);

    // try to reset the costmap to all unknown information
    //costmap.resetMaps();  // protected function (could use a friendly function to get to it
    //   encoder_costmap_ros->resetMapOutsideWindow(0,0);
    charArray = costmap.getCharMap();

    unsigned int numXcells = encoder_costmap_ros->getSizeInCellsX();
    unsigned int numYcells = encoder_costmap_ros->getSizeInCellsY();
    ROS_INFO("Size of map in cells is %d, %d", numXcells, numYcells);

    unsigned int sizeX = costmap.getSizeInMetersX();
    unsigned int sizeY = costmap.getSizeInMetersY();
    ROS_INFO("Size of map in meters is %d X %d", sizeX, sizeY);

    double RobotPoseX;
    double RobotPoseY;

    // GOING TO TRY ADDING A PERIODIC THREAD THAT WILL PRINT COSTMAP DATA
    double map_print_frequency = 0.1;  // hopefully this will make the thread run every 10 seconds?
    map_print_thread_ = new boost::thread(boost::bind(&matrix_encoder::MatrixEncoder::mapPrintLoop, this, map_print_frequency));
      


//     ros::Rate r(1.0);

/*   while(true) {
       if (!encoder_costmap_ros->getRobotPose(robotPose)) {
         ROS_ERROR("Could not get robot pose!");
       }

       RobotPoseX = robotPose.getOrigin().x();
       RobotPoseY = robotPose.getOrigin().y();

       ROS_WARN("Robot's pose is x: %g   y: %g", RobotPoseX, RobotPoseY);

       r.sleep();
    }
*/
/*
    int index = 0;
    ROS_INFO("About to print initial map");
    for (int j = 0; j < numXcells; j++) {
      for(int i = 0; i < numYcells; i++) {
        ROS_WARN("1st: %d", charArray[index++]);
      }
    }  */
/*
    index = 0;
    encoder_costmap_ros->resetMapOutsideWindow(0,0);
    encoder_costmap_ros->getCostmapCopy(costmap);
    charArray = costmap.getCharMap();
    ROS_INFO("About to print cleared map");
    for (int j = 0; j < numXcells; j++) {
      for(int i = 0; i < numYcells; i++) {
        ROS_WARN("2nd: %d", charArray[index++]);
      }
    } */
  }

  void MatrixEncoder::mapPrintLoop(double frequency) {
    // this loop should print out some version of the costmap data
    ros::NodeHandle nh;
    ros::Rate r(frequency);
    while(nh.ok()) {
      ROS_INFO("print loop running");
      encoder_costmap_ros->updateMap(); // force map update
      encoder_costmap_ros->resetMapOutsideWindow(0,0);
      unsigned int sumObstacles = 0;
      unsigned int numCellsX = encoder_costmap_ros->getSizeInCellsX();
      unsigned int numCellsY = encoder_costmap_ros->getSizeInCellsY();
      charArray = costmap.getCharMap();
      for (int index = 0; index < (numCellsX * numCellsY); index++) {
        if (charArray[index] == 254) {
          sumObstacles++;
        }
      }
      ROS_INFO("Current number of obstacles: %d", sumObstacles);
      r.sleep();
    }
  }  

}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "encoder");

  tf::TransformListener tf(ros::Duration(10));  // need to investigate what this does
  matrix_encoder::MatrixEncoder matrix_encoder("matrix_encoder", tf);

  ros::NodeHandle n;

  ros::Rate r(10.0); // 5 second timer
  
  while(true) {
    ros::spinOnce();
    // print out the map, but this takes a LOT of time.....
//    r.sleep();
 //   ROS_INFO("About to print map in main");
  //  encoder_costmap_ros->getCostmapCopy(costmap);
 //   charArray = costmap.getCharMap();
//    for (int j = 0; (j < matrix_encoder->getSizeInCellsX() * matrix_encoder->getSizeInCellsY()); j++) {
//       ROS_WARN("M: %d" charArray[j]);
//    }
  }
  return 0;
}
