/* 
 * Встраиваемые системы
 * Шарангия Игорь 19-ЗКБс-ПР1
 * вариант 19
 * igor_korenovsk@mail.ru
 */

const int LED = 10;
const int variant = 19;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000+variant*100);
  digitalWrite(LED, LOW);
  delay(1000+variant*100);
}
