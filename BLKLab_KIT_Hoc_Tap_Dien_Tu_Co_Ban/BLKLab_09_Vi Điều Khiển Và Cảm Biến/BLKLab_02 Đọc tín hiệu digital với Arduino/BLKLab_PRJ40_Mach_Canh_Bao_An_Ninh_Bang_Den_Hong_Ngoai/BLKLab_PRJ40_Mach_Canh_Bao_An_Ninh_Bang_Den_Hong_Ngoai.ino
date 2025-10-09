int buzzer = 8,                          //Khai báo chân điều khiển còi 
    led = 9,                             //khai báo chân điều khiển đèn báo
    sensor = 10;                         //Khai báo chân nhận tín hiệu cảm biến
void setup(){
  pinMode(led,OUTPUT);                   //Cài đặt chức năng cho các chân điều khiển đã khai báo
  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
  digitalWrite(led,0);                   //Tắt đèn khi bắt đầu chương trình
  digitalWrite(buzzer,0);                //Tắt còi khi bắt đầu chương trình
}
void loop(){
  int stage = digitalRead(sensor);       //Đọc trạng thái cảm biến
  if(stage==1){                          //Khi phát hiện vật thể xâm nhập cản tín hiệu từ LED phát truyền tới -> cảnh báo
   for(int i = 0; i<30; i++){
    digitalWrite(led,1);
    digitalWrite(buzzer,1);
    delay(50);
    digitalWrite(led,0);
    digitalWrite(buzzer,0);
    delay(50);
   }
  }
  else{
    digitalWrite(led,0);                 //Nếu không phát hiện tín hiệu bị ngắt, tắt đèn
    digitalWrite(buzzer,0);
  }
}