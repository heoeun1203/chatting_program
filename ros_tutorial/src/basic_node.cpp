#include <ros/ros.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "basic_node");
  ros::NodeHandle nh;

  int i = 0;

  while (i < 11) {
     ROS_INFO("20819 허은");
     i++;
  }

}
