# NodeMCU LED
NodeMCU RGB LED strip control over WiFi

## Parts required
1x nodemcu (I used v3)<br>
1x RGB LED strip (5 meter)<br>
3x TIP41c transistors (or any with support 1.7 Amper)<br>
3x small heat-sink for transistors (optional)<br>
3x 3.3k-ohm resistors<br>
1x 12v pwm fan<br>
1x 12v 6A power supply<br>
1x USB cable<br>
1x breadboard or circuit board<br>
some wires<br>
Arduino IDE

## Project Structure
Server.ino	-> Main Arduino app source<br>
Color.h			-> Color manager header<br>
Color.cpp		-> Color manager source<br>
mainPage.h	-> Web-Server HTML file<br>
assets			-> Static CSS/JS files which can accessed from CDN<br>

## CDN links
I've uploaded files (minifed) to ArvanCloud CDN due to it's higher performance. Here's the links:<br>
https://arduino.s3.ir-thr-at1.arvanstorage.com/style.min.css<br>
https://arduino.s3.ir-thr-at1.arvanstorage.com/fan.min.css<br>
https://arduino.s3.ir-thr-at1.arvanstorage.com/script.js<br>
https://arduino.s3.ir-thr-at1.arvanstorage.com/fan.png

## How To Start
Make the curcuit like the image below (will be added as soon).<br>
Change your WIFI name, password and IP address in Server.ino line 10,11,12.<br>
Connect your NodeMCU (or any arduino based board) via USB to PC and upload sketch to board.<br>
<br>
<strong>Full guide will be available on instructables.</strong><br>
If you want board to get IP Address from DHCP remove 12,13,14,41 lines from Server.ino file.
