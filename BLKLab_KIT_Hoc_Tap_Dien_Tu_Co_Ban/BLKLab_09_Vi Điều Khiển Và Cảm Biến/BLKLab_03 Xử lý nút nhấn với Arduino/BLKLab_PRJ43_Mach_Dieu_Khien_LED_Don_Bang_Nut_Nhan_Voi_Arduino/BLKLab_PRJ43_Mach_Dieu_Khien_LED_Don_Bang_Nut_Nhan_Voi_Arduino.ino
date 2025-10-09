int button=8,                               //Khai báo chân điều khiển nút nhấn
    led=9,                                  //Khai báo chân điều khiển LED
    lastButtonStage=1,                      //Biến ghim trạng thái nút nhấn
    flag=1,                                 //Cờ chống nhấn giữ
    count=0;                                //Biến đếm ghim trạng thái đèn
unsigned long lastDebonceTime;              //Biến ghim thời điểm nút ấn dội lần cuối
void setup() {
  pinMode(led,OUTPUT);                      //Cài đặt chức năng cho các chân vừa khai báo
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button)!=lastButtonStage){ //Phát hiện nút nhấn được ấn
    lastDebonceTime=millis();               //Ghim lại thời điểm nút nhấn đóng
    lastButtonStage=digitalRead(button);    //GHim lại trạng thái nút nhấn khi đó
  }
  if((millis()-lastDebonceTime)>=30){       //Sau 30ms kể từ lần dội cuối cùng kiểm tra 
    if(digitalRead(button)!=flag){          
      flag=digitalRead(button);             //Thay đổi trạng thái cờ theo trạng thái nút nhấn để biến count chỉ tăng 1 lần
      if(flag==1){                          //Nếu nút nhấn đã được nhả ra mới tăng biến count
        count++;
        count=count%2;                      //Chia biến count lấy dư để giới hạn 2 chức năng bật/tắt
      } 
    }
    Serial.println(count);
  }
  if(count==0){                             //Nếu biến count = 0, tắt LED
    digitalWrite(led,0);
  }
  if(count==1){                             //Nếu biến count = 1, bật LED
    digitalWrite(led,1);
  }
}
