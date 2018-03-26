//Made by Edgar Arakelyan
//Statistics will count wins, losses, ties and probabilities

using namespace std;

class Statistics{
public:
    Statistics();
    ~Statistics();
    int getCycleCount();
    int getPlayerWinCount();
    int getBankerWinCount();
    int getTieCount();


private:
    int playerWins;
    int bankerWins;
    int ties;
    int cycleCount;
};