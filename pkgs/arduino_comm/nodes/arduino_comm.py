#!/usr/bin/env python
import roslib; roslib.load_manifest('arduino_comm')
import rospy
import serial
from std_msgs.msg import UInt16

ser = serial.Serial('/dev/ttyUSB0', 115200)    

def callback(data):
    rospy.loginfo(rospy.get_name() + "I heard %d", data.data)
    ser.write(chr(data.data&0xFF)+chr(data.data>>8))

def listener():
    rospy.init_node('arduino_listener', anonymous=True)
    rospy.Subscriber('obstacledata', UInt16, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
