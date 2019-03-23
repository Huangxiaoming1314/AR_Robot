// Generated by gencpp from file autolabor_pro1_driver/Encode.msg
// DO NOT EDIT!


#ifndef AUTOLABOR_PRO1_DRIVER_MESSAGE_ENCODE_H
#define AUTOLABOR_PRO1_DRIVER_MESSAGE_ENCODE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace autolabor_pro1_driver
{
template <class ContainerAllocator>
struct Encode_
{
  typedef Encode_<ContainerAllocator> Type;

  Encode_()
    : left(0)
    , right(0)  {
    }
  Encode_(const ContainerAllocator& _alloc)
    : left(0)
    , right(0)  {
  (void)_alloc;
    }



   typedef int64_t _left_type;
  _left_type left;

   typedef int64_t _right_type;
  _right_type right;





  typedef boost::shared_ptr< ::autolabor_pro1_driver::Encode_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::autolabor_pro1_driver::Encode_<ContainerAllocator> const> ConstPtr;

}; // struct Encode_

typedef ::autolabor_pro1_driver::Encode_<std::allocator<void> > Encode;

typedef boost::shared_ptr< ::autolabor_pro1_driver::Encode > EncodePtr;
typedef boost::shared_ptr< ::autolabor_pro1_driver::Encode const> EncodeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::autolabor_pro1_driver::Encode_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace autolabor_pro1_driver

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'autolabor_pro1_driver': ['/home/hxm/catkin_ws/src/nav/autolabor_pro1-master/autolabor_pro1_driver/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::autolabor_pro1_driver::Encode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::autolabor_pro1_driver::Encode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::autolabor_pro1_driver::Encode_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "10ec03ad83d596042691890fad8ead6e";
  }

  static const char* value(const ::autolabor_pro1_driver::Encode_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x10ec03ad83d59604ULL;
  static const uint64_t static_value2 = 0x2691890fad8ead6eULL;
};

template<class ContainerAllocator>
struct DataType< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "autolabor_pro1_driver/Encode";
  }

  static const char* value(const ::autolabor_pro1_driver::Encode_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 left\n\
int64 right\n\
";
  }

  static const char* value(const ::autolabor_pro1_driver::Encode_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.left);
      stream.next(m.right);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Encode_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::autolabor_pro1_driver::Encode_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::autolabor_pro1_driver::Encode_<ContainerAllocator>& v)
  {
    s << indent << "left: ";
    Printer<int64_t>::stream(s, indent + "  ", v.left);
    s << indent << "right: ";
    Printer<int64_t>::stream(s, indent + "  ", v.right);
  }
};

} // namespace message_operations
} // namespace ros

#endif // AUTOLABOR_PRO1_DRIVER_MESSAGE_ENCODE_H
