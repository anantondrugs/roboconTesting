#include <USBHost_t36.h>

USBHost mysub;
JoystickController ps4(mysub);
BluetoothController bt(mysub , true , "0000");
USBHIDParser hid1(mysub);

int prevLX=0;
int prevLY=0;
int prevRY=0;
void setup(){

  Serial.begin(9600);
  mysub.begin();

  delay(5000);
 
  Serial.println("Connecting to PS4 controller");
  
  delay(5000);
}


void loop(){
  mysub.Task();

  if(ps4.available()){
    int LX = ps4.getAxis(0);
    int LY = ps4.getAxis(1);
    int RX = ps4.getAxis(2);
    int RY = ps4.getAxis(5);
    Serial.print("Lx: ");
    Serial.println(LX);
    Serial.print("Ly: ");
    Serial.println(LY);
    Serial.print("Rx: ");
    Serial.println(RX);
    Serial.print("Ry: ");
    Serial.println(RY);
  }
  else
    Serial.println("Not connected");
  delay(100);
}