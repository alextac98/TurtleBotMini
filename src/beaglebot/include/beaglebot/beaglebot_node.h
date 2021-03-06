#ifndef BEAGLEBOT_NODE_H
#define BEAGLEBOT_NODE_H


//-----Signal Handlers-----------------------------------------------------------------------------------
ros::Subscriber disableSignalHandler_sub; //not implemented
ros::Subscriber enableSignalHandler_sub;  //not implemented

//-----System States-------------------------------------------------------------------------------------
ros::Publisher getRCState_pub;
ros::Subscriber setRCState_sub;

//-----LED Control---------------------------------------------------------------------------------------
ros::Subscriber setLED_sub;
ros::Publisher getLED_pub;
ros::Subscriber blinkLED_sub;

//-----Button Control------------------------------------------------------------------------------------
//Not Implemented yet

//-----Motor Control-------------------------------------------------------------------------------------
ros::Subscriber enableMotors_sub;
void enableMotors_callback(const std_msgs::Bool msg);

ros::Subscriber setMotor_sub;
void setMotor_callback(const beaglebot_msg::setMotor_msg msg);
ros::Subscriber setAllMotors_sub;
//void setAllMotors(const);

ros::Subscriber freeSpinMotor_sub;
ros::Subscriber freeSpinAllMotors_sub;

ros::Subscriber breakMotor_sub;
ros::Subscriber breakAllMotors_sub;

//-----Quadrature Encoder Control------------------------------------------------------------------------
ros::Publisher getEncoderPosition_pub;
ros::Publisher setEncoderValue_pub;

//-----Analog Reads--------------------------------------------------------------------------------------
ros::Publisher batteryVoltage_pub;
ros::Publisher dcJackVoltage_pub;
ros::Publisher adcVoltage_pub;

//-----Servo Control-------------------------------------------------------------------------------------
ros::Subscriber enableServos_sub;
ros::Subscriber disableServos_sub;


//-----

#endif // BEAGLEBOT_NODE_H
