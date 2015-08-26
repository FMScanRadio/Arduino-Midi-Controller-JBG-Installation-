//Requires NewPing library: http://playground.arduino.cc/Code/NewPing
#include <NewPing.h>

#define ECHO_PIN_1     2
#define TRIGGER_PIN_1  3
#define ECHO_PIN_2     4
#define TRIGGER_PIN_2  5
#define ECHO_PIN_3     6
#define TRIGGER_PIN_3  7
#define ECHO_PIN_4     8
#define TRIGGER_PIN_4  9
#define MAX_DISTANCE 400 //In centimeters. Set max distance according to specs. 300cm for SRF04, 400cm for SRF05.

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);

//Set delay to minimum refresh time as per rangefinder specs. 50ms for SRF04/SRF05.
int delayTime = 50; 

void setup() {
  Serial.begin(9200);
}

void loop() {
  int uS1 = sonar1.ping();
  Serial.write(uS1 / US_ROUNDTRIP_CM);
  delay(delayTime); //Full delay after each ping to make sure last radio wave has dissipated before the next ping.
  
  int uS2 = sonar2.ping();
  Serial.write(uS2 / US_ROUNDTRIP_CM);
  delay(delayTime);
  
  int uS3 = sonar3.ping();
  Serial.write(uS3 / US_ROUNDTRIP_CM);
  delay(delayTime);
  
  int uS4 = sonar4.ping();
  Serial.write(uS4 / US_ROUNDTRIP_CM);
  delay(delayTime);
}
