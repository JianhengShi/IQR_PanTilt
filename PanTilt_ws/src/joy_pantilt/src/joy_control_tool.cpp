#include"joy_sensor.h"
#include"ros/ros.h"
int main(int argc,char** argv){
  ros::init(argc, argv, "joy_pantilt");
  ros::NodeHandle n;
  SJ::SensorJoy joy_pantilt(n);
  while(ros::ok()) {
    joy_pantilt.pan_tilt_publish();
  }
  return 0;
}