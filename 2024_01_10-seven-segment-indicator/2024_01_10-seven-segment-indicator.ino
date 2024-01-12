const int LEDS_SIZE = 8;
const int LEDS[LEDS_SIZE] = {2,3,4,5,6,7,8,9};
bool numbers[10][LEDS_SIZE] = {
  {0,1,1,1,1,0,1,1},
  {0,0,1,0,1,0,0,0},
  {1,0,1,1,0,0,1,1},
  {1,0,1,1,1,0,1,0},
  {1,1,1,0,1,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,0,1,1,0,1,1},
  {0,0,1,1,1,0,0,0},
  {1,1,1,1,1,0,1,1},
  {1,1,1,1,1,0,1,0},
};

const int BUTTON_1 = 10;
const int BUTTON_2 = 11;

int num = 5;

void setup() {
  int i = 0;
  while (i<LEDS_SIZE) {
    pinMode(LEDS[i], OUTPUT);
    i++;
  }
  pinMode(BUTTON_1,INPUT); // кнопка
  pinMode(BUTTON_2,INPUT);
}

void loop() {
  // пример кода - отображение всех цифр от 0 до 9
  /*num = 0;
  while (num<10) {
    int i = 0;
    while (i<LEDS_SIZE) {
      digitalWrite(LEDS[i], numbers[num][i]);
      i++;
    }
    num++;
    delay(1000);
  }*/
  // пример кода - увеличение значения при нажатии на одну кнопку
  // и уменьшение значения при нажатии на другую кнопку
  int i = 0;
  while (i<LEDS_SIZE) {
    digitalWrite(LEDS[i], numbers[num][i]);
    i++;
  }
  if (digitalRead(BUTTON_1)==1) { // кнопка
  	num++;
    delay(1000);
  }
  if (digitalRead(BUTTON_2)==1) {
  	num--;
    delay(1000);
  }
}
