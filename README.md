# Arduino-Midi-Controller [JBG Installation]

See infographic [here](https://raw.githubusercontent.com/KirilMK/Arduino-Midi-Controller_JBG-Installation/master/INFOGRAPHIC.png). Graphic designed by [@rachelshneyer](https://twitter.com/rachelshneyer) | [rachelshneyer.com](rachelshneyer.com).

This project consists of a set of ultrasonic range finders and an Arduino acting as a midi controller. The hardware, connected to a laptop and amp, is located inside a pyramid structure. Each range finder, when triggered, adjusts the volume of part of the song playing. (https://soundcloud.com/fmscanradio/deep-deep) 

The serial data from the Arduino is routed through a Pure Data script into Ableton. 

# Materials:

Arduino Uno (1x)

SRF05 Ultrasonic Rangefinders (3x)

- Tech specs: http://www.robot-electronics.co.uk/htm/srf05tech.htm

Requires NewPing library for the Arduino code to function: http://playground.arduino.cc/Code/NewPing
