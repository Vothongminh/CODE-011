//https://www.youtube.com/c/VTMVlogVoThongMinh
#define sensor 4              //Khai báo chân cho cảm biến 
#define clk 2            //Khai báo chân clk của driver TB6600
#define cw 3             //Khai báo chân cw của driver TB6600
//........................................
void setup() {
  Serial.begin(9600);
  pinMode(clk, OUTPUT); //Khai báo là chân ngõ ra output
  pinMode(cw, OUTPUT);
  pinMode(sensor, INPUT_PULLUP); //Khai báo chân tín hiệu cảm biến là ngõ vào
  digitalWrite(cw, HIGH);
}
//........................................
void loop() {
  if (digitalRead(sensor) == 0) {  //Nếu nhận được tín hiệu từ cảm biến
    Serial.println("run");
    for (int x = 0; x < 1600; x++) { //ở đây mình để ở chế độ vi bước 1/8 nên để quay được 1 vòng cần 1600 xung, tương tự 2 vòng sẽ nhân lên là 3200 xung
      digitalWrite(clk, HIGH);
      delayMicroseconds(50);
      digitalWrite(clk, LOW);
      delayMicroseconds(50);
    }
    while (digitalRead(sensor) == 0);
  }
