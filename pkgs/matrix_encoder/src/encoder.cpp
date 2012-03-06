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

namespace matrix_encoder {

   MatrixEncoder::MatrixEncoder(std::string name, tf::TransformListener& tf) :
   tf_(tf), encoder_costmap_ros(NULL), charArray(NULL) {


   ros::NodeHandle nh;   // move_base also has a private node handler private_nh

  
   // create the ros wrapper for the encoder's costmap... and initialize a pointer we'll use with the underlying map
   encoder_costmap_ros = new costmap_2d::Costmap2DROS("encoder_costmap", tf_);
   encoder_costmap_ros->pause(); // prevent the costmap from updating
   encoder_costmap_ros->start(); // start updating the costmap
   encoder_costmap_ros->getCostmapCopy(costmap);
   charArray = costmap.getCharMap();
   unsigned int numXcells = encoder_costmap_ros->getSizeInCellsX();
   unsigned int numYcells = encoder_costmap_ros->getSizeInCellsY();
  
   ofstream myfile;
   myfile.open("Map.txt");
   for (int j = 0; j < 50; j++) {
      for(int i = 0; i < (numXcells * numYcells); i++){
         myfile << charArray[i];
      }
      myfile << endl << endl;
      // delay
      sleep(5000); // time to wait in msec      
   }


   myfile.close();
   }
}

void chatterCallback(const std_msgs::String::ConstPtr& msg){
   ROS_INFO("I heard: [%s]", msg->data.c_str());
}

//void mapCallback(nav_msgs::OccupancyGrid map){
//   ROS_INFO("Received a map update");
//}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "encoder");
  
  tf::TransformListener tf(ros::Duration(10));  // need to investigate what this does
  matrix_encoder::MatrixEncoder matrix_encoder("matrix_encoder", tf);

  ros::NodeHandle n;
  
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
//  ros::Subscriber mapSub = n.subscribe("map", 100, mapCallback);

  ros::spin();

  return 0;
}
