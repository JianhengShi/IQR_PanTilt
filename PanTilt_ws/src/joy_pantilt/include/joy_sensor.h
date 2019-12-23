#ifndef SENSORJOY_H
#define SENSORJOY_H

#include<string.h>

#include"ros/ros.h"
#include"sensor_msgs/Joy.h"
#include"pan_tilt_msg/PanTiltCmd.h"

namespace SJ {

  class SensorJoy
  {
  private:

    std::string sub_topic_;
    std::string pub_topic_;

    ros::Publisher pub_;
    ros::Subscriber sub_;

  public:
    SensorJoy(ros::NodeHandle& yn);
    ~SensorJoy();
    void pan_tilt_publish();
  };
}
#endif