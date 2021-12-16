source games.sh

while true
do
echo "












Welcome to ShulkerOS evo














Powered by ShulkerOS++"
sleep 3
clear -x
python ./Login.py
clear -x
echo "Welcome User




1. Games
2. Email
3. App Store
4. Internet Browser
5. Terminal"
read ShulkerBox
clear -x
case $ShulkerBox in
  1)
    game
    ;;
  2 | 3)
    echo "Coming Soon!"
    ;;

  
  4)
    lynx
    ;;
  5)
    bash
    ;;
esac
done
