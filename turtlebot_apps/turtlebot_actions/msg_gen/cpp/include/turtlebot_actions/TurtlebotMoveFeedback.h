/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-electric-turtlebot-apps-0.2.3/debian/ros-electric-turtlebot-apps/opt/ros/electric/stacks/turtlebot_apps/turtlebot_actions/msg/TurtlebotMoveFeedback.msg */
#ifndef TURTLEBOT_ACTIONS_MESSAGE_TURTLEBOTMOVEFEEDBACK_H
#define TURTLEBOT_ACTIONS_MESSAGE_TURTLEBOTMOVEFEEDBACK_H
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


namespace turtlebot_actions
{
template <class ContainerAllocator>
struct TurtlebotMoveFeedback_ {
  typedef TurtlebotMoveFeedback_<ContainerAllocator> Type;

  TurtlebotMoveFeedback_()
  : turn_distance(0.0)
  , forward_distance(0.0)
  {
  }

  TurtlebotMoveFeedback_(const ContainerAllocator& _alloc)
  : turn_distance(0.0)
  , forward_distance(0.0)
  {
  }

  typedef float _turn_distance_type;
  float turn_distance;

  typedef float _forward_distance_type;
  float forward_distance;


private:
  static const char* __s_getDataType_() { return "turtlebot_actions/TurtlebotMoveFeedback"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "c971f114b08a2a1ad79af4c9ca9f358c"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
float32 turn_distance\n\
float32 forward_distance\n\
\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, turn_distance);
    ros::serialization::serialize(stream, forward_distance);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, turn_distance);
    ros::serialization::deserialize(stream, forward_distance);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(turn_distance);
    size += ros::serialization::serializationLength(forward_distance);
    return size;
  }

  typedef boost::shared_ptr< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct TurtlebotMoveFeedback
typedef  ::turtlebot_actions::TurtlebotMoveFeedback_<std::allocator<void> > TurtlebotMoveFeedback;

typedef boost::shared_ptr< ::turtlebot_actions::TurtlebotMoveFeedback> TurtlebotMoveFeedbackPtr;
typedef boost::shared_ptr< ::turtlebot_actions::TurtlebotMoveFeedback const> TurtlebotMoveFeedbackConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace turtlebot_actions

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "c971f114b08a2a1ad79af4c9ca9f358c";
  }

  static const char* value(const  ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xc971f114b08a2a1aULL;
  static const uint64_t static_value2 = 0xd79af4c9ca9f358cULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "turtlebot_actions/TurtlebotMoveFeedback";
  }

  static const char* value(const  ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
float32 turn_distance\n\
float32 forward_distance\n\
\n\
\n\
";
  }

  static const char* value(const  ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.turn_distance);
    stream.next(m.forward_distance);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct TurtlebotMoveFeedback_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::turtlebot_actions::TurtlebotMoveFeedback_<ContainerAllocator> & v) 
  {
    s << indent << "turn_distance: ";
    Printer<float>::stream(s, indent + "  ", v.turn_distance);
    s << indent << "forward_distance: ";
    Printer<float>::stream(s, indent + "  ", v.forward_distance);
  }
};


} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_ACTIONS_MESSAGE_TURTLEBOTMOVEFEEDBACK_H

