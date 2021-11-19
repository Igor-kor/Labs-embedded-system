/*
 * Встраиваемые системы
 * Шарангия Игорь 19-ЗКБс-ПР1
 * igor_korenovsk@mail.ru
 */

const int LED = 10;
const int BUTTON = 2; // Контакт 2 для подключения кнопки
int tekButton = LOW; // Переменная для сохранения текущего состояния кнопки
int prevButton = LOW; // Переменная для сохранения предыдущего состояния
// к нопки
boolean ledOn = false; // Текущее состояние светодиода (включен/выключен)


void setup() {
  // put your setup code here, to run once:
  pinMode (LED, OUTPUT);
  // Сконфигурировать контакт кнопки как вход
  pinMode (BUTTON, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  tekButton = digitalRead(BUTTON);
  if (tekButton == HIGH && prevButton == LOW)
  {
    // нажатие кнопки – изменить состояние светодиода
    ledOn = !ledOn;
    digitalWrite(LED, ledOn);
   }
  prevButton = tekButton;

}
