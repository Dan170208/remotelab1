/*-----------------------------------code điều khiển động cơ bước---------------------------------------*/
/*
 * Điện áp cung cấp: 5VDC.
   Số phase: 4.
   Bước: 5.6250/64.
 */
#define step_motor_in_1 46          // Khai báo chân tín hiệu của step motor
#define step_motor_in_2 47          // Khai báo chân tín hiệu của step motor
#define step_motor_in_3 48          // Khai báo chân tín hiệu của step motor
#define step_motor_in_4 49          // Khai báo chân tín hiệu của step motor

int step_number = 0;                // Khai báo biến step_number dùng kiểu dữ liệu int

void setup()                        // code ghi trong đây sẽ chỉ chạy 1 lần, đây là điểm bắt đầu của code
{
  pinMode(step_motor_in_1, OUTPUT); // Khởi tạo giá trị tại chân tín hiệu 1 của step motor 
  pinMode(step_motor_in_2, OUTPUT); // Khởi tạo giá trị tại chân tín hiệu 1 của step motor  
  pinMode(step_motor_in_3, OUTPUT); // Khởi tạo giá trị tại chân tín hiệu 1 của step motor
  pinMode(step_motor_in_4, OUTPUT); // Khởi tạo giá trị tại chân tín hiệu 1 của step motor
}

void loop()                         // đặt code trong đây sẽ lặp lại vô hạn lần 
{
  
}

void stepmotor(bool dir)           // viết hàm con stepmotor
{
  if(dir)                          // điều kiện dir      
  {
    switch(step_number)             
    {
      case 0:
        digitalWrite(step_motor_in_1, HIGH);              /*---------Switch case-------*/
        digitalWrite(step_motor_in_2, LOW);               /*Mã sử dụng cấu trúc switch-case*/    
        digitalWrite(step_motor_in_3, LOW);               /*để điều khiển các trạng thái*/
        digitalWrite(step_motor_in_4, LOW);               /*khác nhau của động cơ bước.*/
        break;
      case 1:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, HIGH);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 2:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, HIGH);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 3:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, HIGH);
        break;
    } 
  }
  else
  {
    switch(step_number)
    {
      case 0:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, HIGH);
        break;
      case 1:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, HIGH);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 2:
        digitalWrite(step_motor_in_1, LOW);
        digitalWrite(step_motor_in_2, HIGH);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
      case 3:
        digitalWrite(step_motor_in_1, HIGH);
        digitalWrite(step_motor_in_2, LOW);
        digitalWrite(step_motor_in_3, LOW);
        digitalWrite(step_motor_in_4, LOW);
        break;
    } 
  }
  step_number++;
  if(step_number > 3)
  {
    step_number = 0;
  }
}
