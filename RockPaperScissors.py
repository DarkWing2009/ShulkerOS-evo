import os, time

quote = True


while quote:
  print("Hello world")
  print("How are you today?")
  answer = input()
  if answer.lower() == "good" or answer == "okay":
    print("since you are feeling good, than lets play a game, ")
  else:
    print("I'm sorry to hear that, maybe a game will cheer you up, ")
  print("lets play rock paper scissors! You start first. ")
  a = input().lower()
  if a == "rock" and answer == "good" or answer == "okay":
    print("I choose paper")
  elif a == "rock":
    print("I choose scissors")
  elif a == "scissors" and answer == "good" or answer == "okay":
    print("I choose rock")
  elif a == "scissors" == "good" or answer == "okay":
    print("I choose paper")
  elif a == "paper" and answer == "good" or answer == "okay":
    print("I choose scissors")
  elif a == "paper":
    print("I choose rock")
  elif a != "rock" or a != "paper" or a != "scissors":
    print("Try again!")

  print("Do you want to play again?")
  v = input()
  if v == "yes":
    quote = True
  else:
    quote = False
    print("so... now that we have finished that, lets play a game!")
    os.system('clear')
    print("It's time to play Game Show!")
    time.sleep(5)
    print("Here are the rules:")
    time.sleep(5)
    print("1. You are not allowed to look up the answers.")
    print("2. You are not allowed to ask a friend for help.")
    print("3. You must use capitilization.")
    time.sleep(15)
    print("What year was Minecraft released?")
    answer = input()
    if answer == "2009":
      print("Correct!")
      time.sleep(3)
      os.system('clear')
      print("Who is the president?")
      answer = input()
      if answer == "Joe Biden":
        print ("Correct!")
        time.sleep(3)
        os.system('clear')
        print("What language is this coded in?")
        answer = input()
        if answer == "Python":
          print("Correct!")
          time.sleep(3)
          os.system('clear')
          print("What is my name?")
          answer = input()
          if answer == "Alex Johnson":
            print("Correct!")
            time.sleep(3)
            os.system('clear')
            print("How much health does the Ender Dragon have?")
            answer = input()
            if answer == "200":
              print("Correct!")
              time.sleep(3)
              os.system('clear')
            else:
              print("You Failed!")
          else:
            print("You Failed!")
        else:
          print ("You Failed!")

      else:
        print("You Failed!") 
    else:
      print("You Failed!")
