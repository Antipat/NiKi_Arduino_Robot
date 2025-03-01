// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ:                    // * Строки со звёздочкой являются необязательными.
                                                  //
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку для работы с аппаратной шиной I2C.
#include <KLIK_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
KLIK_I2C_Motor mot;                           //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor.
                                                  //   Если при объявлении объекта указать адрес, например, mot(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(115200);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    if( mot.begin() ){                            //   Инициируем работу с мотором.
        Serial.print("Найден мотор 0x");          //
        Serial.println( mot.getAddress(), HEX );  //   Выводим текущий адрес модуля.
        
    }else{                                        //
        Serial.println("Мотор не найден!");       //
    }                                             //
}                                                 //
                                                  //
void loop(){                                      //
}                                                 //
                                                  //
//  ПРИМЕЧАНИЕ:                                   //
//  Данный скетч демонстрирует не только          //
//  возможность смены адреса на указанный в       //
//  переменной newAddress, но и обнаружение,      //
//  и вывод текущего адреса модуля на шине I2C.   //
