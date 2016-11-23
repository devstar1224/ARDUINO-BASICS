
int AL_green = 6, AL_blue = 5, AL_red = 4; //DEFINE ALAM LED PIN_NV
int md_green = 10, md_blue = 9, md_red =8; //DEFINE MODE LED PIN_NV
int bz = 7; //DEFINE BUZZER PIN_NV
int bt = 3; //DEFINE BUTTON PIN_NV
int sensor = A0; //DEFINE DETECT SENSOR PIN_NV
int bt_mode;

void setup() {
pinMode(AL_green, OUTPUT); //BUTTON ACTIVITY LED
pinMode(AL_blue, OUTPUT);
pinMode(AL_red, OUTPUT);
pinMode(md_green, OUTPUT);
pinMode(md_blue, OUTPUT);
pinMode(md_red, OUTPUT);
pinMode(bt, INPUT); 
pinMode(bz, OUTPUT);
Serial.begin(9600);
}

void loop() { // DETECTING THE BUTTON
if (digitalRead(bt) == 1){
  bt_mode++;
}
  switch(bt_mode){
    case(0): //off mode
      dig_wr(bz, 0);
      dig_wr(AL_green, 0);
      dig_wr(AL_blue, 0);
      dig_wr(AL_red, 0);
      dig_wr(md_red, 0);
      dig_wr(md_green, 0);
      dig_wr(md_blue, 1);
      delay(300);
      break;
    case(1): //safe mode
      dig_wr(AL_green, 1);
      dig_wr(AL_blue, 0);
      dig_wr(AL_red, 0);
      dig_wr(md_red, 0);
      dig_wr(md_green, 1);
      dig_wr(md_blue, 0);
      delay(300);
      break;
    case(2)://detect_move mode
      dig_wr(AL_green, 0);
      dig_wr(AL_blue, 0);
      dig_wr(AL_red, 0);
      dig_wr(md_red, 1);
      dig_wr(md_green, 0);
      dig_wr(md_blue, 0);
      detect_move();
      delay(300);
      break;
    default:
      bt_mode = 0;
      break;
  }
}

void detect_move(){
while (1){
  if (analogRead(sensor) >= 200 && bt_mode == 2){ //200 is sensor values, you must be edited the values
 while (1){
        dig_wr(AL_blue, 1);
        delay(100);
        dig_wr(bz, 1);
        dig_wr(AL_blue, 0);
        dig_wr(AL_red, 1);
        delay(100);
        dig_wr(AL_red, 0);
    if ( digitalRead(bt) == 1){ //When the button is pressed while the siren is operating
        bt_mode = 0;
        break;
       }
    }
 }
else{
  delay(300);
 if (digitalRead(bt) == 1 || bt_mode == 0){
        bt_mode = 0;
        break;
       }
 }
}
}
void dig_wr(int wr_pin_nv, int value) { 
 digitalWrite(wr_pin_nv, value);
}

/* 
#####2016.11.23#####
http://github.com/devstar1224
*/