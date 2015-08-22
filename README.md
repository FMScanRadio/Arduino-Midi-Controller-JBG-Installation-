# Arduino-Midi-Controller [JBG Installation]

This project consists of a set of ultrasonic range finders and an Arduino acting as a midi controller and a DMX lighting controller. The hardware, connected to a laptop, is located inside a geodesic structure surrounded by 4 speakers. Each range finder, when triggered, will change a different setting in Ableton (tone, pitch, etc.) and affect the color of the LED lights.

Currently, the provided code is only sending pings out and recieving the data in as to test the sensors. One is apparently dead on arrival and requires replacement. There are two possible methods for connecting the results to Ableton; the preferred solution being using USB serial from the Arduino, and the other one requiring a MIDI->USB converter. 

# Materials:

Arduino Uno (1x)

SRF05 Ultrasonic Rangefinders (4x)

- Tech specs: http://www.robot-electronics.co.uk/htm/srf05tech.htm

Requires NewPing library for the Arduino code to function: http://playground.arduino.cc/Code/NewPing
