#!/usr/bin/python

import roslib; roslib.load_manifest('pin_gui')
import rospy
from std_msgs.msg import UInt16
from Tkinter import *
import math
import time
import thread

data = None

def gui():
    global w
    rospy.init_node('pin_gui', anonymous=True)
    rospy.Subscriber('obstacledata', UInt16, callback)
    master = Tk()
    
    w = Canvas(master)
    w.pack()
    thread.start_new_thread(change,())
    mainloop()
    rospy.spin()

def callback(new_data):
    global data
    data = new_data.data


def change():
    text = None
    circles = []
    while(True):
        if data is not None:
            w.delete(text)
            text = None
            if len(circles) == 0:
                w.config(width=200, height=200)
                for y in range(0, 4):
                    for x in range(0, 4):
                        value = 'green' if (data & (1 << (y*4+x))) > 0 else 'red'
                        circles.append(w.create_oval(x*25, y*25, (x+1)*25-10, (y+1)*25-10, fill=value))
            else:
                for y in range(0, 4):
                    for x in range(0, 4):
                        value = 'green' if (data & (1 << (y*4+x))) > 0 else 'red'
                        w.itemconfig(circles[y*4+x], fill=value)
        else:
            if text is None:
                canvas_options = w.config()
                text = w.create_text(int(canvas_options['width'][4])/2, int(canvas_options['height'][4])/2, text="Still waiting on robot");

if __name__ == '__main__':
    gui()

