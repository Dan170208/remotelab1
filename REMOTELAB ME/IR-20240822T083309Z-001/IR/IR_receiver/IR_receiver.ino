/*-----------------------------------code điều khiển cảm biến nhận tín hiệu hồng ngoại---------------------------------------*/
/*
 * 
 */
#include <Arduino.h>                                        //Khai báo thư viện Arduino
#include <IRremote.hpp>                                     //Khai báo thư viện IRremote

#define DECODE_NEC                                          //Khai báo giải mã NEC
#define IR_RECEIVE_PIN 25                                   //Khai báo chân nhận tín hiệu hồng ngoại

void setup()                                                // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code 
{
  Serial.begin(230400);                                     //Mở cổng Serial, tốc độ truyền dữ liệu (9600,115200,230400,....)
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);    //Khởi tạo biến IrSender
}

void loop()                                                 //Đặt code trong đây sẽ lặp lại vô hạn lần
{
  if (IrReceiver.decode())                                  //Điều kiện nêu cảm biến nhận tín hiệu hồng ngoại thì sẽ giải mã
  {
    if (IrReceiver.decodedIRData.protocol == UNKNOWN)       //Nếu tín hiẹu hồng ngoại nhận được không nhận diện được
    {
      IrReceiver.printIRResultRawFormatted(&Serial, true);  //In ra cổng Serial thông tin chi tiết về tín hiệu hồng ngoại chưa nhận điện được
    }
    IrReceiver.resume();                                    //Sau khi xử lý xong tín hiệu sẽ xử 
    Serial.println(IrReceiver.decodedIRData.command);       //In dữ liệu tín hiệu hồng ngoại ra cổng serial
  }
}+
