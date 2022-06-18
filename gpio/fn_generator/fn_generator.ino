
#define led0  D2   // node mcu built in led --- led on when pull down
#define led1  D3
#define led2  D4
#define led3  D5

int off_delay = 1000;
int delay_on =1000;

void setup(){
  
Serial.begin(9600);
  pinMode(led0,OUTPUT);
	pinMode(led1,OUTPUT);
	pinMode(led2,OUTPUT);
	pinMode(led3,OUTPUT);

}


void loop(){

	long int timeInSeconds = millis()/1000;   // convert uptime into seconds
    digitalWrite(led0,LOW);
Serial.println(timeInSeconds);
	if (timeInSeconds % 3 == 0){
		digitalWrite(led1,LOW);
// execute even seconds eg. 2,4,6 ...
	}

	if (timeInSeconds % 6 == 0){
		digitalWrite(led2,LOW);
    // execute 3,6,9....
}
	if (timeInSeconds % 9 == 0){
		digitalWrite(led3,LOW);
    // execute 4,8,12 ...
	}

delay(off_delay);
	digitalWrite(led1,HIGH);
	digitalWrite(led2,HIGH);
	digitalWrite(led3,HIGH);
delay(delay_on);

}
