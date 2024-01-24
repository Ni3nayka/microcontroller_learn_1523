const int DIR_1 = 10;
const int DIR_2 = 11;

void setup() {
  pinMode(DIR_1, OUTPUT);
  pinMode(DIR_2, OUTPUT);
}

void loop() {
  for (int i = 0; i<=255; i++) {
   	analogWrite(DIR_1,i);
    delay(10);
  }
  for (int i = 255; i>=0; i--) {
   	analogWrite(DIR_1,i);
    delay(10);
  }
  for (int i = 0; i<=255; i++) {
   	analogWrite(DIR_2,i);
    delay(10);
  }
  for (int i = 255; i>=0; i--) {
   	analogWrite(DIR_2,i);
    delay(10);
  }
}
