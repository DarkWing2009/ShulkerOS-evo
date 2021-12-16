import time, os, random
def clear():
  os.system("clear")


red = "\033[0;91m"
green = "\033[0;92m"
yellow = "\033[0;93m"
blue = "\033[0;94m"
magenta = "\033[0;95m"
cyan = "\033[0;96m"
white = "\033[0;97m"
blue_back="\033[0;44m"
orange_back="\033[0;43m"
red_back="\033[0;41m"
grey_back="\033[0;40m"

randtime=random.randint(10,20)
count=0

while count<randtime:
  clear()
  print(magenta+"Making ad")
  time.sleep(0.5)
  count+=1
  clear()
  print("Making ad.")
  time.sleep(0.5)
  count+=1
  clear()
  print("Making ad..")
  count+=1
  time.sleep(0.5)
  clear()
  print("Making ad...")
  count+=1
  time.sleep(0.5)
  clear()