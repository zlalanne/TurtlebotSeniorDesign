/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-electric-turtlebot-apps-0.2.3/debian/ros-electric-turtlebot-apps/opt/ros/electric/stacks/turtlebot_apps/turtlebot_actions/msg/ActionMsgMapperActionGoal.msg */
#ifndef TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERACTIONGOAL_H
#define TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERACTIONGOAL_H
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

#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "turtlebot_actions/ActionMsgMapperGoal.h"

namespace turtlebot_actions
{
template <class ContainerAllocator>
struct ActionMsgMapperActionGoal_ {
  typedef ActionMsgMapperActionGoal_<ContainerAllocator> Type;

  ActionMsgMapperActionGoal_()
  : header()
  , goal_id()
  , goal()
  {
  }

  ActionMsgMapperActionGoal_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , goal_id(_alloc)
  , goal(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
   ::actionlib_msgs::GoalID_<ContainerAllocator>  goal_id;

  typedef  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator>  _goal_type;
   ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator>  goal;


private:
  static const char* __s_getDataType_() { return "turtlebot_actions/ActionMsgMapperActionGoal"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "10050ee576c29a2c373416dcd9499fb9"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
ActionMsgMapperGoal goal\n\
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
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: turtlebot_actions/ActionMsgMapperGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definition\n\
string    input_topic      \n\
string    output_topic      \n\
string    input_type      \n\
string    output_type      \n\
string[]   input_list\n\
string[]   output_list\n\
\n\
\n\
\n\
"; }
public:
  ROS_DEPRECATED static const std::string __s_getMessageDefinition() { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED const std::string __getMessageDefinition() const { return __s_getMessageDefinition_(); }

  ROS_DEPRECATED virtual uint8_t *serialize(uint8_t *write_ptr, uint32_t seq) const
  {
    ros::serialization::OStream stream(write_ptr, 1000000000);
    ros::serialization::serialize(stream, header);
    ros::serialization::serialize(stream, goal_id);
    ros::serialization::serialize(stream, goal);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, header);
    ros::serialization::deserialize(stream, goal_id);
    ros::serialization::deserialize(stream, goal);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(header);
    size += ros::serialization::serializationLength(goal_id);
    size += ros::serialization::serializationLength(goal);
    return size;
  }

  typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ActionMsgMapperActionGoal
typedef  ::turtlebot_actions::ActionMsgMapperActionGoal_<std::allocator<void> > ActionMsgMapperActionGoal;

typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperActionGoal> ActionMsgMapperActionGoalPtr;
typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperActionGoal const> ActionMsgMapperActionGoalConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace turtlebot_actions

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "10050ee576c29a2c373416dcd9499fb9";
  }

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x10050ee576c29a2cULL;
  static const uint64_t static_value2 = 0x373416dcd9499fb9ULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "turtlebot_actions/ActionMsgMapperActionGoal";
  }

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
ActionMsgMapperGoal goal\n\
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
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: turtlebot_actions/ActionMsgMapperGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#goal definition\n\
string    input_topic      \n\
string    output_topic      \n\
string    input_type      \n\
string    output_type      \n\
string[]   input_list\n\
string[]   output_list\n\
\n\
\n\
\n\
";
  }

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.goal_id);
    stream.next(m.goal);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ActionMsgMapperActionGoal_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::turtlebot_actions::ActionMsgMapperActionGoal_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
s << std::endl;
    Printer< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};


} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERACTIONGOAL_H

