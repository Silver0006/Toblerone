import tkinter, os, sys, pyautogui
from playsound import playsound
from tkinter import *
from PIL import Image, ImageTk
pyautogui.press('volumeup', 100)
playsound("spook1.wav")
root = Tk()
playsound("spook2.mp3", block=False)
root.attributes('-fullscreen',True)
image1 = Image.open("spooks.png")
test = ImageTk.PhotoImage(image1)
label1 = tkinter.Label(image=test)
label1.place(x=0, y=0)
root.config(cursor="none")
root.after(4200,lambda:root.destroy())
root.mainloop()
