#include <ros/ros.h>
#include <string>
#include <std_msgs/String.h>
#include "ros_arduino_msgs/Analog.h"
#include "ros_arduino_msgs/AnalogFloat.h"


//话题回调函数
void chatterCallback_MQ_5(const ros_arduino_msgs::Analog::ConstPtr& msg)
{
   ROS_INFO("Get the value of arduino_MQ_5   :[ %d ]", msg->value);
}
void chatterCallback_MQ_135(const ros_arduino_msgs::Analog::ConstPtr& msg)
{
   ROS_INFO("Get the value of arduino_MQ_135 :[ %d ]", msg->value);
}

int main(int argc,char **argv)
{

   ros::init(argc,argv,"check_sensor_node");//初始化ROS，命名节点名
   ros::NodeHandle n; //节点句柄实例话
   ros::Subscriber sub = n.subscribe("arduino/sensor/arduino_MQ_5",1000,chatterCallback_MQ_5);  
   ros::Subscriber sub1 = n.subscribe("arduino/sensor/arduino_MQ_135",1000,chatterCallback_MQ_135);
   ros::spin();//程序循环，直到ros::ok返回false,进程结束
   
   return 0;
}
