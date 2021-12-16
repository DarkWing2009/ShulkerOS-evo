import os, random

os.system('clear')
print("")
print("")
print("Lets play guess the number!")
print("You have 10 attemps.")
print("Choose a number between 1 and 100")
number = random.randint(1, 100)
try:
  for i in range(10):
    answer = int(input())
    if answer == number:
      print("You win!")
      exit(0)
    elif answer > number:
      print("Too high!")
    elif answer < number:
      print("Too low!")
  print("You fail!")
except ValueError as ham:
  print(ham)