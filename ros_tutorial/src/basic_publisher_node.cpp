#include "ros/ros.h"
#include "std_msgs/String.h"
#include <boost/algorithm/string/replace.hpp>

int main(int argc, char **argv)
{
  time_t time_now;
    time_now = time(NULL);

    std::string my_name;
    std::string chat_message;

    std::cout << "Input your name : ";

    getline(std::cin, my_name);
    boost::replace_all(my_name, " ", "_");

    std::string time_stamp = std::to_string(time_now);
    std::string node_name = "chatter_publisher_node_" + my_name + "_" + time_stamp;

  ros::init(argc, argv, "he_basic_publisher_node");
  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(60);

boost::replace_all(my_name, "_", " ");

  while (ros::ok())
  {
    std::string mesage;

    std::cin >> mesage;

    std_msgs::String msg;
    msg.data = mesage;
    chatter_pub.publish(msg);

    getline(std::cin, chat_message);

    msg.data = my_name + " : " + chat_message;

       ros::spinOnce();

       loop_rate.sleep();
  }

  return 0;
}
