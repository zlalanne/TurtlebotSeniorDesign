#!/usr/bin/python

import roslib; roslib.load_manifest('med_gui')
import rospy
from std_msgs.msg import UInt8MultiArray
from Tkinter import *
import math
import time
import thread

SIZE = 20
ROBOT_HEIGHT = 12
ROBOT_BASE = 6
ROBOT_RADIUS = 20
ANGLE = math.pi - math.atan(ROBOT_HEIGHT/ROBOT_BASE)

width = None
height = None
data = []
theta = None
w = None
lock = thread.allocate_lock()
updated = False

def gui():
    global w
    rospy.init_node('med_gui', anonymous=True)
    rospy.Subscriber('virtualguidata', UInt8MultiArray, callback, queue_size=1, buff_size=10000)
    master = Tk()
    
    w = Canvas(master)
    w.pack()
    thread.start_new_thread(change,())
    mainloop()
    rospy.spin()

def callback(new_data):
    global width
    global height
    global theta
    global data
    global updated

    if lock.acquire(1):
        data = [ord(x) for x in new_data.data]
        width = data.pop(0)
        height = data.pop(0)
        theta = data.pop(0) << 8
        theta += data.pop(0)
        theta = math.radians(theta)
        updated = True                                                               
        lock.release()

def change():
    global updated

    text = None
    circles = []
    robot = None
    robotOutline = None

    while(True):
        if len(data) > 0 and updated:
            w.delete(text)
            text = None
            lock.acquire()
            if len(circles) == 0:
                w.config(width=width*SIZE, height=height*SIZE)
                for y in range(0, height):
                    for x in range(0, width):
                        value = data[y*width+x]
                        if value == 255:
                            value = 'black'
                        else:
                            value = "#%02X%02X00" % (value, 254-value)
                        circles.append(w.create_rectangle(x*SIZE, y*SIZE, (x+1)*SIZE, (y+1)*SIZE, fill=value, outline=value))
            else:
                for y in range(0, height):
                    for x in range(0, width):
                        if(len(circles) > 0):
                            value = data[y*width+x]
                            if value == 255:
                                value = 'black'
                            else:
                                value = "#%02X%02X00" % (value, 254-value)
                            try:
                                w.itemconfig(circles[y*width+x], fill=value, outline=value)
                            except IndexError:
                                print "RectConfig Error: " + str(y*width+x);
                                circles = []
                            
            centerX = width*SIZE/2
            centerY = height*SIZE/2
            x0 = centerX + ROBOT_HEIGHT*math.cos(theta);
            y0 = centerY - ROBOT_HEIGHT*math.sin(theta);
            x1 = centerX + ROBOT_BASE*math.cos(theta+ANGLE);
            y1 = centerY - ROBOT_BASE*math.sin(theta+ANGLE);
            x2 = centerX + ROBOT_BASE*math.cos(theta-ANGLE);
            y2 = centerY - ROBOT_BASE*math.sin(theta-ANGLE);
            if robot is None:
                robot = w.create_polygon(x0, y0, x1, y1, x2, y2, fill='white')
                robotOutline = w.create_oval(centerX-ROBOT_RADIUS, centerY-ROBOT_RADIUS, centerX+ROBOT_RADIUS, centerY+ROBOT_RADIUS, outline='white')
            else:
                w.coords(robot, x0, y0, x1, y1, x2, y2);
                w.coords(robotOutline, centerX-ROBOT_RADIUS, centerY-ROBOT_RADIUS, centerX+ROBOT_RADIUS, centerY+ROBOT_RADIUS)
            updated = False
            lock.release()
        else:
            if text is None:
                canvas_options = w.config()
                text = w.create_text(int(canvas_options['width'][4])/2, int(canvas_options['height'][4])/2, text="Still waiting on robot");

if __name__ == '__main__':
    gui()

