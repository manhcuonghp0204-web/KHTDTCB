int signal = 10,                                //Khai báo chân nhận tín hiệu từ đèn hồng ngoại
    motor = 9,                                  //Khai báo chân điều khiển motor 
    lastSignalStage = 1,                        //Biến lưu trạng thái nhận từ đầu vào
    flag = 1,                                   //Cờ chống nhấn giữ
    count = 0;                                  //Biến đếm số lần nhận tín hiệu
unsigned long lastDebonceTime;

void setup() {
  pinMode(motor,OUTPUT);                        //Cài đặt chức năng cho các chân vừa khai báo
  pinMode(signal, INPUT_PULLUP);                
}
void loop() {
  if(digitalRead(signal)!=lastSignalStage){     //Phát hiện tín hiệu từ led hồng ngoại
    lastDebonceTime=millis();                   //Ghim mốc thời gian lần cuối thay đổi trạng thái tín hiệu
    lastSignalStage=digitalRead(signal);        //Ghi nhận trạng thái tín hiệu cuối cùng nhận được
  }
  if((millis()-lastDebonceTime)>=30){           //Sau 30ms kể từ lần cuối tín hiệu bị thay đổi , bắt đầu kiểm tra
    if(digitalRead(signal)!=flag){              //Nếu trạng thái tín hiệu khác với cờ thì đảo trạng thái cờ
      flag=digitalRead(signal);                 //Ghim lại trạng thái cờ trùng với trạng thái của nút nhấn để biến đếm không bị tăng nhiều lần khi tín hiệu phát giữ lâu
      if(flag==1){                              
        count++;                                //Tăng biến đếm 1 đơn vị với mỗi lần nhận tín hiệu
        count=count%4;                          //Chia 4 lấy dư để chỉ ghi nhận 4 trạng thái của động cơ DC
      } 
    }
  }
  if(count==0){                                //Trạng thái 1
    digitalWrite(motor,0);                     //Tắt động cơ
  }
  if(count==1){                                //Trạng thái 2
    analogWrite(motor,30);                     //Động cơ quay chậm
  }
  if(count==2){                                //Trạng thái 3
    analogWrite(motor,125);                    //Động cơ quay tốc độ vừa phải
  }
  if(count==3){                                //Trạng thái 4
    analogWrite(motor,255);                    //Động cơ quay nhanh
  }
  
}