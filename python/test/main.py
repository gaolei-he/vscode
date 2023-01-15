from keras.models import load_model
import  numpy  as np
import cv2
model=load_model("cnn_model.h5")
image=cv2.imread("/home/mechrevo/Documents/vscode/python/test/test.png")
img=cv2.imread("/home/mechrevo/Documents/vscode/python/test/test.png",0)
img=np.reshape(img,(1,28,28,1)).astype(bool).astype("float32")/255
my_proba=model.predict_on_batch(img)#输出序列概率
my_predict=np.argmin(model.predict(img), axis=-1)#输出类别
print("图片数字为:")
print(my_proba)
print(my_predict)
cv2.imshow("image",image)#opencv 显示图片
cv2.waitKey(1000)