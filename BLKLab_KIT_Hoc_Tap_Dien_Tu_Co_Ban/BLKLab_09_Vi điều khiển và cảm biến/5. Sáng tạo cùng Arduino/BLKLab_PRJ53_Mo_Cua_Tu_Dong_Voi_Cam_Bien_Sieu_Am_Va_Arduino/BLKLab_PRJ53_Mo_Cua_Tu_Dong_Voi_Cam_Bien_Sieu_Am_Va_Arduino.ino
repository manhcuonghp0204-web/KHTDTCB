#include <Servo.h>         //Thư viện điều khiển servo
Servo myServo;             //Khởi tạo servo
int out = 11,              //Khai báo chân nhận tín hiệu đầu ra cho servo
    openTime=1500;         //Thời gian mở cửa sau khi ngưng phát hiện vật thể
int greenLed=6;            //Chân điều khiển đèn xanh(khi cửa mở)
int redLed=7;              //Chân điều khiển đèn đỏ (khi cửa đóng)
int trig=10,echo=9;        //Khai báo chân phát và thu tín hiệu của cảm biến
void setup() {
  myServo.attach(out);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(redLed,OUTPUT);
  }

void loop() {
  digitalWrite(trig,0);                             //Tắt chân phát tín hiệu khi bắt đầu chương trình
  delayMicroseconds(2);                             //Nghỉ 2 micro giây
  digitalWrite(trig,1);                             //Bật chân phát tín hiệu siêu âm trong 10 micro giây
  delayMicroseconds(10);
  digitalWrite(trig,0);                             //Ngắt tín hiệu phát
  long time = pulseIn(echo, HIGH);                  //Đọc thời gian chân echo nhận được tín hiệu từ chân trig dội về
  float kc=((time*0.0343)/2);                       //Dùng công thức vận tốc âm thanh tính ra khoảng cách từ cảm biến đến vật cản                                      
  if(kc<=15){
    myServo.write(90);                              //Nếu có người đến gần (<15cm) ->mở cửa bằng servo, bật đèn xanh
    digitalWrite(greenLed,1);
    digitalWrite(redLed,0);
    delay(openTime);                                //Thời gian cửa mở sau khi đã đi qua
  }
  else{
    digitalWrite(greenLed,0);                       //Nếu không phát hiện gì, bật đèn đỏ, nghỉ 0.2 giây sau mỗi lần quét
    digitalWrite(redLed,1);
    myServo.write(0);
    delay(200);
  }
}
