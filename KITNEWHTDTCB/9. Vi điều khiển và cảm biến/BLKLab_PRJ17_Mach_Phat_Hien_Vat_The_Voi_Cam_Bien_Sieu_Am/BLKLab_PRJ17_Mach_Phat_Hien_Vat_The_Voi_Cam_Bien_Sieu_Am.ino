int trig=10,                                           //Khai báo các chân phát và nhận tín hiệu cho cảm biến
    echo=9,
    led=8,                                            //Khai báo chân điều khiển LED
    openTime=2000;                                    //Biến thời gian đèn giữ trạng thái bật sau khi vật thể đi qua
void setup() {
  pinMode(trig,OUTPUT);                               //Cài đặt chức năng cho các chân đã khai báo
  pinMode(echo,INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  digitalWrite(trig,0);                             //Tắt chân phát tín hiệu khi bắt đầu chương trình
  delayMicroseconds(2);                             //Nghỉ 2 micro giây
  digitalWrite(trig,1);                             //Bật chân phát tín hiệu siêu âm trong 10 micro giây
  delayMicroseconds(10);
  digitalWrite(trig,0);                             //Ngắt tín hiệu phát
  long time = pulseIn(echo, HIGH);                  //Đọc thời gian chân echo nhận được tín hiệu từ chân trig dội về
  float kc=((time*0.0343)/2);                       //Dùng công thức vận tốc âm thanh tính ra khoảng cách từ cảm biến đến vật cản
  if(kc<40){                                        //Nếu phát hiện vật thể trong vòng 40cm đổ lại thì bật đèn
    digitalWrite(led,1);                            
    delay(openTime);                                //Duy trì trong 2 giây nếu vật thể đã đi qua
  }
  else{
    digitalWrite(led,0);                            //Không phát hiện vật thể thì tắt LED
  }
  delay(200);                                       //Nghỉ 0.2 giây sau đó đo tiếp lần tiếp theo
}
