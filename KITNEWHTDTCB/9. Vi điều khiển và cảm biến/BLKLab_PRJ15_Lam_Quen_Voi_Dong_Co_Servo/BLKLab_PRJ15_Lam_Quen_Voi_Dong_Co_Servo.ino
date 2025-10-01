#include <Servo.h>      //  Khai báo thư viện điều khiển servo
Servo myServo;          // Tạo đối tượng servo

void setup() {
  myServo.attach(9);   // Gắn servo vào chân số 9
  myServo.write(0);    // Quay servo đến góc 90 độ
}

void loop() {
  myServo.write(90);  // Quay servo đến góc 90 độ
  delay(500);         // Nghỉ 0.5 giây
  myServo.write(180); // Quay servo đến góc 90 độ
  delay(500);         // Nghỉ 0.5 giây
  myServo.write(90);  // Quay servo đến góc 90 độ
  delay(500);         // Nghỉ 0.5 giây
  myServo.write(0);   // Quay servo đến góc 90 độ
  delay(500);         // Nghỉ 0.5 giây
}