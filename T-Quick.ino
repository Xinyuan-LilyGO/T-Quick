#include <esp32PWMUtilities.h>

#include <DabbleESP32.h>
Motor Motor1;

Motor Motor2;
void _setup() {
  pinMode(2, OUTPUT);
  Motor1.attach(21, 26, 25);

  Motor2.attach(17, 13, 15);

  Dabble.begin("T-Car1");
}

void _loop() {
  Dabble.processInput();
}

void setup() {
  _setup();
  digitalWrite(2, true);
}

void loop() {
  _loop();
  if (GamePad.isPressed(0)) {
    Motor1.moveMotor(2.55 * 100);
    Motor2.moveMotor(2.55 * 100);
  }
  else {
    if (GamePad.isPressed(1)) {
      Motor1.moveMotor(-2.55 * 100);
      Motor2.moveMotor(-2.55 * 100);
    }
    else {
      if (GamePad.isPressed(3)) {
        Motor1.moveMotor(-2.55 * 100);
        Motor2.moveMotor(2.55 * 100);
      }
      else {
        if (GamePad.isPressed(2)) {
          Motor1.moveMotor(2.55 * 100);
          Motor2.moveMotor(-2.55 * 100);
        }
        else {
          Motor1.lockMotor();
          Motor2.lockMotor();
        }
      }
    }
  }
}
