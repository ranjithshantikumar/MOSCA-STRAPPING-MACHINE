 /*
  This is a Program to control
  
     Mosca Strap sealing Temperature
     as a Replacement for N1 temp regulator module
     
     
     
     Does not report any bug while compiling
     tested in basic setup and works fine
     
     yet to be tested in original set up and 
     many calibration of Sensor value A0( HEATAING)to MOSCA MAY BE NEEDED

     Dangerous temp avoidance circuit may be tested 
     this is version 2
     and  changes has to be made when connected online
     check for all redunancy and ask colleauges for any missing concept while heating loop
     .

 The circuit:
 * photoresistor from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground

 created 8 SEP 2016
 modified 11 Apr 2012
 by RANJITHKUMAR

 */

// these constants won't change. They are the
// lowest and highest readings you get from your sensor:
const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 230;    // sensor maximum, discovered through experiment
const int heater_on = 0;
const int heaterNotReady =1;
int sensorReading = 0;
void setup() {
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  // initialize serial communication:
  //Serial.begin(9600);
}

void loop() {
  
  // read the sensor:
  int sensorReading = analogRead(1);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 4);

  // do something different depending on the
  // range value:
  switch (range) {
    case 0:    // your hand is on the sensor
     // Serial.println("cold");
      digitalWrite(1,HIGH);
      digitalWrite(0,HIGH);
       break;
    case 1:    // your hand is close to the sensor
      //Serial.println("warm");
      digitalWrite(1,HIGH);
      digitalWrite(0,HIGH);
      break;
    case 2:    // your hand is a few inches from the sensor
     // Serial.println("medium");
      digitalWrite(1,LOW);
      digitalWrite(0,HIGH);
      break;
    case 3:    // your hand is nowhere near the sensor
    //  Serial.println("ok");
      delay(5);
      digitalWrite(1,LOW);
      delay(10);
      digitalWrite(0,HIGH);
      break;
      case 4:    // your hand is nowhere near the sensor
     // Serial.println("HEATING CYCLE START");
      digitalWrite(1,LOW);
      digitalWrite(0,HIGH);
      delay(1000);
      digitalWrite(0,LOW);
      delay(3000);
     break;
  }
  delay(1);        // delay in between reads for stability
}





