import os, time, random
from replit import db

#NORMAL STUFF
lvl = 1
exp = 0
Gold = 200
maxHealth = 100
Class = 'Knight'
expNeeded = 125
CurrentPlace = "void"
maxPotions = 3
Potions = 3
PotionsPower = 40
PotionsPriceam = 1500
PotionsPricepo = 1400
maxPotionsAmount = 7
maxPotionsPower = 100
Boss_token = 0
Enermy = 'Nobody'
Bonus = (lvl - 1) * 0.1
BossTokenReceived = 0
Goldreceived = 0
expReceived = 0
Manapool = 500
Manacost = 50
Ability = 'none'
Current_Ability = 'none'
ManaCost2 = 200
SmallGoblinKill = 0
BigGoblinKill = 0
GoblinBossKill = 0
MonsterSkeletonKill = 0
MonsterWormKill = 0
MonsterSpiderKill = 0
MonsterTurtleKill = 0
MonsterPirahnaKill = 0
MonsterCrocKill = 0
ForestBossKill = 0
UndergroundBossKill = 0
Update1 = 0
Update2 = 0
if Ability == 'none' and Current_Ability == 'none':
  Ability_damage = 0
  Ability_heal = 0
elif Ability == Fireball and Current_Ability == Fireball:
  Ability_damage = Fireball['damage']
  Ability_heal = 0
elif Ability == LightningStrike and Current_Ability == LightningStrike:
  Ability_damage = LightningStrike['damage']
  Ability_heal = 0
elif Ability == MegaHeal and Current_Ability == MegaHeal:
  Ability_damage = 0
  Ability_heal = 400

RED = "\033[1;31m"
BLUE = "\033[1;34m"
CYAN = "\033[1;36m"
GREEN = "\033[0;32m"
RESET = "\033[0;0m"
YELLOW = "\033[1;33m"
BOLD = "\033[;1m"
REVERSE = "\033[;7m"
#NORMAL STUFF

#MANA SHOP



#AUTO SAVE
def AutoSave():
  UpdateSave1()


#ARMORY 
def Armory():
    global CurrentPlace
    global Gold
    global Current_Armor
    global leatherArmorOwn
    global ironArmorOwn
    global GoldenArmorOwn
    global DiamondArmorOwn
    global NetheriteArmorOwn
    global EmeraldArmorOwn
    CurrentPlace = "Armory"
    os.system("clear")
    Info()
    if leatherArmorOwn == True:
        print("1. Equip Leather Armor")
    elif leatherArmor['price'] > Gold:
        print(RED + "1. Buy Leather Armor (" + str(leatherArmor['price']) +
              " Gold)" + RESET)
    elif leatherArmor['price'] <= Gold:
        print(GREEN + "1. Buy Leather Armor (" + str(leatherArmor['price']) +
              " Gold)" + RESET)
    if ironArmorOwn == True:
        print("2. Equip Iron Armor")
    elif ironArmor['price'] > Gold:
        print(RED + "2. Buy Iron Armor (" + str(ironArmor['price']) +
              " Gold)" + RESET)
    elif ironArmor['price'] <= Gold:
        print(GREEN + "2. Buy Iron Armor (" + str(ironArmor['price']) +
              " Gold)" + RESET)
    if GoldenArmorOwn == True:
        print("3. Equip Golden Armor")
    elif GoldenArmor['price'] > Gold:
        print(RED + "3. Buy Golden Armor (" + str(GoldenArmor['price']) +
              " Gold)" + RESET)
    elif GoldenArmor['price'] <= Gold:
        print(GREEN + "3. Buy Golden Armor (" + str(GoldenArmor['price']) +
              " Gold)" + RESET)
    if DiamondArmorOwn == True:
        print("4. Equip Diamond Armor")
    elif DiamondArmor['price'] > Gold:
        print(RED + "4. Buy Diamond Armor (" + str(leatherArmor['price']) +
              " Gold)" + RESET)
    elif DiamondArmor['price'] <= Gold:
        print(GREEN + "4. Buy Diamond Armor (" + str(leatherArmor['price']) +
              " Gold)" + RESET)
    if NetheriteArmorOwn == True:
        print("5. Equip Netherite Armor")
    elif NetheriteArmor['price'] > Gold:
        print(RED + "5. Buy Netherite Armor (" + str(leatherArmor['price']) +
              " Gold)" + RESET)
    elif NetheriteArmor['price'] <= Gold:
        print(GREEN + "5. Buy Netherite Armor (" + str(NetheriteArmor['price']) +
              " Gold)" + RESET)
    if EmeraldArmorOwn == True:
        print("6. Equip Emerald Armor")
    elif EmeraldArmor['price'] > Gold:
        print(RED + "6. Buy Emerald Armor (" + str(EmeraldArmor['price']) +
              " Gold)" + RESET)
    elif leatherArmor['price'] <= Gold:
        print(GREEN + "6. Buy Emerald Armor (" + str(EmeraldArmor['price']) +
              " Gold)" + RESET)
    print("7. Unequip Armor")
    print("0. back")
    haha = str(input(">"))
    if haha == "1":
        if leatherArmorOwn == True:
            print("You equipied leather Armor!")
            Current_Armor = leatherArmor
            time.sleep(1)
            Armory()
        elif leatherArmor['price'] > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            Armory()
        elif leatherArmor['price'] <= Gold:
            print("You bought Leather Armor!")
            Gold -= leatherArmor['price']
            Current_Armor = leatherArmor
            leatherArmorOwn = True
            time.sleep(1)
            Armory()
    elif haha == "2":
        if ironArmorOwn == True:
            print("You equipied iron Armor")
            Current_Armor = ironArmor
            time.sleep(1)
            Armory()
        elif ironArmor['price'] > Gold:
            print("you dont have enough Gold to buy that!")
            time.sleep(1)
            Armory()
        elif ironArmor['price'] <= Gold:
            print("You bought iron Armor!")
            Current_Armor = ironArmor
            ironArmorOwn = True
            Gold -= ironArmor['price']
            time.sleep(1)
            Armory()
    elif haha == "3":
        if GoldenArmorOwn == True:
            print("you equpied Golden Armor!")
            Current_Armor = GoldenArmor
            time.sleep(1)
            Armory()
        elif GoldenArmor['price'] > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            Armory()
        elif GoldenArmor['price'] <= Gold:
            print("You bought Golden Armor!")
            Current_Armor = GoldenArmor
            GoldenArmorOwn = True
            Gold -= GoldenArmor['price']
            time.sleep(1)
            Armory()
    if haha == "4":
        if DiamondArmorOwn == True:
            print("You equipied Diamond Armor!")
            Current_Armor = DiamondArmor
            time.sleep(1)
            Armory()
        elif DiamondArmor['price'] > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            Armory()
        elif DiamondArmor['price'] <= Gold:
            print("You bought Diamond Armor!")
            Gold -= DiamondArmor['price']
            Current_Armor = DiamondArmor
            DiamondArmorOwn = True
            time.sleep(1)
            Armory()
    if haha == "5":
        if NetheriteArmorOwn == True:
            print("You equipied Netherite Armor!")
            Current_Armor = NetheriteArmor
            time.sleep(1)
            Armory()
        elif NetheriteArmor['price'] > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            Armory()
        elif NetheriteArmor['price'] <= Gold:
            print("You bought Netherite Armor!")
            Gold -= NetheriteArmor['price']
            Current_Armor = NetheriteArmor
            NetheriteArmorOwn = True
            time.sleep(1)
            Armory()
    if haha == "6":
        if EmeraldArmorOwn == True:
            print("You equipied Emerald Armor!")
            Current_Armor = EmeraldArmor
            time.sleep(1)
            Armory()
        elif EmeraldArmor['price'] > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            Armory()
        elif EmeraldArmor['price'] <= Gold:
            print("You bought Emerald Armor!")
            Gold -= EmeraldArmor['price']
            Current_Armor = EmeraldArmor
            EmeraldArmorOwn = True
            time.sleep(1)
            Armory()
    elif haha == "7":
        print("You unequiped Armor!")
        Current_Armor = noneArmor
        time.sleep(1)
        Armory()
    elif haha == "0":
        Home()
    else:
        print("you can only pick a number from the list!")
        time.sleep(1)
        Armory()

#SMALL GOBLIN
SmallGoblin = "Small Goblin"
SmallGoblin_attack = random.randint(3, 10)
SmallGoblin_Health = 40
#BIG GOBLIN
BigGoblin = "Big Goblin"
BigGoblin_attack = random.randint(5, 15)
BigGoblin_Health = 60
#Goblin Boss
GoblinBoss = "Big Goblin"
GoblinBoss_attack = random.randint(10, 20)
GoblinBoss_Health = 100
#FOREST MOBS
ForestMobs = [SmallGoblin, BigGoblin, GoblinBoss]

#MONSTER WORM
MonsterWorm = "Monster Worm"
MonsterWorm_attack = random.randint(15, 30)
MonsterWorm_Health = 120
#MONSTER SKELETON
MonsterSkeleton = "Monster Skeleton"
MonsterSkeleton_attack = random.randint(20, 30)
MonsterSkeleton_Health = 110
#Monster Spider
MonsterSpider = "Monster Spider"
MonsterSpider_attack = random.randint(25, 30)
MonsterSpider_Health = 130
#UNDERGROUND MOBS
Umobs = [MonsterWorm, MonsterSkeleton, MonsterSpider]

#MONSTER TURTLE
MonsterTurtle = "Monster Turtle"
MonsterTurtle_attack = random.randint(15, 30)
MonsterTurtle_Health = 300
#MonsterPiranha
MonsterPiranha = "Monster Piranha"
MonsterPiranha_attack = random.randint(30, 50)
MonsterPiranha_Health = 75
#MonsterCroc
MonsterCroc = "Monster Croc"
MonsterCroc_attack = random.randint(25, 40)
MonsterCroc_Health = 175
Uwater = [MonsterTurtle, MonsterPiranha, MonsterCroc]

#FOREST BOSS
MutatedOgre = "Mutated Ogre"
MutatedOgre_attack = random.randint(15, 25)
MutatedOgre_Health = 200
#FORESTBOSS AWAKENING
MutatedOgre2 = "Awakened Mutated Ogre"
MutatedOgre2_attack = random.randint(25,40)
MutatedOgre2_Health = 300

#UNDERGROUND BOSS
EnlargedSilverfish = "Enlarged Silverfish"
EnlargedSilverfish_attack = random.randint(30, 45)
EnlargedSilverfish_health = 300
#ENRAGED SILVERFISH
EnragedSilverfish = "Enraged Silverfish"
EnragedSilverfish_attack = random.randint(40, 55)
EnragedSilverfish_health = 400

#DUNGEONS
Forest = "Forest"
Underground = "UnderGround"
Underwater = "UnderWater"
#BOSS DUNGEONS
ForestBoss = "ForestBoss"
UndergroundBoss = "UndergroundBoss"









#DUNGEON
def Dungeon():
    global exp
    global CurrentPlace
    CurrentPlace = "Dungeoun"
    os.system("clear")
    Info()
    print(GREEN + "1. Forest" + RESET)
    if lvl >= 5:
        print(GREEN + "2. Underground" + RESET)
    else:
        print(RED + "2. Underground (+5 lvl)" + RESET)
    if lvl >= 5:
        print(GREEN+"3. Forest's Boss (+5 lvl)(Recommanded Full Diamond)"+RESET)
    else:
        print(RED+"3. Forest's Boss (+5 lvl)(Recommanded Full Diamond)"+RESET)
    if lvl >= 10:
        print(GREEN + "4. UnderWater" + RESET)
    else:
        print(RED + "4. UnderWater (+10 lvl)" + RESET)
    if lvl >= 10:
        print(GREEN+"5. UnderGround Boss(+10 lvl)(Recommanded Full Netherite)")
    else:
        print(RED+"5. UnderGround Boss(+10 lvl)(Recommanded Full Netherite)")
    print(RESET+"0. back")
    move = str(input(">"))
    if move == "1":
        CurrentPlace = Forest
        Fight()
    elif move == "2":
        if lvl < 5:
            print("Your level is too low!")
            time.sleep(1)
            os.system("clear")
            Dungeon()
        else:
            CurrentPlace = Underground
            Fight()
    elif move == "3":
        if lvl < 5:
            print("Your level is too low!")
            time.sleep(1)
            os.system("clear")
            Dungeon()
        else:
            CurrentPlace = ForestBoss
            Fight()
    elif move == "4":
        if lvl < 10:
            print("Your level is too low!")
            time.sleep(1)
            os.system("clear")
            Dungeon()
        else:
            CurrentPlace = Underwater
            Fight()
    elif move == "5":
        if lvl < 10:
            print("Your level is too low!")
            time.sleep(1)
            os.system("clear")
            Dungeon()
        else:
            CurrentPlace = UndergroundBoss
            Fight()
    elif move == "0":
        Home()
    else:
        print("you can pick a number from the list!")
        time.sleep(1)
        Dungeon()


def Fight():
    #getting ready to fight system (some borning stuff)
    global Enermy
    global Enermy_attack
    global Enermy_Health
    global Current_Sword_sharp
    global maxHealth
    global Health
    global Potions
    global CurrentPlace
    global Ability
    global Ability_damage
    global Ability_heal
    global Current_Ability
    global Manapool
    global lvl

    #REFRESHING STUFF
    Health = maxHealth
    maxHealth = 100 + Current_Armor['Health']
    Potions = maxPotions
    Bonus = (lvl - 1) * 0.1

    if Current_Ability == Fireball:
      Ability_damage = 150
      Ability_heal = 0
    elif Current_Ability == LightningStrike:
      Ability_damage = 200
      Ability_heal = 0
    elif Current_Ability == MegaHeal:
      Ability_damage = 0
      Ability_heal = 400
    else:
      Ability_damage = 0
      Ability_heal = 0

    if CurrentPlace == Forest:
        Enermy = random.choice(ForestMobs)
        if Enermy == BigGoblin:
            Enermy_Health = BigGoblin_Health
            Enermy_attack = BigGoblin_attack
        elif Enermy == SmallGoblin:
            Enermy_Health = SmallGoblin_Health
            Enermy_attack = SmallGoblin_attack
        elif Enermy == GoblinBoss:
            Enermy_Health = GoblinBoss_Health
            Enermy_attack = GoblinBoss_attack
    elif CurrentPlace == Underground:
        Enermy = random.choice(Umobs)
        if Enermy == MonsterSkeleton:
            Enermy_Health = MonsterSkeleton_Health
            Enermy_attack = MonsterSkeleton_attack
        elif Enermy == MonsterWorm:
            Enermy_attack = MonsterWorm_attack
            Enermy_Health = MonsterWorm_Health
        elif Enermy == MonsterSpider:
            Enermy_attack = MonsterSpider_attack
            Enermy_Health = MonsterSpider_Health
        if Ability == none:
          Ability_damage = none['damage']
        elif Ability == Fireball:
          Ability_damage = Fireball['damage']
        elif Ability == LightningStrike:
          Ability_damage = LightningStrike['damage']
        elif Ability == MegaHeal:
          Ability_damage = 0
        elif Ability == none:
          Ability_heal += 0
        elif Ability == Fireball:
          Ability_heal += 0
        elif Ability == LightningStrike:
          Ability_heal += 0
        elif Ability == MegaHeal:
          Ability_heal = MegaHeal['heal']
    if CurrentPlace == Underwater:
        Enermy = random.choice(Uwater)
        if Enermy == MonsterTurtle:
            Enermy_Health = MonsterTurtle_Health
            Enermy_attack = MonsterTurtle_attack
        elif Enermy == MonsterPiranha:
            Enermy_Health = MonsterPiranha_Health
            Enermy_attack = MonsterPiranha_attack
        elif Enermy == MonsterCroc:
            Enermy_Health = MonsterCroc_Health
            Enermy_attack = MonsterCroc_attack
    if CurrentPlace == ForestBoss:
        Enermy = MutatedOgre
        Enermy_Health = MutatedOgre_Health
        Enermy_attack = MutatedOgre_attack
    if CurrentPlace == UndergroundBoss:
        Enermy = EnlargedSilverfish
        Enermy_Health = 300
        Enermy_attack = random.randint(30, 45)
    if Current_Sword == Wooden_Sword:
        Current_Sword_sharp = random.randint(5,11)
    if Current_Sword == Stone_Sword:
        Current_Sword_sharp = random.randint(10,16)
    if Current_Sword == Golden_Sword:
        Current_Sword_sharp = random.randint(15,21)
    if Current_Sword == Iron_Sword:
        Current_Sword_sharp = random.randint(20,26)
    if Current_Sword == Diamond_Sword:
        Current_Sword_sharp = random.randint(25,31)
    if Current_Sword == Netherite_Sword:
        Current_Sword_sharp = random.randint(30,36)
    if Current_Sword == Emerald_Sword:
        Current_Sword_sharp = random.randint(40,46)
    if Ability == none:
        Ability_damage += 0
    elif Ability == Fireball:
        Ability_damage += 150
    elif Ability == LightningStrike:
        Ability_damage += 200
    elif Ability == MegaHeal:
        Ability_damage += 0
    elif Ability == none:
        Ability_heal += 0
    elif Ability == Fireball:
        Ability_heal += 0
    elif Ability == LightningStrike:
        Ability_heal += 0
    elif Ability == MegaHeal:
        Ability_heal += 400
    if Class == "Knight":
      Current_Sword_sharp *= 1.1
    elif Class == "Mage":
      Ability_damage += 25
      Ability_heal += 25
    elif Class == "Tank":
      Health += 20

    os.system("clear")
    FInfo()
    Fsys()

#Class selection
def ClassSelection():
  global Class
  global CurrentPlace
  os.system("clear")
  CurrentPlace = "Class Selection"
  Info()
  print(GREEN+"1. Knight (+5 DMG PER HIT)"+RESET)
  print(GREEN+"2. Mage (+25 Ability Power PER USE)"+RESET)
  print(GREEN+"3. Tank (+20 Health)"+RESET)
  print("0. Back")
  lmfao = str(input(">"))
  if lmfao == "1":
      Class = "Knight"
      ClassSelection()
  elif lmfao == "2":
      Class = "Mage"
      ClassSelection()
  elif lmfao == "3":
      Class = "Tank"
      ClassSelection()
  elif lmfao == "0":
      Home()
  else:
    print("Please Select a option number")

def IsDead():
  global Enermy
  global Enermy_Health
  if Enermy == MutatedOgre:
    if Enermy_Health <= 0:
      print("OH! YOU THINK U CAN DEFEAT ME? Press Any option u like...")
      Enermy = MutatedOgre2
      Enermy_Health = 0
      Enermy_Health = 300
      Fsys()
    if Health <= 0:
      ForestLose()
  if Enermy == EnlargedSilverfish:
    if Enermy_Health <= 0:
      print("WHAT? I CAN'T BE DEFEATED!!!!!!!U HAVE ENRAGED ME")
      Enermy = EnragedSilverfish
      Enermy_Health = 0
      Enermy_Health = 400
      Fsys()
    if Health <= 0:
      ForestLose()
  elif Enermy != MutatedOgre and Enermy != EnlargedSilverfish:
    if Enermy_Health <= 0 and Health <= 0:
        ForestDraw()
    if Enermy_Health <= 0:
        ForestWin()
    if Health <= 0:
        ForestLose()


def ForestLose():
    global Gold
    global exp
    Gold += random.randint(10, 30)
    exp += random.randint(10, 60)
    print("you noob lose")
    input("yes >")
    Home()


def ForestWin():
    global Gold
    global exp
    global Enermy
    global Boss_token
    global BossTokenReceived
    global Goldreceived
    global expReceived
    global SmallGoblinKill
    global BigGoblinKill
    global GoblinBossKill
    global MonsterSkeletonKill
    global MonsterWormKill
    global MonsterSpiderKill
    global MonsterTurtleKill
    global MonsterPirahnaKill
    global MonsterCrocKill
    global ForestBossKill
    global UndergroundBossKill
    print("You won!")
    if Enermy == SmallGoblin:
        expReceived = random.randint(250, 500)
        Goldreceived = random.randint(100, 250)
        SmallGoblinKill += 1
        QuestFinish()
    elif Enermy == BigGoblin:
        expReceived = random.randint(350, 600)
        Goldreceived = random.randint(250, 400)
        BigGoblinKill += 1
        QuestFinish()
    elif Enermy == GoblinBoss:
        expReceived = random.randint(450, 700)
        Goldreceived = random.randint(400, 550)
        GoblinBossKill += 1
        QuestFinish()
    elif Enermy == MonsterSkeleton:
        expReceived = random.randint(550, 800)
        Goldreceived = random.randint(550, 700)
        MonsterSkeletonKill += 1
        QuestFinish()
    elif Enermy == MonsterWorm:
        expReceived = random.randint(650, 900)
        Goldreceived = random.randint(700, 850)
        MonsterWormKill += 1
        QuestFinish()
    elif Enermy == MonsterSpider:
        expReceived = random.randint(750, 1000)
        Goldreceived = random.randint(850, 1000)
        MonsterSpiderKill += 1
        QuestFinish()
    elif Enermy == MonsterTurtle:
        expReceived = random.randint(850, 1100)
        Goldreceived = random.randint(1000, 1150)
        MonsterTurtleKill += 1
        QuestFinish()
    elif Enermy == MonsterPiranha:
        expReceived = random.randint(950, 1200)
        Goldreceived = random.randint(1150, 1300)
        MonsterPirahnaKill += 1
        QuestFinish()
    elif Enermy == MonsterCroc:
        expReceived = random.randint(1050, 1300)
        Goldreceived = random.randint(1300, 1450)
        MonsterCrocKill += 1
        QuestFinish()
    elif Enermy == MutatedOgre2:
        expReceived = random.randint(1150, 1400)
        BossTokenReceived = random.randint(1, 20)
        Boss_token += BossTokenReceived
        ForestBossKill += 1
        QuestFinish()
    elif Enermy == EnragedSilverfish:
        expReceived = random.randint(1250, 1500)
        BossTokenReceived = random.randint(5, 25)
        Boss_token += BossTokenReceived
        UndergroundBossKill += 1
        QuestFinish()
    exp += expReceived
    Gold += Goldreceived
    if Enermy != MutatedOgre2 and Enermy != EnragedSilverfish:
      print("You received " + str(Goldreceived) + " Gold and " + str(expReceived) + " exp !")
      input("Click Enter To Continue >")
    else:
      print("You received " + str(BossTokenReceived) + " Boss Tokens and " + str(expReceived) + " exp!")
      input("Click Enter To Continue >")
    Home()


def ForestDraw():
    global Gold
    print("HOW DID YOU DRAW THIS LOOOL")
    print("FOR THIS YOU RECIVE INFINITE GOLD")
    Gold += 100000000000
    input("Click Enter To Continue >")
    Home()


#FIGHT SYSTEM
def Fsys():
    global Enermy_Health
    global Wooden_Sword_sharp
    global Stone_Sword_sharp
    global Golden_Sword_sharp
    global Iron_Sword_sharp
    global Diamond_Sword_sharp
    global Netherite_Sword_sharp
    global Emerald_Sword_sharp
    global Current_Sword_sharp
    global Potions
    global Health
    global Current_Armor
    global Boss_token
    global Ability
    global Current_Ability
    global Manapool
    global Ability_damage
    global Ability_heal
    global Health
    global maxHealth
    maxHealth = 100 + Current_Armor['Health']

    print("1. Attack")
    print("2. Use Potion")
    print("3. Use Ability")
    print("4. Wait")
    print("5. Give Up")
    de = str(input(">"))
    if de == "1":
        #SWORD SHARP REFRESHING
        Wooden_Sword_sharp = random.randint(5, 11)
        Stone_Sword_sharp = random.randint(10, 16)
        Golden_Sword_sharp = random.randint(15, 21)
        Iron_Sword_sharp = random.randint(20, 26)
        Diamond_Sword_sharp = random.randint(25, 31)
        Netherite_Sword_sharp = random.randint(30, 36)
        Emerald_Sword_sharp = random.randint(40, 46)
        if Current_Sword == Wooden_Sword:
            Current_Sword_sharp = Current_Sword_sharp
        if Current_Sword == Stone_Sword:
            Current_Sword_sharp = Stone_Sword_sharp
        if Current_Sword == Golden_Sword:
            Current_Sword_sharp = Golden_Sword_sharp
        if Current_Sword == Iron_Sword:
            Current_Sword_sharp = Iron_Sword_sharp
        if Current_Sword == Diamond_Sword:
            Current_Sword_sharp = Diamond_Sword_sharp
        if Current_Sword == Netherite_Sword:
            Current_Sword_sharp = Netherite_Sword_sharp
        if Current_Sword == Emerald_Sword:
            Current_Sword_sharp = Emerald_Sword_sharp
        Current_Sword_sharp = Current_Sword_sharp * (1 + Bonus)
        if Class == "Knight":
            Current_Sword_sharp += 5
            round(Current_Sword_sharp)
        elif Class == "Mage":
            Ability_damage += 25
            Ability_heal += 25

        elif Class == "Tank":
            Health += 20
        Enermy_Health -= Current_Sword_sharp
        os.system("clear")
        FInfo()
        print("You attacked Enermy with " + str(Current_Sword_sharp) +
              " damage!")
        time.sleep(2)
        os.system("clear")
        FInfo()
        IsDead()
    elif de == "2":
        if Health == maxHealth:
            print("You cant Use Potion Now!")
            time.sleep(1)
            os.system("clear")
            FInfo()
            Fsys()
        elif Potions == 0:
            print("You dont have more potions!")
            time.sleep(1)
            os.system("clear")
            FInfo()
            Fsys()
        else:
            Potions -= 1
            if Health >= maxHealth - PotionsPower:
                Health = maxHealth
            else:
                Health += PotionsPower
            os.system("clear")
            FInfo()
            print("You used Health Potion!")
            time.sleep(1.5)
    elif de == "3":
        if Manapool >= 50:
            if Current_Ability == MegaHeal or Ability == MegaHeal:
                Health = Health + Ability_heal
                Manapool = Manapool - 50
                os.system("clear")
                FInfo()
                print("You Healed Yourself For " + str(Ability_heal) + " Damage!")
                time.sleep(1.5)
                IsDead()      
            elif Current_Ability != MegaHeal or Ability != MegaHeal:
                Enermy_Health = Enermy_Health - Ability_damage
                Manapool -= 50
                os.system("clear")
                FInfo()
                print("You Damaged Enermy for " + str(Ability_damage) + " Damage!")
                time.sleep(1.5)
                IsDead()
        else:
            os.system("clear")
            FInfo()
            print("You do not have enough Mana to do this.")
            time.sleep(1.5)
    elif de == "4":
        os.system("clear")
        FInfo()
        print("You are waiting for Enermy's move!")
        time.sleep(2)
        os.system("clear")
        FInfo()
    elif de == "5":
        print("You gived up!")
        ForestLose()
    else:
        print("You can only pick a number from the list!")
        time.sleep(1)
        os.system("clear")
        FInfo()
        Fsys()
    print("Wait for Enermy move..")
    time.sleep(1)
    os.system("clear")
    FInfo()
    Enermyturn()
    Fsys()


def Enermyturn():
    global Health
    global Enermy_attack
    global Enermy
    #changing enemys attack dmg lol
    if Enermy == SmallGoblin:
        Enermy_attack = random.randint(3, 10)
    if Enermy == BigGoblin:
        Enermy_attack = random.randint(5, 15)
    if Enermy == GoblinBoss:
        Enermy_attack = random.randint(10, 20)
    if Enermy == MonsterSkeleton:
        Enermy_attack = random.randint(15, 25)
    if Enermy == MonsterWorm:
        Enermy_attack = random.randint(20, 30)
    if Enermy == MonsterSpider:
        Enermy_attack = random.randint(25, 35)
    if Enermy == MonsterTurtle:
        Enermy_attack = random.randint(15, 30)
    if Enermy == MonsterPiranha:
        Enermy_attack = random.randint(30, 50)
    if Enermy == MonsterCroc:
        Enermy_attack = random.randint(25, 40)
    if Enermy == MutatedOgre:
        Enermy_attack = random.randint(15, 25)
    if Enermy == MutatedOgre2:
        Enermy_attack = random.randint(25, 35)
    if Enermy == EnlargedSilverfish:
        Enermy_attack = EnlargedSilverfish_attack
    if Enermy == EnragedSilverfish:
        Enermy_attack = EnragedSilverfish_attack
    Health -= Enermy_attack
    os.system("clear")
    FInfo()
    print("Enermy attacked You with " + str(Enermy_attack) + " damage!")
    time.sleep(1)
    IsDead()


def Home():
    #TODO:
    # Load And Save functions the game in replit DataBase
    global CurrentPlace
    CurrentPlace = "Home"
    os.system("clear")
    Info()
    print("1. Enter the Dungeon")
    print("2. Go to Shop")
    print("3. Go to Armory")
    print("4. Buy Abilities")
    print("5. Buy more Mana")
    print("6. Change Class")
    print("7. Check Quest")
    print("8. Load Game")
    print("9. Save Game")
    Move = str(input(">"))
    if Move == "1":
        Dungeon()
    elif Move == "2":
        Shop()
    elif Move == "3":
        Armory()
    elif Move == "4":
        AbilityShop()
    elif Move == "5":
        ManaShop()
    elif Move == "6":
        ClassSelection()
    elif Move == "7":
        Quest()
    elif Move == "8":
        Load()
    elif Move == "9":
        Save()
    else:
        print("You can pick a number from the list!")
        time.sleep(1)
        Home()

Quest1 = {
  'reward': 250,
  'name': 'Kill 1 Small Goblin'
}
Quest1Done = False
Quest2 = {
  'reward': 300,
  'name': 'Kill 1 Big Goblin'
}
Quest2Done = False
Quest3 = {
  'reward': 350,
  'name': 'Kill 1 Goblin Boss'
}
Quest3Done = False
Quest4 = {
  'reward': 500,
  'name': 'Get level 5'
}
Quest4Done = False
Quest5 = {
  'reward': 550,
  'name': 'Kill 10 Small Goblins'
}
Quest5Done = False
Quest6 = {
  'reward': 750,
  'name': 'Kill 10 Big Goblins'
}
Quest6Done = False
Quest7 = {
  'reward': 1000,
  'name': 'Kill 10 Goblin Boss'
}
Quest7Done = False
Quest8 = {
  'reward': 1250,
  'name': 'Kill 1 Monster Skeleton'
}
Quest8Done = False
Quest9 = {
  'reward': 1500,
  'name': 'Kill 1 Monster Worm'
}
Quest9Done = False
Quest10 = {
  'reward': 1750,
  'name': 'Kill 1 Monster Spider'
}
Quest10Done = False
Quest11 = {
  'reward': 2000,
  'name': 'Get lvl 10'
}
Quest11Done = False
Quest12 = {
  'reward': 20,
  'name': 'Kill Mutated Ogre Once'
}
Quest12Done = False
Quest13 = {
  'reward': 40,
  'name': 'Kill Enlarged SilverFish Once'
}
Quest13Done = False
AllQuestDone = False
#Quest
def Quest():
  os.system("clear")
  Info()
  QuestFinish()
  print('All Quest Will Automatically be Claimed.')
  if Quest1Done == False:
    print(Quest1['name'])
    print("0. Back")
  elif Quest2Done == False:
    print(Quest2['name'])
    print("0. Back")
  elif Quest3Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest4Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest5Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest6Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest7Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest8Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest9Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest10Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest11Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest12Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif Quest13Done == False:
    print(Quest3['name'])
    print("0. Back")
  elif AllQuestDone == True:
    print("All Quest Have Been Finished, Come Back Later.")
    print("0. Back")
  else:
    print("0. Back")
  quest = str(input(">"))
  if quest == "0":
    os.system('clear')
    Home()
  else:
    print("Please only click 0.")
    time.sleep(1)
    Home()


#MANA SHOP
def ManaShop():
  global CurrentPlace
  global Manapool
  global Boss_token
  global ManaCost2
  global Gold
  CurrentPlace = "ManaShop"
  os.system("clear")
  Info()
  if ManaCost2 > Gold:
      print(RED + "1. Increase Mana per Fight by 10 (" + str(ManaCost2) + " Gold)" + RESET)
  elif ManaCost2 <= Gold:
      print(GREEN + "1. Increase Mana per Fight by 10 (" + str(ManaCost2) + " Gold)" + RESET)
  print("0. Back")
  lmao = str(input(">"))
  if lmao == "1":
      if ManaCost2 <= Gold:
            print("You bought +10 Mana!")
            Manapool += 10
            Gold -= ManaCost2
            time.sleep(1)
            ManaShop()
      elif ManaCost2 > Gold:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            ManaShop()
  elif lmao == "0":
      Home()
  else:
      print("You can pick a number from the list.")
      time.sleep(1.5)
      os.system("clear")
      ManaShop()


def Uptade():
    global lvl
    global exp
    global expNeeded
    while exp > expNeeded:
        exp = exp - expNeeded
        expNeeded = int(expNeeded * 1.5)
        lvl += 1

#ITEMS
Wooden_Sword = "Wooden sword"
Wnooden_Sword_sharp = 5
Stone_Sword = BOLD + "Stone sword" + RESET
Stone_Sword_sharp = 10
StoneSwordOwn = False
Golden_Sword = YELLOW + "Golden Sword" + RESET
Golden_Sword_sharp = 15
GoldenSwordOwn = False
Iron_Sword = BOLD + "Iron Sword" + RESET
Iron_Sword_sharp = 20
IronSwordOwn = False
Diamond_Sword = BLUE + "Diamond Sword" + RESET
Diamond_Sword_sharp = 25
DiamondSwordOwn = False
Netherite_Sword = RED+"Netherite Sword"+RESET
Netherite_Sword_sharp = 30
NetheriteSwordOwn = False
Emerald_Sword = GREEN+"Emerald Sword"+RESET
Emerald_Sword_sharp = 40
EmeraldSwordOwn = False
Current_Sword = Wooden_Sword

noneArmor = {'Health': 0, 'name': 'none'}
leatherArmor = {'Health': 20, 'name': 'Leather Armor', 'price': 1300}
leatherArmorOwn = False
ironArmor = {'Health': 50, 'name': BOLD + 'Iron Armor' + RESET, 'price': 2300}
ironArmorOwn = False
GoldenArmor = {
    'Health': 100,
    'name': YELLOW + 'Golden Armor' + RESET,
    'price': 5500
}
GoldenArmorOwn = False
DiamondArmor = {
    'Health': 200,
    'name': BLUE + 'Diamond Armor' + RESET,
    'price': 15000
}
DiamondArmorOwn = False
NetheriteArmor = {
    'Health': 350,
    'name': RED+"Netherite Armor"+RESET,
    'price': 30000
}
NetheriteArmorOwn = False
EmeraldArmor = {
  'Health': 500,
  'name': GREEN+"Emerald Armor"+RESET,
  'price': 50000
}
EmeraldArmorOwn = False
Current_Armor = noneArmor

none = {
  'damage': 0,
  'Manacost': 50,
  'Name': 'None',
  'cost': 0
}
noneOwn = True
Fireball = {
  'damage': 150,
  'Name': 'FireBall',
  'Manacost': 50,
  'cost': 35
}
FireballOwn = False
LightningStrike = { 
  'damage': 200,
  'Name': 'Lightning Strike',
  'Manacost': 50,
  'cost': 70
}
LightningStrikeOwn = False
MegaHeal = {
  'heal': 400,
  'Name': 'Mega Heal',
  'Manacost': 50,
  'cost': 120
}
MegaHealOwn = False

#NORMAL INFO
def Info():
    Uptade()
    global Ability
    global Current_Ability
    if Ability == none or Current_Ability == none:
      Current_Ability = 'None'
    elif Ability == Fireball:
      Current_Ability = 'FireBall'
    elif Ability == LightningStrike:
      Current_Ability = 'Lightning Strike'
    elif Ability == MegaHeal:
      Current_Ability = 'Mega Heal'
    print(BLUE + CurrentPlace + RESET)
    print("-----------------")
    print(CYAN + "exp: " + str(exp) + "/" + str(expNeeded) + RESET)
    print(BLUE + "lvl: " + str(lvl) + RESET)
    print(YELLOW + "Gold: " + str(Gold) + RESET)
    print("Weapon: " + Current_Sword)
    print("Armor: " + Current_Armor['name'])
    print("Class: " + str(Class))
    print("Mana: " + str(Manapool) + RESET)
    print("Boss tokens: " + str(Boss_token) + RESET)
    if Current_Ability == none:
        print("Ability: None ")
    if Current_Ability == Fireball:
        print("Ability: Fireball")
    if Current_Ability == LightningStrike:
        print("Ability: Lightning Strike")
    if Current_Ability == MegaHeal:
        print("Ability: MegaHeal")
    print("Potions: " + str(maxPotions))
    print("Potions Power: " + str(PotionsPower))
    print("-----------------\n\n")


#INFO IN FIGHT
def FInfo():
    Uptade()
    global Current_Ability
    global Ability
    print("-----------------")
    print(BLUE + Enermy + RESET)
    print(RED + str(Enermy_Health) + " HP" + RESET)
    print("-----------------")
    print(BLUE + "YOU" + RESET)
    print(RED + str(Health) + " HP" + RESET)
    print("Weapon: " + Current_Sword)
    print("Class: " + str(Class))
    print("Armor: " + Current_Armor['name'])
    print("Mana: " + str(Manapool) )
    if Current_Ability == none:
        print("Ability: None ")
    if Current_Ability == Fireball:
        print("Ability: Fireball")
    if Current_Ability == LightningStrike:
        print("Ability: Lightning Strike")
    if Current_Ability == MegaHeal:
        print("Ability: MegaHeal")
    print("Potions: " + str(Potions))
    print("Potions Power: " + str(PotionsPower))
    print("-----------------\n\n")


#ITEMS
def Load():
    global Gold
    global lvl
    global exp
    global expNeeded
    global maxPotions
    global PotionsPower
    global PotionsPriceam
    global PotionsPricepo
    global Current_Sword
    global Current_Armor
    global StoneSwordOwn
    global GoldenSwordOwn
    global leatherArmorOwn
    global ironArmorOwn
    global GoldenArmorOwn
    global IronSwordOwn
    global DiamondSwordOwn
    global DiamondArmorOwn
    global NetheriteArmorOwn
    global EmeraldArmorOwn
    global NetheriteSwordOwn
    global EmeraldSwordOwn
    global Boss_token
    global Manapool
    global Ability
    global Current_Ability
    global Ability_damage
    global Ability_heal
    global SmallGoblinKill
    global BigGoblinKill
    global GoblinBossKill
    global MonsterSkeleton
    global MonsterWormKill
    global MonsterSpiderKill
    global MonsterTurtleKill
    global MonsterPirahnaKill
    global MonsterCrocKill
    global ForestBossKill
    global UndergroundBossKill
    global Quest1Done
    global Quest2Done
    global Quest3Done
    global Quest4Done
    global Quest5Done
    global Quest6Done
    global Quest7Done
    global Quest8Done
    global Quest9Done
    global Quest10Done
    global Quest11Done
    global Quest12Done
    global Quest13Done
    SmallGoblinKill = db['SmallGoblinKill']
    BigGoblinKill = db['BigGoblinKill']
    GoblinBossKill = db['GoblinBossKill']
    MonsterSkeletonKill = db['MonsterSkeletonKill']
    MonsterWormKill = db['MonsterWormKill']
    MonsterSpiderKill = db['MonsterSpiderKill']
    MonsterTurtleKill = db['MonsterTurtleKill']
    MonsterPirahnaKill = db['MonsterPirahnaKill']
    MonsterCrocKill = db['MonsterCrocKill']
    ForestBossKill = db['ForestBossKill']
    UndergroundBossKill = db['UndergroundBossKill']
    Quest1Done = db['Quest1Done']
    Quest2Done = db['Quest2Done']
    Quest3Done = db['Quest3Done']
    Quest4Done = db['Quest4Done']
    Quest5Done = db['Quest5Done']
    Quest6Done = db['Quest6Done']
    Quest7Done = db['Quest7Done']
    Quest8Done = db['Quest8Done']
    Quest9Done = db['Quest9Done']
    Quest10Done = db['Quest10Done']
    Quest11Done = db['Quest11Done']
    Quest12Done = db['Quest12Done']
    Quest13Done = db['Quest13Done']
    Gold = db["Gold"]
    lvl = db["lvl"]
    exp = db["exp"]
    expNeeded = db["expNeeded"]
    maxPotions = db["maxPotions"]
    PotionsPower = db["PotionsPower"]
    PotionsPriceam = db["PotionsPriceam"]
    PotionsPricepo = db["PotionsPricepo"]
    Current_Sword = db["Current_Sword"]
    Current_Armor = db["Current_Armor"]
    StoneSwordOwn = db["StoneSwordOwn"]
    GoldenSwordOwn = db["GoldenSwordOwn"]
    leatherArmorOwn = db["leatherArmorOwn"]
    ironArmorOwn = db["ironArmorOwn"]
    GoldenArmorOwn = db["GoldenArmorOwn"]
    IronSwordOwn = db["IronSwordOwn"]
    DiamondSwordOwn = db["DiamondSwordOwn"]
    DiamondArmorOwn = db["DiamondArmorOwn"]
    NetheriteSwordOwn = db["NetheriteSwordOwn"]
    EmeraldSwordOwn = db["EmeraldSwordOwn"]
    NetheriteArmorOwn = db["NetheriteArmorOwn"]
    EmeraldArmorOwn = db["EmeraldArmorOwn"]
    Boss_token = db["Boss_token"]
    Manapool = db["Manapool"]
    Ability = db["Ability"]
    Ability_damage = db["Ability_damage"]
    Ability_heal = db["Ability_heal"]
    print(GREEN + "Game has been loaded!" + RESET)
    time.sleep(1)
    Home()


def Save():
    global Gold
    global lvl
    global exp
    global expNeeded
    global maxPotions
    global PotionsPower
    global PotionsPriceam
    global PotionsPricepo
    global Current_Sword
    global Current_Armor
    global StoneSwordOwn
    global GoldenSwordOwn
    global leatherArmorOwn
    global ironArmorOwn
    global GoldenArmorOwn
    global IronSwordOwn
    global DiamondSwordOwn
    global DiamondArmorOwn
    global NetheriteArmorOwn
    global EmeraldArmorOwn
    global NetheriteSwordOwn
    global EmeraldSwordOwn
    global Boss_token
    global Manapool
    global Ability
    global Current_Ability
    global Ability_damage
    global Ability_heal
    global SmallGoblinKill
    global BigGoblinKill
    global GoblinBossKill
    global MonsterSkeleton
    global MonsterWormKill
    global MonsterSpiderKill
    global MonsterTurtleKill
    global MonsterPirahnaKill
    global MonsterCrocKill
    global ForestBossKill
    global UndergroundBossKill
    global Quest1Done
    global Quest2Done
    global Quest3Done
    global Quest4Done
    global Quest5Done
    global Quest6Done
    global Quest7Done
    global Quest8Done
    global Quest9Done
    global Quest10Done
    global Quest11Done
    global Quest12Done
    global Quest13Done
    db['SmallGoblinKill'] = SmallGoblinKill
    db['BigGoblinKill'] = SmallGoblinKill
    db['GoblinBossKill'] = SmallGoblinKill
    db['MonsterSkeletonKill'] = SmallGoblinKill
    db['MonsterWormKill'] = MonsterWormKill
    db['MonsterSpiderKill'] = MonsterSpiderKill
    db['MonsterTurtleKill'] = MonsterTurtleKill
    db['MonsterPirahnaKill'] = MonsterPirahnaKill
    db['MonsterCrocKill'] = MonsterCrocKill
    db['ForestBossKill'] = ForestBossKill
    db['UndergroundBossKill'] = UndergroundBossKill
    db['Quest1Done'] = Quest1Done
    db['Quest2Done'] = Quest2Done
    db['Quest3Done'] = Quest3Done
    db['Quest4Done'] = Quest4Done
    db['Quest5Done'] = Quest5Done
    db['Quest6Done'] = Quest6Done
    db['Quest7Done'] = Quest7Done
    db['Quest8Done'] = Quest8Done
    db['Quest9Done'] = Quest9Done
    db['Quest10Done'] = Quest10Done
    db['Quest11Done'] = Quest11Done
    db['Quest12Done'] = Quest12Done
    db['Quest13Done'] = Quest13Done
    db["Gold"] = Gold
    db["lvl"] = lvl
    db["exp"] = exp
    db["expNeeded"] = expNeeded
    db["maxPotions"] = maxPotions
    db["PotionsPower"] = PotionsPower
    db["PotionsPriceam"] = PotionsPriceam
    db["PotionsPricepo"] = PotionsPricepo
    db["Current_Sword"] = Current_Sword
    db["Current_Armor"] = Current_Armor
    db["StoneSwordOwn"] = StoneSwordOwn
    db["GoldenSwordOwn"] = GoldenSwordOwn
    db["leatherArmorOwn"] = leatherArmorOwn
    db["ironArmorOwn"] = ironArmorOwn
    db["GoldenArmorOwn"] = GoldenArmorOwn
    db["IronSwordOwn"] = IronSwordOwn
    db["DiamondSwordOwn"] = DiamondSwordOwn
    db["DiamondArmorOwn"] = DiamondArmorOwn
    db["NetheriteArmorOwn"] = NetheriteArmorOwn
    db["EmeraldArmorOwn"] = EmeraldArmorOwn
    db["NetheriteSwordOwn"] = NetheriteSwordOwn
    db["EmeraldSwordOwn"] = EmeraldSwordOwn
    db["Boss_token"] = Boss_token
    db["Manapool"] = Manapool 
    db["Ability"] = Ability
    db["Ability_damage"] = Ability_damage
    db["Ability_heal"] = Ability_heal
    print(GREEN + "Game has been saved!" + RESET)
    time.sleep(1)
    Home()

#SLIENT SAVE
def UpdateSave1():
    global Class
    global Update1
    db["Class"] = Class
    if db["Update1"] >= 1:
      UpdateSave2()
      Start()
    else:
      global SmallGoblinKill
      global BigGoblinKill
      global GoblinBossKill
      global MonsterSkeleton
      global MonsterWormKill
      global MonsterSpiderKill
      global MonsterTurtleKill
      global MonsterPirahnaKill
      global MonsterCrocKill
      global ForestBossKill
      global UndergroundBossKill
      global Quest1Done
      global Quest2Done
      global Quest3Done
      global Quest4Done
      global Quest5Done
      global Quest6Done
      global Quest7Done
      global Quest8Done
      global Quest9Done
      global Quest10Done
      global Quest11Done
      global Quest12Done
      global Quest13Done
      global AllQuestDone
      db['SmallGoblinKill'] = SmallGoblinKill
      db['BigGoblinKill'] = BigGoblinKill
      db['GoblinBossKill'] = GoblinBossKill
      db['MonsterSkeletonKill'] = MonsterSkeletonKill
      db['MonsterWormKill'] = MonsterWormKill
      db['MonsterSpiderKill'] = MonsterSpiderKill
      db['MonsterTurtleKill'] = MonsterTurtleKill
      db['MonsterPirahnaKill'] = MonsterPirahnaKill
      db['MonsterCrocKill'] = MonsterCrocKill
      db['ForestBossKill'] = ForestBossKill
      db['UndergroundBossKill'] = UndergroundBossKill
      db['Quest1Done'] = Quest1Done
      db['Quest2Done'] = Quest2Done
      db['Quest3Done'] = Quest3Done
      db['Quest4Done'] = Quest4Done
      db['Quest5Done'] = Quest5Done
      db['Quest6Done'] = Quest6Done
      db['Quest7Done'] = Quest7Done
      db['Quest8Done'] = Quest8Done
      db['Quest9Done'] = Quest9Done
      db['Quest10Done'] = Quest10Done
      db['Quest11Done'] = Quest11Done
      db['Quest12Done'] = Quest12Done
      db['Quest13Done'] = Quest13Done
      db['Update1'] += 1
      db['AllQuestDone'] = AllQuestDone
      UpdateSave2()
      Start()
    
def UpdateSave2():
    if db['Update2'] > 1:
      Start()
    else:
      global FireballOwn
      global LightningStrikeOwn
      global MegaHealOwn
      db['FireballOwn'] = FireballOwn
      db['LightningStrikeOwn'] = LightningStrikeOwn
      db['MegaHealOwn'] = MegaHealOwn
      db['Update2'] += 1
      Start()

#QUESTFINISHEDSYSTEM
def QuestFinish():
  global Quest1Done
  global Quest2Done
  global Quest3Done
  global Quest4Done
  global Quest5Done
  global Quest6Done
  global Quest7Done
  global Quest8Done
  global Quest9Done
  global Quest10Done
  global Quest11Done
  global Quest12Done
  global Quest13Done
  global SmallGoblinKill
  global BigGoblinKill
  global GoblinBossKill
  global MonsterSkeletonKill
  global MonsterWormKill
  global MonsterSpiderKill
  global MonsterTurtleKill
  global MonsterPirahnaKill
  global MonsterCrocKill
  global ForestBossKill
  global UndergroundBossKill
  global Gold
  global Boss_token
  global lvl
  if Quest1Done == False:
    if SmallGoblinKill >= 1:
      Gold += 250
      Quest1Done = True
  elif Quest2Done == False:
    if BigGoblinKill >= 1:
      Gold += 300
      Quest2Done = True
  elif Quest3Done == False:
    if GoblinBossKill >= 1:
      Gold += 350
      Quest3Done = True
  elif Quest4Done == False:
    if lvl >= 5:
      Gold += 500
      Quest4Done
  elif Quest5Done == False:
    if MonsterSkeletonKill >= 1:
      Gold += 550
      Quest5Done
  elif Quest6Done == False:
    if MonsterWormKill >= 1:
      Gold += 750
      Quest6Done = True
  elif Quest7Done == False:
    if MonsterSpiderKill >= 1:
      Gold += 1000
      Quest7Done = True
  elif Quest8Done == False:
    if lvl >= 10:
      Gold += 1250
      Quest8Done = True
  elif Quest9Done == False:
    if MonsterTurtleKill >= 1:
      Gold += 1500
      Quest9Done = True
  elif Quest10Done == False:
    if MonsterPirahnaKill >= 1:
      Gold += 1750
      Quest10Done = True
  elif Quest11Done == False:
    if MonsterCrocKill >= 1:
      Gold += 2000
      Quest11Done = True
  elif Quest12Done == False:
    if ForestBossKill >= 1:
      Boss_token += 20
      Quest12Done == True
  elif Quest13Done == False:
    if UndergroundBossKill >= 1:
      Boss_token += 50
      Quest13Done = True
  else:
    AllQuestDone = True


#SHOP
def Shop():
    global CurrentPlace
    CurrentPlace = "Shop"
    os.system("clear")
    Info()
    print("1. Swords")
    print("2. Potions")
    print("0 to back")
    hm = str(input(">"))
    if hm == "1":
        os.system("clear")
        Info()
        ShopSwords()
    elif hm == "2":
        os.system("clear")
        Info()
        ShopPotions()
    elif hm == "0":
        Home()
    else:
        print("You can only pick a number from the list!")
        time.sleep(1)
        Shop()

#ABILITY SHOP
def AbilityShop():
  global CurrentPlace
  global Boss_token
  global noAbilityOwn
  global FireballOwn
  global LightningStrikeOwn
  global MegaHealOwn
  global Fireball
  global LightningStrike
  global Current_Ability
  CurrentPlace = "Armory"
  os.system("clear")
  Info()
  if FireballOwn == True:
        print("1. Equip Fireball")
  elif Fireball['cost'] > Boss_token:
        print(RED + "1. Buy Fireball (" + str(Fireball['cost']) + " Boss token)" + RESET)
  elif Fireball['cost'] <= Boss_token:
        print(GREEN + "1. Buy Fireball (" + str(Fireball['cost']) + " Boss_token)" + RESET)
  if LightningStrikeOwn == True:
        print("2. Equip Lightning Strike")
  elif LightningStrike['cost'] > Boss_token:
        print(RED + "2. Buy Lightning Strike (" + str(LightningStrike['cost']) + " Boss Token)" + RESET)
  elif LightningStrike['cost'] <= Boss_token:
        print(GREEN + "2. Buy Lightning Strike (" + str(LightningStrike['cost']) + " Boss Token)" + RESET)
  if MegaHealOwn == True:
        print("3. Equip MegaHeal")
  elif MegaHeal['cost'] > Boss_token:
        print(RED + "3. Buy MegaHeal (" + str(MegaHeal['cost']) + " Boss Token)" + RESET)
  elif MegaHeal['cost'] <= Boss_token:
        print(GREEN + "3. Buy MegaHeal (" + str(MegaHeal['cost']) + " Boss Token)" + RESET)
  print("4. Unequip Abilities")
  print("0. Back")
  champ = str(input(">"))
  if champ == "1":
        if FireballOwn == True:
            print("You equipped Fireball!")
            Ability = Fireball
            Current_Ability = Fireball
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif Fireball['cost'] > Boss_token:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif Fireball['cost'] <= Boss_token:
            print("You bought Fireball!")
            Boss_token -= Fireball['cost']
            Ability = Fireball
            Current_Ability = Fireball
            FireballOwn = True
            time.sleep(1)
            os.system("clear")
            AbilityShop()
  elif champ == "2":
        if LightningStrike == True:
            print("You equipped Lightning Strike")
            Ability = LightningStrike
            Current_Ability = LightningStrike
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif LightningStrike['cost'] > Boss_token:
            print("you dont have enough Gold to buy that!")
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif LightningStrike['cost'] <= Boss_token:
            print("You bought Lightning Strike!")
            Ability = LightningStrike
            Current_Ability = LightningStrike
            LightningStrikeOwn = True
            Boss_token -= LightningStrike['cost']
            time.sleep(1)
            os.system("clear")
            AbilityShop()
  elif champ == "3":
        if MegaHeal == True:
            print("you equpied MegaHeal!")
            Ability = MegaHeal
            Current_Ability = MegaHeal
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif MegaHeal['cost'] > Boss_token:
            print("you dont have enough money to buy that!")
            time.sleep(1)
            os.system("clear")
            AbilityShop()
        elif MegaHeal['cost'] <= Boss_token:
            print("You bought MegaHeal!")
            Ability = MegaHeal
            Current_Ability = MegaHeal
            MegaHealOwn = True
            Boss_token -= MegaHeal['cost']
            time.sleep(1)
            os.system("clear")
            AbilityShop()
  elif champ == "4":
        print("You unequiped All Abilities!")
        Ability = 'none'
        time.sleep(1)
        os.system("clear")
        AbilityShop()
  elif champ == "0":
        os.system("clear")
        Home()
  else:
        print("Please Select a option.")
        time.sleep(1)
        os.system("clear")
        AbilityShop()


def ShopSwords():
    global Gold
    global Current_Sword
    global GoldenSwordOwn
    global StoneSwordOwn
    global IronSwordOwn
    global DiamondSwordOwn
    global NetheriteSwordOwn
    global EmeraldSwordOwn
    if StoneSwordOwn == True:
        print("1. Equip Stone Sword")
    elif Gold >= 1500:
        print(GREEN + "1. Buy Stone Sword (1500 Gold)" + RESET)
    elif Gold < 1500:
        print(RED + "1. Buy Stone Sword (1500 Gold)" + RESET)
    if GoldenSwordOwn == True:
        print("2. Equip Golden Sword")
    elif Gold >= 5000:
        print(GREEN + "2. Buy Golden Sword (5000 Gold)" + RESET)
    elif Gold < 5000:
        print(RED + "2. Buy Golden Sword (5000 Gold)" + RESET)
    if IronSwordOwn == True:
        print("3. Equip Iron Sword")
    elif Gold >= 10000:
        print(GREEN + "3. Buy Iron Sword (10000 Gold)" + RESET)
    elif Gold < 10000:
        print(RED + "3. Buy Iron Sword (10000 Gold)" + RESET)
    if DiamondSwordOwn == True:
        print("4. Equip Diamond Sword")
    elif Gold >= 10000:
        print(GREEN + "4. Buy Diamond Sword (20000 Gold)" + RESET)
    elif Gold < 10000:
        print(RED + "4. Buy Diamond Sword (20000 Gold)" + RESET)
    if NetheriteSwordOwn == True:
        print("5. Equip Netherite Sword")
    elif Gold >= 40000:
        print(GREEN + "5. Buy Netherite Sword (40000 Gold)" + RESET)
    elif Gold < 40000:
        print(RED + "5. Buy Netherite Sword (40000 Gold)" + RESET)
    if EmeraldSwordOwn == True:
        print("6. Equip Emerald Sword")
    elif Gold >= 60000:
        print(GREEN + "6. Buy Emerald Sword (60000 Gold)" + RESET)
    elif Gold < 60000:
        print(RED + "6. Buy Emerald Sword (60000 Gold)" + RESET)
    print("7. Equip Wooden Sword")
    print("0. back")
    a = str(input(">"))
    if a == "1":
        if StoneSwordOwn == True:
            print("You equipied Stone Sword!")
            Current_Sword = Stone_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 1500:
                print("You bought Stone Sword! for 1500 Gold")
                Gold -= 1500
                Current_Sword = Stone_Sword
                StoneSwordOwn = True
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            else:
                print("You dont have enough money to buy that!")
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
    elif a == "2":
        if GoldenSwordOwn == True:
            print("You equpied Golden Sword!")
            Current_Sword = Golden_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 5000:
                print("You bought Golden Sword for 5000 Gold")
                Gold -= 5000
                GoldenSwordOwn = True
                Current_Sword = Golden_Sword
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            elif Gold < 5000:
                print("you dont have enought money to buy that!")
                os.system("clear")
                Info()
                ShopSwords()
    if a == "3":
        if IronSwordOwn == True:
            print("You equipied Iron Sword!")
            Current_Sword = Iron_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 10000:
                print("You bought Iron Sword! for 10000 Gold")
                Gold -= 10000
                Current_Sword = Iron_Sword
                IronSwordOwn = True
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            else:
                print("You dont have enough money to buy that!")
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
    if a == "4":
        if DiamondSwordOwn == True:
            print("You equipied Diamond Sword!")
            Current_Sword = Diamond_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 20000:
                print("You bought Diamond Sword! for 20000 Gold")
                Gold -= 20000
                Current_Sword = Diamond_Sword
                DiamondSwordOwn = True
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            else:
                print("You dont have enough money to buy that!")
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
    if a == "5":
        if NetheriteSwordOwn == True:
            print("You equipied Netherite Sword!")
            Current_Sword =  Netherite_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 40000:
                print("You bought Netherite Sword! for 40000 Gold")
                Gold -= 40000
                Current_Sword = Netherite_Sword
                NetheriteSwordOwn = True
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            else:
                print("You dont have enough money to buy that!")
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
    if a == "6":
        if EmeraldSwordOwn == True:
            print("You equipied Emerald Sword!")
            Current_Sword = Emerald_Sword
            time.sleep(1)
            os.system("clear")
            Info()
            ShopSwords()
        else:
            if Gold >= 60000:
                print("You bought Emerald Sword! for 60000 Gold")
                Gold -= 60000
                Current_Sword = Emerald_Sword
                EmeraldSwordOwn = True
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
            else:
                print("You dont have enough money to buy that!")
                time.sleep(1)
                os.system("clear")
                Info()
                ShopSwords()
    elif a == "7":
        print("You equpied Wooden Sword!")
        Current_Sword = Wooden_Sword
        time.sleep(1)
        os.system("clear")
        Info()
        ShopSwords()
    elif a == "0":
        Shop()
    else:
        print("You can only pick a number from the list!")
        time.sleep(1)
        os.system("clear")
        Info()
        ShopSwords()


def ShopPotions():
    global maxPotions
    global PotionsPower
    global Gold
    global PotionsPriceam
    global PotionsPricepo
    global maxPotionsAmount
    global maxPotionsPower
    if maxPotionsAmount == maxPotions:
        print("1. Buy more Potions (cant buy)")
    elif PotionsPriceam <= Gold:
        print(GREEN + "1. Buy more Potions (" + str(PotionsPriceam) +
              " Gold)" + RESET)
    else:
        print(RED + "1. Buy more Potions (" + str(PotionsPriceam) + " Gold)" +
              RESET)
    if maxPotionsPower == PotionsPower:
        print("2. Buy +10 Health to Potions Power (cant buy)")
    elif PotionsPricepo <= Gold:
        print(GREEN + "2. Buy +10 Health to Potions Power (" +
              str(PotionsPricepo) + " Gold)" + RESET)
    elif PotionsPricepo > Gold:
        print(RED + "2. Buy +10 Health to Potions Power (" +
              str(PotionsPricepo) + " Gold)" + RESET)
    print("0. back")
    abc = str(input(">"))
    if abc == "1":
        if maxPotionsAmount == maxPotions:
            print("You have max amount (" + str(maxPotionsAmount) +
                  ") of Potions")
            time.sleep(1)
            os.system("clear")
            Info()
            ShopPotions()
        elif PotionsPriceam <= Gold:
            Gold -= PotionsPriceam
            PotionsPriceam *= 2
            maxPotions += 1
            print("You bought 1 potion!")
            time.sleep(1)
            os.system("clear")
            Info()
            ShopPotions()
        elif PotionsPriceam > Gold:
            print("You dont have enough Gold to buy that!")
            time.sleep(1)
            os.system("clear")
            Info()
            ShopPotions()
        else:
            os.system("clear")
            print("Game crashed bc of really wierd glitch lol")
            input("Close game >")
            exit(0)
    elif abc == "2":
        if maxPotionsPower == PotionsPower:
            print("You have max amount (" + str(maxPotionsPower) +
                  ") of Potions Power")
            time.sleep(1)
            os.system("clear")
            Info()
            ShopPotions()
        elif PotionsPricepo <= Gold:
            Gold -= PotionsPricepo
            PotionsPricepo *= 2
            PotionsPower += 10
            print("You Bought +10 Health to Potions Power!")
            time.sleep(1)
            os.system("clear")
            Info()
            ShopPotions()
        elif PotionsPricepo > Gold:
            print("You dont have enough Gold to buy that!")
            time.sleep(1)
            os.system("clear")
            ShopPotions()
    elif abc == "0":
        os.system("clear")
        Info()
        Shop()

def Start():
    input(
        "Welcome To Dungeon Game By Me xD. Class Update, Its now finally looking like a RPG game. Please do not select the class you already are\n>"
    )
    Game()


#GAME LOOP
def Game():
    global GameLoop
    GameLoop = True
    os.system("clear")
    while GameLoop == True:
        Home()
        os.system("cls")
        print(RED + "The Game Crashed!" + RESET)
        print(BLUE + "Reason: " + RESET + "unfortunately left the game loop")
        input("Click Enter to Close the game >")
        GameLoop = False

def cheat():
  global Gold
  global exp
  global Boss_token
  Gold += 10000000000
  exp += 10000000
  Boss_token += 100000
  Home()

Start()