int blue=7,                          //Khai báo các chân điều khiển LED RGB
    green = 8, 
    red = 9, 
    sensor = 10,                     //Khai báo chân nhận tín hiệu cảm biến
    mode = 0,                        //Khai báo biến đếm ghim thứ tự chế độ
    count = 0;                       //Khai báo biến đếm số lần nhận tín hiệu vỗ tay
unsigned long lastTime = 0;
void setup(){
  pinMode(red,OUTPUT);               //Cài đặt chức năng cho các chân đã khai báo
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(sensor,INPUT);
}
void loop(){
  if(digitalRead(sensor)==0){        //Nếu có tiếng vỗ tay, cảm biến xuất ra tín hiệu 0
    delay(100);                      //Dừng 0.1 giây để tránh âm thanh dội
    count++;                         //Tăng biến đếm số lần vỗ tay
    if(count==1){
      lastTime = millis();           //Sau 1 lần vỗ ghim lại thời gian tại lúc đó
    }
    if(count==2){                    //Sau lần vỗ thứ 2 reset biến count về 0
      count=0;
      if((millis()-lastTime)<=1500){ //Nếu 2 lần vỗ cách nhau dưới 1.5 giây thì tăng biến mode để đổi sang chế độ tiếp theo
        mode++;
        mode=mode%4;                 //Giới hạn 4 chế độ
      }
    }
  }
  
  if(mode==0){
    digitalWrite(red,0);             //Chế độ 1, tắt tất cả đèn
    digitalWrite(blue,0);
    digitalWrite(green,0);
  }
  if(mode==1){
    digitalWrite(red,0);             //Chế độ 2, bật đèn xanh dương và tắt các đèn còn lại
    digitalWrite(blue,1);
    digitalWrite(green,0);
  }
  if(mode==2){
    digitalWrite(red,0);             //Chế độ 3, bật đèn xanh lục và tắt các đèn còn lại
    digitalWrite(blue,0);
    digitalWrite(green,1);
  }
  if(mode==3){
    digitalWrite(red,1);             //Chế độ 4, bật đèn đỏ và tắt các đèn còn lại
    digitalWrite(blue,0);
    digitalWrite(green,0);
  }
}