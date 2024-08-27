/*--------------------------code  đọc giá trị cảm biến nhiệt độ và độ ẩm----------------------------*/
/*
 * Đây là code hướng dẫn lập trình để cảm biến đọc giá trị nhiệt độ và độ ẩm môi trường xung quanh
 */
/*
/*------------------- thông số kỹ thuật của cảm biến nhiệt độ và độ ẩm------------------------------*/
/*
 *  Nguồn: 3 -> 5 VDC.
 *  Dòng sử dụng: 2.5mA max (khi truyền dữ liệu). 
 *  Khoảng đo độ ẩm: 20%-90% RH (sai số 5%RH) 
 *  Khoảng đo nhiệt độ: 0-50°C (sai số 2°C) 
 *  Tần số lấy mẫu tối đa: 1Hz (1 giây / lần) 
 *  Kích thước 15mm x 12mm x 5.5mm.
 * 
 */


#include "DHT.h"                            //Khai báo thư viện cho cảm biết DHT11    

#define DHTPIN 11                           //Khai báo chân tín hiệu cảm biến 
#define DHTTYPE11 DHT11                     //Khai báo loại cảm biến /* cảm biến trên kit là DHT11 */

DHT dht(DHTPIN, DHTTYPE11);                 //Khởi tạo một đối tượng của thư viện DHT

void setup()                                //Code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
 
{
  dht.begin();                              //Khởi tạo từ thư viện dht
  Serial.begin(230400);                     //Mở cổng Serial, tốc độ truyền dữ liệu (9600,115200,230400,....)  

}

void loop()                                 //Đặt code trong đây sẽ lặp lại vô hạn lần 
{
  
}

void READ_DHT()                             //Đặt tên hàm con READ_DHT(Đọc dữ liệu từ cảm biến DHT)
{
  int humidity = dht.readHumidity();        //Đặt tên biến humidity để đọc giá trị độ ẩm môi trường từ thư viện DHT
  int temperature = dht.readTemperature();  //Đặt tên biến tempature để đọc giá trị nhiệt độ môi trường từ thư viện DHT   
  if(isnan(humidity) || isnan(temperature)) //Câu lệnh điều kiện if để kiểm tra lỗi coi độ ẩm "humidity", nhiệt độ "tempature" 
  {                                         //Có phải là NaN "Not a Number" không
    Serial.println("Failed to read from DHT sensor!");  //Nếu không phải là số thì sẽ in ra màn hình Serial là "Failed to read from DHT sensor" Thất bại đọc dữ liệu từ cảm biến DHT 
    return;                                 //Trả về để thực hiện code bên dưới
  }
  
  Serial.print("Humidity: ");               //In ra màn hình chữ "Humidity:"        
  Serial.print(humidity);                   //In ra màn hình độ ẩm  
  Serial.print(" %\t");                     //In ra màn hình dấu "%"
  Serial.print("Temperature: ");            //In ra màn hình chữ "Tempature:"
  Serial.print(temperature);                //In ra màn hình nhiệt độ
  Serial.print(" *C ");                     //In ra màn hình dấu "*C" 
  Serial.println();                         //In ra màn hình 1 ký tự để xuống dòng
}
