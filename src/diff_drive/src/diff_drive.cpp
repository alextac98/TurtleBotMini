#include "ros/ros.h"
#include "std_msgs/String.h"
#include "diff_drive/diff_drive.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "diff_drive");
  ros::NodeHandle nh;

  ros::Subscriber controller = nh.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}

