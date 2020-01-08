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
//  // put your main code here, to run repeatedly:
//  for (int i = 0; i < 255; i++) {
//    analogWrite(FWD1, i);
//    analogWrite(FWD2, i);
//
//    delay(50);
//  }
//  analogWrite(FWD1, 0);
//  analogWrite(FWD2, 0);
  if(Serial.available() > 0){
    char inchar= Serial.read();
    if(inchar == 'w'){
      analogWrite(FWD1, 200);
      Serial.write("lets goooooooooo");
    }
    if(inchar == 's'){
      analogWrite(FWD1, 0);
      Serial.write("stop it, get some help");
    }
  }

  //delay(1000);
}
