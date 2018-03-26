//Made by Edgar Arakelyan
//Statistics will count wins, losses, ties and probabilities

using namespace std;

class Statistics{
public:
    Statistics();
    ~Statistics();
    int getCycleCount();
    void playerWinIncrement();
    void bankerWinIncrement();
    void tieIncrement();
    int getPlayerWinCount();
    int getBankerWinCount();
    int getTieCount();


private:
    int playerWins;
    int bankerWins;
    int ties;
    int cycleCount;
};