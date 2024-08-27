/*-----------------------------------code điều khiển LED BAR---------------------------------------*/
/*
 * Thông số kỹ thuật  SKU: 104020006
                      Điện áp sử dụng: 3.3~5VDC
                      Số Led: 10
 */
#include <Grove_LED_Bar.h>                  // Khai báo thư viện của led bar
Grove_LED_Bar bar(28, 29, 0, LED_BAR_10);   // Gọi hàm từ thư viện
#define button 50                           // Khai báo nút bấm
int button1 = 0;                            // biến button1 sử dụng kiểu dữ liệu int    
  
void setup()                                // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  bar.begin();                              // Khởi tạo biến bar
  pinMode(button, INPUT_PULLUP);            // khởi tạo nút nhấn
}
  
void loop()                                 // đặt code trong đây sẽ lặp lại vô hạn lần 
{
  /*
  int read_button = digitalRead(button);    // code nút nhấn
  if(read_button == 0)
  {
    button1++;
    delay(250);
  }
  bar.setLevel(button1);
  if(button1 == 10)
  {
    button1 = 0;
  }*/
  singleled();                            // hàm con singleled
  level();                                // hàm con level
  setled();                               // hàm con setled
  randomled();                            // hàm con randomled
  reverseled();                           // hàm con reverseled
  toggle();                               // hàm con toggle
  walk();                                 // hàm con walk
}
void singleled()                          // hàm con singleled
{
  /* bar.setLed(position led, 1=on/0=off) */

  for (int i = 1; i <= 10; i++)  // bật toàn bộ LED
  {
    bar.setLed(i, 1);
    delay(500);
  }
 
  for (int i = 1; i <= 10; i++)  //tắt toàn bộ LED
  {
    bar.setLed(i, 0);
    delay(500);
  }
}

void level()                              // hàm con level
{
  /* bar.setLevel(min=0/max=10) */
  for (int i = 0; i <=10; i++)            //led chạy theo mức từ thấp --> cao
  {
    bar.setLevel(i);
    delay(1000);
  }
}

void setled()                            // hàm con setled  
{
  // Turn on LEDs with binary
  // LEDs color     green        yellow  red
  // LEDs position     10 9 8 7 6 5 4 3 2 1
  // Binary          0b 1 1 1 1 1 1 1 1 1 1 = 0x3FF (HEX)
  bar.setBits(0x3ff);         // set bit để led chạy theo
  delay(1000);
  bar.setBits(0x0);           // tắt toàn bộ LED 
  delay(1000);  
  bar.setBits(0b0000000001); // Bật LED 1 
  delay(1000);
  bar.setBits(0x155); // bật các LEDs 1, 3, 5, 7, 9 (0x155 = 0b0101010101)
  delay(1000);
  bar.setBits(0x2AA); // bật các LEDs 2, 4, 6, 8, 10(0x2AA = 0b1010101010)
  delay(1000);
}

void randomled()                        //hàm con randomled
{
  // Display a random value between 0 (all LEDs off) and 1023 (all LEDs on)
  bar.setBits(random(1024));            //led bật random
  delay(50);
}

void reverseled()                       // hàm con reverseled
{
  bar.setGreenToRed(1); // LED chạy từ xanh lá qua đỏ
  level();
  bar.setGreenToRed(0); // LED chạy từ đỏ qua xanh lá
  level();
}

void toggle()                          // hàm con toggle   
{
  bar.toggleLed(3); // Tắt LED 3
  delay(1000);
  bar.toggleLed(3); // Bật LED 3
  delay(1000);
}

void walk()                           // hàm con walk 
{
  // 0 = 0x0 = all 10 LEDs turned off
  // 1023 = 0x3FF = all 10 LEDs lit up
  for (int i = 0; i <= 1023; i++)    // LED bật từ LED 1 --> 10
  {
    bar.setBits(i);                 // Set bit
    delay(50);
  }
}
