int gate=9,                    //Khai báo chân điều khiển cho động cơ DC
void setup() {
  pinMode(gate,OUTPUT);        //Cài đặt chức năng cho các chân đã khai báo
}

void loop() {
  analogWrite(gate,255);       //Ánh xạ giải 0-255 theo mức điện áp từ 0-VCC để điều khiển tốc độ quay động cơ
  delay(2000);                  //Cho quay trong 2 giây
  analogWrite(gate,0);
  delay(2000);
}
