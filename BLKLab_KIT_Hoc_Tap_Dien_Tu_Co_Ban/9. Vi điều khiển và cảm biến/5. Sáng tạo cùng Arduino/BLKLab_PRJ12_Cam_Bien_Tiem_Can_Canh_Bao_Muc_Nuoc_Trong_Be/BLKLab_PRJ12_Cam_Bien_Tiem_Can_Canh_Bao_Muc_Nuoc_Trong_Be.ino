int trig=10,                                        //Khai báo chân phát và thu tín hiệu của cảm biến
    echo=9;
int buzzer=11,                                     //Khai báo chân điều khiển còi
    level=0;                                       //Biến lưu mức cảnh báo
int led[]={8,7,6,5,4,3,2};                         //Mảng khai báo các chân điều khiển dãy đèn cảnh báo
void setup() {
  pinMode(trig,OUTPUT);                            //Cài đặt chức năng cho các chân đã khai báo
  pinMode(echo,INPUT);
  pinMode(buzzer,OUTPUT);
  for(int i=0;i<7;i++){
    pinMode(led[i],OUTPUT);
  }
  Serial.begin(9600);                               //Khởi tạo giao tiếp giữa Arduino và máy tính
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
  if(kc<5){                   //Khoảng cách từ mặt nước đến cảm biến <5cm -> nước quá đầy -> Mức cảnh báo cao nhất (lv7)                     
    level=7;                                          
  }
  else if(kc>=5 && kc<10){    //lv6
    level=6;
  }
  else if(kc>=10 && kc<15){   //lv5
    level=5;
  }
  else if(kc>=15 && kc<20){   //lv4
    level=4;
  }
  else if(kc>=20 && kc<25){   //lv3
    level=3;
  }
  else if(kc>=25 && kc<30){   //lv2
    level=2;
  }
  else if(kc>=30){            //lv1
    level=1;
  }
    for(int k=level;k<7;k++){ //Tắt các LED không dùng
    digitalWrite(led[k],0);
  }
   for(int i=0;i<level;i++){  //Bật số LED tương ứng với số level
    digitalWrite(led[i],1);
  }
  if(level==7){
    digitalWrite(buzzer,1);   //Bật còi khi mức cảnh báo chạm lv7
    delay(50);
    digitalWrite(buzzer,0);
    delay(50);
    digitalWrite(buzzer,1);
    delay(50);
  }
}
