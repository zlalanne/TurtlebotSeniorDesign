#include "ros/ros.h"
#include "costmap_2d/costmap_2d_ros.h"
#include "costmap_2d/costmap_2d.h"

namespace matrix_encoder {

   /**
    * @class MatrixEncoder
    * @brief A class that maintains a costmap and uses its costmap to create a representation for the user interface matrix
    */
   class MatrixEncoder {
      public:
         MatrixEncoder(std::string name, tf::TransformListener& tf);
         //~MatrixEncoder(); // i don't know why this is virtual
      private:
         tf::TransformListener& tf_;
         costmap_2d::Costmap2DROS* encoder_costmap_ros;
         costmap_2d::Costmap2D costmap; // The underlying costmap to update
         const unsigned char* charArray;  // pointer to the underlying unsigned char array used as the costmap
         tf::Stamped<tf::Pose> robotPose; // variable that will store the current position of the robot, update with getRobotPose
         boost::thread* map_print_thread_; // thread for printing map data
         boost::thread* heading_print_thread;
         ros::Publisher obstacledata_pub; // Publisher object for publishing obstacle data
         unsigned short count; // Variable for debugging topic publishing
         std_msgs::UInt16 msg; // Message object for publishing obstacle data
         void mapPrintLoop(double frequency);
         void headingPrintLoop(double frequency);

   };
};
