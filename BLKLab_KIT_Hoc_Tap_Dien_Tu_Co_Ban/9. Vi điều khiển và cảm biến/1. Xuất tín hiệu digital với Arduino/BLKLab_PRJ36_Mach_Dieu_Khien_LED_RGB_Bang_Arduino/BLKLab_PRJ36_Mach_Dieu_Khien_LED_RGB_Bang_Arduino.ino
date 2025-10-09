int blue=7,                     //Khai báo các chân LED RGB 
    green = 8, 
    red = 9, 
    delayTime = 300;            //Thời gian phát sáng
void setup(){
  pinMode(red,OUTPUT);          //Đặt chức năng đầu ra cho các chân điều khiển LED RGB
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  digitalWrite(red,0);          //Tắt bóng đỏ và bóng xanh lục , bật bóng xanh dương
  digitalWrite(blue,1);
  digitalWrite(green,0);
  delay(delayTime);             //Thời gian sáng
  digitalWrite(red,0);          //Chuyển sang bóng xanh lục sáng, 2 bóng còn lại tắt
  digitalWrite(blue,0);
  digitalWrite(green,1);
  delay(delayTime);
  digitalWrite(red,1);          //Chuyển sang bóng đỏ sáng, 2 bóng còn lại tắt
  digitalWrite(blue,0);
  digitalWrite(green,0);
  delay(delayTime);

}
