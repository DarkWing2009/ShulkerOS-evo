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
2. Email
3. App Store
4. Internet Browser
5. Terminal
6. Exit"
read ShulkerBox
clear -x
case $ShulkerBox in
  1)
    game
    ;;
  2)
    echo "Coming Soon!"
    ;;
  3)
    echo "Coming Soon!"
    ;;
  4)
    lynx https://google.com
    ;;
  5)
    bash
    ;;
  6)
    exit 0
esac
done