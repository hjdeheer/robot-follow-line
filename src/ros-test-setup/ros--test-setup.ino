#include <ros.h>
#include <geometry_msgs/Twist.h>

const int REV1 = 7;
const int FWD1 = 6;
const int REV2 = 3;
const int FWD2 = 2;
ros::NodeHandle nh;

void velCallback(const geometry_msgs::Twist& vel) {
   geometry_msgs::Twist new_vel = vel;  
   nh.loginfo("Test");
   digitalWrite(FWD1, HIGH); 
 }

ros::Subscriber<geometry_msgs::Twist> sub ("cmd_vel", &velCallback); 

void setup() {  
  pinMode(REV1, OUTPUT);
  pinMode(FWD1, OUTPUT);
  pinMode(REV2, OUTPUT);
  pinMode(FWD2, OUTPUT); 
  nh.initNode();  
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();  
  delay(1); 
}
