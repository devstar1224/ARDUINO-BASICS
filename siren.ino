
int green = 2, blue = 3, red = 4; //DEFINE LED PIN_NV
int bt = 5; //DEFINE BUTTON PIN_NV
int siren; //CHK SIREN STATUS

/* 
When the siren is in operation, the value is 1
if not else the value is 0
same to boolean
*/

void setup() {
pinMode(green, OUTPUT); //BUTTON ACTIVITY LED
pinMode(blue, OUTPUT);
pinMode(red, OUTPUT);
pinMode(bt, INPUT); 
}

void loop() { // DETECTING THE BUTTON
	if (siren == 0){
		dig_wr(green, 1);
		  if (digitalRead(bt)== 1){
		  	dig_wr(green, 0);
  			  siren = 1;
  			  siren_act();
  		  }
	}
}

void siren_act(){ // Blinking siren
delay(300); //Time to loooong press the button so, need to delay
  while (1){
    if(siren==1){
        dig_wr(blue, 1);
        delay(100);
        dig_wr(blue, 0);
        dig_wr(red, 1);
        delay(100);
        dig_wr(red, 0);
      if (digitalRead(bt) == 1){ //When the button is pressed while the siren is operating
        siren = 0;
       }
    }
    else{
      dig_wr(blue, 0);
      dig_wr(red, 0);
      //Time to press the button again
      delay(600); //PUSH BUTTON ERROR DELAY
    break;
    }
 }  
}


void dig_wr(int pin_nv, int value) { 
 digitalWrite(pin_nv, value);
}


/* 
#####2016/11/22##### 
http://github.com/devstar1224
*/
