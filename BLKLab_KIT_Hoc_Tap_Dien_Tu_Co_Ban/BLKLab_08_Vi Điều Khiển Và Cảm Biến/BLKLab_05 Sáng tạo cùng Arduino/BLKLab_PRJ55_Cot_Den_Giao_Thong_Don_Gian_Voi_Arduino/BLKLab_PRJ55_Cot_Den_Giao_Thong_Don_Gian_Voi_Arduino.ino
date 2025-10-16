int led[8] = {3, 4, 5, 6, 7, 8, 9, 10};                   //Khai báo mảng chứa các chân điều khiển LED 7 thanh
int delayTime = 1000;                                     //Thời gian đếm 1 giây//
int count =9,                                             //Biến đếm thời gian
    mode=0;                                               //Biến đếm chế độ
int greenLed  = 11,                                       //Khai báo chân điều khiển các đèn xanh vàng đỏ
    yellowLed = 12,
    redLed    = 13; 
unsigned long lastTime=0;                                 //Biến ghim mốc thời gian
const byte number[] = {                               
  0b11000000, 0b11111001, 0b10100100, 0b10110000,         //Mảng chứa mã nhị phân điều khiển LED 7 thanh hiển thị các số từ 0-9 dành cho loại anode chung
  0b10011001, 0b10010010, 0b10000010, 0b11111000,
  0b10000000, 0b10010000};
void setup() {
  for (int i = 0; i < 8; i++) {                           //Cài đặt chức năng cho các chân vừa khai báo ở trên
    pinMode(led[i], OUTPUT);
  }
  pinMode(greenLed,OUTPUT);
  pinMode(yellowLed,OUTPUT);
  pinMode(redLed,OUTPUT);
}
void loop(){
  if((millis()-lastTime)>=delayTime){                     //Đếm thời gian và ghim lại mốc thời gian
    lastTime=millis();
    count--;                                              //Khi đếm đủ giảm biến đếm
    if (count<0){
      if(mode==1){                                        //Nếu ở chế độ đèn vàng (mode 2) chỉ đếm ngược 2 giây
        count=2;}
      else{                                               //Nếu ở chế độ đèn đỏ và xanh (mode 0 & 2) đếm ngược 9 giây
        count=9;
      }
      mode++;                                             //Đổi chế độ khi biến đếm về 0
      mode=mode%3;                                        //Giới hạn chỉ 3 chế độ
    }

  }
  for(int i=0;i<8;i++){
    digitalWrite(led[i],(number[count]>>i) & 0b1);        //Hiển thị các đèn của LED 7 thanh cho các con số ứng với biến đếm
  }
  if(mode==0){                                            //Mode 0 (đèn đỏ), bật đèn đỏ, tắt 2 đèn còn lại
    digitalWrite(redLed,1);
    digitalWrite(greenLed,0);
    digitalWrite(yellowLed,0);
  }
  if(mode==1){                                            //Mode 1 (đèn xanh), bật đèn xanh, tắt 2 đèn còn lại                                       
    digitalWrite(redLed,0);
    digitalWrite(greenLed,1);
    digitalWrite(yellowLed,0);
  }
  if(mode==2){                                            //Mode 2 (đèn vàng), bật đèn vàng, tắt 2 đèn còn lại
    digitalWrite(redLed,0);
    digitalWrite(greenLed,0);
    digitalWrite(yellowLed,1);
  }
}