import getpass

combolist = open('combolist.txt').read().splitlines()

choice = input("login or register: ")

#login
if choice == 'login':
    print("Please enter a username and password")
    user = input("Username: ")
    passw = getpass.getpass("Password: ")

    combo = user + ':' + passw

    if combo in combolist:
        print("Logged in with the username:", user)
    else:
        print("Doesn't exist or wrong username and password")
      
# register

if choice == 'register':
    username_valid = True
    print("Enter the desired username")
    wanted_user = input("Username: ")
    for combo in combolist:
      if wanted_user in combo:
        print("Username is taken! Make another!")
        username_valid = False
    if username_valid == True:
      wanted_pass = getpass.getpass("Password: ")
      wanted_passw = getpass.getpass("Confirm Password: ")
      if wanted_pass != wanted_passw:
        print("Passwords do not match")

      combo = wanted_user + ":" + wanted_pass

      f1 = open('combolist.txt', 'a+')
      f1.writable()
      f1.write(combo + "\n")
      f1.close()

      print("Successfully registered! Try and login.")

if choice != "login" or "register":
  print("Not an option")
  exit(1)