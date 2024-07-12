from PIL import Image

img = Image.open('../file.jpg')

if img.mode != "RGBA":
    img = img.convert("RGBA")

pixels = img.load()

w, h = img.size
for x in range(w):
    for y in range(h):
        r, g, b, a = pixels[x, y]
        if r + b + g >= 750:
            pixels[x, y] = (r, g, b, 0)

img.save('../file1.png')