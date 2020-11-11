#include <iostream>

#include <termios.h>
#include <unistd.h>

#include <ros/ros.h>

#include <std_msgs/Int16.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int16>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    std_msgs::Int16 msg;

    char input_char;

    // int key_input;
    
    std::cout << "Input Mode ( !: exit, 0: 0 torque, 1: 10 torque, 2: 50 torque)" << std::endl;
    std::cin >> input_char;

    if(input_char == '0')
    {
      msg.data = 0;
    }
    else if(input_char == '1')
    {
      msg.data = 10;
    }
    else if(input_char == '2')
    {
      msg.data = 50;
    }
    else if(input_char == '!')
    {
      break;
    }
    else
    {
      std::cout << "Wrong Input!!"<< std::endl;
      continue;
    }

    // ROS_INFO("%d", msg);

    chatter_pub.publish(msg);

    ros::spinOnce();
  }

  return 0;
}
