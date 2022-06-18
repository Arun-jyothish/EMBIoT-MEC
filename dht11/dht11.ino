#include <DHT11.h>

#define DHTPIN 2

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup(){
	Serial.begin(9600);
	
}
void loop(){
	
	float humidity = dht.readHumidity();
	float temperature = dht.readTemperature();

	if(isnan(humidity)&&isnan(temperature)){
		Serial.println(" Couldn't Read from sensor .. ! ");
		return;
	}

	Serial.print("Humidity : ");
	Serial.println(humidity);
	Serial.print("Temperature : ");
	Serial.println(temperature);
	delay(500);
}
