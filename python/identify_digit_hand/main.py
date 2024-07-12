import numpy as np
from keras._tf_keras.keras.preprocessing import image
# 加载模型
from keras._tf_keras.keras.models import load_model
model = load_model('digit_recognition_model.h5')

# 加载并预处理图像
def preprocess_image(img_path):
    img = image.load_img(img_path, color_mode='grayscale', target_size=(28, 28))
    img = image.img_to_array(img)
    img = np.expand_dims(img, axis=0)
    img = img / 255.0
    return img

# 预测图像
def predict_digit(img_path):
    img = preprocess_image(img_path)
    predictions = model.predict(img)
    predicted_digit = np.argmax(predictions)
    return predicted_digit

# 示例：预测本地图像
img_path = 'digit.png'
predicted_digit = predict_digit(img_path)
print(f"The predicted digit is: {predicted_digit}")