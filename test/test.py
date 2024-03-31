from PIL import Image
img = Image.open('test.jpg')

pixels = img.load()
w, h = img.size
for x in range(w):
    for y in range(h):
        