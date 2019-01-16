import serial #Serial imported for Serial communication
import time #Required to use delay functions
import pyautogui #module for programmatically controlling the mouse and keyboard

ArduinoSerial = serial.Serial('com5', 9600) #Create Serial port object called arduinoSerialData
time.sleep(2) #wait for 2 seconds for the communication to get established

while 1:
    incoming = str (ArduinoSerial.readline())
    print incoming

    if 'VUp' in incoming:
        pyautogui.hotkey('volumeup')

    if 'VDown' in incoming:
        pyautogui.hotkey('volumedown')

    incoming ="";
