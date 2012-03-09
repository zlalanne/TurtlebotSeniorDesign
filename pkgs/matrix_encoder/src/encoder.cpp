#include "ros/ros.h"
#include "std_msgs/String.h"
#include "matrix_encoder/encoder.h"
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
   tf_(tf), encoder_costmap_ros(NULL), charArray(NULL) {


   ros::NodeHandle nh;   // move_base also has a private node handler private_nh

   // This needs to happen before we start fooling around with logger levels. Otherwise the level we set may be overwritten by a configuration file
   ROSCONSOLE_AUTOINIT;  
   log4cxx::LoggerPtr my_logger = log4cxx::Logger::getLogger(ROSCONSOLE_DEFAULT_NAME);
   // Set the logger for this package to output all statements
   my_logger->setLevel(ros::console::g_level_lookup[ros::console::levels::Debug]);

   ROS_DEBUG("Testing");
   ROS_INFO("About to create costmap object");
   // create the ros wrapper for the encoder's costmap... and initialize a pointer we'll use with the underlying map
   encoder_costmap_ros = new costmap_2d::Costmap2DROS("encoder_costmap", tf_);
   encoder_costmap_ros->pause(); // prevent the costmap from updating
   encoder_costmap_ros->start(); // start updating the costmap
   encoder_costmap_ros->getCostmapCopy(costmap);
   // try to reset the costmap to all unknown information
   //costmap.resetMaps();  // protected function (could use a friendly function to get to it
   encoder_costmap_ros->resetMapOutsideWindow(0,0);
   charArray = costmap.getCharMap();
   unsigned int numXcells = encoder_costmap_ros->getSizeInCellsX();
   unsigned int numYcells = encoder_costmap_ros->getSizeInCellsY();
   ROS_INFO("About to start priting the char array to a file");

  // ofstream myfile;
  // myfile.open("~/Map.txt");
   for (int j = 0; j < 50; j++) {
      for(int i = 0; i < (numXcells * numYcells); i++){
        // myfile << charArray[i] << " ";
         ROS_INFO("%d", charArray[i]);
        // if ((i % numYcells) == 0) {
           // myfile << endl;
        // }
      }
      //myfile << endl << endl;
      // delay
      sleep(2000); // time to wait in msec
      //ROS_INFO("Should have printed to file");
   }


 //  myfile.close();
   }
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "encoder");

  tf::TransformListener tf(ros::Duration(10));  // need to investigate what this does
  matrix_encoder::MatrixEncoder matrix_encoder("matrix_encoder", tf);

  ros::NodeHandle n;

  ros::spin();

  return 0;
}
