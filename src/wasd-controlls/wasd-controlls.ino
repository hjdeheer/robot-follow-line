#include <NewPing.h>
// THE TIRES OF THE ARDUINO
const int REV1 = 7;
const int FWD1 = 6;
const int REV2 = 3;
const int FWD2 = 2;
const int serialPort = 9600;

void setup() {
  // put your setup code here, to run once:
  pinMode(REV1, OUTPUT);
  pinMode(FWD1, OUTPUT);
  pinMode(REV2, OUTPUT);
  pinMode(FWD2, OUTPUT);
  Serial.begin(serialPort);
}

void loop() {
  if(Serial.available() > 0){
    char inchar= Serial.read();
    if(inchar == 'w'){
      analogWrite(FWD1, 200);
      analogWrite(FWD2, 200);
      analogWrite(REV1, 0);
      analogWrite(REV2, 0);
      Serial.write("forward \n");
    }
    if(inchar == 'a'){
      analogWrite(REV1, 200);
      analogWrite(REV2, 0);
      analogWrite(FWD2, 200);
      analogWrite(FWD1, 0);
      Serial.write("left\n");
    }
    if(inchar == 'd'){
      analogWrite(REV1, 0);
      analogWrite(REV2, 200);
      analogWrite(FWD2, 0);
      analogWrite(FWD1, 200);
      Serial.write("right\n");
    }
    
    if(inchar == 's'){
      analogWrite(FWD1, 0);
      analogWrite(FWD2, 0);
      analogWrite(REV1, 200);
      analogWrite(REV2, 200);
      Serial.write("reverse\n");
    }
    if(inchar == 'x'){
      analogWrite(FWD1, 0);
      analogWrite(FWD2, 0);
      analogWrite(REV1, 200);
      analogWrite(REV2, 200);
      Serial.write("reverse\n");
    }
  }

  //delay(1000);
}
