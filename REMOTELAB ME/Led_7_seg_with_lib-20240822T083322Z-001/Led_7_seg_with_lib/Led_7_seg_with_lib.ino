/*-----------------------------------code điều khiểu LED 7 đoạn---------------------------------------*/
/*
 * Thông số kỹ thuật SKU: 104030003
                     Điện áp sử dụng: 3.3~5VDC
                     Dòng sử dụng: 80mA
                     Kích thước led 7 đoạn: 0.36 inch
 */

#include "TM1637.h"                 //Khai báo thư viện "TM1637"
#define CLK1 30                     // Khai báo Pin CLK for display 1                            
#define DIO1 31                     // Khai báo Pin DIO for display 1
#define CLK2 32                     // Khai báo Pin CLK for display 2
#define DIO2 33                     // Khai báo Pin DIO for display 2
TM1637 tm1637_1(CLK1, DIO1);        // Khai báo object TM1637 for display 1
TM1637 tm1637_2(CLK2, DIO2);        // Khai báo object TM1637 for display 2
float number = -1234.5;             // Khai báo biến number xài kiểu dữ liệu float
int reverse_value = 1;              // Khai báo biến reverse_value xài kiểu dữ liệu int
void setup() {                      // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
  tm1637_1.init();                  // khởi tạo display 1
  tm1637_1.set(BRIGHT_TYPICAL);     // set độ sáng display 1
  tm1637_2.init();                  // khởi tạo display 2
  tm1637_2.set(BRIGHT_TYPICAL);     // set độ sáng display 2
  tm1637_1.clearDisplay();          // clear Display 1
  tm1637_2.clearDisplay();          // clear Display 2
}

void loop() {                       // đặt code trong đây sẽ lặp lại vô hạn lần
  display_string();                 // in chuỗi display
  delay(2000);                      // trong khoảng 2s
  display_lock();                   // khoá display
  delay(2000);                      // trong khoảng 2s
  display_number();                 // số display
}

void display_number()               // viết hàm con display_number
{
  /*
  Hàm in giá trị số lên màn hình display 4 số
  */
  tm1637_1.displayNum(number);      // gọi thư viện cho hàm display Num
  number += 17.42 * reverse_value;  // tính toán
  if (abs(number) > 1500)           // nếu giá trị tuyệt đối lớn hơn 1500
  {
    reverse_value *= -1;            // giá trị đảo ngược 
  }
  delay(50);                        // delay 50ms
}

void display_string()               // viết hàm con display_string
{
  /*
    Hàm in giá trị số lên màn hình display 4 số
  */
  tm1637_2.clearDisplay();        // clear nội dung đang hiển thị trên màn hình
  // ON
  tm1637_2.displayStr("ON");      //Dòng này gọi hàm displayStr() của đối tượng tm1637_2 để hiển thị chuỗi ký tự "ON" lên màn hình.                  
  delay(2000);                    //delay 2s
  // loop
  tm1637_2.displayStr("REMOTELAB", 1000); //Dòng này hiển thị chuỗi "REMOTELAB" lên màn hình và giữ nguyên trong 1000 đơn vị thời gian.
  delay(2000);                    //delay 2s
  // OFF
  tm1637_2.displayStr("0FF");     //Hiển thị chuỗi "OFF" lên màn hình.
  delay(2000);                    //delay 2s
}

void display_lock()
{
  /*
  Hàm in giá trị số lên màn hình display 4 số.
  tm1637.display(vị trí, giá trị);
  */
  tm1637_2.display(0,1);  // Vị trí 1 show số 1 on display
  tm1637_2.display(1,2);  // Vị trí 2 show số 2 on display
  tm1637_2.display(2,3);  // Vị trí 3 show số 3 on display
  tm1637_2.display(3,4);  // Vị trí 4 show số 4 on display
  tm1637_1.display(0,5);  // Vị trí 1 show số 5 on display
  tm1637_1.display(1,6);  // Vị trí 2 show số 6 on display
  tm1637_1.display(2,7);  // Vị trí 3 show số 7 on display
  tm1637_1.display(3,8);  // Vị trí 4 show số 8 on display
}
