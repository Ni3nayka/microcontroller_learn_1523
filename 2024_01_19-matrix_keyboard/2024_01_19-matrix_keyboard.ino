const int out_pin[4] = {13,12,11,10}; // строки
const int in_pin[4] = {9,8,7,6}; // столбцы

// пины светодиодов
const int LED_GREEN = 2;
const int LED_RED = 3;

// матрица символов на клавиатуре
char matrix[4][4] = { 
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char key = 'X';
char old_key = key;

String password = "";

void setup() {
  Serial.begin(9600);
  // запускаем светодиоды
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_RED,OUTPUT);
  // запускаем пины в нужных нам режимах
  for (int i = 0; i < 4; i++) {
    pinMode(out_pin[i], OUTPUT); 
    pinMode(in_pin[i], INPUT_PULLUP); 
    //Serial.println(out_pin[i]);
  }
}

void loop() {
  operating_keyboard();
  if (key!=old_key && key!='X') {
    if (key=='D') {
      if (password=="1234") {
        Serial.println("OK");  
        digitalWrite(LED_GREEN,1);
        delay(1000);
        digitalWrite(LED_GREEN,0);
      }
      else {
        Serial.println("ban!");
        digitalWrite(LED_RED,1);
        delay(1000);
        digitalWrite(LED_RED,0);
        //delay(10000);
      }
      password = "";
    }
    else {
      password += key;
      Serial.println(password);   
    }
  }
  old_key = key;
}

void operating_keyboard() {
  key = 'X';
  // выключаем все out_pin
  for (int i = 0; i < 4; i++) {
    digitalWrite(out_pin[i],1);
  }
  for (int i2 = 0; i2 < 4; i2++) {
    // включаем одну строку
    digitalWrite(out_pin[i2],0); 
    // опрашиваем столбики
    for (int i = 0; i < 4; i++) {
      int k = !digitalRead(in_pin[i]);
      if (k==1) {
        //Serial.println(matrix[i2][i]);
        key = matrix[i2][i];
      }
    }
    // выключаем эту строку
    digitalWrite(out_pin[i2],1); 
  }
}

