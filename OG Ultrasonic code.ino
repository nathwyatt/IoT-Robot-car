

// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 12; 
// Create a servo object 

//Ultra sonic sensor'
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

Servo Servo1; 


const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 2;
const int IN4 = 7;




void setup() { 

   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin);
//Ultra sonic setup
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Serial.begin(9600);
Servo1.write(90); 

 // set the data rate for the SoftwareSerial port


  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

move_stop();
}
void loop(){ 

    autonomous_mode();
  
 
} //.. bluetooth has to be available

// Functions
// autonomous mode
void autonomous_mode(){
  Serial.println("Distance");
Serial.println(ultrasonic_distance());

if(ultrasonic_distance()>20){Servo1.write(90); move_forward(); }
  else {
    move_stop();
      Servo1.write(0); 
      delay(500);                   
      if(ultrasonic_distance()>20)  { turn_right();}
      else {Servo1.write(180);
            
            delay(500);    
              if(ultrasonic_distance()>20)  { turn_left();}
              else{Servo1.write(90);delay(200);
                      if (ultrasonic_distance()<20){ move_backward(); delay(1000);}
              }
          } 
    }

  }

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
int ultrasonic_distance(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  
  return distance;
}