import time, os, random
def clear():
  os.system("clear")

randtime=random.randint(10,30)
count=0

while count<randtime:
  clear()
  print("Selling")
  count+=1
  time.sleep(0.5)
  clear()
  print("Selling.")
  count+=1
  time.sleep(0.5)
  clear()
  print("Selling..")
  count+=1
  time.sleep(0.5)
  clear()
  print("Selling...")
  count+=1
  time.sleep(0.5)
  clear()