const int LED_PIN = 13; // пин светодиода

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0) { // если мы что-то отправили на ардуинку из монитора порта
  	char f = Serial.read(); // считать первый пришедший символ изз монитора порта
    if (f=='H') { // если считанный символ - H - то включить светодиод
      digitalWrite(LED_PIN,1);
    }
    if (f=='L') {// если считанный символ - L - то выключить светодиод
      digitalWrite(LED_PIN,0);
    }
  }
}
