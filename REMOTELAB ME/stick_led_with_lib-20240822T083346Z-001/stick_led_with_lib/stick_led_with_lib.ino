/*-----------------------------------code điều khiển stick led---------------------------------------*/
#include "Adafruit_NeoPixel.h"                  // Khai báo thư viện

#define led_stick_pin_1 5                       // Khai báo chân tín hiệu led 1
#define led_stick_pin_2 6                       // Khai báo chân tín hiệu led 2  

#define num_pixels 10                           // Khai báo số led mỗi stick (10 cái)

Adafruit_NeoPixel led_stick_1 = Adafruit_NeoPixel(num_pixels, led_stick_pin_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_stick_2 = Adafruit_NeoPixel(num_pixels, led_stick_pin_2, NEO_GRB + NEO_KHZ800);

int brightness = 10;                            // Khai báo biến brightness dùng kiễu dữ liệu int (độ sáng)
int led_stick_num;                              // Khai báo biến led_stick_num dùng kiễu dữ liệu int (số stick)
int num_led_of_led_stkick;                      // Khai báo biến num_led_of_led_stick dùng kiễu dữ liệu int (số led trên stick)
int red_led;                                    // Khai báo biến red_led
int green_led;                                  // Khai báo biến green_led
int blue_led;                                   // Khai báo biến blue_led    

void setup()                                    // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  #if defined (__AVR_ATtiny85__)   
  if (F_CPU == 16000000) 
  {
    clock_prescale_set(clock_div_1);                  /*Khởi tạo đối tượng led_stick_1*/
  }                                                   /*và led_stick_2 với độ sáng brightness.*/
  #endif                                              /*Gọi hàm begin để khởi tạo thư viện NeoPixel.*/
  led_stick_1.setBrightness(brightness);
  led_stick_1.begin();
  led_stick_2.setBrightness(brightness);
  led_stick_2.begin();
}

void loop()                                     // đặt code trong đây sẽ lặp lại vô hạn lần 
{
  for (int i = 0; i < 10; i++)                /*Chạy 8 vòng lặp, mỗi vòng lặp tạo hiệu ứng LED di chuyển qua lại trên 1 LED stick.*/ 
  {                                           /*Vòng lặp bên trong: Lặp 10 lần để di chuyển LED từ đầu đến cuối LED stick.*/
    control_single_led( 1, i, 255, 0, 0);     /*Gọi hàm control_single_led để điều khiển một LED đơn.*/
    delay(100);                               /*Đặt màu sắc cho LED theo thứ tự (đỏ -> tắt -> xanh -> tắt -> xanh dương -> tắt -> trắng -> tắt).*/
  }                                           /*Sau mỗi vòng lặp di chuyển, có một khoảng chờ delay(100) để tạo hiệu ứng nhấp nháy.*/
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);                    
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 0, 255, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 0, 0, 255);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, i, 255, 255, 255);
    delay(100);
  }
  for (int i = 0; i < 10; i++)
  {
    control_single_led( 1, 9 - i, 0, 0, 0);
    delay(100);
  }
}

void control_single_led(int led_stick_num, int num_led_of_led_stkick, int red, int green, int blue) // hàm control_sigle_led
{
  if (led_stick_num == 1)                                                                           /*Điều khiển một LED đơn trên LED stick được chọn (led_stick_num).*/
  {                                                                                                 /*Kiểm tra led_stick_num để xác định LED stick.*/
    led_stick_1.setPixelColor(num_led_of_led_stkick, led_stick_1.Color(red, green, blue));          /*Gọi hàm setPixelColor để đặt màu sắc cho LED tại vị trí num_led_of_led_stkick*/
    led_stick_1.show();                                                                             /*Gọi hàm show để hiển thị màu sắc mới trên LED stick.*/
  }
  else if (led_stick_num == 2)
  {
    led_stick_2.setPixelColor(num_led_of_led_stkick, led_stick_2.Color(red, green, blue));
    led_stick_2.show();
  }
}

void led_stick_all_on()                                                                             // hàm led_stick_all_on
{
  for (int i = num_pixels; i >= 0; i--)                                                             /*Bật tất cả các LED trên cả 2 LED stick với màu trắng (255, 255, 255).*/
  {                                                                                                 /*Sử dụng vòng lặp để duyệt qua tất cả các LED.*/
    led_stick_1.setPixelColor(i, led_stick_1.Color(255, 255, 255));                                 /*Gọi setPixelColor để đặt màu cho từng LED.*/  
    led_stick_2.setPixelColor(i, led_stick_2.Color(255, 255, 255));                                 /*Gọi show để hiển thị màu sắc mới trên cả 2 LED stick*/ 
  }
  led_stick_1.show();
  led_stick_2.show();
}

void led_stick_all_off()                                                                            // hàm led_stick_all_off  
{
  for (int i = num_pixels; i >= 0; i--)                                                             /*Tắt tất cả các LED trên cả 2 LED stick.*/
  {                                                                                                 /*Sử dụng vòng lặp để duyệt qua tất cả các LED*/
    led_stick_1.setPixelColor(i, led_stick_1.Color(0, 0, 0));                                       /*Gọi setPixelColor để đặt màu đen (0, 0, 0) cho từng LED.*/
    led_stick_2.setPixelColor(i, led_stick_2.Color(0, 0, 0));                                       /*Gọi show để hiển thị màu sắc mới trên cả 2 LED stick.*/
  }
  led_stick_1.show();
  led_stick_2.show();
}
