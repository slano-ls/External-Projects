#!/usr/bin/env python3

# Python program to create an Image Viewer Application using Tkinter  
  
# Importing Tkinter and ImageTk modules  
from tkinter import *  
import tkinter as tk  
from PIL import ImageTk, Image  
  
# Creation of the new window  
windw = Tk() # creating the required window  
windw.resizable() # geometry of the window  
windw.title('Image Viewer') # title of the window  
Label(window, text = "Image Viewer App", font = ('bold', 20)).pack() # label  
   
#creating the required frame  
Frames = Frame(window, width = 230, height = 200, bg = 'white')  
frames.pack()  
  
# creating the two, next and back buttons  
# The back button, to move to previous image  
Button(windw, text = 'Back', command = Back, bg= ' light blue ').place(x = 240, y = 50)  
  
# The next button, to move to next image  
Button(windw, text = 'Next', command = Next, bg = ' light blue ').place(x = 1010, y = 50)  
  
# opening of the images  
# assigning a variable for each image to be stored  
img1 = ImageTk.PhotoImage(Image.open("img1.jpeg"))  
img2 = ImageTk.PhotoImage(Image.open("img2.jpeg"))  
img3 = ImageTk.PhotoImage(Image.open("img3.jpeg"))  
   
# adding all the images to a list  
imglst = [img1, img2, img3]  
j = 0  
img_label = Label(frames, image = imglst[j])   
  
# packing the images into the window  
img_label.pack()  
  
# defining a forward function to be called when next image is to be displayed  
def Forward():  
    global j # creating a global variable j  
    j = j + 1  
    try:  
        img_label.config(image = imglst[j])  
    except:  
        j = -1  
        Forward() # calling the forward function  
  
# defining a backward function to be called when next image is to be displayed  
def Backward():  
    global j # creating a global variable j  
  
    j = j - 1  
    try:  
        img_label.config(image = imglst[j])  
    except:  
        j = 0  
        Backward() # calling the forward function  
  
# Calling the mainloop method to execute our code  
windw.mainloop()  
