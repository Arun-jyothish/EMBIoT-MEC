#include <Servo.h>

Servo myservo;

int angle;
#define servo_pin D6

void setup(){
	myservo.attach(servo_pin);
	Serial.begin(9600);
}

void loop(){

angle = 0;
myservo.write(angle);
delay(500);
angle += 90;
myservo.write(angle);
delay(500);

if (Serial.available()){
	Serial.println("Enter angle : ");
	int read_value = Serial.read();
	myservo.write(read_value);
}
	
}
