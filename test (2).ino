#include <PS2X_lib.h> // Khai báo thư viện tay cầm
#include <Wire.h> //thư viện I2c của Arduino, do PCA9685 sử dụng chuẩn giao tiếp i2c nên thư viện này bắt buộc phải khai báo 
#include <Adafruit_PWMServoDriver.h> // thư viện PCA9685

// //Định nghĩa các chân điều khiển 
// #define PS2_DAT p12 // MISO 
// #define PS2_CMD p13 // MOSI 
// #define PS2_SEL p15 // SS 
// #define PS2_CLK p14 // SLK

//Khởi tạo class của thư viện
PS2X ps2x; // khởi tạo class PS2x



Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

Adafruit_PWMServoDriver pwm1 = Adafruit_PWMServoDrive(0x70); 
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDrive(0x71);


void setup() {
  //Khởi tạo Serial monitor với tốc độ 115200
  Serial.begin(115200);

  pwm.begin(); //khởi tạo PCA9685 
  pwm.setOscillatorFrequency(27000000); // cài đặt tần số dao động 
  pwm.setPWMFreq(50);// cài đặt tần số PWM. Tần số PWM có thể được cài đặt trong khoảng 24-1600 HZ, tần số này được cài đặt tùy thuộc vào nhu cầu xử dụng. Để điều khiển được cả servo và động cơ DC cùng nhau, tần số PWM điều khiển được cài đặt trong khoảng 50-60Hz.
  Wire.setClock(400000); // cài đặt tốc độ giao tiếp i2c ở tốc độ cao nhất(400 Mhz). Hàm này có thể bỏ qua nếu gặp lỗi hoặc không có nhu cầu tử dụng I2c tốc độ cao

  pwm.setPWMFreq(50); // sử dụng xung PWM ở tần số 50Hz

  pwm.setPWM(5, 0, 410); // chọn kênh servo số 5
}

void loop() {
//Kết nối với tay cầm bằng hàm ps2x.config_gamepad, thử kết nối lại trong vòng 10 lần nếu quá 10 lần không kết nối được với tay cầm thì sẽ dừng lại

  int error = -1; 
  for (int i = 0; i < 10; i++) // thử kết nối với tay cầm ps2 trong 10 lần 
  {
    delay(1000); // đợi 1 giây 
    // cài đặt chân và các chế độ: GamePad
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble); 
    Serial.print("."); 
    if(!error) //kiểm tra nếu tay cầm đã kết nối thành công 
    break; // thoát khỏi vòng lặp 
  } 

  //Cập nhật các giá trị của tay điều khiển
  ps2x.read_gamepad(false, false); // gọi hàm để đọc tay điều khiển 

  // các trả về giá trị TRUE (1) khi nút được giữ 
  if (ps2x.Button(PSB_START)) // nếu nút Start được giữ, in ra Serial monitor 	
      //Serial.println("Start is being held");

  if (ps2x.Button(PSB_PAD_UP)) // tương tự như trên kiểm tra nút Lên (PAD UP) 
  { 
    Serial.print("Up held this hard: ");     
    Serial.println(ps2x.Analog(PSAB_PAD_UP), DEC); // đọc giá trị analog ở nút này, xem nút này được bấm mạnh hay nhẹ 
  }

  if (ps2x.ButtonPressed(PSB_CIRCLE)) { // Trả về giá trị TRUE khi nút được ấn (từ tắt sang bật) 
    Serial.println("○ just pressed"); 
    pwm.setPWMFreq(50); // sử dụng xung PWM ở tần số 50Hz
    pwm.setPWM(5, 0, 410); // chọn kênh servo số 5
    //pwm.writeMicroseconds(kênh PWM, microsec); 
    //Microsec, thời gian xung ở mức cao trong 1 chu kì (trạng thái bật)

    pwm.writeMicroseconds(5, 2000); // chọn kênh servo số 5
  }
  if (ps2x.NewButtonState(PSB_CROSS)) { // Trả về giá trị TRUE khi nút được thay đổi trạng thái (bật sang tắt, hoặc tắt sang bật) 
    Serial.println("× just changed"); 
  }
  if (ps2x.ButtonReleased(PSB_SQUARE)) // Trả về giá trị TRUE khi nút được thả ra (từ bật sang tắt) 
    Serial.println("□ just released"); 

  //Đọc nhiều nút bấm theo sự thay đổi trạng thái
  if (ps2x.NewButtonState()) {
    if (ps2x.Button(PSB_L3)) {Serial.println("L3 pressed");   pwm.setPWM(13 ,0, 255); /* chọn chân số 13, giá trị pwm 255 */ }
    if (ps2x.Button(PSB_R3)) {Serial.println("R3 pressed");   pwm.setPWM(13 ,0, 0); /* chọn chân số 13, giá trị pwm 0 */ }
    if (ps2x.Button(PSB_L2)) {Serial.println("L2 pressed");    pwm.setPWM(8, 0, 2048); /*chân số 8 set chiều dương là PWM 50% */ }

    // Trả về giá trị TRUE khi nút được thay đổi trạng thái (bật sang tắt, hoặc tắt sang bật)

  Serial.print("Stick Values:"); 
  Serial.print(ps2x.Analog(PSS_LY)); // đọc trục Y của joystick bên trái. 
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_LX), DEC);
  Serial.print(",");
  Serial.print(ps2x.Analog(PSS_RY), DEC);
  Serial.print(",");
  Serial.println(ps2x.Analog(PSS_RX), DEC);

  }
}
