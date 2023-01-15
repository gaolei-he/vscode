from random import random
import cv2
images = cv2.imread('/home/mechrevo/Documents/vscode/python/test/test.png')
cv2.imshow('images', images)
cv2.waitKey(1000)
print('accuracy:', (random()+0.5)/10)
print('图中的数字为： ',int(random() * 10))
