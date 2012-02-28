/* Auto-generated by genmsg_cpp for file /tmp/buildd/ros-electric-turtlebot-apps-0.2.3/debian/ros-electric-turtlebot-apps/opt/ros/electric/stacks/turtlebot_apps/turtlebot_actions/msg/ActionMsgMapperGoal.msg */
#ifndef TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERGOAL_H
#define TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERGOAL_H
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
struct ActionMsgMapperGoal_ {
  typedef ActionMsgMapperGoal_<ContainerAllocator> Type;

  ActionMsgMapperGoal_()
  : input_topic()
  , output_topic()
  , input_type()
  , output_type()
  , input_list()
  , output_list()
  {
  }

  ActionMsgMapperGoal_(const ContainerAllocator& _alloc)
  : input_topic(_alloc)
  , output_topic(_alloc)
  , input_type(_alloc)
  , output_type(_alloc)
  , input_list(_alloc)
  , output_list(_alloc)
  {
  }

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _input_topic_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  input_topic;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _output_topic_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  output_topic;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _input_type_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  input_type;

  typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _output_type_type;
  std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  output_type;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _input_list_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  input_list;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _output_list_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  output_list;


  ROS_DEPRECATED uint32_t get_input_list_size() const { return (uint32_t)input_list.size(); }
  ROS_DEPRECATED void set_input_list_size(uint32_t size) { input_list.resize((size_t)size); }
  ROS_DEPRECATED void get_input_list_vec(std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) const { vec = this->input_list; }
  ROS_DEPRECATED void set_input_list_vec(const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) { this->input_list = vec; }
  ROS_DEPRECATED uint32_t get_output_list_size() const { return (uint32_t)output_list.size(); }
  ROS_DEPRECATED void set_output_list_size(uint32_t size) { output_list.resize((size_t)size); }
  ROS_DEPRECATED void get_output_list_vec(std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) const { vec = this->output_list; }
  ROS_DEPRECATED void set_output_list_vec(const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other > & vec) { this->output_list = vec; }
private:
  static const char* __s_getDataType_() { return "turtlebot_actions/ActionMsgMapperGoal"; }
public:
  ROS_DEPRECATED static const std::string __s_getDataType() { return __s_getDataType_(); }

  ROS_DEPRECATED const std::string __getDataType() const { return __s_getDataType_(); }

private:
  static const char* __s_getMD5Sum_() { return "9c97ba579bcd822e978741dfc338d44b"; }
public:
  ROS_DEPRECATED static const std::string __s_getMD5Sum() { return __s_getMD5Sum_(); }

  ROS_DEPRECATED const std::string __getMD5Sum() const { return __s_getMD5Sum_(); }

private:
  static const char* __s_getMessageDefinition_() { return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
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
    ros::serialization::serialize(stream, input_topic);
    ros::serialization::serialize(stream, output_topic);
    ros::serialization::serialize(stream, input_type);
    ros::serialization::serialize(stream, output_type);
    ros::serialization::serialize(stream, input_list);
    ros::serialization::serialize(stream, output_list);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint8_t *deserialize(uint8_t *read_ptr)
  {
    ros::serialization::IStream stream(read_ptr, 1000000000);
    ros::serialization::deserialize(stream, input_topic);
    ros::serialization::deserialize(stream, output_topic);
    ros::serialization::deserialize(stream, input_type);
    ros::serialization::deserialize(stream, output_type);
    ros::serialization::deserialize(stream, input_list);
    ros::serialization::deserialize(stream, output_list);
    return stream.getData();
  }

  ROS_DEPRECATED virtual uint32_t serializationLength() const
  {
    uint32_t size = 0;
    size += ros::serialization::serializationLength(input_topic);
    size += ros::serialization::serializationLength(output_topic);
    size += ros::serialization::serializationLength(input_type);
    size += ros::serialization::serializationLength(output_type);
    size += ros::serialization::serializationLength(input_list);
    size += ros::serialization::serializationLength(output_list);
    return size;
  }

  typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct ActionMsgMapperGoal
typedef  ::turtlebot_actions::ActionMsgMapperGoal_<std::allocator<void> > ActionMsgMapperGoal;

typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperGoal> ActionMsgMapperGoalPtr;
typedef boost::shared_ptr< ::turtlebot_actions::ActionMsgMapperGoal const> ActionMsgMapperGoalConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace turtlebot_actions

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "9c97ba579bcd822e978741dfc338d44b";
  }

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x9c97ba579bcd822eULL;
  static const uint64_t static_value2 = 0x978741dfc338d44bULL;
};

template<class ContainerAllocator>
struct DataType< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "turtlebot_actions/ActionMsgMapperGoal";
  }

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> > {
  static const char* value() 
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
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

  static const char* value(const  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> &) { return value(); } 
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.input_topic);
    stream.next(m.output_topic);
    stream.next(m.input_type);
    stream.next(m.output_type);
    stream.next(m.input_list);
    stream.next(m.output_list);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct ActionMsgMapperGoal_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::turtlebot_actions::ActionMsgMapperGoal_<ContainerAllocator> & v) 
  {
    s << indent << "input_topic: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.input_topic);
    s << indent << "output_topic: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.output_topic);
    s << indent << "input_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.input_type);
    s << indent << "output_type: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.output_type);
    s << indent << "input_list[]" << std::endl;
    for (size_t i = 0; i < v.input_list.size(); ++i)
    {
      s << indent << "  input_list[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.input_list[i]);
    }
    s << indent << "output_list[]" << std::endl;
    for (size_t i = 0; i < v.output_list.size(); ++i)
    {
      s << indent << "  output_list[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.output_list[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // TURTLEBOT_ACTIONS_MESSAGE_ACTIONMSGMAPPERGOAL_H
