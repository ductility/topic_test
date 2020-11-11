#include <iostream>

#include <termios.h>
#include <unistd.h>

#include <ros/ros.h>

#include <std_msgs/Int16.h>

void chatterCallback(const std_msgs::Int16& msg)
{
  std::cout << "Input Torque: " << msg.data << std::endl;
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

  while(ros::ok())
  {
    ros::spinOnce();
  }

  return 0;
}