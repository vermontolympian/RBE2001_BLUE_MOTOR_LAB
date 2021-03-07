#include <Arduino.h>
#include <Romi32U4.h>
#include "BlueMotor.h"
#include <Romi32U4Buttons.h>

Romi32U4ButtonB pb;
Romi32U4ButtonA pa;
BlueMotor motor;


void setup() {
  Serial.begin(9600);
  motor.setup();
}

void loop() {
  if(pb.isPressed()){
      unsigned long endTime = millis() + 100;
      motor.setEffort(350); // effort test value
      Serial.print(millis());
      Serial.print(" , ");
      Serial.print(motor.getPosition());
      Serial.print(" , ");
      Serial.println(motor.getVelocity());
      while (millis() < endTime);
  }
  if(pa.isPressed()){
    unsigned long endTime = millis() + 100;
    motor.setEffort(-350);
    while (millis() < endTime);
  }
  else {
      motor.setEffort(0);
      motor.reset();
  }
}