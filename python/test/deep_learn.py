import mnist
import numpy as np
from keras.models import Sequential#顺序模型
from keras.layers import Dense,Dropout,Activation,Flatten
#dense fc(全连接层),Activation激活层
from keras.layers import Conv2D,MaxPooling2D,AveragePooling2D
 
nb_class=10
kernel_size=(5,5)#卷积核大小
pool_size=(2,2)
img_rows,img_cols=28,28
batch_size=128#批处理样本数量
epochs=600 #迭代次数
 
input_shape=(img_rows,img_cols,1)#图片维度
#X_train[[],[],[],[].......]
X_train,Y_train=mnist.get_train_data_set(1000,False)#加载训练样本数据集
 
X_test,Y_test=mnist.get_test_data_set(1000,False)#加载测试样本数据集
 
X_train=np.array(X_train).astype(bool).astype(float)/255#?????????????????????
print("X_train_F:",X_train)
X_train=X_train[:,:,:,np.newaxis]#添加新维度
print("X_train_B:",X_train)
Y_train=np.array(Y_train)
X_test=np.array(X_test).astype(bool).astype(float)/255#?????????????????????
X_test=X_test[:,:,:,np.newaxis]#添加新维度转换成[[[[0.],[0.],[],......]]]
 
Y_test=np.array(Y_test)
print("样本数据集维度:",X_train.shape,Y_train.shape)#由外到内,包含元素
print("测试数据集维度:",X_test.shape,Y_test.shape)
#
# 构建模型
#
model=Sequential()#顺序模型
model.add(Conv2D(6,kernel_size,input_shape=input_shape,strides=1))#卷积层,步进1
 
model.add(AveragePooling2D(pool_size=pool_size,strides=2))#池化层
#再次卷积不需要输入图像
model.add(Conv2D(12,kernel_size,strides=1))
model.add(AveragePooling2D(pool_size=pool_size,strides=2))
 
model.add(Flatten())#一维数据
model.add(Dense(nb_class))#全连接
model.add(Activation("sigmoid"))#激活函数
 
#编译模型
#loss交叉熵,优化器,评估
model.compile(loss="categorical_crossentropy",optimizer="adadelta",
              metrics=["accuracy"])
print("X_test:",X_test.shape)
print("Y_test:",Y_test.shape)
#训练模型
model.fit(X_train,Y_train,batch_size=batch_size,epochs=epochs,verbose=1,
          validation_data=(X_test,Y_test))
#评估模型
score=model.evaluate(X_test,Y_test,verbose=0)
print("Test score:",score[0])
print("Test accuracy:",score[1])
 
#保存模型
model.save("cnn_model.h5")#保存模型,HDF5文件