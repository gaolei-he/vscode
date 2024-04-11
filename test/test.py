import os
import pyheif
from PIL import Image
from PIL.ExifTags import TAGS

def get_exif_data(image_path):
    exif_data = {}
    try:
        if image_path.lower().endswith('.heic'):
            heif_file = pyheif.read(image_path)
            exif_data = heif_file.metadata
        else:
            exif_data = Image.open(image_path)._getexif()
    except Exception as e:
        print(f"Error reading EXIF data for {image_path}: {e}")
    return exif_data

def has_location_info(exif_data):
    if exif_data is not None:
        for tag, value in exif_data.items():
            tag_name = TAGS.get(tag, tag)
            if tag_name == 'GPSInfo':
                return True
    return False

def main():
    image_folder = '/path/to/your/image/folder'
    images = os.listdir(image_folder)

    for image_file in images:
        image_path = os.path.join(image_folder, image_file)
        exif_data = get_exif_data(image_path)
        if has_location_info(exif_data):
            print(f"{image_file} contains location information.")
        else:
            print(f"{image_file} does not contain location information.")

if __name__ == "__main__":
    main()
