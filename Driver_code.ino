#include <ArduinoHardware.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>
#include "CytronMotorDriver.h"
/*
#define EN_L 9
#define IN1_L 10
#define IN2_L 11

#define EN_R 8
#define IN1_R 12
#define IN2_R 13
*/
#define L1_dir 2 //left front wheel
#define L1_pwm 3
#define L2_dir 4 //left back wheel
#define L2_pwm 5
#define R1_dir 8 //right front wheel
#define R1_pwm 9
#define R2_dir 10 //right rear wheel
#define R2_pwm 11

CytronMD motorL1(PWM_DIR, L1_pwm, L1_dir);
CytronMD motorL2(PWM_DIR, L2_pwm, L2_dir);
CytronMD motorR1(PWM_DIR, R1_pwm, R1_dir);
CytronMD motorR2(PWM_DIR, R2_pwm, R2_dir);

double w_r=0, w_l=0;

//wheel_rad is the wheel radius ,wheel_sep is
double wheel_rad = 0.0325, wheel_sep = 0.295;


ros::NodeHandle nh;
int lowSpeed = 200;
int highSpeed = 50;
double speed_ang=0, speed_lin=0;

void messageCb( const geometry_msgs::Twist& msg){
  speed_ang = msg.angular.z;
  speed_lin = msg.linear.x;
  w_r = (speed_lin/wheel_rad) + ((speed_ang*wheel_sep)/(2.0*wheel_rad));
  w_l = (speed_lin/wheel_rad) - ((speed_ang*wheel_sep)/(2.0*wheel_rad));
}


ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &messageCb );
void Motors_init();
void MotorL(int Pulse_Width1);
void MotorR(int Pulse_Width2);

void setup(){

 Motors_init();

 nh.initNode();

 nh.subscribe(sub);

}


void loop(){
 MotorL(w_l*10);

 MotorR(w_r*10);

 nh.spinOnce();

}


void Motors_init(){

 /*pinMode(EN_L, OUTPUT);

 pinMode(EN_R, OUTPUT);

 pinMode(IN1_L, OUTPUT);

 pinMode(IN2_L, OUTPUT);

 pinMode(IN1_R, OUTPUT);

 pinMode(IN2_R, OUTPUT);

 digitalWrite(EN_L, LOW);

 digitalWrite(EN_R, LOW);

 digitalWrite(IN1_L, LOW);

 digitalWrite(IN2_L, LOW);

 digitalWrite(IN1_R, LOW);

 digitalWrite(IN2_R, LOW);*/

}

void MotorL(int Pulse_Width1){
 if (Pulse_Width1 > 0){

    /* analogWrite(EN_L, Pulse_Width1);

     digitalWrite(IN1_L, HIGH);

     digitalWrite(IN2_L, LOW);
*/
    motorL1.setSpeed(Pulse_Width1);
    motorL2.setSpeed(Pulse_Width1);
 }

 if (Pulse_Width1 < 0){
/*
     Pulse_Width1=abs(Pulse_Width1);

     analogWrite(EN_L, Pulse_Width1);

     digitalWrite(IN1_L, LOW);

     digitalWrite(IN2_L, HIGH);
*/
    motorL1.setSpeed(Pulse_Width1);
    motorL2.setSpeed(Pulse_Width1);
 }

 if (Pulse_Width1 == 0){

     /*analogWrite(EN_L, Pulse_Width1);

     digitalWrite(IN1_L, LOW);

     digitalWrite(IN2_L, LOW);
*/
     motorL1.setSpeed(Pulse_Width1);
     motorL2.setSpeed(Pulse_Width1);
 }

}


void MotorR(int Pulse_Width2){


 if (Pulse_Width2 > 0){
/*
     analogWrite(EN_R, Pulse_Width2);

     digitalWrite(IN1_R, LOW);

     digitalWrite(IN2_R, HIGH);
*/  motorR1.setSpeed(Pulse_Width2);
    motorR2.setSpeed(Pulse_Width2);
 }

 if (Pulse_Width2 < 0){
/*
     Pulse_Width2=abs(Pulse_Width2);

     analogWrite(EN_R, Pulse_Width2);

     digitalWrite(IN1_R, HIGH);

     digitalWrite(IN2_R, LOW);
*/
    motorR1.setSpeed(Pulse_Width2);
    motorR2.setSpeed(Pulse_Width2);
 }

 if (Pulse_Width2 == 0){

    /* analogWrite(EN_R, Pulse_Width2);

     digitalWrite(IN1_R, LOW);

     digitalWrite(IN2_R, LOW);
*/
    motorR1.setSpeed(Pulse_Width2);
    motorR2.setSpeed(Pulse_Width2);
 }

}
