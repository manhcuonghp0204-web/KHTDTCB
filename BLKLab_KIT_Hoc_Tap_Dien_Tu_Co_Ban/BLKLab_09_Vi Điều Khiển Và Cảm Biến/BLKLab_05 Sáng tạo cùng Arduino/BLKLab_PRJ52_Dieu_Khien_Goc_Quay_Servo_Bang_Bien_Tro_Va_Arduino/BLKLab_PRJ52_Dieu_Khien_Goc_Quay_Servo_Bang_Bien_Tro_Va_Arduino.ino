#include <Servo.h>            //Thư viện điều khiển servo
Servo servo;                  //Khởi tạo servo
int pin=6,                    //Khai báo chân nhận tín hiệu
    in=A0;                    //Khai báo điều khiển servo
double angle = 0;             //Biến nhận giá trị góc quay
void setup() {
 servo.attach(pin);           //Gán chân điều khiển servo là chân pin
 pinMode(in,INPUT);           //Cài chức năng cho chân đầu vào
}

void loop() {
  int value = analogRead(in); //Đọc giá trị nhận về từ cổng đầu vào
  angle=(value*180)/1023;     //Tính toán góc quay tham chiếu theo góc quay của biến trở
  servo.write(sangle);        //Cho servo quay theo góc đã tính toán
}
