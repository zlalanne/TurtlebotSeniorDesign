namespace matrix_encoder {
   
   /**
    * @class MatrixEncoder
    * @brief A class that maintains a costmap and uses its costmap to create a representation for the user interface matrix
    */
   class MatrixEncoder {
      public:
         MatrixEncoder(std::string name, tf::TransformListener& tf);
         virtual ~MatrixEncoder();
      private:
         tf::TransformListener& tf_;
   }
}
