import tkinter

import PIL

import MyClient
import cv2
from PIL import Image, ImageTk

global img;

def connnectToServer():
   print("clicked button")
   thisSocket = MyClient.MySocket();
   thisSocket.connect("127.0.0.1", 12345)
   imageName = thisSocket.myreceive();
   img_label = tkinter.Label(window)
   img_label.image = tkinter.PhotoImage(file="../res/"+imageName)
   img_label['image'] = img_label.image
   img_label.pack()


window = tkinter.Tk()
window.title("MAS Projekt")
connectButton = tkinter.Button(window, text ="Hello", command=connnectToServer())
connectButton.pack()
window.mainloop()