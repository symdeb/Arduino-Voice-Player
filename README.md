
# VOICE

This example uses 3 microphones each connected to one of the ADC's


We read each  ADC inputs for 100 times each and accumulate a total for each channel.
When the value it low, the sound recorded was low, and a high value indicated loud sound.
The longer the sound, the higher the value is. A short abut loud "shout" will still result in a low value.

The total of values is divided in 4 ranges
Based on each range of values an mp3 file is played with the dflplayer.

There are 3 LEDS connected to the digital out pins. When recording starts the LED
will be lit so the person know when to start speaking.

The microphones are very sensitive, just a small amount of sound will increase the value a lot
So the micrphones must be distanced and siplated from each other to prevent sounds to influence each other.


There is a switch and a USB connector. when a conputer is connected to the USB port and the switch is set in "ON" position, then powr onthe Arduno, the dfplayer will act an an USB drive and files can be moved from the PC to the dfplayer. 
This mmakes it conventient to change files and not need to take out the SD card.  After transfer, the swiych must be set ot OFF and the Arduno reset.

** Material List **

* [uno] - Arduino Uno 
* [speaker] - 2W or more speaker (3W recommended)
* [dfplayer] - DFplayer Mini
* [usb] - USB type B connector
* [switch] - Mini Push Button Switch Latching DPDT
* [resistors] - Some resistors
* [microphone] - Electret micrphpone breakout board


[uno]:  https://www.arduino.cc/	
[speaker]: https://www.amazon.com/2w-speaker/s?k=2w+speaker
[usb]: https://www.molex.com/molex/products/datasheet.jsp?part=active/0670687041_IO_CONNECTORS.xml
[switch]: https://www.e-switch.com/product-catalog/pushbutton/product-lines/tl2230-series-pushbutton-switches
[dfplayer]: https://www.dfrobot.com/product-1121.html
[switch]: https://www.e-switch.com/product-catalog/pushbutton/product-lines/tl2230-series-pushbutton-switches
[microphone]: https://www.aliexpress.com/item/1pcs-Wholesale-Sound-Detection-Sensor-Module-Sound-Sensor-Intelligent-Vehicle-For-Arduino/32654537130.html
	 
