# Arduino-server-with-TMP102-to-MYSQL

Equipment
-------------------------

- Arduino Uno
- Shield Ethernet C3 PKA04'2
- TMP102 Digital I2C (RED)
- Simple Switch
- 2 Ethernet cable


Introduction
-------------------------
This script is a copy of another commit. But it is in server mode this time.
This mode allows the ethernet shield to give the temperature to the client and at the same time respond to a ping.
The client sends an HTTP request and receives the temperature from the arduino.


Details
-------------------------
- Please replace my values with those of your environment
- If you use WAMP server 3. See insert <Require all granted> in the file httpd-vhosts.conf. Otherwise you will have 403 errors with the arduino.
- You need to download the UIPEthernet lib. This is compatible with my shield. If you are using another Shield, the ethernet.h lib may be the one to use for you.
