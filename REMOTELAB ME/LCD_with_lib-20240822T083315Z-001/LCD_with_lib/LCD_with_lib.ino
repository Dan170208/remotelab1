
#include <Wire.h>                                       // Khai báo thư viện I2C
#include <LiquidCrystal_I2C.h>                          // Khai bao thư viện LCD

LiquidCrystal_I2C lcd(0x27,20,4);                       // Khai báo địa chỉ, kích thước màn hình LCD

int x;                                                  // Khai ba1o biến x xài kiểu dữ lệu int

void setup()                                            // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  lcd.init();                                           // Gọi lệnh từ thư viện màn hinh LCD
  lcd.backlight();                                      // Bật đèn nền của LCD
  lcd.begin(20, 4);                                     // Khởi tạo màn hinh LCD
  lcd.setCursor(0,1);lcd.print("Lac Hong University");  // Đặt vị trí con nháy ở vị trí số 0, hàng 1 và in ra "Lac Hong University"
  lcd.setCursor(6,2);lcd.print("RemoteLab");            // Đặt vị trí con nháy ở vị trí số 6, hàng 2 và in ra "RemoteLab"
}

void loop()                                             // đặt code trong đây sẽ lặp lại vô hạn lần
{
  lcd.setCursor(0,3);                                   // Đặt vị trí con nháy ở vị trí số 0, hàng 1    
  lcd.print(String(x) + " ");                           // in ra màn hình LCD 1 chuỗi biến x
}
