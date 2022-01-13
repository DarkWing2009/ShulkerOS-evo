source games.sh

echo "












Welcome to ShulkerOS evo














Powered by ShulkerOS++"
sleep 3
clear -x
python ./Login.py
while :
do
clear -x
cowsay -f dragon-and-cow Welcome User
echo "



1. Games
2. App Store
3. Internet Browser
4. Terminal
5. Exit"
read ShulkerBox
clear -x
case $ShulkerBox in
  1)
    game
    ;;
  2)
    echo "What app would you like?"
    read app
    nix-shell -p $app
    ;;
  3)
    lynx https://google.com
    ;;
  4)
    bash
    ;;
  5)
    exit 0
esac
done