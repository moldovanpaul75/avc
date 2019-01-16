# arduino ultrasonic sensor volume control

The concept behind the project is very simple. We will place a Ultrasonic (US) sensors and will read the distance between it and our hand using Arduino, based on this value of distance we will perform certain actions. To perform actions on our computer we use Python pyautogui library. The commands from Arduino are sent to the computer through serial port (USB). This data will be then read by python which is running on the computer and based on the read data an action will be performed.

# Circuit Diagram:
https://imgur.com/a/sN89m90

# Arduino:
By reading the value of distance we can arrive at certain actions to be controlled with gestures. When your hand is placed up before the sensor at a particular near distance the volume should increase and if moved away the volume should decrease.


Let us see how the program is written to perform the above actions. So, like all programs we start with defining the I/O pins as shown below. The US sensor is connected to Digital pins 2, 4 and are powered by +5V pin. The Trigger pin is the output pin and Echo pin is the input pin.
The Serial communication between Arduino and python takes places at a baud rate of 9600.

We need to calculate the distance between the Sensor and the hand each time before concluding on any action. So we have to do it many times, which means this code should be used as a function. We have written a function named calculate_distance() which will return us the distance between the sensor and the hand.

Inside our main loop we check for the value of distance and perform the actions mentioned above. Before that we use a variable dist1 which gets updated with current distance value.

To control the volume we have to place the our hand approx. at a distance of 10-40 cm , then you can either move it towards the sensor to increase the volume of move it away from the sensor to decrease the volume. Based on the action, here the word “VUp” or “VDown” will be sent out through serial port.

# Python:
The python program for this project is very simple. We just have to establish a serial communication with Arduino through the correct baud rate and then perform some basic keyboard actions. For this to work you need Python27 with pyautogui and serial modules installed.
https://www.python.org/download/releases/2.7/
https://pyautogui.readthedocs.io/en/latest/

# How to use:

1.First of all you need a arduino board, a ultrasonic sensor hc-sr04 and a laptop or pc.
Also you need to install Arduino IDE, which you can download from here https://www.arduino.cc/en/Main/Software , and Python27 32-bit http://www.python.org/ftp/python/2.7.9/python-2.7.9.msi

2.Alter installing ArduinoIDE and Python27 you need to install serial and pyautogui modules.
Open command prompt as admin and launch python27

cd C:\Python27
and after

pip install pyserial,
pip install pyautogui

3.After installing all programs connect the ultrasonic sensor to the board like in the circuit diagram and connect it to the laptop.
Using ArduinoIDE upload the code from volumec.ino.

4.After this open command prompt as admin again and launch python27 
cd C:\Python27

and run the python program from volumec.py (connect your board to COM5, if you get a port restricted error reconnect it) 

http://prntscr.com/m80riz

5.Now keep your hand in range of 10 to 20cm for volume up or 20 to 30 for volume down 

http://prntscr.com/m80ry2

