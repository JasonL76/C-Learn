#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

void highscore(int score) {
    bool high = false;
    //make a textfile that reads what the highscore is.
    ofstream w;
    string name, fileline, answer;

    cout << "Give me a unique username!!!" << endl;
    cin >> name;

    w.open("High Score.txt", ios::app);
    w << name << " "<< score << endl;
    high = true;
}

void casino(int score, bool exit, bool clover) {
    int token = 0;
    string ans;
    int tokenask;

    //exit becomes false when this function is called from the game function. 
    //This is to make sure there are no repeats after the highscore function is called.
    if (!exit) {
        cout << "Do you want to buy tokens? (1 costs 50 points).\nType y for Yes or n for No" << endl;
        cin >> ans;

        if (ans == "y") {
            cout << "How many?" << endl;
            cin >> tokenask;
            if (tokenask * 50 <= score && !clover) {
                token = tokenask;
                score -= (tokenask*50);
            } else if (tokenask * 50 <= score && clover) {
                cout << "Your clover has activated and you earn more tokens. Nice." << endl;
                token = (tokenask+5);
                score -= (tokenask*50);
            } else {
                cout << "Not enough points" << endl;
                highscore(score);
            }
            cout << "You currently have " << score << " points" << endl;
            for (int i = token; i > 0; i--) {
                cout << "Press anything to use a token" << endl;
                cin >> ans;  
                int random = (rand() % 9);
                switch (random) {
                case 1:
                    cout << "Jackpot!" << endl;
                    score += 500;
                    break;
                case 2:
                    cout << "You found trash." << endl;
                    score -= 100;
                    break;
                case 3:
                    cout << "You found a pair of Queens" << endl;
                    score += 100;
                    break;
                case 4:
                    cout << "Absolute Disaster." << endl;
                    score = 0;
                    break;
                case 5:
                    cout << "Your significant other divorced you." << endl;
                    score -= 250;
                    break;
                case 6:
                    cout << "You found Stevens Ducks." << endl;
                    score += 250;
                    break;
                case 7:
                    cout << "7 is a lucky number, but not in this case." << endl;
                    score -= 103;
                    break;
                case 8:
                    cout << "Womp womp." << endl;
                    score = 1;
                    break;
                case 9:
                    cout << "You discovered a fifth suite in this deck of cards???" << endl;
                    score += 350;
                    break;
                default:
                    cout << "You found some points stolen from the last guy" << endl;
                    score += (rand() % 100);
                    break;
                }
                cout << "Your current score is " << score << "." << endl;
                if (score < 0) {
                    cout << "Fortunately you can't have negative points lol" << endl;
                    score = 0;
                }            
            }
            if (token == 0) {
                cout << "Out of tokens. Thanks for playing!" << endl;
            }
        } else if (ans == "n") {
            cout << "Playing safe I see." << endl;
        } else {
            cout << "Invalid answer. I'm taking your answer as a no." << endl;
        }
        highscore(score);
    }
}

class Player {
public:
void game() {
    int game = 0;
    bool load = false;
    bool clover = false;
    bool checker[52];
    int score = 0;
    char slot[4];
    int suit[4];

    for (int i = 0; i < 52; i++) {
        checker[i] = false;
    }

    while (game < 3) {
        string cards = "AAAA222233334444555566667777888899990000JJJJQQQQKKKK";
        int suite[52];
        int random[4];

        for (int i = 0; i < 52; i++) {
            if (i % 4 == 1) {
                suite[i] = 0;
            } else if (i % 4 == 2) {
                suite[i] = 1;
            } else if (i % 4 == 3) {
                suite[i] = 2;
            } else if (i % 4 == 0) {
                suite[i] = 3;
            }
        }

        string input;
        string deck = "draw";
        string save = "save";
        char ans[4];

        srand(time(0));
        //generate "rng"

        cout << "Type 'draw' for a card, 'save' if you are satisfied with your deck, or 'rules' for rules." << endl;
        cin >> input;

        if (input == "draw") {
            load = true;

            for (int i = 0; i < 4; i++) {
                int random = (rand() % 51);
                ans[i] = cards[random];

                if (suite[random] == 0 && checker[random] == false) {
                    cout << ans[i] << " HEARTS" << endl;
                    checker[random] = true;
                    slot[i] = ans[i];
                    suit[i] = 0;
                } else if (suite[random] == 1 && checker[random] == false) {
                    cout << ans[i] << " DIAMONDS" << endl;
                    checker[random] = true;
                    slot[i] = ans[i];
                    suit[i] = 1;
                } else if (suite[random] == 2 && checker[random] == false) {
                    cout << ans[i] << " CLUBS" << endl;
                    checker[random] = true;
                    slot[i] = ans[i];
                    suit[i] = 2;
                } else if (suite[random] == 3 && checker[random] == false) {
                    cout << ans[i] << " SPADES" << endl;
                    checker[random] = true;
                    slot[i] = ans[i];
                    suit[i] = 3;
                } else {
                    i--;
                    //if duplicates are found, it resets that particular for loop to reshuffle
                }

                //ensures that there are no duplicates
            }
        } else if (input == "save" && load == true) {
            for (int i = 0; i < 4; i++) {
                game = 3;
            }
        } else if (input == "save" && load == false) {
            cout << "You don't have cards!" << endl;
            game--;
        } else if (input == "rules") {
            cout << "\nAt the end of the round, you receive points based on your deck of cards. \nFace cards always give 50 points. Same cards give 100 points. Same suites give 100 points. \nSame face cards give 500 points.\n" << endl;
            game--;
        } else {
            cout << "Invalid Statement." << endl;
            game--;
        }

        game++;
    }

    if (game >= 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                if (slot[i] == slot[j]) {
                    if (slot[i] == 'J' || slot[i] == 'Q' || slot[i] == 'K' || slot[i] == 'A') {
                        score += 500;
                    } else {
                        score += 100;
                    }                  
                } else if (suit[i] == suit[j]) {
                    score += 100;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            if (slot[i] == 'J' || slot[i] == 'Q' || slot[i] == 'K' || slot[i] == 'A') {
                score += 50;
            }
        }
    }

    cout << "Your score is: " << score << endl;

    if (score >= 750) {
        cout << "You found a four leaf clover. It means you won't fail your finals!" << endl;
        clover = true;
    }

    casino(score, false, clover);
}
};

int main() {
    int playercount;
    cout << "Welcome to this amazing game of cards!!!" << endl;
    cout << "In this game, you will draw some cards to earn points then potentially win BIG prizes at the casino!!!\nHow many players do you have?" << endl;
    cin >> playercount;
    Player play[playercount];
    for (int i = 0; i < playercount; i++) {
        cout << "\nPlayer " << (i+1) << "'s turn!\n" << endl;
        play[i].game();
    }
    return 0;
}