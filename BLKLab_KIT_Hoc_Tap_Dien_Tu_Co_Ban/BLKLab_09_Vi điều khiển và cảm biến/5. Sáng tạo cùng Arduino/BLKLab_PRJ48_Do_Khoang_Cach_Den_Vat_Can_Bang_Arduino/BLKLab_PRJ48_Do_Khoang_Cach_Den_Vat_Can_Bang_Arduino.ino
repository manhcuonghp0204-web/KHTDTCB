int trig = 10,                                      //Khai các báo chân phát và nhận tín hiệu từ cảm biến
    echo = 9;                                        
void setup() {
  pinMode(trig,OUTPUT);                             //Cài đặt chức năng cho các chân đã khai báo
  pinMode(echo,INPUT);
  Serial.begin(9600);                               //Khởi tạo giao tiếp giữa vi điều khiển và máy tính
}

void loop() {
  digitalWrite(trig,0);                             //Tắt chân phát tín hiệu khi bắt đầu chương trình
  delayMicroseconds(2);                             //Nghỉ 2 micro giây
  digitalWrite(trig,1);                             //Bật chân phát tín hiệu siêu âm trong 10 micro giây
  delayMicroseconds(10);
  digitalWrite(trig,0);                             //Ngắt tín hiệu phát
  long time = pulseIn(echo, HIGH);                  //Đọc thời gian chân echo nhận được tín hiệu từ chân trig dội về
  float kc=((time*0.0343)/2);                       //Dùng công thức vận tốc âm thanh tính ra khoảng cách từ cảm biến đến vật cản
  Serial.print("khoang cach den vat can la: ");     //In ra khoảng cách tính toán được
  Serial.print(kc);
  Serial.println("cm");
  delay(200);                                       //Nghỉ 0.2 giây trước khi đo lần tiếp theo
}
