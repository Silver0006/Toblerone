#Potential to import audio and image into exe research later
import tkinter, os, sys
from playsound import playsound
from tkinter import *
from PIL import Image, ImageTk
root = Tk()
root.attributes('-fullscreen',True)
image1 = Image.open(os.path.join(sys.path[0], "spooks.png"), "r")
test = ImageTk.PhotoImage(image1)
label1 = tkinter.Label(image=test)
label1.place(x=0, y=0)
playsound(os.path.join(sys.path[0], "spook1.wav"), block=False)
root.mainloop()
