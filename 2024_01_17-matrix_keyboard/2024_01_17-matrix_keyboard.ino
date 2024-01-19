const int out_pin[4] = {13,12,11,10}; // строки
const int in_pin[4] = {9,8,7,6}; // столбцы

// матрица символов на клавиатуре
char matrix[4][4] = { 
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

void setup() {
  Serial.begin(9600);
  // запускаем пины в нужных нам режимах
  for (int i = 0; i < 4; i++) {
    pinMode(out_pin[i], OUTPUT); 
    pinMode(in_pin[i], INPUT_PULLUP); 
    //Serial.println(out_pin[i]);
  }
}

void loop() {
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
        //Serial.print(i2);
        //Serial.print(" ");
        //Serial.println(i);
        Serial.print(matrix[i2][i]);
      }
      else {
        Serial.print(k);
      }
    }
    Serial.println();
    // выключаем эту строку
    digitalWrite(out_pin[i2],1); 
  }
  Serial.println();
  delay(100);
}

