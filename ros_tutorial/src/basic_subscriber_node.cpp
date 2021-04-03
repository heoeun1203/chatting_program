#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  std::cout<<msg->data.c_str()<< std::endl;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "he_basic_subscriber_node");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}
