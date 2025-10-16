int buzzer=9;                             // Khai báo chân điều khiển còi                    
int DO = 820;                             // Khai báo biến và gán giá trị tần số cho các 6 nốt nhạc từ DO - LA
int RE = 880;
int MI = 956;
int FA = 1014;
int SOL = 1136;
int LA = 1275;
int melody[] = {                            //Mảng chứa giai điệu bài hát           
  DO, DO, SOL, SOL, LA, LA, SOL,
  FA, FA, MI, MI, RE, RE, DO,
  SOL, SOL, FA,
  MI, MI, RE,
  SOL, SOL, FA,
  MI, MI, RE
};  
int noteDurations[] = {                     //Mảng chứa thời gian nghỉ giữa các nốt nhạc
  500, 500, 500, 500, 500, 500, 800,
  500, 500, 500, 500, 500, 500, 800,
  500, 500, 800,
  500, 500, 800,
  500, 500, 800,
  500, 500, 500};


void setup() {
 pinMode(buzzer,OUTPUT);                     //Cài đặt chức năng output cho chân điều khiển còi
}
void loop() {
  delay(1000);                               //Nghỉ 1 giây trước khi bắt đầu bài nhạc và trước khi lặp lại bài nhạc lần tiếp theo
  for(int i=0;i<26;i++){                    
    tone(buzzer,melody[i],noteDurations[i]); //Dùng vòng "for" để chạy các nốt nhạc 
    delay(noteDurations[i]*1.2);             //Dùng vòng "for"để chạy quãng nghỉ sau khi phát nốt nhạc
  }
}
