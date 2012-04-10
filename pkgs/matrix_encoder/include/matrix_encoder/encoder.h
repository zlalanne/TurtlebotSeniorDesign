#include "ros/ros.h"
#include "costmap_2d/costmap_2d_ros.h"
#include "costmap_2d/costmap_2d.h"

#include <cmath>
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
         ros::Publisher guidata_pub; // Publisher object for publishing obstacle data
         std_msgs::UInt16 msg; // Message object for publishing obstacle data
         std_msgs::UInt8MultiArray msgGUIData; // Message object for publishing data to gui
         void mapPrintLoop(double frequency);
         unsigned short count; // Variable for debugging topic publishing
         void headingPrintLoop(double frequency);
         void RotateAroundRobot(const unsigned char *, unsigned char *, int, int, int, int, double);
   };
};

