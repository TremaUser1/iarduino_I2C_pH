// ПРИМЕР НАСТРОЙКИ МОДУЛЯ:                       // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку   для работы с аппаратной шиной I2C.
#include <iarduino_I2C_pH.h>                      //   Подключаем библиотеку   для работы с pH-метром I2C-flash.
iarduino_I2C_pH sensor(0x09);                     //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_pH, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_pH sensor;), то адрес будет найден автоматически.
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     sensor.begin();                              //   Инициируем работу с pH-метром I2C-flash.
     sensor.setKnownPH (1, 4.00);                 //   Устанавливаем водородный показатель 1 жидкости для калибровки модуля кнопкой от 0 до 14,000 pH.
     sensor.setKnownPH (2, 9.18);                 //   Устанавливаем водородный показатель 2 жидкости для калибровки модуля кнопкой от 0 до 14,000 pH.
     sensor.setKy      (   3.00);                 //   Устанавливаем коэффициент усиления операционного усилителя от 1 до 65,535.
     sensor.setVstp    (  59.16);                 //   Устанавливаем шаг смещения напряжения датчика от 0,01 мВ до 655,35 мВ при смещении кислотности на 1 pH.
     sensor.setPHn     (   7.00);                 //   Устанавливаем нейтральную кислотность для датчика от 0 до 14,000 pH.
}                                                 //
                                                  //
void loop(){}                                     //
                                                  //
/*   Все указанные значения сохраняются в         //
 *   энергонезависимую память модуля.             //
 *   Функция setKy не меняет коэффициент усиления //
 *   ОУ, а указывает его значение для рассчётов.  //
 */