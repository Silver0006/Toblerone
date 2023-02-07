
import tkinter
from tkinter import *
from PIL import Image, ImageTk
root = Tk()
root.attributes('-fullscreen',True)
image1 = Image.open("E:\Toblerone\spooks.png")
test = ImageTk.PhotoImage(image1)
label1 = tkinter.Label(image=test)
label1.resize((599, 599), Image.ANTIALIAS)
label1.place(x=40, y=0)
root.mainloop()