import serial
import Tkinter as tk
from Tkinter import *
import os
import time

ArduinoList=[]

DeviceList=os.listdir("/dev") #it will return a list of the contents inside /dev
for i in DeviceList:
	temp=i
	if (temp[:6]=='ttyACM'):
		ArduinoList.append(i)

def FullRotation():
	ser.write(b'2')
		
	
def TurnClock():
	ser.write(b'1')
	text1.configure(text='Position: '+"%s" %ser.readline())
	
root=tk.Tk()
root.title("Calibration")
frame=tk.Frame(root)
frame.grid(column=0,row=1, sticky=(N,W,E,S) )
frame.columnconfigure(0, weight = 1)
frame.rowconfigure(0, weight = 1)
frame.pack(pady = 0, padx = 100)
ChosenOption = StringVar(root)
ChosenOption.set(ArduinoList[0])
Box = OptionMenu(frame, ChosenOption, *ArduinoList)
path='/dev/'+ChosenOption.get()
Box.pack()
ser=serial.Serial(path, 9600)
text1=Label(text="\nPosition: "+ "%s" %ser.readline())
text1.pack()
text2=Label(text="Commands:")
text2.pack()
Button1=tk.Button(root, text="Full Rotation", command=FullRotation)
Button1.pack()
Button2=tk.Button(root, text="Move One Step", command=TurnClock)
Button2.pack()
root.mainloop()

