//Made by Edgar Arakelyan
//User is a class to hold Player and Banker instances
#include <vector>
#include <string>


using namespace std;

class User{
public:
    User();
    ~User();
    int GetHandValue();
    void resetHand();
    void drawCard(string);
    void printHand();

private:
    vector<string> hand;
};