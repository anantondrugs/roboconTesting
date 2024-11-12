#include <USBHost_t36.h>

USBHost mysub;
USBHIDParser hid1(mysub);
BluetoothController bt(mysub , true , "0000");
JoystickController ps4(bt);

int prevLX=0;
int prevLY=0;
int prevRY=0;
void setup(){
  Serial.begin(9600);
  mysub.begin();

  bt.begin();

  Serial.println("Connecting to PS4 controller...");

}


void loop(){
  mysub.Task();

  if(ps4.available()){
    int LX = ps4.getAxis(0);
    int LY = ps4.getAxis(1);
    int RY = ps4.getAxis(3);
    if(LX!=prevLX)
      Serial.println(LX);
    if(LY!=prevLY)
      Serial.println(LY);
    if(RY!=prevRY)
      Serial.println(RY);
    prevLX = LX;
    prevLY = LY;
    prevRY=RY;
  }
  else
    Serial.println("Not connected");
}