// Mảng chứa các chân điều khiển LED
int led[] = {5, 6, 7, 8, 9};     

// Chân nhận tín hiệu từ cảm biến âm thanh (digital)
int sensor = 10;                

void setup() {
  // Thiết lập các chân LED là OUTPUT
  for (int t = 0; t < 5; t++) {
    pinMode(led[t], OUTPUT);
  }

  // Thiết lập chân cảm biến là INPUT để nhận tín hiệu
  pinMode(sensor, INPUT);
}

void loop() {
  // Kiểm tra nếu cảm biến phát hiện âm thanh mạnh (bass)
  if (digitalRead(sensor) == 0) {  // LOW = có tín hiệu bass

    // Thực hiện hiệu ứng nhấp nháy toàn bộ LED 3 lần
    for (int i = 0; i < 3; i++) {

      // Bật tất cả LED
      for (int k = 0; k < 5; k++) {
        digitalWrite(led[k], HIGH);
      }

      // Giữ sáng trong 50ms
      delay(50);

      // Tắt tất cả LED
      for (int k = 0; k < 5; k++) {
        digitalWrite(led[k], LOW);
      }

      // Nghỉ 10ms trước lần nhấp tiếp theo
      delay(10);
    }

  } else {
    // Nếu không có tín hiệu bass, đảm bảo tất cả LED đều tắt
    for (int k = 0; k < 5; k++) {
      digitalWrite(led[k], LOW);
    }
  }
}