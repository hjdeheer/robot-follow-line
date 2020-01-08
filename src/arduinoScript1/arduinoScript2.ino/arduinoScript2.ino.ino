const int REV1 = 7;
const int FWD1 = 6;
const int REV2 = 3;
const int FWD2 = 2;

void setup() {
  pinMode(REV1, OUTPUT);
  pinMode(FWD1, OUTPUT);
  pinMode(REV2, OUTPUT);
  pinMode(FWD2, OUTPUT);

}

void loop() {
  for(int i = 0; i < 255; i++){
    analogWrite(REV1, i);
    analogWrite(REV2, i);
    delay(5);
  }

  delay(3000);
  
  for(int i = 255; i > -1; i--){
    analogWrite(REV1, i);
    analogWrite(REV2, i);
    delay(5);
  }
  
  delay(3000);

  for(int i = 0; i < 255; i++){
    analogWrite(FWD1, i);
    analogWrite(FWD2, i);
    delay(5);
  }

  delay(3000);

  for(int i = 255; i > -1; i--){
    analogWrite(FWD1, i);
    analogWrite(FWD2, i);
    delay(5);
  }
  
  delay(3000);
}
