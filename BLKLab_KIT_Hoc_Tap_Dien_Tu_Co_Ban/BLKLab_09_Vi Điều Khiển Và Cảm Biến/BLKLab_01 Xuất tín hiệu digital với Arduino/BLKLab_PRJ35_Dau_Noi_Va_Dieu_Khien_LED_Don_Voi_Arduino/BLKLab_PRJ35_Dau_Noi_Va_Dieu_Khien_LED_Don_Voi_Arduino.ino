int Led = 12;          //Khai báo chân điều khiển LED

void setup() {
  pinMode(Led, OUTPUT);//Khai báo chức năng của chân điều khiển LED
}

void loop() {
  digitalWrite(Led, HIGH); // Bật LED
  delay(500);           // Chờ 500ms
}