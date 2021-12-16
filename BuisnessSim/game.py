

import time,os, random
from datetime import date
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


clear()
print(white+"")

print(yellow+"Setting prices...")
print(red+"Choose one of the following:")
print(magenta+"")
print("  1. $10,000 (recommended)")
print("  2. $5,000 (challenge)")
print("  3. $15,000 (pretty easy)")
print("  4. $20,000 (easy)")
print("  5. $100,000 (your welcome)")

totalmoneynuminp=input("> ")
if totalmoneynuminp=="2":
  totalmoney=5000
elif totalmoneynuminp=="3":
  totalmoney=15000
elif totalmoneynuminp=="4":
  totalmoney=20000
elif totalmoneynuminp=="5":
  totalmoney=100000
else:
  totalmoney=10000
clear()

day=1
#Change ending lines if you change totalmoney
popular=0
product1=red+"[Not created]"+white
product2=red+"[Not created]"+white
sell1=yellow+"[None]"+white
sell2=yellow+"[None]"+white
stock1=0
stock2=0
adleft=10


def ad1():
  print(blue+"   _______________________________________________________   ")
  print(blue+"  /  ___________________________________________________  \  ")
  print(blue+" /  /                                                   \  \ ")
  print(blue+" |  |     "+red+"       _____                 __             "+blue+"  |  | ")
  print(blue+" |  |     "+red+"      / ___/__  __ _  ___   / /____         "+blue+"  |  | ")
  print(blue+" |  |     "+red+"     / /__/ _ \/  ' \/ -_) / __/ _ \        "+blue+"  |  | ")
  print(blue+" |  |     "+red+"   __\___/\___/_/_/_/\__/  \__/\___/        "+blue+"  |  | ")
  print(blue+" |  |     "+red+"  / /_/ /  (_)__   ___ / /____  _______     "+blue+"  |  | ")
  print(blue+" |  |     "+red+" / __/ _ \/ (_-<  (_-</ __/ _ \/ __/ -_)    "+blue+"  |  | ")
  print(blue+" |  |     "+red+" \__/_//_/_/___/ /___/\__/\___/_/  \__/     "+blue+"  |  | ")
  print(blue+" |  |     "+red+"                                            "+blue+"  |  | ")
  print(blue+" |  |     "+red+"           You Won't Regret It              "+blue+"  |  | ")
  print(blue+" \  \___________________________________________________/  / ")
  print(blue+"  \_______________________________________________________/  "+white)
                                       

def ad2():
  print(red+"          __________________________________________________________         ")
  print(red+" ________|    _    ___              __            __   __    __     |_______ ")
  print(red+" \       |   / '  |   |  |\    /|  |__     |__|  |__  |__|  |__     |      / ")
  print(red+"  \      |   \_.  |___|  |  \/  |  |__     |  |  |__  |  \  |__     |     /  ")
  print(red+"  /      |__________________________________________________________|     \  ")
  print(red+" /________________)           You Won't Regret It           (______________\ ")


def ad3():
  print(yellow+" ________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_________ ")
  print(yellow+" ________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_________ ")
  print(yellow+" ___¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___ ")
  print(yellow+" _¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_ ")
  print(yellow+" ¶¶¶¶______¶¶¶¶¶¶¶¶¶___¶¶¶¶¶¶¶¶¶¶_______¶¶¶¶ ")
  print(yellow+" ¶¶¶_______¶¶¶¶¶¶¶¶_¶__¶¶¶¶¶¶¶¶¶¶________¶¶¶ ")
  print(yellow+" ¶¶¶_______¶¶¶¶¶¶¶_¶¶__¶¶¶¶¶¶¶¶¶¶________¶¶¶ ")
  print(yellow+" ¶¶¶_____¶¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶______¶¶¶ ")
  print(yellow+" ¶¶¶____¶¶¶¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶____¶¶¶¶ ")
  print(yellow+" _¶¶¶___¶¶¶_¶¶¶¶¶¶¶¶____¶¶¶¶¶¶¶¶_¶¶¶____¶¶¶_ ")
  print(yellow+" _¶¶¶¶___¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶__¶¶¶¶__ ")
  print(yellow+" ___¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶___ ")
  print(yellow+" ____¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶¶¶¶¶¶¶¶¶____ ")
  print(yellow+" ______¶¶¶¶¶¶__¶¶¶¶¶¶¶¶¶¶¶¶¶¶___¶¶¶¶¶¶______ ")
  print(yellow+" _______________¶¶¶¶¶¶¶¶¶¶¶¶________________ ")
  print(yellow+" _________________¶¶¶¶¶¶¶¶__________________ ")
  print(yellow+" ___________________¶¶¶¶____________________ ")
  print(yellow+" ___________________¶¶¶¶____________________ ")
  print(yellow+" ___________________¶¶¶¶____________________ ")
  print(yellow+" _______________¶¶¶¶¶¶¶¶¶¶¶¶________________ ")
  print(yellow+" ____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶"+magenta+"  Number 1  "+yellow+"¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶"+magenta+"Store in the"+yellow+"¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶"+magenta+"    area    "+yellow+"¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________ ")
  print(yellow+" ____________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_____________ ")
  print(yellow+" __________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶___________ ")
  print(yellow+" _________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__________ ")


print(blue_back+"Day",str(day),"(You have 10 days total)"+white)
print(grey_back+"You have $"+str(totalmoney),"left"+white)
print("\n")
print(magenta+"    1.",product1,"===",str(stock1),"in stock")
print(magenta+"    2.",product2,"===",str(stock2),"in stock")
print("\n")
time.sleep(1)
print("Welcome to the store, I see you are new here...")
time.sleep(1)
print("To start, lets create a product...")
time.sleep(1)
task=input("[Press enter to continue]\n  ")
if task=="":
  product1=input("What would you like to name your first product- ")
  make1=int(input("How much will it cost to make (per thing)- "))
  price1=int(input("How much do you want to sell it for (no decimals)- "))
  if price1>999:
    print("Really...")
    time.sleep(3)
    os.system("python3 game.py")
  else:
    stock1=random.randint(10,50)
    loss1=make1*stock1
    totalmoney-=loss1
    print("You have",str(stock1),"of this product in stock")
    product2=input("What would you like to name your second product- ")
    if product1==product2:
      print("Really...")
      time.sleep(2)
      clear()
    else:
      make2=int(input("How much will it cost to make (per thing) - "))
      price2=int(input("How much do you want to sell it for (no  decimals)- "))
      stock2=random.randint(10,50)
      if price2>999:
        print("Really...")
        time.sleep(3)
        os.system("python3 game.py")
      else:
        print("You have",str(stock2),"of this product in stock")
        loss2=make2*stock2
        totalmoney-=loss2
        print("\nYour products are... "+product1,"and",product2 +".")
        input()
        clear()
else:
  os.system("python3 game.py")
while 1>0:
  if day<11 and totalmoney>0:
    print(blue_back+"Day",str(day),"(You have 10 days total)"+white)
    print(grey_back+"You have $"+str(totalmoney),"left"+white)
    print(green+"Popularity=",str(popular)+"%"+white)
    print("\n")
    print(magenta+"    1.",product1,"===",sell1,yellow+"sold last time ==="+red,str(stock1),"in stock"+white)
    print(magenta+"    2.",product2,"===",sell2,yellow+"sold last time ==="+red,str(stock2),"in stock"+white)
    print("\n")
    print(yellow+"Which would you like to do...")
    print("  1. Sell a products\n  2. Replace a product\n  3. Make an ad (You can make",str(adleft),"more)\n  4. Partner with a company\n  5. Sell company\n"+red+"  [Press enter to end the day]")
    task=input(white+"--")
    if task=="2":
      replace=int(input("Which product would you like to replace (1 for product 1, 2 for product 2)- "))
      if replace==1:
        product1=input("What would you like to name your first product- ")
        make1=int(input("How much will it cost to make (per thing)- "))
        price1=int(input("How much do you want to sell it for (no decimals)- "))
        if price1>1000:
          print("Really... that's too much")
          clear()
        else:
          stock1=random.randint(10,50)
          loss1=make1*stock1
          totalmoney-=loss1
          print("You have",str(stock1),"of this product in stock")
          time.sleep(3)
          clear()
      elif replace==2:
        product2=input("What would you like to name your second product- ")
        if product1==product2:
          print("Really...")
          time.sleep(2)
          clear()
        else:
          make2=int(input("How much will it cost to make (per thing) - "))
          price2=int(input("How much do you want to sell it for (no  decimals)- "))
          stock2=random.randint(10,50)
          if price2>1000:
            print("Really...")
            time.sleep(3)
            os.system("python3 game.py")
          else:
            print("You have",str(stock2),"of this product in stock")
            loss2=make2*stock2
            totalmoney-=loss2
            input()
            clear()
      else:
        print("Try again")
        time.sleep(3)
        clear()
    elif task=="1":
      if product1=="[Not created]":
        print("Create a product first")
        time.sleep(3)
        clear()
      else:
        if stock1<=0 or stock2<=0:
          print(red+"You have to little products, get some more by advancing a day or 2")
          input()
          clear()
        else:
          print(green+"Selling your products"+white)
          time.sleep(1.5)
          os.system("python3 sell.py")
          if popular>60:
            sell1=random.randint(75,150)
            sell2=random.randint(75,150)
            ppl=sell1+sell2
          elif popular>40 and popular<60:
            sell1=random.randint(50,100)
            sell2=random.randint(50,100)
            ppl=sell1+sell2
          elif popular>20 and popular<40:
            sell1=random.randint(25,60)
            sell2=random.randint(25,60)
            ppl=sell1+sell2
          else:
            sell1=random.randint(0,20)
            sell2=random.randint(0,20)
            ppl=sell1+sell2
          gain1=price1*sell1
          gain2=price2*sell2
          print(green+str(ppl),"people came to your store today!")
          time.sleep(1.5)
          print(magenta+"You sold",str(sell1),"of",product1,"for a total gain of $"+str(gain1),"on that product.")
          time.sleep(1.5)
          print(magenta+"You sold",str(sell2),"of",product2,"for a total gain of $"+str(gain2),"on that product.")
          totalmoney+=gain1
          totalmoney+=gain2
          time.sleep(1.5)
          popgain=random.randint(3,7)
          totalgain=gain1+gain2
          print(green+"You gained",str(popgain)+"% popularity")
          print(green+"You gained $"+str(totalgain))
          popular+=popgain
          stock1-=sell1
          stock2-=sell2
          input()
          clear()
    elif task=="3":
      if adleft<=0:
        print(red+"You can't make any more adds!")
        time.sleep(3)
        clear()
      else:
        clear()
        os.system("python3 ad.py")
        adnum=random.randint(1,3)
        if adnum==1:
          ad1()
        elif adnum==2:
          ad2()
        else:
          ad3()
        input()
        clear()
        adgain=random.randint(5,10)
        popular+=adgain
        print(green+"You gained",str(adgain)+"% popularity from your ad")
        totalmoney-=50
        adleft-=1
        input()
        clear()

    elif task=="4":
      companynames=["Store Angel","Washington Market","Madison Exchange","City Spot Sports Store","Ace Place Car Repair","Star Wars Galaxy Toy Store","LawnMarathon","Sander's BBQ","Jason and Mark Law Firm"]
      company=random.choice(companynames)
      print("You partnered with",company+", which would you like to do?")
      print("  1. Exposure event ("+green+"+popularity"+white+", "+red+"-day"+white+")")
      print("  2. Fundraising ("+green+"+$$$"+white+", "+red+"-day"+white+")")
      print("  3. QuickOrder ("+green+"+products"+white+", "+red+"-$$$ and -day"+white+")")
      partnerchoice=input("> ")
      if partnerchoice=="1":
        print("You teamed up with",company,"and held an event in a nearby part of town")
        day+=1
        teamgain=random.randint(1,20)
        time.sleep(1.5)
        print(green+"\nYou gained",str(teamgain)+"% popularity"+white)
        popular+=teamgain
        input()
        clear()
      elif partnerchoice=="2":
        print("You teamed up with",company,"and did some fundraising in the area")
        day+=1
        tdollagain=random.randint(100,2000)
        time.sleep(1.5)
        print(green+"\nYou gained $"+str(tdollagain)+white)
        totalmoney+=tdollagain
        input()
        clear()
      elif partnerchoice=="3":
        print("You teamed up with",company,"and QuickOrdered some products for both of y'all")
        stock1+=random.randint(10,30)
        stock2+=random.randint(10,30)
        loss1part=make1*stock1
        totalmoney-=loss1part
        loss2part=make2*stock2
        totalmoney-=loss2part
        totalpartloss=loss1part+loss2part
        day+=0.5
        time.sleep(1.5)
        print(green+"\nMore products were shipped")
        print(red+"\nAnd lost $"+str(totalpartloss)+white)
        input()
        clear()
      else:
        clear()
    elif task=="5":
      sure=input(red+"Are you sure you want to sell your company? (y or n)- ").lower()
      if sure=="y" or sure=="yes":
        offer1change=random.randint(500,2500)
        offer1porm=random.randint(1,2)
        if offer1porm==1:
          offer1price=totalmoney+offer1change
        else:
          offer1price=totalmoney-offer1change
        offer2change=random.randint(470,2630)
        offer2porm=random.randint(1,2)
        if offer1porm==1:
          offer2price=totalmoney+offer2change
        else:
          offer2price=totalmoney-offer2change
        print(magenta+"You got some offers...")
        print(green+"  1. $"+str(offer1price))
        print(green+"  2. $"+str(offer2price))
        print(white+"Which offer will you take?")
        offerchoice=input("-- ")
        if offerchoice=="1":
          time.sleep(1)
          clear()
          print(green+"Today, your store was sold for $"+str(offer1price)+white)
          time.sleep(2)
          print("Thank you for playing Buisness Simulator")
          time.sleep(2)
          print("Like this? Give it an upvote. Check out my profile for more awesome projects :)")
          time.sleep(4)
          clear()
          os.system("python3 credits.py")
        elif offerchoice=="2":
          time.sleep(1)
          clear()
          print(green+"Today, your store was sold for $"+str(offer2price)+white)
          time.sleep(2)
          print("Thank you for playing Buisness Simulator")
          time.sleep(2)
          time.sleep(4)
          clear()
        else:
          print("Sorry, please try again")
      else:
        clear()
    elif task=="":
      day+=1
      dayleft=11-day
      stock1+=random.randint(10,30)
      stock2+=random.randint(10,30)
      loss1=make1*stock1
      totalmoney-=loss1
      loss2=make2*stock2
      totalmoney-=loss2
      print(yellow+"Day ended,",str(dayleft),"days left")
      time.sleep(1.5)
      popgain=random.randint(1,3)
      print(green+"You gained",str(popgain)+"% popularity")
      popular+=popgain
      input()
      clear()
    else:
      print(red+"Sorry, please try again")
      input()
      clear()
  else:
    print(red+"GAME OVER. You ended with $"+str(totalmoney))
    time.sleep(3)
    totalgain=totalmoney-10000
    if totalgain>0:
      print(green+"You gained $"+str(totalgain))
    else:
      print(red+"You gained $"+str(totalgain),"(lost money)")
    time.sleep(10)
    clear()