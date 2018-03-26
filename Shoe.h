//Made by EDGAR ARAKELYAN
//The Shoe Class is an 8-deck card shoe for Baccarat play
#include <vector>
#include <string>


using namespace std;

class Shoe{
public:
    Shoe();
    ~Shoe();
    void newCycle();
    void shuffleShoe();
    int getCycleCount();

private:
    vector<string> shoe;
    int CycleCount;
    int randomFunc(int);
};