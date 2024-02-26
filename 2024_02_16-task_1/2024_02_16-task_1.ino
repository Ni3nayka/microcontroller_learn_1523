const int LED_PIN = 9;
const int SENSOR_PIN = A0;
const int BUTTON_PIN = 10;

bool sleep_mode = 1; // 1 - не реагируем, 0 - реагируем на сенсор
bool robber = 0; // 0 - не видели грабителя, 1 - видели грабителя

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if (robber==1) { // если видели вора - мигаем светодиодом
    digitalWrite(LED_PIN, 1);
    delay(500);
    digitalWrite(LED_PIN, 0);
    delay(500);
  }
  else { // если не видели вора - не мигаем
    digitalWrite(LED_PIN, 0);
  }
  
  if (digitalRead(BUTTON_PIN)==1) { // если кнопка нажата
     // ждем пока кнопка нажата
    while (digitalRead(BUTTON_PIN)==1);
    // меняем режим работы
    if (sleep_mode==1) {
      sleep_mode = 0;  
    }
    else {
      sleep_mode = 1;
      robber = 0;
    }
  }
  
  // если включен режим реагирования (не спим) и увидели вора
  if (sleep_mode==0 && analogRead(SENSOR_PIN)<500) {
    robber = 1; // запоминаем, что видели вора
  }
}
