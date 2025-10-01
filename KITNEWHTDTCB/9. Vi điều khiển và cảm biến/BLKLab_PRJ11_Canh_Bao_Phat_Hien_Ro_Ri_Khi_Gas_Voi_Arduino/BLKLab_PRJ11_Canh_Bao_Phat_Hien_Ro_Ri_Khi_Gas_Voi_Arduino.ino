int buzzer = 8,                          //Khai báo chân điều khiển còi 
    led = 9,                             //khai báo chân điều khiển đèn báo
    sensor = 10,                         //Khai báo chân nhận tín hiệu cảm biến
void setup(){
  pinMode(led,OUTPUT);                   //Cài đặt chức năng cho các chân điều khiển đã khai báo
  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
  digitalWrite(led,0);                   //Tắt đèn khi bắt đầu chương trình
  digitalWrite(buzzer,0);                //Tắt còi khi bắt đầu chương trình
}
void loop(){
  int stage = digitalRead(sensor);       //Đọc trạng thái cảm biến
  if(stage==0){                          //Khi phát hiện khí gas cảm biến xuất ra tín hiệu 0
    digitalWrite(led,1);                 //Bật đèn LED báo
    delay(50);                           //Bật tắt đèn liên tục với chu kì 50ms để báo hiệu
    digitalWrite(led,0);
    delay(50);
    digitalWrite(buzzer,1);              //Bật còi báo
  }
  else{
    digitalWrite(led,0);                 //Nếu không có tín hiệu phát hiện khí gas, tắt còi và LED
    digitalWrite(buzzer,0);
  }
}