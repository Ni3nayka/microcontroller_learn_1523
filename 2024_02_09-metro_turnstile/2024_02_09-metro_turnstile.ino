#include <Servo.h>

Servo servo_1;

const int OPTICAL_SENSOR = A0;
const int BUTTON_PIN = 4;

void setup() {
  Serial.begin(9600);
  pinMode(OPTICAL_SENSOR,INPUT);
  pinMode(BUTTON_PIN,INPUT);
  servo_1.attach(7);
  servo_1.write(0);
  //delay(1000);
  //servo_1.write(90);
  //delay(1000);
  //servo_1.write(0);
}


// вариант попроще
/*void loop() {
  bool optical = digitalRead(OPTICAL_SENSOR);
  bool button = digitalRead(BUTTON_PIN);
  Serial.println(optical);
  if (optical==1) { // если пробегает заяц
    servo_1.write(90);
    delay(1000);
    servo_1.write(0);
  }
  if (button==1) {
    while (optical==0) {
      optical = digitalRead(OPTICAL_SENSOR);
    }
    delay(100);
    while (optical==1) {
      optical = digitalRead(OPTICAL_SENSOR);
    }
    delay(100);
  }
}*/

// вариант посложнее

bool button_enable = 0;
bool people_was_go = 0;

void loop() {
  bool optical = digitalRead(OPTICAL_SENSOR);
  bool button = digitalRead(BUTTON_PIN);
  Serial.println(optical);
  if (optical==1) { // если пробегает заяц
    people_was_go = 1;
    if (button_enable==0) {
      servo_1.write(90);
      delay(1000);
      servo_1.write(0);
    }
  }
  else {
    if (people_was_go==1 && button_enable==1) {
      button_enable = 0;
    }
    people_was_go = 0;
  }
  if (button==1) {
    button_enable = 1;
  }
}
