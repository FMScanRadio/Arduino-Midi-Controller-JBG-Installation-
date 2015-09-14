//Requires NewPing library: http://playground.arduino.cc/Code/NewPing
#include <NewPing.h>

#define ECHO_PIN_1     2
#define TRIGGER_PIN_1  3
#define ECHO_PIN_2     4
#define TRIGGER_PIN_2  5
#define ECHO_PIN_3     6
#define TRIGGER_PIN_3  7
#define MAX_DISTANCE 400 //In meters. Set to within max distance of sensor (300m for SRF04, 400 for SRF05.)

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);

//Set delay to minimum refresh time as per rangefinder specs. 50ms for SRF04/SRF05.
int delayTime = 50; 

int total1 = 0;
int total2 = 0;
int total3 = 0;

int old1 = 0;
int old2 = 0;
int old3 = 0;

int fade = MAX_DISTANCE * 0.05;

void setup() {
  Serial.begin(9200);
}

void loop() {
  //Each sensor pings once in a 50ms*N (N being # of sensors) cycle.
  //If there is a response (!= 0), then save and send the detected range.
  //If there is no response (== 0), then if an old save value exists, fade and send it.
  //If there is no response (== 0) and no old save value, send the max distance value.
  
  int uS1 = sonar1.ping();
  total1 = uS1 / US_ROUNDTRIP_CM;
  if (total1 != 0) {
  Serial.write(total1);
  old1 = total1;
  } else {
    if (old1 < MAX_DISTANCE){
    old1 = old1 + fade;
    Serial.write(old1);
    }else {
    Serial.write(MAX_DISTANCE);
  }
  }
  
  delay(delayTime); //Full delay after each ping to make sure last radio wave has dissipated before the next ping.
  
  int uS2 = sonar2.ping();
  total2 = uS2 / US_ROUNDTRIP_CM;
  if (total2 != 0) {
  Serial.write(total2);
  old2 = total2;
  } else {
    if (old2 < MAX_DISTANCE){
    old2 = old2 + fade;
    Serial.write(old2);
    }else {
    Serial.write(MAX_DISTANCE);
  }
  }
  delay(delayTime);
  
  int uS3 = sonar3.ping();
  total3 = uS3 / US_ROUNDTRIP_CM;
  if (total3 != 0) {
  Serial.write(total3);
  old3 = total3;
  } else {
    if (old3 < MAX_DISTANCE){
    old3 = old3 + fade;
    Serial.write(old3);
    }else {
    Serial.write(MAX_DISTANCE);
  }
  }
  delay(delayTime);
}
