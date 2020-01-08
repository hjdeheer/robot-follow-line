// THE TIRES OF THE ARDUINO
const int REV1 = 7;
const int FWD1 = 6;
const int REV2 = 3;
const int FWD2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(REV1, OUTPUT);
  pinMode(FWD1, OUTPUT);
  pinMode(REV2, OUTPUT);
  pinMode(FWD2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 255; i++) {
    analogWrite(FWD1, i);
    analogWrite(FWD2, i);

    delay(50);
  }
  analogWrite(FWD1, 0);
  analogWrite(FWD2, 0);

  delay(1000);
}
