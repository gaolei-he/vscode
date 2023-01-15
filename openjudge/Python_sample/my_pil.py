from PIL import Image

img = Image.open('/home/mechrevo/Downloads/Google Download/tmp/1016_2.jpg')
img = img.resize((144, 192))
w, h = img.size
pix = img.load()
t = pix[0, 0]
def f(x):
    for i in x:
        if i < 220:
            return False
    return True
for x in range(w):
    for y in range(h):
        p = pix[x, y]
        if f(p):
            pix[x, y] = (3, 150, 240)
img.show()
img.save('/home/mechrevo/Downloads/Google Download/tmp/1016.jpg')