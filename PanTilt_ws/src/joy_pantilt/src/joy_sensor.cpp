#include "joy_sensor.h"
SJ::SensorJoy::SensorJoy(ros::NodeHandle& yn) {
  /*Get the topic_name from parameter master.*/
  yn.getParamCached("pub_topic_", pub_topic_);
  yn.getParamCached("sub_topic_", sub_topic_);
  /*Initialize the publisher and subscriber.*/
  pub_ = yn.advertise<pan_tilt_msg::PanTiltCmd>(pub_topic_, 1);
  // sub_ = yn.subscribe<sensor_msgs::Joy>(sub_topic_, 10, &SJ::SensorJoy::JoyCallback, this);
  sleep(2);
}

SJ::SensorJoy::~SensorJoy() {
}

void SJ::SensorJoy::pan_tilt_publish() {
  pan_tilt_msg::PanTiltCmd pan_tilt;
  //reset
  pan_tilt.pitch = 0.0;
  pan_tilt.yaw = 0.0;
  pan_tilt.speed = 20;
  pub_.publish(pan_tilt);
  sleep(2);
  while (1)
  {
  //yaw:40
  pan_tilt.yaw = 60.0;
  pan_tilt.pitch = 60.0;
  pan_tilt.speed = 30;
  pub_.publish(pan_tilt);
  sleep(6);
  pan_tilt.yaw = -60.0;
  pan_tilt.pitch = -60.0;
  pan_tilt.speed = 30;
  pub_.publish(pan_tilt);
  sleep(6);
  }
  
}
