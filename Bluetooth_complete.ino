//code write by Moz for YouTube changel LogMaker360, 27-10-2015
//code belongs to this video: https://www.youtube.com/watch?v=6jZMJ7DFCY0

#include <SoftwareSerial.h>
SoftwareSerial BT(1, 0); 
// creates a "virtual" serial port/UART
// connect BT module TX to 0
// connect BT module RX to 1
// connect BT Vcc to 5V, GND to GND

// L298 pins

const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 2;
const int IN4 = 7;
void setup()  
{
  // set digital pin to control as an output
  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");

  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='m')
    {
      digitalWrite(13, HIGH);
      BT.println(" Moving forward ");
    move_forward(); 
    
    }
    if (a=='s')
    {
      digitalWrite(13, LOW);
      BT.println(" STOP");
    move_stop();
    
  }
    if (a=='l')
    {
      BT.println("Turning left");
      turn_left();
    
    }   

    if (a=='r')
    {
      BT.println("Turning r");
      turn_right();
    
    } 

    if (a=='b')
    {
      BT.println("Reversing");
      move_backward();
    
    } 
    // you can add more "if" statements with other characters to add more commands
  }
}
// FUnctions
    void move_backward() {
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , LOW);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
  }
  void move_forward() {
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
  }

  void move_stop() {
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , HIGH);
  }

  void turn_left() {
    digitalWrite(IN1 , LOW);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , HIGH);
    delay(1000);
  }

  void turn_right() {
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , LOW);
    digitalWrite(IN4 , HIGH);
    delay(1000);
  }