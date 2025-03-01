// ОПРЕДЕЛЕНИЕ РЕАЛЬНОГО ПЕРЕДАТОЧНОГО ОТНОШЕНИЯ: // * Строки со звёздочкой являются необязательными.
                                                  //
                                                  //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки KLIK_I2C_Motor.
#include <KLIK_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
KLIK_I2C_Motor mot(0x09);                     //   Объявляем объект mot для работы с функциями и методами библиотеки KLIK_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (KLIK_I2C_Motor mot;), то адрес будет найден автоматически.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    mot.begin(&Wire); // &Wire1, &Wire2 ...       //   Инициируем работу с мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (по умолчанию &Wire).
    mot.delSum();                                 //   Сбрасываем количество совершённых оборотов вала.  
}                                                 //   Для определения этого значения воспользуйтесь примером библиотеки FindMagnet.
                                                  //
void loop(){                                      //
    Serial.println( mot.getReducer());        //   Выводим передаточное отношение
    delay(200);                                   //
}                                                 //
                                                  //
/*  ВЫПОЛНИТЕ СЛЕДУЮЩИЕ ДЕЙСТВИЯ:                 //
 *  После старта скетча, в мониторе будут появляться значения 0.00
 *  При вращении ротора мотора (в любую сторону), эти значения будут увеличиваться.
 *  Поворачивайте вручную ротор мотора до тех пор пока вал редуктора не повернётся на 1 полный оборот.
 *  В мониторе появится значение равное передаточному отношению редуктора. Оно может быть не целым!
 *  Для большей точности советуем поворачивать ротор мотора до тех пор, пока вал редуктора не повернётся 10 раз, и разделить полученное значение на 10.
*/