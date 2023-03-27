# ESP8266

Collection of serval ESP8266-Projects

## Arduino IDE Boards Manager

To add the ESP to the Arduino IDE, add `http://arduino.esp8266.com/stable/package_esp8266com_index.json` to the Boards Manager

## Known Problems

In Ubuntu 22.10 brltty prevents the Arduino IDE from connecting to the ESP. If one is not using Braile devices, uninstall brltty:
`sudo apt autoremove brltty`
