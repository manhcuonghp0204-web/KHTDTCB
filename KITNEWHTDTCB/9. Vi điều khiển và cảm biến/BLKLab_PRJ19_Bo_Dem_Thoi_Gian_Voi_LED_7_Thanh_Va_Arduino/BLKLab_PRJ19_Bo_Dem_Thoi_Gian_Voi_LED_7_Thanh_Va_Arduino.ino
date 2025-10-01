int led[8] = {3, 4, 5, 6, 7, 8, 9, 10};             //Khai báo mảng chứa các chân điều khiển LED 7 thanh anode chung
int delayTime = 1000;                               //Biến chứa thời gian đếm ngược
int count = 0;                                      //Biến đếm số
unsigned long lastTime=0;                           //Biến ghim mốc thời gian
const byte number[] = {                             //Mảng chứa đoạn mã nhị phân để hiển thị các số từ 0-9 
  0b11000000, 0b11111001, 0b10100100, 0b10110000,
  0b10011001, 0b10010010, 0b10000010, 0b11111000,
  0b10000000, 0b10010000};
void setup() {                                       
  for (int i = 0; i < 8; i++) { 
    pinMode(led[i], OUTPUT);                         //Dùng vòng "for" cài đặt chức năng cho các chân đã khai báo
  }
}
void loop(){
  if((millis()-lastTime)>=delayTime){                //Sau thời gian đã set , tăng biến đếm       
    lastTime=millis();
    count++;
    count = count % 10;                               //Giữ phạm vi biến k chạy quá 9
  }
  for(int i=0;i<8;i++){ 
    digitalWrite(led[i],(number[count]>>i) & 0b1);    //Dùng vòng for hiển thị hàng loạt các đèn cho các con số ứng với biến đếm "count"
  }
}