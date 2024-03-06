const int LED = 13;
const int BUTTON = 5;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  //int button = digitalRead(BUTTON);
  while (digitalRead(BUTTON)==0);
  while (digitalRead(BUTTON)==1);
  //delay(3000);
  unsigned long int t = millis(); // сколько время?
  bool save_button_state = 0;
  //while (digitalRead(BUTTON)==0 && t+3000>millis());
  while (1) {
    if (digitalRead(BUTTON)==1) {
      save_button_state = 1;
      digitalWrite(LED,1);
      delay(1000);
      digitalWrite(LED,0);
      delay(1000);
      break;  
    }
    if (t+3000<millis()) {
      break;  
    }
  }
  
  t = millis();
  bool led_state = 0;
  while (digitalRead(BUTTON)==0 && !save_button_state) {
    if (t+1000<millis()) {
      led_state = !led_state;
      t = millis();
    }
    digitalWrite(LED, led_state);
    /*digitalWrite(LED,1);
    delay(1000);
    digitalWrite(LED,0);
    delay(1000);*/
    // мы анализируем кнопку
  }
  while (digitalRead(BUTTON)==1);
}
