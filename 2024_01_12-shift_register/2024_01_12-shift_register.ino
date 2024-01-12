// https://ampermarket.kz/base/ex8-indicator-and-74hc595n/
// https://роботехника18.рф/сдвиговый-регистр-74hc595/

#define dataPin  3  // пин подключен к входу DS
#define latchPin 4  // пин подключен к входу ST_CP
#define clockPin 5  // пин подключен к входу SH_CP

const int LEDS_SIZE = 8;
bool numbers [10] [LEDS_SIZE] = {
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,1,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,0},
  {1,1,1,0,0,0,0,0},  
};

int number = 0;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  digitalWrite(latchPin,0);
  for (int i = 0; i<9; i++) {
  	digitalWrite(clockPin,1);
    digitalWrite(dataPin,numbers[number][i]);
  	digitalWrite(clockPin,0); // 1=>0 считывание регистром данных
  }
  digitalWrite(latchPin,1);
  number++;
  if (number>9) number = 0;
  delay(1000);
}
