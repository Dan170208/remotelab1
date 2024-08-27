/*-----------------------------------code điều khiển động cơ DC---------------------------------------*/
/*
 * Đây là code hướng dẫn quay động cơ DC quay thuận, nghịch, và dừng động cơ đang quay. 
 * Khi có tín hiệu xuất xung tới chân ENA, IN1, IN2 của module mạch khuếch đại L298N sẽ làm cho động cơ quay. 
 */
/*------------------* Thông số kỹ thuật của động cơ và mạch khuếch đại cầu H L298N---------------------*/
/*
 * 
 * Động cơ DC 12V
 * Hộp số giảm tốc 128:1
 * Encoder HEDL 5540 https://www.alldatasheet.com/datasheet-pdf/pdf/105536/ETC/HEDL5540A.html
 * Số xung trên vòng: 500 ppr
 * 
 *
*/

#define l2985v 42  // Khai báo chân 5V
#define l298ena 8  // Khai báo chân ENA
#define l298in1 44 // Khai báo chân IN1 
#define l298in2 45 // Khai báo chân IN2

long pulse = 0;            // Khai báo kiểu dữ liệu long cho biến pulse
int speed_motor = 255;     // Khai báo kiểu dữ liệu int cho biến speed_motor

void setup() // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  pinMode(l2985v, OUTPUT); 
  pinMode(l298ena, OUTPUT); 
  pinMode(l298in1, OUTPUT); 
  pinMode(l298in2, OUTPUT); 

  Serial.begin(230400);   // Mở cổng Serial, tốc độ truyền dữ liệu (9600,115200,230400,....)  
}

void loop()               // đặt code trong đây sẽ lặp lại vô hạn lần 
{
  
}

void forward()            // đặt tên hàm con forward(đi thuận, đây là code làm motor quay thuận)
{
  digitalWrite(l298in1, HIGH);
  digitalWrite(l298in2, LOW);
  analogWrite(l298ena, speed_motor);
  digitalWrite(l2985v, HIGH);
}
void reverse()            // đặt tên hàm con reverse(đi nghịch, đây là code làm motor quay nghịch)
{
  digitalWrite(l298in1, LOW);
  digitalWrite(l298in2, HIGH);
  analogWrite(l298ena, speed_motor);
  digitalWrite(l2985v, HIGH);
}
void stop_motor()         // đặt tên hàm con stop_motor (dừng, đây là code làm motor dừng quay)   
{
  digitalWrite(l298in1, LOW);
  digitalWrite(l298in2, LOW);
  analogWrite(l298ena, 0);
  digitalWrite(l2985v, LOW);
}
