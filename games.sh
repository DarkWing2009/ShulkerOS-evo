function game() {
echo "What Game Would You Like To Play?:
1. Guess The Number
2. New RPG
3. Rock Paper Scissors
4. Business Simulator
5. Kingdom Sim"
read Choice
clear -x
case $Choice in
  1)
    python ./guessTheNumber.py
    ;;
  2)
    python ./NewRPG.py
    ;;
  3)
    python ./RockPaperScissors.py
    ;;
  4)
    python ./BuisnessSim.py
    ;;
  5)
    clang++ KingdomSimulator.cpp -o KingdomSimulator && ./KingdomSimulator
    ;;
  *)
    echo "No"
    ;;
esac
}