#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int SENSOR_PIN_1 = A0;
const int SENSOR_PIN_2 = A1;

int count = 0; // количество людей
bool first_triggering = 0; // запоминаем, что увидели человека

void setup() {
  lcd.begin(16,2);
}

void loop() {
  // если хотя бы одним датчиком мы увидели человека
  if (analogRead(SENSOR_PIN_1)<500 || analogRead(SENSOR_PIN_2)<500) {
    // прибавляем 1 если увидели "левым"
    if (analogRead(SENSOR_PIN_1)<500) {
      count++;
    }
    else if (count>0) { // и вычитаем, если увидели "правым" и проверяем чтобы счетчик не ушел в минус
      count--;
    }
    // отрисовываем количество людей на дисплее
    lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print(count);  
    // ждем, пока человек загораживает первый датчик
    while (analogRead(SENSOR_PIN_1)<500 || analogRead(SENSOR_PIN_2)<500);
    // ждем, пока человек не загораживает датчики (находится между ними)
    while (analogRead(SENSOR_PIN_1)>500 && analogRead(SENSOR_PIN_2)>500);
    // ждем, пока человек загораживает второй датчик
    while (analogRead(SENSOR_PIN_1)<500 || analogRead(SENSOR_PIN_2)<500);
  }
}
