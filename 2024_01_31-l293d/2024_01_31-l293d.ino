const int DIR1_M1 = 2; // пин для подключения DIR1 микросхемы моторшилда
const int DIR2_M1 = 4;
const int PWM_M1 = 3;

const int DIR1_M2 = 7;
const int DIR2_M2 = 6;
const int PWM_M2 = 5;

void motor(int velocity_left, int velocity_right, int time_delay=0) {
  velocity_left = constrain(velocity_left,-255,255);
  velocity_right = constrain(velocity_right,-255,255);
  
  if (velocity_left>0) {
    digitalWrite(DIR1_M1,1);
    digitalWrite(DIR2_M1,0);
    analogWrite(PWM_M1,velocity_left);
  }
  else {
    digitalWrite(DIR1_M1,0);
    digitalWrite(DIR2_M1,1);
    analogWrite(PWM_M1,-velocity_left);
  }
  
  digitalWrite(DIR1_M2,velocity_right>0);
  digitalWrite(DIR2_M2,velocity_right<0);
  analogWrite(PWM_M2,abs(velocity_right));
  
  delay(time_delay);
}

void setup() {
  pinMode(DIR1_M1, OUTPUT);
  pinMode(DIR2_M1, OUTPUT);
  pinMode(PWM_M1, OUTPUT);
  pinMode(DIR1_M2, OUTPUT);
  pinMode(DIR2_M2, OUTPUT);
  pinMode(PWM_M2, OUTPUT);
  motor(0,0);
}

void loop() {
  motor(500,-127,1000);
  motor(-255,255,1000);
}
