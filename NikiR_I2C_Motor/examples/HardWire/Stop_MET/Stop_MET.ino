// ПРИМЕР ОСТАНОВКИ МОТОРА НА ЗАДАННОМ РАССТОЯНИИ:        // * Строки со звёздочкой являются необязательными.
                                                 //
#include <Wire.h>                                 //   Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки NikiR_I2C_Motor.
#include <NikiR_I2C_Motor.h>                   //   Подключаем библиотеку для работы с мотором I2C-flash.
NikiR_I2C_Motor mot(0x08);                     //   Объявляем объект mot для работы с функциями и методами библиотеки NikiR_I2C_Motor, указывая адрес модуля на шине I2C.
int PWM_Speed = 70;                            // скорость шим
float k = 1.0;                                                  //   Если объявить объект без указания адреса (NikiR_I2C_Motor mot;), то адрес будет найден автоматически.
void setup(){                                     //
    delay(500);                                   // * Ждём завершение переходных процессов связанных с подачей питания.
    Serial.begin(9600);                           //
    while(!Serial){;}                             // * Ждём завершения инициализации шины UART.
    mot.begin(&Wire); // &Wire1, &Wire2 ...       //   Инициируем работу с мотором, указав ссылку на объект для работы с шиной I2C на которой находится мотор (по умолчанию &Wire).
    mot.radius = 12.2;                            //   Указываем радиус колеса в мм.
    k = 100/PWM_Speed;                             // коэффициент пропорциональности
    mot.setSpeed(PWM_Speed, MOT_PWM, 0.5, MOT_MET);
    delay(1500*k);    
    mot.setStop();   
}                                                 //
                                                  //
void loop(){                                      //
                                //   Приостанавливаем выполнение скетча на 1 секунду.
}                                                 //
