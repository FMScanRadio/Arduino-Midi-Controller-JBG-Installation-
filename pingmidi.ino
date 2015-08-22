//Requires NewPing library for the Arduino code to function: http://playground.arduino.cc/Code/NewPing
#include <NewPing.h>

#define ECHO_PIN_1     2
#define TRIGGER_PIN_1  3
#define ECHO_PIN_2     4
#define TRIGGER_PIN_2  5
#define ECHO_PIN_3     6
#define TRIGGER_PIN_3  7
#define ECHO_PIN_4     8
#define TRIGGER_PIN_4  9
#define MAX_DISTANCE 400

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);


void setup() {
  Serial.begin(115200);
}

void loop() {
  delay(50);
  int uS1 = sonar1.ping();
  Serial.print("1 Ping: ");
  Serial.print(uS1 / US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.write(uS1 / US_ROUNDTRIP_CM);
  
  delay(50);
  int uS2 = sonar2.ping();
  Serial.print("2 Ping: ");
  Serial.print(uS2 / US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.write(uS2 / US_ROUNDTRIP_CM);
  
  delay(50);
  int uS3 = sonar3.ping();
  Serial.print("3 Ping: ");
  Serial.print(uS3 / US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.write(uS3 / US_ROUNDTRIP_CM);
  
  delay(50);
  int uS4 = sonar4.ping();
  Serial.print("4 Ping: ");
  Serial.print(uS4 / US_ROUNDTRIP_CM);
  Serial.println("cm");
  Serial.write(uS4 / US_ROUNDTRIP_CM);
}
