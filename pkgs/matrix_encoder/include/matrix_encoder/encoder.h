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
         virtual ~MatrixEncoder(); // i don't know why this is virtual
      private:
         tf::TransformListener& tf_;
         costmap_2d::Costmap2DROS* encoder_costmap_ros;
   };
};