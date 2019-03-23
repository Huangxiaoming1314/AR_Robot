#!/usr/bin/env python 
import rospy 
from std_msgs.msg import String 
 
def callback(data): 
rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data) #写入日志 
 
def listener(): 
 
# In ROS, nodes are uniquely named. If two nodes with the same 
# node are launched, the previous one is kicked off. The 
# anonymous=True flag means that rospy will choose a unique 
# name for our 'listener' node so that multiple listeners can 
# run simultaneously. 
rospy.init_node('listener', anonymous=True) #设置名字为listener的节点,加入随机数 
 
rospy.Subscriber("imu_data", String, callback) #订阅名字为 chatter的话题 
 
# spin() simply keeps python from exiting until this node is stopped 
rospy.spin() 
 
if __name__ == '__main__': 
listener()

