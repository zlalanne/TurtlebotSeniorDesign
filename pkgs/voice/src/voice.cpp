#include <sensor_msgs/Joy.h>
#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

static float robot_x;
static float robot_y;
static float robot_heading;
static float obj_x;
static float obj_y;
static bool button_pressed;

void say_heading() {
    stringstream command_string;

    double heading = (atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360);
    if(heading >= 360) {
        heading -= 360;
    }
    string direction = (heading>robot_heading) ? "left" : "right";
    heading = (heading>robot_heading) ? heading-robot_heading : robot_heading-heading;
    double distance = sqrt(pow(obj_x-robot_x, 2) + pow(obj_y-robot_y, 2));

    distance *= 100;
    command_string << "espeak -v en-us+f2 \"The shit is " << (int)heading << "degrees to the " << direction << " and " << (int)distance << " units away.\" > /dev/null";
    
    system(command_string.str().c_str());
    cout << "Done" << endl;
}

void robotpos_callback(const std_msgs::Float32MultiArray::ConstPtr& data) {
    robot_x = data->data[0];
    robot_y = data->data[1];
    robot_heading = data->data[2];
    obj_x = data->data[3];
    obj_y = data->data[4];
}

void joy_callback(const sensor_msgs::Joy::ConstPtr& joy) {
    button_pressed = joy->buttons[1];
}

int main(int argc, char **argv) {
    //system("espeak -v en \"zack\"");
    bool done = false;
    ros::init(argc, argv, "voice");
    ros::NodeHandle nh;

    ros::Subscriber robotpos_sub = nh.subscribe<std_msgs::Float32MultiArray>("robotpos", 1, robotpos_callback);
    ros::Subscriber joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 1, joy_callback);
   
    while(nh.ok()) {
        if(button_pressed && !done) {
            done = true;
            say_heading();
        }
        else if(!button_pressed) {
            done = false;
        }
        ros::spinOnce();
    }
       return 0;
}
