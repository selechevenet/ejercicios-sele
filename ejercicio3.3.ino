#include <Servo.h>

Servo servo_5;

void setup()
{
  servo_5.attach(5, 500, 2500);

}

void loop()
{
  servo_5.write(0);
  servo_5.write(180);
  delay(10);
}
