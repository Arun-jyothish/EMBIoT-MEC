#define button_pin D0
const int led_pin = LED_BUILTIN;
int count = 0;
bool button_state = true;


void setup(){
	Serial.begin(9600);
	pinMode(5,INPUT_PULLUP);
	pinMode(led_pin,OUTPUT);
	
}


void loop(){

button_state = digitalRead(button_pin);

if (!button_state){
  while(1){
	button_state = digitalRead(button_pin);
	if(button_state){
		count = count+1;
    return;
	}
	}
}
Serial.println(count);
}
