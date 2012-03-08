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
 *
 */


namespace matrix_encoder {

   MatrixEncoder::MatrixEncoder(std::string name, tf::TransformListener& tf) :
   tf_(tf), encoder_costmap_ros(NULL), charArray(NULL) {


   ros::NodeHandle nh;   // move_base also has a private node handler private_nh

   ROS_INFO("About to create costmap object");
   // create the ros wrapper for the encoder's costmap... and initialize a pointer we'll use with the underlying map
   encoder_costmap_ros = new costmap_2d::Costmap2DROS("encoder_costmap", tf_);
   encoder_costmap_ros->pause(); // prevent the costmap from updating
   encoder_costmap_ros->start(); // start updating the costmap
   encoder_costmap_ros->getCostmapCopy(costmap);
   charArray = costmap.getCharMap();
   unsigned int numXcells = encoder_costmap_ros->getSizeInCellsX();
   unsigned int numYcells = encoder_costmap_ros->getSizeInCellsY();
   ROS_INFO("About to start priting the char array to a file");
   ofstream myfile;
   myfile.open("~/Map.txt");
   for (int j = 0; j < 50; j++) {
      for(int i = 0; i < (numXcells * numYcells); i++){
         myfile << charArray[i] << " ";
         if ((i % numYcells) == 0) {
            myfile << endl;
         }
      }
      myfile << endl << endl;
      // delay
      sleep(2000); // time to wait in msec
      ROS_INFO("Should have printed to file");
   }


   myfile.close();
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
