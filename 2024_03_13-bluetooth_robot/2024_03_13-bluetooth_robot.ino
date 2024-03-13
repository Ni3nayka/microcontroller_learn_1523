const int PWM_1 = 5;
const int PWM_2 = 6;
const int DIR_1 = 4;
const int DIR_2 = 7;
const int DIR_1a = 9;
const int DIR_2a = 8;

void setup() {
  pinMode(PWM_1, OUTPUT);
  pinMode(PWM_2, OUTPUT);
  pinMode(DIR_1, OUTPUT);
  pinMode(DIR_2, OUTPUT);
  pinMode(DIR_1a, OUTPUT);
  pinMode(DIR_2a, OUTPUT);
  Serial.begin(9600);
}

int m = 255;

void loop() {
  /*motors(255,255);
  delay(1000);
  motors(-255,-255);
  delay(1000);
  motors(-100,100);
  delay(1000);*/
  if (Serial.available()>0) {
    char f = Serial.read();
    if (f=='F') motors(m,m);
    if (f=='B') motors(-m,-m);
    if (f=='L') motors(-m,m);
    if (f=='R') motors(m,-m);
    if (f=='S') motors(0,0);
    if (f=='0') m = 0;
    if (f=='1') m = 25;
    if (f=='2') m = 50;
    if (f=='3') m = 75;
    if (f=='4') m = 100;
    if (f=='5') m = 125;
    if (f=='6') m = 150;
    if (f=='7') m = 175;
    if (f=='8') m = 200;
    if (f=='9') m = 225;
    if (f=='q') m = 255;
  }
}

void motors(int speed_1, int speed_2) {
  if (speed_1>0) {
    digitalWrite(DIR_1,1);
    digitalWrite(DIR_1a,0);
    analogWrite(PWM_1,speed_1);
  }
  else {
    digitalWrite(DIR_1,0);
    digitalWrite(DIR_1a,1);
    analogWrite(PWM_1,-speed_1);
  }
  if (speed_2>0) {
    digitalWrite(DIR_2,1);
    digitalWrite(DIR_2a,0);
    analogWrite(PWM_2,speed_2);
  }
  else {
    digitalWrite(DIR_2,0);
    digitalWrite(DIR_2a,1);
    analogWrite(PWM_2,-speed_2);
  }
}
