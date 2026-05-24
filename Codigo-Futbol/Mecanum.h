#include <Arduino.h>
#define MAX_PWM 255

struct Motors {
  int fl_pwm;
  int fr_pwm;
  int bl_pwm;
  int br_pwm;

  bool fl_dir;
  bool fr_dir;
  bool bl_dir;
  bool br_dir;
}

class Mecanum {
  public:

  static Motors getMotorValues(int x, int y, int rotation){
    Motors motors;

    int fl_pwm = y + x + rotation; 
    int fr_pwm = y - x - rotation; 
    int bl_pwm = y - x + rotation; 
    int br_pwm = y + x - rotation;

    int max = max({abs(fl_pwm), abs(fr_pwm), abs(bl_pwm), abs(br_pwm)});
    
    if(max > MAX_PWM){
      fl_pwm = (fl_pwm * MAX_PWM) / max;
      fr_pwm = (fr_pwm * MAX_PWM) / max;
      bl_pwm = (bl_pwm * MAX_PWM) / max;
      br_pwm = (br_pwm * MAX_PWM) / max;
    }

    motors.fl_pwm = abs(fl_pwm);
    motors.fr_pwm = abs(fr_pwm);
    motors.bl_pwm = abs(bl_pwm);
    motors.br_pwm = abs(br_pwm);

    motors.fl_dir = fl_pwm >= 0;
    motors.fr_dir = fr_pwm >= 0;
    motors.bl_dir = bl_pwm >= 0;
    motors.br_dir = br_pwm >= 0;

    return motors;
  }
}