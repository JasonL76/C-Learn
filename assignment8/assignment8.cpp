#include <iostream>
using namespace std;

class VendingMachine {
public:
    int itemcount[5];
    float price[5];
    int refill;
    string y;

    VendingMachine() {
        for (int i = 0; i < 5; i++) {
            itemcount[i] = 10;
            price[i] = 1.0 + (i/5.0);
        }
    }
    void Refill(int count) {
        switch (count) {
        case 1:
            cout << "Sprite refilled by 5." << endl;
            itemcount[0] += 5;
            break;
        case 2:
            cout << "Water refilled by 5." << endl;
            itemcount[1] += 5;
            break;
        case 3:
            cout << "Skittles refilled by 5." << endl;
            itemcount[2] += 5;
            break;
        case 4:
            cout << "Snickers refilled by 5." << endl;
            itemcount[3] += 5;
            break;
        case 5:
            cout << "Caffeine refilled by 5." << endl;
            itemcount[4] += 5;
            break;
        default:
            cout << "You picked nothing lol" << endl;
            break;
        }
    }

    void Inventory(int count) {
        switch (count) {
        case 1:
            cout << "You have " << itemcount[0] << " Sprite remaining." << endl;
            break;
        case 2:
            cout << "You have " << itemcount[1] << " Water remaining." << endl;
            break;
        case 3:
            cout << "You have " << itemcount[2] << " Skittles remaining." << endl;
            break;
        case 4:
            cout << "You have " << itemcount[3] << " Snickers remaining." << endl;
            break;
        case 5:
            cout << "You have " << itemcount[4] << " Caffeine remaining." << endl;
            break;
        default:
            cout << "You picked nothing lol" << endl;
            break;
        }
    }

    void getSprite(float cash) {
        cout << "You have " << itemcount[0] << " Sprite remaining. Press y to buy." << endl;
        cin >> y;
        if (y == "y") {
            if (itemcount[0] == 0) {
                cout << "I ran out of Sprite. You receive" << cash << " back. \nPress 1 to refill" << endl;
                cin >> refill;
                if (refill == 1) {
                    cout << "Sprite refilled by 5." << endl;
                    itemcount[0] = 5;
                }
            } else if (price[0] > cash) {
                cout << "You don't have enough money..." << endl;
            } else if (price[0] <= cash) {
                cout << "You got 1 Sprite and " << cash - price[0] << " back." << endl;
                itemcount[0]--;
            }
        } else {
            cout << "Vending Machine failed." << endl;
        }
    }

    void getWater(float cash) {
        cout << "You have " << itemcount[1] << " Water remaining. Press y to buy." << endl;
        cin >> y;
        if (y == "y") {        
            if (itemcount[1] == 0) {
                cout << "I ran out of Water. You receive" << cash << " back. \n Press 1 to refill" << endl;
                cin >> refill;
                if (refill == 1) {
                    cout << "Water refilled by 5." << endl;
                    itemcount[1] = 5;
                }
            } else if (price[1] > cash) {
                cout << "You don't have enough money..." << endl;
            } else if (price[1] <= cash) {
                cout << "You got 1 Water and " << cash - price[1] << " back." << endl;
                itemcount[1]--;
            }
        } else {
            cout << "Vending Machine failed." << endl;
        }
    }
    
    void getSkittles(float cash) {
        cout << "You have " << itemcount[2] << " Skittles remaining. Press y to buy." << endl;
        cin >> y;
        if (y == "y") {        
            if (itemcount[2] == 0) {
                cout << "I ran out of Skittles. You receive" << cash << " back. \n Press 1 to refill" << endl;
                cin >> refill;
                if (refill == 1) {
                    cout << "Skittles refilled by 5." << endl;
                    itemcount[2] = 5;
                }
            } else if (price[2] > cash) {
                cout << "You don't have enough money..." << endl;
            } else if (price[2] <= cash) {
                cout << "You got 1 Skittles and " << cash - price[2] << " back." << endl;
                itemcount[2]--;
            }
        } else {
            cout << "Vending Machine failed." << endl;
        }

    }

    void getSnickers(float cash) {
        cout << "You have " << itemcount[3] << " Snickers remaining. Press y to buy." << endl;
        cin >> y;
        if (y == "y") {
            if (itemcount[3] == 0) {
                cout << "I ran out of Snickers. You receive" << cash << " back. \n Press 1 to refill" << endl;
                cin >> refill;
                if (refill == 1) {
                    cout << "Snickers refilled by 5." << endl;
                    itemcount[3] = 5;
                }
            } else if (price[3] > cash) {
                cout << "You don't have enough money..." << endl;
            } else if (price[3] <= cash) {
                cout << "You got 1 Snickers and " << cash - price[3] << " back." << endl;
                itemcount[3]--;
            } 
        } else {
            cout << "Vending Machine failed." << endl;
        }
    }

    void getCaffeine(float cash) {
        cout << "You have " << itemcount[4] << " Caffeine remaining. Press y to buy." << endl;
        cin >> y;
        if (y == "y") {
            if (itemcount[4] == 0) {
                cout << "I ran out of Caffeine. You receive" << cash << " back. \n Press 1 to refill" << endl;
                cin >> refill;
                if (refill == 1) {
                    cout << "Caffeine refilled by 5." << endl;
                    itemcount[4] = 5;
                }
            } else if (price[4] > cash) {
                cout << "You don't have enough money..." << endl;
            } else if (price[4] <= cash) {
                cout << "You got 1 Caffeine and " << cash - price[4] << " back." << endl;
                itemcount[4]--;
            } 
        } else {
            cout << "Vending Machine failed." << endl;
        }
    }
};

int main() {
    VendingMachine crappy;
    float money;
    int choice;
    bool exit = false;
    string ans;

    while (exit == false) {
        cout << "\nType exit to leave. Otherwise type anything to continue..." << endl;
        cin >> ans;
        if (ans == "exit") {
            exit = true;
            break;
        }

        cout << "\nType b to buy, v to view inventory, or r to refill." << endl;
        cin >> ans;

        if (ans == "b") {
            cout << "Enter cash." << endl;
            cin >> money;
            
            cout << "Press 1 for Sprite, 2 for Water, 3 for Skittles, 4 for Snickers, 5 for Caffeine" << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                crappy.getSprite(money);
                break;
            case 2:
                crappy.getWater(money);
                break;
            case 3:
                crappy.getSkittles(money);
                break;
            case 4:
                crappy.getSnickers(money);
                break;
            case 5:
                crappy.getCaffeine(money);
                break;
            default:
                cout << "You picked nothing lol" << endl;
                break;
            }            
        } else if (ans == "v") {
            cout << "Press 1 for Sprite, 2 for Water, 3 for Skittles, 4 for Snickers, 5 for Caffeine" << endl;
            cin >> choice;
            crappy.Inventory(choice);            
        } else if (ans == "r") {
            cout << "Press 1 for Sprite, 2 for Water, 3 for Skittles, 4 for Snickers, 5 for Caffeine" << endl;
            cin >> choice;
            crappy.Refill(choice);               
        } else {
            cout << "Invalid statement." << endl;
        }


    }
    return 0;
}