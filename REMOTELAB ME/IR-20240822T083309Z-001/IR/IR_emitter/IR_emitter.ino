/*-----------------------------------code điều khiển cảm biến Phát tín hiệu hồng ngoại---------------------------------------*/
/*
 * 
 */
#include <Arduino.h>                                //Khai báo thư viện Arduino
#include <IRremote.hpp>                             //Khai báo thư viện IRremote

#define DISABLE_CODE_FOR_RECEIVER                   //Khai báo tắt code cho Receiver    
#define IR_SEND_PIN 3                               //Khai báo chân tín hiệu của đầu phát

uint8_t sCommand = 0x00 ;                           //Khai báo biến sCommand dùng kiểu dữ liệu uint8_t
uint8_t sRepeats = 0;                               //Khai báo biến SRepeat dùng kiểu dữ liệu uint8_t
char sChar;                                         //Khai báo biến sChar dùng kiểu dữ liệu Char

void setup()                                        // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code

{
  Serial.begin(230400);                             //Mở cổng Serial, tốc độ truyền dữ liệu (9600,115200,230400,....)  
  IrSender.begin(DISABLE_LED_FEEDBACK);             //Khởi tạo biến IrSender
}

void loop()                                         //Đặt code trong đây sẽ lặp lại vô hạn lần
{
  if (Serial.available() > 0)                       //Điều kiện Nếu có số Serial > 0
  {
    sChar = Serial.read();                          //Đọc dữ liệu từ biến sChar
    sCommand = (uint8_t)strtol(&sChar, NULL, 16);   //Đọc dữ liệu từ biến sCommand 
    Serial.flush();                                 //Đẩy toàn bộ dữ liệu cũ đi 
    IrSender.sendNEC(0x00, sCommand, 0);            //Cảm biến hồng ngoại gửi Lệnh đi
    delay(20);                                      //Gửi lệnh đi trong 0,2s
  }
}
