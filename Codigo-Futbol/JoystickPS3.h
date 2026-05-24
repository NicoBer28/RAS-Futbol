#include <Ps3Controller.h>

//Ps3.data.button.cross (square/triangle/circle/down/up/left/right)
class JoystickPS3 : public InterfazJoystick {
  public:

  void begin() override {
    Ps3.begin("08:a9:5a:11:ab:e3");
  }

  bool isConnected() override {
    return Ps3.isConnected();
  }

  int getX() override {
    return Ps3.data.analog.stick.lx;
  }

  int getY() override {
    return Ps3.data.analog.stick.ly;
  }

  int getRotation() override {

  }
}