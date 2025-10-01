int in = A0;                  //Khai báo chân nhận tín hiệu                                          
int checkTem = 25 ;           //Nhiệt độ điều kiện phòng tiêu chuẩn
int checkRegister = 10000;    //Mốc điện trở tại điều kiện phòng tiêu chuẩn
int outRegister
void setup() {
  pinMode(in,INPUT);          //Cài đặt chức năng cho chân đầu vào
  Serial.begin(9600);         //Khởi tạo giao tiếp giữa vi điều khiển và máy tính
}

void loop() {
  int value = analogRead(in);                                             //Đọc giá trị từ điện trở nhiệt gửi về qua vi điều khiển
  float thermistor = (value/512.0)*10000;                                 //Tính giá trị điện trở của điện trở nhiệt 
  float temperature = (1/(0.000253*log(thermistor)+0.0010229))-273.15;    //
  Serial.print("nhiet do la: ");
  Serial.print(temperature);
  Serial.println("°C");
  delay(200);
}
