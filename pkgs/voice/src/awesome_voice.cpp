#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

void say_heading(int robot_x, int robot_y, int robot_heading, int obj_x, int obj_y) {
    stringstream command_string;

    command_string << "espeak -v mb-us1 \"The object is " << (((int)(atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360)%360)>robot_heading ? ((int)(atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360)%360)-robot_heading : robot_heading-((int)(atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360)%360)) << "degrees to the " << (((int)(atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360)%360)>robot_heading ? "left" : "right") << " and " << (int) sqrt(pow(obj_x-robot_x, 2) + pow(obj_y-robot_y, 2)) << " units away.\"";
    system(command_string.str().c_str());
}

int main() {
    //system("espeak -v en \"zack\"");
    say_heading(1, 0, 0, 3, 4);
    return 0;
}
