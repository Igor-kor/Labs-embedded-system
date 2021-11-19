/*
 * Встраиваемые системы
 * Шарангия Игорь 19-ЗКБс-ПР1
 * используется датчик температуры DS18b20 и библиотека OneWire
 * пример подключения https://arduinomaster.ru/datchiki-arduino/arduino-ds18b20/
 * даташит DS18b20 http://mypractic.ru/ds18b20-datchik-temperatury-s-interfejsom-1-wire-opisanie-na-russkom-yazyke.html
 * igor_korenovsk@mail.ru
*/
#include <OneWire.h>

OneWire ds(8); // Объект OneWire

const int BLUE = 5; // Вывод BLUE RGB-светодиода
const int GREEN = 9; // Вывод GREEN RGB-светодиода
const int RED = 6; // Вывод RED RGB-светодиода
int MIN_T = 20; // Нижний порог
int MAX_T = 30; // Верхний порог

int temperature = 0; // Глобальная переменная для хранения значение температуры с датчика DS18B20

long lastUpdateTime = 0; // Переменная для хранения времени последнего считывания с датчика
const int TEMP_UPDATE_TIME = 1000; // Определяем периодичность проверок

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

}

void loop() {
  detectTemperature(); // Определяем температуру от датчика DS18b20
  Serial.println(temperature); // Выводим полученное значение температуры
  // Т.к. переменная temperature имеет тип int, дробная часть будет просто отбрасываться
}

int detectTemperature() {

  byte data[2];
  ds.reset();
  ds.write(0xCC);
  ds.write(0x44);

  if (millis() - lastUpdateTime > TEMP_UPDATE_TIME)
  {
    lastUpdateTime = millis();
    ds.reset();
    ds.write(0xCC);
    ds.write(0xBE);
    data[0] = ds.read();
    data[1] = ds.read();

    // Формируем значение
    temperature = (data[1] << 8) + data[0]; 
    temperature = temperature >> 4;
    if (temperature < MIN_T) // синий цвет RGB-светодиода
      setRGB(1, 1, 0);
    else if (temperature > MAX_T) // красный цвет RGB-светодиода
      setRGB(0, 1, 1);
    else // зеленый цвет RGB-светодиода
      setRGB(1, 0, 1);
  }

}

void setRGB(int r, int g, int b)
{
  digitalWrite(RED, r);
  digitalWrite(GREEN, g);
  digitalWrite(BLUE, b);
}
