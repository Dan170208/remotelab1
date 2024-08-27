/*-----------------------------------code cảm biến dòng điện---------------------------------------*/
/*
 * Đây là code hướng dẫn lập trình lấy giá trị của dòng điện đo được từ cảm biến dòng điện
 */
/*-------------------------------- Thông số kỹ thuật của Wattmeter --------------------------------*/



#include "DFRobot_INA219.h"                            //Khai báo thư viện dùng cho cảm biến dòng điện      
#include <Wire.h>                                      //Khai báo thư viện Wire dùng trong giao tiếp I2C


DFRobot_INA219_IIC ina219(&Wire, INA219_I2C_ADDRESS4); //Tạo một đối tượng ina219 thuộc lớp DFRobot_INA219, sử dụng giao tiếp I2C và địa chỉ I2C là INA219_I2C_ADDRESS4.
float ina219Reading_mA = 1000;                         //Khai báo kiểu dữ kiểu dữ liệu float cho biến ina219Reading_mA
float extMeterReading_mA = 1000;                       //Khai báo kiểu dữ kiểu dữ liệu float cho biến extMeterReading_mA = 1000     

float voltage;                                         //Khai báo kiểu dữ kiểu dữ liệu float cho biến voltage
float current;                                         //Khai báo kiểu dữ kiểu dữ liệu float cho biến current
float power;                                           //Khai báo kiểu dữ kiểu dữ liệu float cho biến power

void setup()                                           //code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code 
{
  Serial.begin(230400);                                //Mở cổng Serial, tốc độ truyền dữ liệu
  while(ina219.begin() != true)                        //Điều kiện khi khởi tạo đối tượng không phải ina219 
  {
    Serial.println("INA219 begin failed");              //Thì sẽ in ra màn hình dòng chữ "INA219 begin failed"   
    delay(2000);                                        //Delay 2000ms = 2 sec = 2 giây
  }
  ina219.linearCalibrate(ina219Reading_mA, extMeterReading_mA); //Dòng này thực hiện hiệu chỉnh tuyến tính cho cảm biến.
  Wire.begin();                                         //Khởi tạo giao tiếp I2C
  Wire.beginTransmission(0x45);                         //địa chỉ của cảm biến dòng điện
  Wire.write(8);                                        
  Wire.endTransmission();                               //Kết thúc truyền tín hiệu
}

void loop()                                             // đặt code trong đây sẽ lặp lại vô hạn lần 

{
  
}

void read_data_wattmeter()                              //Viết hàm con read_data_wattemeter
{
  voltage = ina219.getBusVoltage_V();                   //Biến Voltage sẽ có giá trị khi đọc tín hiệu lấy volt từ cảm biến
  current = ina219.getCurrent_mA();                     //Biến current sẽ có giá trị khi đọc tín hiệu lấy current từ cảm biến  
  power = ina219.getPower_mW();                         //Biến lưu trữ giá trị công suất,
                                                        //ina219.getPower_mW: Phương thức để tính toán và trả về 
}                                                        //công suất tiêu thụ, kết quả tính bằng 
                                                        //miliwatt (mW). 
