#include <string>
#include <ros/ros.h> // 包含ROS的头文件
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <boost/asio.hpp> //包含boost库函数
#include <boost/bind.hpp>
#include <math.h>
#include "std_msgs/String.h" //ros定义的String数据类型
#include <std_msgs/Float32.h>
using namespace std;
using namespace boost::asio; //定义一个命名空间，用于后面的读写操作
unsigned char buf[9]; //定义字符串长度，IMU返回的数据是17个字节一组，可用串口调试助手获得
unsigned char flag[2];
std::string string_to_hex(const std::string& input)
{
	static const char* const lut = "0123456789ABCDEF";
	size_t len = input.length();
	std::string output;
	output.reserve(2 * len);
	for (size_t i = 0; i < len; ++i)
	{
		const unsigned char c = input[i];
		output.push_back(lut[c >> 4]);
		output.push_back(lut[c & 15]);
	}
	return output;
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "JY901"); //初始化节点
	ros::NodeHandle n;
	ros::Publisher IMU_pub = n.advertise<std_msgs::Float32>("imu_data", 20); //定义发布消息的名称及sulv
	ros::Rate loop_rate(5000);
	io_service iosev;
	serial_port sp(iosev, "/dev/ttyUSB0"); //定义传输的串口
	sp.set_option(serial_port::baud_rate(115200));// 波特率
	sp.set_option(serial_port::flow_control(serial_port::flow_control::none));// 流量控制
	sp.set_option(serial_port::parity(serial_port::parity::none ));// 奇偶校验
	sp.set_option(serial_port::stop_bits(serial_port::stop_bits::one));// 停止位
	sp.set_option(serial_port::character_size(8));// 数据位
	ROS_INFO_STREAM("Serial Port initialized"); 
	ROS_INFO_STREAM("Serial Port initialized"); 
	ROS_INFO_STREAM("Serial Port initialized"); 
	while (ros::ok())
	{
		//read (sp,buffer(buf));
		read (sp,buffer(flag));
		if(flag[0]==0x55&&flag[1]==0x53)
		{
			read (sp,buffer(buf));		
		string str(&buf[0],&buf[8]); //将数组转化为字符串
		std_msgs::String msg;
		std::stringstream ss;
		ss << str;
		std_msgs::Float32 Yaw; //定义机器人偏航角，单位为度数
		std_msgs::Float32 Roll;
		std_msgs::Float32 Pitch;		
		//cout << Yaw << endl; //输出偏航角到终端
		msg.data = string_to_hex(ss.str());
		ROS_INFO("%s", msg.data.c_str()); //打印接受到的字符串
		Yaw.data = (short(buf [5]<<8| buf [4]))/32768.0*180;
		Roll.data = (short(buf [1]<<8| buf [0]))/32768.0*180;
		Pitch.data = (short(buf [3]<<8| buf [2]))/32768.0*180;
                ROS_INFO_STREAM("Yaw:  %s "<<Yaw);
                ROS_INFO_STREAM("Roll: %s "<<Roll);
                ROS_INFO_STREAM("Pitch:%s "<<Pitch);
		//cout <<"Yaw:"<<Yaw<< endl;
		//cout <<"Roll:"<<Roll<< endl;
		//cout <<"Pitch:"<<Pitch<< endl;	 
		IMU_pub.publish(Yaw); //发布消息
                IMU_pub.publish(Roll);
                IMU_pub.publish(Pitch);
		}
		//else
	        //{
	        //	flag[0]='\0';
	        //	for(int i=0;i<10;i++)
	        //		buf[i]='\0';
	        //}	
	        ros::spinOnce();
	        loop_rate.sleep();	
	}
	
	iosev.run();
	return 0;
}
/*
#include <string>
#include <ros/ros.h>                           // 包含ROS的头文件
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <boost/asio.hpp>                  //包含boost库函数
#include <boost/bind.hpp>
#include <math.h>
#include "std_msgs/String.h"              //ros定义的String数据类型
#include <std_msgs/Float32.h>
 
using namespace std;
using namespace boost::asio;           //定义一个命名空间，用于后面的读写操作
 
unsigned char buf[17];                      //定义字符串长度，IMU返回的数据是17个字节一组，可用串口调试助手获得
 
std::string string_to_hex(const std::string& input)
{
   static const char* const lut = "0123456789ABCDEF";
   size_t len = input.length();
   std::string output;
   output.reserve(2 * len);
   for (size_t i = 0; i < len; ++i)
   {
    const unsigned char c = input[i];
    output.push_back(lut[c >> 4]);
    output.push_back(lut[c & 15]);
   }
   return output;
}
 
 
int main(int argc, char** argv)
{
 
    ros::init(argc, argv, "boost");       //初始化节点
    ros::NodeHandle n;
 
    ros::Publisher IMU_pub = n.advertise<std_msgs::Float32>("IMU_data", 1000);      //定义发布消息的名称及sulv
 
    ros::Rate loop_rate(100);
 
    io_service iosev;
    serial_port sp(iosev, "/dev/ttyUSB0");         //定义传输的串口
    sp.set_option(serial_port::baud_rate(115200));
    sp.set_option(serial_port::flow_control());
    sp.set_option(serial_port::parity());
    sp.set_option(serial_port::stop_bits());
    sp.set_option(serial_port::character_size(8));
 
    while (ros::ok())
    {
 
       read (sp,buffer(buf));
       string str(&buf[0],&buf[17]);            //将数组转化为字符串
 
       std_msgs::String msg;
       std::stringstream ss;
       ss << str;
       std_msgs::Float32  Yaw;        //定义机器人偏航角，单位为度数
       char higher;
       char lower;
       higher = buf[5];
       lower = buf[4];
       Yaw.data= (float)((higher * 256 + lower))/100;
       cout << Yaw << endl;   //输出偏航角到终端
       msg.data = string_to_hex(ss.str());
       ROS_INFO("%s", msg.data.c_str());        //打印接受到的字符串
       IMU_pub.publish(Yaw);   //发布消息
       ros::spinOnce();
       loop_rate.sleep();
    }
    iosev.run();
    return 0;
}
*/
