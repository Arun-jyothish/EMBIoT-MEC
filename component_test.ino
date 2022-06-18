// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h> #include <Servo.h>

#define TRIGGER_PIN  D2  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     D3  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


#define led1  D2
#define servo_pin  D6
#define led2  D9
#define pot_pin A0

Servo myservo;


void setup() {
	Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
	Serial.println (" NodeMcu Connected ");  // Print  Connection message in Each Reset
	myservo.attach(servo_pin);

}

void loop() {
	delay(50);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
	digitalWrite(led1,HIGH);
	delay(1000);
	digitalWrite(led1,LOW);
	delay(2000);
	int angle = 90;
	myservo.write(angle);
	Serial.print(" Servo write : ");
	Serial.println(angle);
	delay(1000);

	myservo.write(angle);
	Serial.print(" Servo write : ");
	Serial.println(angle);
	delay(1000);  

	Serial.println("Analog Read from pin ");
	Serial.print(pot_pin);
	int analog_value = analogRead(pot_pin);

	Serial.print(" Read value ");
	Serial.println(analog_value);



	//  Serial.println("PWM LED DIM");
	for(int intensity=0; intensity<255; intensity++){
		analogWrite(led2,intensity);
		delay(10);
	}

	unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
	Serial.print("Ping: ");
	Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
	Serial.println("cm");
}
