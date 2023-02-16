
# Python program to Convert Image into sketch


# import all the required modules
import numpy as np
import imageio
import scipy.ndimage
import cv2
imginput = input("What image would you like to input (PATH)> ")

# take image input and assign variable to it
img = imginput


# function to convert image into sketch
def rgb2gray(rgb):
    # 2 dimensional array to convert image to sketch
    return np.dot(rgb[..., :3], [0.2989, 0.5870, .1140])


def dodge(front, back):

    # if image is greater than 255 (which is not possible) it will convert it to 255
    final_sketch = front*255/(255-back)
    final_sketch[final_sketch > 255] = 255
    final_sketch[back == 255] = 255

    # to convert any suitable existing column to categorical type we will use aspect function
    # and uint8 is for 8-bit signed integer
    return final_sketch.astype('uint8')


ss = imageio.imread(img)
gray = rgb2gray(ss)

i = 255-gray


# to convert into a blur image
blur = scipy.ndimage.filters.gaussian_filter(i, sigma=13)


# calling the function
r = dodge(blur, gray)


cv2.imwrite('4.png', r)
