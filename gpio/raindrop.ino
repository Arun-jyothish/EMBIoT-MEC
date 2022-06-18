int led[10] = {2,3,4,5,6,7,8,9,10,11};


void setup(){
	
	for (int i = 0; i<10 ; i++){
		pinMode(led[i],OUTPUT); 
	}
	
}


void loop(){

	for (int i = 2; i<10 ; i++){

		analogWrite(led[i-2],50); 
		analogWrite(led[i-1],150); 
		digitalWrite(led[i],HIGH); 	
		delay(500);
	}

	if (i == 10)
		i = 0;

}
