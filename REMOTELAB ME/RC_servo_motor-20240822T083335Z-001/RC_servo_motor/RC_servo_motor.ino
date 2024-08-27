/*-----------------------------------code điều khiển động cơ Servo---------------------------------------*/
/*
 * Thông số kỹ thuật  Chủng loại: Analog RC Servo.
                      Điện áp hoạt động: 4.8~6.6VDC
                      Lực kéo: 
                      3.5 kg-cm (180.5 ozin) at 4.8V-1.5A
                      5.5 kg-cm (208.3 ozin) at 6V-1.5A
                      Tốc độ quay:
                      0.17sec / 60 degrees (4.8V no load)
                      0.13sec / 60 degrees (6.0V no load)
                      Kích thước: 40mm x 20mm x 43mm
                      Trọng lượng: 55g
 */
#include <Servo.h>          //Khai báo thư viện

#define RCMOTOR 9           //Khai báo biến

Servo myservo;              //Khai báo một đối tượng có tên là myservo thuộc lớp Servo.

void setup()                // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  myservo.attach(RCMOTOR);  
}

void loop() 
{
  myservo.write(val);      // quay theo biến var
}
