//https://forum.arduino.cc/t/fire-car-with-obstacle-avoidance/927635/8



// L298 pins
//const int ENa = 5;
//const int ENb = 6;
const int IN1 = 3;
const int IN2 = 4;
const int IN3 = 2;
const int IN4 = 7;
//Ultra sonic sensor'
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
//Ultra sonic setup
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input


  Serial.begin(9600);

  // pinMode(ENa, OUTPUT);
  // pinMode(ENb, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  //set the pwm duty cycle for the Enable pin
  // analogWrite(ENa ,MAX_SPEED);
  // analogWrite(ENb , MAX_SPEED);
//STOP
digitalWrite(IN1 , LOW);
digitalWrite(IN2 , LOW);
digitalWrite(IN3 , LOW);
digitalWrite(IN4 , LOW);
}  
void loop() {
Serial.print("Distance: ");
distance=ultrasonic_distance();
Serial.println(distance);
if (distance < 30){
move_stop();
delay(2000);
turn_right();
}
else {
move_forward();
}
  /*
 move_stop();
  delay(3000);

  //move forward
  move_forward();
  delay(5000);

  //stop
  move_stop();
  delay(3000);

// turn right
turn_right();
delay(100);
// move forward
move_forward();
delay(5000);

/*
// turn left
turn_left();
delay(100);
// move forward
move_forward();
delay(5000);



// stop
move_stop();
delay(3000);
// reverse
move_backward();
 delay(5000);

 //Stop
 move_stop();
delay(3000);
*/
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
    digitalWrite(IN1 , HIGH);
    digitalWrite(IN2 , HIGH);
    digitalWrite(IN3 , HIGH);
    digitalWrite(IN4 , LOW);
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
  