#!/usr/bin/env python

""" calibrate_linear.py - Version 1.1 2013-12-20

    Move the robot 1.0 meter to check on the PID parameters of the base controller.

    Created for the Pi Robot Project: http://www.pirobot.org
    Copyright (c) 2012 Patrick Goebel.  All rights reserved.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.5
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details at:
    
    http://www.gnu.org/licenses/gpl.html
      
"""
import tf
import rospy
from math import copysign, sqrt, pow
from geometry_msgs.msg import Twist, Point

class CalibrateLinear():
    def __init__(self):
        rospy.init_node('calibrate_linear_node', anonymous=False)

        #execute a shutdown function when terminating the script
        rospy.on_shutdown(self.shutdown)

        self.test_distance = rospy.get_param("~test_distance", 2.0)
        self.speed     = rospy.get_param("~linear_speed", 0.5)
        self.tolerance = rospy.get_param("~tolerance_linear", 0.005)
        self.odom_linear_scale = rospy.get_param("~linear_scale", 1.000)
        self.rate  = rospy.get_param("~check_rate", 15)
        check_rate = rospy.Rate(self.rate)
        self.start_test = True  #default when startup run calibrate

        #Publisher to control the robot's speed
        self.cmd_topic = rospy.get_param("~cmd_topic", '/cmd_vel')
        self.cmd_vel   = rospy.Publisher(self.cmd_topic, Twist, queue_size=5)

        #The base frame is base_footprint for the robot,odom_frame is odom
        self.base_frame = rospy.get_param('~base_frame', '/base_footprint')
        self.odom_frame = rospy.get_param('~odom_frame', '/odom')

        #initialize the tf listener and wait
        self.tf_listener = tf.TransformListener()
        rospy.sleep(2)

        #make sure we see the odom and base frames
        self.tf_listener.waitForTransform(self.odom_frame, self.base_frame, rospy.Time(), rospy.Duration(30.0))
        self.position = Point()

        #get the starting position from the tf between the odom and base frames
        self.position = self.get_position()
        self.x_start  = self.position.x
        self.y_start  = self.position.y

        #print start calibrate summary info
        self.print_summary()

        while not rospy.is_shutdown():
            #get the starting position from the tf between the odom and base frames
            self.position = self.get_position()
            check_rate.sleep() #sleep for while loop

            if self.start_test:
                #compute the euclidean distance from the target point
                distance = sqrt(pow((self.position.x - self.x_start), 2) +
                                pow((self.position.y - self.y_start), 2))

                #correct the estimate distance by the correction factor
                distance *= self.odom_linear_scale
                error = self.test_distance - distance
                rospy.loginfo("-->rest_distance: " + str(error))

                move_cmd = Twist()
                if error < self.tolerance:
                    self.start_test = False
                    self.cmd_vel.publish(Twist())  #stop the robot
                    rospy.logwarn("Now stop move robot !")
                else:
                    move_cmd.linear.x = self.speed
                    self.cmd_vel.publish(move_cmd) #continue move
            else:  #end test
                actual_dist = input("Please input actual distance:")
                linear_scale_error = float(actual_dist)/self.test_distance
                self.odom_linear_scale *= linear_scale_error
                rospy.logwarn("Now get new linear_scale: " + str(self.odom_linear_scale))
                self.print_summary()
                self.start_test = True
                self.x_start = self.position.x
                self.y_start = self.position.y

    def print_summary(self):
        rospy.logwarn("~~~~~~Now Start Linear Speed Calibration~~~~~~")
        rospy.logwarn("-> test_distance: " + str(self.test_distance))
        rospy.logwarn("-> linear_speed: "  + str(self.speed))
        rospy.logwarn("-> move_time: "  + str(self.test_distance/self.speed))
        rospy.logwarn("-> cmd_topic: "  + str(self.cmd_topic))
        rospy.logwarn("-> distance_tolerance: " + str(self.tolerance))
        rospy.logwarn("-> linear_scale: " + str(self.odom_linear_scale))

    #get the current transform between the odom and base frames
    def get_position(self):
        try:
            (trans, rot) = self.tf_listener.lookupTransform(self.odom_frame, self.base_frame, rospy.Time(0))
        except (tf.Exception, tf.ConnectivityException, tf.LookupException):
            rospy.logerr("lookup TF exception !")
            return
        return Point(*trans)

    #Always stop the robot when shutting down the node
    def shutdown(self):
        rospy.logwarn("shutdown test node,stopping the robot")
        self.cmd_vel.publish(Twist())
        rospy.sleep(1)

if __name__ == '__main__':
    try:
        CalibrateLinear()
        rospy.spin()
    except:
        rospy.logerr("Calibration terminated by unknown problems!")
