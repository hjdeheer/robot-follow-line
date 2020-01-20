#include <HCSR04.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

const int REV1 = 7;
const int FWD1 = 6;
const int REV2 = 3;
const int FWD2 = 2;
const int triggerPin = 23;
const int echoPin = 22;
float distance;
float velLeft;
float velRight;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);
ros::NodeHandle nh;

void velCallback(const geometry_msgs::Twist& vel) {
  //turn right = 0 is completely to the left.
  //turn right = 2 is completely to the right.
  //vel = 0 standing still. 1 is max speed, -1 is backwards max speed.
   float linear = vel.linear.x;
   float turnLeft = -(255 * vel.angular.z);
   float turnRight = -turnLeft;
   char result[100];
   
   float velocity = linear * 255;
   float velL = velocity + turnLeft;
   float velR = velocity + turnRight;

   dtostrf(distance,98,2,result);
   nh.loginfo(result);
   if(velL > 255){
    velL = 255;
   }
   if(velR > 255){
    velR = 255;
   }
   if(velL < -255){
    velL = -255;
   }
   if(velR < -255){
    velR = -255;
   }
   velRight = velR;
   velLeft = velL;
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
  distance = distanceSensor.measureDistanceCm();
  bool mayDrive = !(distance < 20 && distance >= 0);
  if(velLeft > 0 && mayDrive){
    analogWrite(FWD1, velLeft);
    analogWrite(REV1, 0);
   } else if (velLeft > 0 && !mayDrive){
      analogWrite(FWD1, 0);
      analogWrite(REV1, 0);
   
   }else{
    analogWrite(FWD1, 0);
    analogWrite(REV1, -velLeft);
   }

   if(velRight > 0 && mayDrive){
    analogWrite(FWD2, velRight);
    analogWrite(REV2, 0);
   } else if (velRight > 0 && !mayDrive) {
    analogWrite(FWD2, 0);
    analogWrite(REV2, 0);
   } else {
    analogWrite(FWD2, 0);
    analogWrite(REV2, -velRight);
   }
  

  nh.spinOnce();  
  delay(1); 
}
