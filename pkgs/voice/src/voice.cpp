#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

void say_heading(int robot_x, int robot_y, int robot_heading, int obj_x, int obj_y) {
    stringstream command_string;

    int heading = ((int)(atan2(obj_y - robot_y, obj_x - robot_x)*180/M_PI+360)%360);
    string direction = (heading>robot_heading) ? "left" : "right";
    heading = (heading>robot_heading) ? heading-robot_heading : robot_heading-heading;
    int distance = sqrt(pow(obj_x-robot_x, 2) + pow(obj_y-robot_y, 2));

    command_string << "espeak -v mb-us1 \"The object is " << heading << "degrees to the " << direction << " and " << distance << " units away.\" &> /dev/null";
    
    system(command_string.str().c_str());
}

int main() {
    //system("espeak -v en \"zack\"");
    say_heading(1, 0, 0, 3, 4);
    return 0;
}
