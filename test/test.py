import qrcode

qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=1,
    border=4,
)

qr.add_data('https://www.google.com')
qr.make(fit=True)

img = qr.make_image(fill_color="black", back_color="white")
img.save("test.png")