import time
import os

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

def clear():
  clear

def welcome():
  print("Welcome to...")
  
  print(blue+" ______           _                      _____ _            ")
  print(" | ___ \         (_)                    /  ___(_)           ")
  print(" | |_/ /_   _ ___ _ _ __   ___  ___ ___ \ `--. _ _ __ ___   ")
  print(" | ___ \ | | / __| | '_ \ / _ \/ __/ __| `--. \ | '_ ` _ \  ")
  print(" | |_/ / |_| \__ \ | | | |  __/\__ \__ \/\__/ / | | | | | | ")
  print(" \____/ \__,_|___/_|_| |_|\___||___/___/\_                  ")



clear()
welcome()
input()
clear()
username=input(green+"Welcome, before we get started,\nplease tell me your (user) name- ").capitalize()
if len(username)<3 or username=="Yeet" or username=="Ur mom":
  print(red+"Thats not a name silly")
  time.sleep(1)
  clear()
elif username=="Cal":
  os.system("python3 game.py")
else:
  store=input("What's the store called- ")
  print(magenta+"\nGreeting's",username,"and welcome to "+store+"...")
  time.sleep(3)
  print("I am giving you the role of manager for this shop. You can set prices, sell items, and that sort of thing. I'm sure you're very eager to begin.")
  story=input("Would you like to take on your role as manager- ").lower()
  if story=="yes" or story=="yep" or story=="y":
    os.system("python game.py")
  elif story=="no":
    print("Ok")
    time.sleep(2)
    clear()
  else:
    print("Try again")