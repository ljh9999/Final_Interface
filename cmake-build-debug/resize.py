from PIL import Image

root = '/home/ljh/Documents/action_detect/Final/Final_Interface/cmake-build-debug/1.jpg'
pic = Image.open(root)
pic = pic.resize((428,240), Image.ANTIALIAS)
pic.save("000.jpg")

