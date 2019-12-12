#include <NewPing.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int ServoPin = 9;
int pot = A2;
int potReading = 0;
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//NewPing sonar(TriggerPin, EchoPin);
Servo servo;

void setup() {
  
  pinMode(pot,INPUT);
  Serial.begin (115200);
  servo.attach(ServoPin);
  lcd.init();
  lcd.backlight();

}

void loop() {
  
  potReading =analogRead(pot);
//  lcd.clear();
//   lcd.setCursor(0, 0);
//  lcd.print("we are the same.");
//  
  //delay(50);
  //  Serial.print("Ping: ");
  //  Serial.print(sonar.ping_cm());
  //  Serial.println("cm");

  int cm = sonar.ping_cm();
  int angle = map(cm, 2, 15, 15, 165);
  servo.write(angle);
  if (cm > 0 && cm < 24) {
    servo.write(178);
  }
  if (cm > 24 || cm == 0) {
    servo.write(0);
  }

  Serial.println (potReading);
//pot and lcd 

  if( potReading < 100){
    lcd.clear();
    lcd.setCursor(5,0);
  lcd.print("hello.");
  }
  
  if(potReading > 200&& potReading < 300){
    lcd.clear();
    lcd.setCursor(4,0);
  lcd.print("I am you");  
  }

  if(potReading > 500 && potReading < 700){
    lcd.clear();
    lcd.setCursor(3,0);
  lcd.print("you are me");  
  }

   if(potReading > 800 && potReading < 1023){
    lcd.clear();
    lcd.setCursor (0,0);
  lcd.print("we are the same");  
  }



}
