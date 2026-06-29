#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(10,11); //TX,RX
Servo gateServo;

char data;

void setup(){
  bluetooth.begin(9600);
  Serial.begin(9600);

  gateServo.attach(9);
  gateServo.write(0);
}
void loop(){
  if (bluetooth.available()){
    data = bluetooth.read();
    Serial.println(data);
    if (data == '1'){
      gateServo.write(90); // Open gate

    }
    if (data == '0'){
      gateServo.write(0); // Close gate
    }
  }
}