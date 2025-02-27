// ПРИМЕР ВЫБОРА БОРТА УСТАНОВКИ (ЛЕВЫЙ/ПРАВЫЙ):  // * Строки со звёздочкой являются необязательными.
                                                  //

#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки NikiR_I2C_Motor.
#include <NikiR_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
NikiR_I2C_Motor mot(0x08);                    //   Объявляем объект mot1 для работы с функциями и методами библиотеки NikiR_I2C_Motor, указывая адрес модуля на шине I2C.

                                                  //   При наличии нескольких моторов на шине I2C нельзя объявлять объект без указания адреса.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    mot.begin(&Wire); // &Wire1, &Wire2 ...      //   Инициируем работу с 1 мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (по умолчанию &Wire).
    
                         
mot.setSpeed(50.0, MOT_PWM); 
}                                                 //
                                                  //
void loop(){                                      //
 mot.setDirection(true);                         // против часовой стрелки 
 delay(3000);
  mot.setDirection(false);                       // по часовой стрелке
 delay(3000);
 

}                                                 //
                                                  //   
// Если моторы установлены по бокам подвижного    //
// механизма (машине, танке, тракторе...), то для //
// реализации поступательного движения механизма, //
// моторы расположенные на противоположных бортах //
// механизма, должны вращаться в противоположном  //
// направлении.                                   //