from PIL import Image
import subprocess
import os
from PIL.ExifTags import TAGS
from pillow_heif import register_heif_opener

register_heif_opener()


file_name = ''
def check(pic):
    img = Image.open(f'./save/{pic}')
    exif_data = img.getexif()
    res = False
    if exif_data is None:
        return res
    for tag, value in exif_data.items():
        tag_name = TAGS.get(tag, tag)
        # print(tag, tag_name, value)
        if tag_name == 'GPSInfo':
            res = True
        if tag_name == 'DateTime':
            global file_name
            file_name = "IMG_" + value.replace(':', '').replace(' ', '_') + "." + pic.split('.')[-1]
    return res



pics = os.listdir('./save')
for pic in pics:
    if check(pic):
        subprocess.run(f"cp ./save/{pic} ./valid/{file_name}", shell=True)
    subprocess.run(f"mv ./save/{pic} ./passed/", shell=True)