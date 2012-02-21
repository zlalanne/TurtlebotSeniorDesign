/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-electric-navigation-1.6.5/debian/ros-electric-navigation/opt/ros/electric/stacks/navigation/move_base_msgs/msg/MoveBaseGoal.msg */
#ifndef MOVE_BASE_MSGS_MESSAGE_MOVEBASEGOAL_H
#define MOVE_BASE_MSGS_MESSAGE_MOVEBASEGOAL_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "geometry_msgs/PoseStamped.h"

namespace move_base_msgs
{
template <class ContainerAllocator>
struct MoveBaseGoal_ {
  typedef MoveBaseGoal_<ContainerAllocator> Type;

  MoveBaseGoal_()
  : target_pose()
  {
  }

  MoveBaseGoal_(const ContainerAllocator& _alloc)
  : target_pose(_alloc)
  {
  }

  typedef  ::geometry_msgs::PoseStamped_<ContainerAllocator>  _target_pose_type;
   ::geometry_msgs::PoseStamped_<ContainerAllocator>  target_pose;


private:
  static const char* __s_getDataType_() { return "move_base_msgs/MoveBaseGoal"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "257d089627d7eb7136c24d3593d05a16"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
geometry_msgs/PoseStamped target_pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, target_pose);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, target_pose);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(target_pose);
    return size;
  }

  typedef boost::shared_ptr< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct MoveBaseGoal
typedef  ::move_base_msgs::MoveBaseGoal_<std::allocator<void> > MoveBaseGoal;

typedef boost::shared_ptr< ::move_base_msgs::MoveBaseGoal> MoveBaseGoalPtr;
typedef boost::shared_ptr< ::move_base_msgs::MoveBaseGoal const> MoveBaseGoalConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace move_base_msgs

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "257d089627d7eb7136c24d3593d05a16";
  }

  static const char* value(const  ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x257d089627d7eb71ULL;
  static const uint64_t static_value2 = 0x36c24d3593d05a16ULL;
};

template<class ContainerAllocator>
struct DataType< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "move_base_msgs/MoveBaseGoal";
  }

  static const char* value(const  ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
geometry_msgs/PoseStamped target_pose\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseStamped\n\
# A Pose with reference coordinate frame and timestamp\n\
Header header\n\
Pose pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of postion and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.target_pose);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct MoveBaseGoal_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::move_base_msgs::MoveBaseGoal_<ContainerAllocator> & v) 
  {
    s << indent << "target_pose: ";
s << std::endl;
    Printer< ::geometry_msgs::PoseStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.target_pose);
  }
};


} // namespace message_operations
} // namespace ros

#endif // MOVE_BASE_MSGS_MESSAGE_MOVEBASEGOAL_H

