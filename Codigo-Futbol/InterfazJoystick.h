
class InterfazJoystick {
  public:
    virtual void begin() = 0;
    virtual bool isConnected() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getRotation() = 0;


}