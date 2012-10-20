/************************************************
 Written by Cruz Monrreal II
 Created on 08-19-2012
 Modified on 10/20/2012
 
 Updates can be found here:
  https://github.com/cmonr/Arduino-Sphero-Library
************************************************/

#include <Sphero.h>

Sphero sphero;

void setup() {
  Serial.begin(115200);

  // Indicator LED
  sphero.setBackLED(0xFF);
  
  // Lock motors
  sphero.setStabilization(0);
  
  // Get Pitch @ 10Hz
  sphero.setStreamingData(10, 1, SPHERO_IMU_PITCH | SPHERO_IMU_ROLL | SPHERO_IMU_YAW);
}

void loop() {  
  sphero.readAsyncPacket();
  
  // Output Pitch, Roll, Yaw
  Serial.print((signed short)sphero.getData(0) << 8 | sphero.getData(1));
  Serial.print(", ");
  Serial.print((signed short)sphero.getData(2) << 8 | sphero.getData(3));
  Serial.print(", ");
  Serial.println((signed short)sphero.getData(4) << 8 | sphero.getData(5));
}
