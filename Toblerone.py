
import tkinter
from playsound import playsound
from tkinter import *
from PIL import Image, ImageTk
root = Tk()
root.attributes('-fullscreen',True)
image1 = Image.open("E:\Toblerone\spooks.png")
test = ImageTk.PhotoImage(image1)
label1 = tkinter.Label(image=test)
label1.place(x=0, y=0)
playsound('E:\Toblerone\spook1.wav')
root.mainloop()
