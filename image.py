#!/usr/bin/env python

# vim: set ai et ts=4 sw=4:

from PIL import Image
import sys
import os

if len(sys.argv) < 2:
    print("Usage: {} <image-file>".format(sys.argv[0]))
    sys.exit(1)

fname = sys.argv[1]

file_name = os.path.basename(fname)
file = os.path.splitext(file_name)
file_out = file[0] + ".c"
print(file_out)

img2 = Image.open(fname)
img = img2.convert('RGB')

data = "const uint16_t " + file[0] + "[] = {\n"
print("const uint16_t test_img[] = {")

for y in range(0, img.height):
    #s = "{"
    s = " "
    for x in range(0, img.width):
        (r, g, b) = img.getpixel((x, y))
        color565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3)
        # for right endiness, so ST7735_DrawImage would work
        #Big-endian
        #color565 = ((color565 & 0xFF00) >> 8) | ((color565 & 0xFF) << 8)
        s += " 0x{:04X},".format(color565)
    #s += "},"
    data += s + "\n"
    print(s)

data += "};\n"
print("};")

f = open(file_out, "w")
f.write(data)
f.close()