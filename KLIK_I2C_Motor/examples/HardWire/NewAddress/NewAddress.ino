// ПРИМЕР СМЕНЫ АДРЕСА МОДУЛЯ:                    // * Строки со звёздочкой являются необязательными.
                                                   //
// Данный скетч демонстрирует не только           //
// возможность смены адреса на указанный в        //
// переменной newAddress, но и обнаружение,       //
// и вывод текущего адреса модуля на шине I2C.    //
                                                  //
// Библиотека <KLIK_I2C_Motor.h> предназначена//
// для работы с моторами серии I2C-flash          //
// и меняет только их адреса.                     //

                                                  //
uint8_t newAddress = 0x09;                        //   Назначаемый модулю адрес (0x07 < адрес < 0x7F).
                                                  //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки KLIK_I2C_Motor.
#include <KLIK_I2C_Motor>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
KLIK_I2C_Motor mot;                           //   Объявляем объект mot для работы с функциями и методами библиотеки KLIK_I2C_Motor
                                                  //   Если при объявлении объекта указать адрес, например, mot(0xBB), то пример будет работать с тем модулем, адрес которого был указан.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    if( mot.begin(&Wire) ){                       //   Инициируем работу с мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (Wire, Wire1, Wire2 ...).
        Serial.print("Найден мотор 0x");          //
        Serial.println( mot.getAddress(), HEX );  //   Выводим текущий адрес модуля.
        if( mot.changeAddress(newAddress) ){      //   Меняем адрес модуля на newAddress.
            Serial.print("Адрес изменён на 0x");  //
            Serial.println(mot.getAddress(),HEX );//   Выводим текущий адрес модуля.
        }else{                                    //
            Serial.println("Адрес не изменён!");  //
        }                                         //
    }else{                                        //
        Serial.println("Мотор не найден!");       //
    }                                             //
}                                                 //
                                                  //
void loop(){                                      //
}                                                 //
