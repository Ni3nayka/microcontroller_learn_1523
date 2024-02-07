#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(1);
Adafruit_LiquidCrystal lcd_2(0);

const int BUTTON = 2;

int dino = 0;
int score = 0;

int kaktus = 17;

int fpc = 500;

void setup() {
  lcd_1.begin(16,2);
  lcd_2.begin(16,2);
  pinMode(BUTTON,INPUT);
  //lcd_1.clear();
}

void loop() {
  int button = digitalRead(BUTTON);
  if (button==1 && dino==0) {
    dino++;  
  }
  
  lcd_2.setCursor(0,0);
  lcd_2.print(score);
  score++;
  delay(fpc);
  
  lcd_1.clear();
  if (dino==0 || dino>2) {
    dino = 0;
    lcd_1.setCursor(0,1);
    lcd_1.print("R");
  }
  else {
    lcd_1.setCursor(0,0);
    lcd_1.print("R");
    dino++;
  }
  
  kaktus--;
  if (kaktus<0) {
    kaktus = 17;
    fpc = fpc*0.5;
  }
  lcd_1.setCursor(kaktus,1);
  lcd_1.print("#");
  
  if (kaktus==0 && dino==0) {
    lcd_1.setCursor(2,0);
    lcd_1.print("GAME OVER!");
    while(1);
  }
}
