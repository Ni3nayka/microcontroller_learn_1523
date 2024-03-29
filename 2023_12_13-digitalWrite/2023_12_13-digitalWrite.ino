// создаем константы, в которые записываем, 
// к какому пину подключен какой светодиод
// *константы принято называть капсом
const int LED_GREEN = 5;  // пин зеленого светодиода
const int LED_YELLOW = 4; // пин желтого светодиода
const int LED_RED = 3;    // пин красного светодиода

// подпрограмма setup, вызывается в самом начале один раз 
// (как main)
void setup() {
  // Запускаем монитор порта (последовательного интерфейса)
  // для вывода информации с контроллера на компьютер
  Serial.begin(9600); 
  
  // выводим в монитор порта фразу "Hello, world!"
  // и после вывода переходим на новую строку (printLN)
  Serial.println("Hello, world!");
  
  // Настраиваем пины, к которым подключены светодиоды, 
  // как пины вывода (управления) - OUTPUT
  pinMode(LED_GREEN,OUTPUT);  // пин зеленого светодиода
  pinMode(LED_YELLOW,OUTPUT); // пин желтого светодиода
  pinMode(LED_RED,OUTPUT);    // пин красного светодиода
}

// подпрограмма loop, вызывается бесконечное количество раз,
// после завершения подпрограммы setup
void loop() {
  digitalWrite(LED_GREEN,1);  // включаем (1) зеленый светодиод
  digitalWrite(LED_RED,0);    // выключаем (0) красный светодиод
  delay(1000); // ждем одну секунду (1000 милисекунд)
  digitalWrite(LED_GREEN,0);  // выключаем (0) зеленый светодиод
  digitalWrite(LED_YELLOW,1); // включаем (1) желтый светодиод
  delay(1000); // ждем одну секунду (1000 милисекунд)
  digitalWrite(LED_YELLOW,0); // выключаем (0) желтый светодиод
  digitalWrite(LED_RED,1);    // включаем (1) красный светодиод
  delay(1000); // ждем одну секунду (1000 милисекунд)
}


