import  numpy  as  np
class  loader(object):#加载文件内容
    def __init__(self,path,count):
        self.path=path
        self.count=count
    def get_file_content(self):
        print('#')
        print(self.path)
        print('#')
        f=open('/home/mechrevo/Documents/vscode/python/test/' + str(self.path),"rb")
        content=f.read()
        f.close()
        return  content
class  ImageLoade(loader):
    def get_picture(self,content,index):
        start=index*28*28+16
        picture=[]
        for i in range(28):
            picture.append([])
            for j in range(28):
                byte1=content[start+i*28+j]
                picture[i].append(byte1)#28*28的一幅图片
        return  picture
    def get_one_sample(self,picture):
        sample=[]
        for i in range(28):
            for j in range(28):
                sample.append(picture[i][j])
        return  sample#转换成784行向量
    def load(self,oneraw=False):
        content=self.get_file_content()#获取文件字节数组
        data_set=[]
        for index in range(self.count):#count为样本个数
            onepic=self.get_picture(content,index)#得到一幅图片,二维数组
            if oneraw:
                onepic=self.get_one_sample(onepic)
            data_set.append(onepic)
        return data_set
class   LabelLoad(loader):#标签数据加载器
    def load(self):
        content=self.get_file_content()#得到文件字节数组
        labels=[]
        for index in range(self.count):
            onelabel=content[index+8]#文件头八个字节
            onelabelvec=self.norm(onelabel)#编码？？？？
            labels.append(onelabelvec)
        return labels#返回一个数组[[],[],[].....]
    def norm(self,label):
        labelvec=[]
        label_value=label#字节转int类型？？
        for i in range(10):#one-hot编码
            if i==label_value:
                labelvec.append(1)
            else:
                labelvec.append(0)
        return  labelvec
def get_train_data_set(num,oneraw=False):#获得训练数据集
    image_loader=ImageLoade("train-images.idx3-ubyte",num)
 
    label_loader=LabelLoad("t10k-labels.idx1-ubyte",num)
 
    return image_loader.load(oneraw),label_loader.load()#返回[[],[],[]......]#28个
def get_test_data_set(num,oneraw=False):
    image_loader=ImageLoade("t10k-images.idx3-ubyte",num)
 
    label_loader=LabelLoad("t10k-labels.idx1-ubyte",num)
 
    return image_loader.load(oneraw),label_loader.load()
def printimg(onepic):
    onepic=onepic.reshape(28,28)
    for i in range(28):
        for j in range(28):
            if onepic[i,j]==0:
                print("  ",end="")
            else:
                print("* ",end="")
        print("")