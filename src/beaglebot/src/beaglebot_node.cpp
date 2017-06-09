#include "ros/ros.h"
#include "std_msgs/String.h"
#include "beaglebot/beaglebot_node.h"

extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}


int main(int argc, char **argv)
{
//-----ROS Initialization-----------------------------------------------------------------------------
  ros::init(argc, argv, "beaglebot_node");
  ros::NodeHandle nh;
  beaglebot::setMotor_msg setmotor;

//-----BeagleBone Robotics Cape Initialization--------------------------------------------------------
  if (rc_initialize() < 0){
    ROS_INFO("Error: failed to initialize robotics cape drivers");
    return -1;
  }

  //ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000); //example publisher

//-----Signal Handlers-----------------------------------------------------------------------------------

//-----System States-------------------------------------------------------------------------------------

//-----LED Control---------------------------------------------------------------------------------------

//-----Button Control------------------------------------------------------------------------------------

//-----Motor Control-------------------------------------------------------------------------------------
  enableMotors_sub = nh.subscribe("enableMotors", 1, enableMotors);
  setMotor_sub = nh.subscribe("setMotors", 1, setMotor);
//-----Quadrature Encoder Control------------------------------------------------------------------------

//-----Analog Reads--------------------------------------------------------------------------------------

//-----Servo Control-------------------------------------------------------------------------------------

  ros::Rate loop_rate(10);


  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  if (rc_cleanup()< 0) {
    ROS_INFO("Error: failed to close robotics cape drivers");
    ROS_INFO("Please run rc_kill in a terminal");
    return -1;
  }

  return 0;
}

//Signal Handlers

//System States

//LED Control

//Button Control

//Motor Control

int enableMotors(bool input){
  if (input){
    rc_enable_motors();
  } else {
    rc_disable_motors();
  }
}

int setMotor(setmotor){
  float duty = setmotor.duty / 100; //change from -100 to 100 to -1 to 1
  //check for out-of-bounds duty
  if (duty > 1) {
    duty = 1;
  } else if (duty < -1) {
    duty = -1;
  }

  //check for out-of-bounds motor
  return rc_set_motor(setmotor.motor, duty);

}

//Servo Control

