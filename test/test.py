from PIL import Image
img = Image.open('/home/mechrevo/Pictures/myscreenshot/GNU_not_Unix.png')
w, h = img.size
piexls = img.load()
for x in range(w):
    for y in range(h):
        # if piexls[x, y] == (0xff, 0xff, 0xff):
            # piexls[x, y] = (0x80, 0x80, 0x80)
        r, g, b = piexls[x, y]
        piexls[x, y] = (r//2, g//2, b//2)

img.show()