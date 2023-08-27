#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Item {
    string name;
    int buyPrice;
    int sellPrice;
};

struct PawnShop {
    string name;
    int money;
};

int random(int min, int max) {
    return min + (rand() % (max - min + 1));
}

int main() {
    srand(time(0));
    
    int playerMoney = 1000;
    
    PawnShop pawnShops[] = {
        {"Downtown Pawn Shop", 5000},
        {"Eastside Pawn Shop", 3000},
        {"Westside Pawn Shop", 4500}
    };
    int shopCount = sizeof(pawnShops) / sizeof(pawnShops[0]);
    
    Item items[] = {
        {"Old Watch", 100, 50},
        {"Antique Vase", 200, 100},
        {"Rare Coin", 150, 75},
        {"Diamond Necklace", 500, 250},
        {"Vintage Guitar", 300, 150},
        {"Gold Ring", 250, 125},
        {"Silver Spoon", 50, 25},
        {"Bronze Statue", 180, 90},
        {"Pocket Watch", 120, 60},
        {"Crystal Vase", 280, 140},
        {"Copper Coin", 30, 15},
        {"Platinum Necklace", 700, 350},
        {"Electric Guitar", 350, 175},
        {"Sapphire Ring", 420, 210},
        {"Pearl Earrings", 180, 90},
        {"Emerald Pendant", 320, 160},
        {"Ruby Bracelet", 450, 225},
        {"Platinum Spoon", 80, 40},
        {"Silver Coin", 20, 10},
        {"Bronze Watch", 70, 35}
    };
    int itemCount = sizeof(items) / sizeof(items[0]);
    
    cout << "Welcome to the Pawn Shop!" << endl;
    cout << "You have $" << playerMoney << "." << endl;
    
    while (playerMoney > 0) {
        cout << "\nAvailable Pawn Shops:" << endl;
        for (int i = 0; i < shopCount; ++i) {
            cout << i + 1 << ". " << pawnShops[i].name << endl;
        }
        cout << shopCount + 1 << ". Quit" << endl;
        
        int shopChoice;
        cin >> shopChoice;
        
        if (shopChoice >= 1 && shopChoice <= shopCount) {
            PawnShop selectedShop = pawnShops[shopChoice - 1];
            cout << "\nWelcome to " << selectedShop.name << "!" << endl;
            cout << "Shop's money: $" << selectedShop.money << endl;
            
            while (true) {
                cout << "\nWhat would you like to do?" << endl;
                cout << "1. Buy an item" << endl;
                cout << "2. Sell an item" << endl;
                cout << "3. Exit " << selectedShop.name << endl;
                
                int choice;
                cin >> choice;
                
                if (choice == 1) {
                    cout << "Items for sale:" << endl;
                    for (int i = 0; i < itemCount; ++i) {
                        cout << i + 1 << ". " << items[i].name << " ($" << items[i].buyPrice << ")" << endl;
                    }
                    
                    int itemChoice;
                    cin >> itemChoice;
                    
                    if (itemChoice >= 1 && itemChoice <= itemCount) {
                        int index = itemChoice - 1;
                        if (playerMoney >= items[index].buyPrice) {
                            cout << "You bought a " << items[index].name << "!" << endl;
                            playerMoney -= items[index].buyPrice;
                            selectedShop.money += items[index].buyPrice;
                        } else {
                            cout << "Not enough money!" << endl;
                        }
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
                } else if (choice == 2) {
                    cout << "Items to sell:" << endl;
                    for (int i = 0; i < itemCount; ++i) {
                        cout << i + 1 << ". " << items[i].name << " ($" << items[i].sellPrice << ")" << endl;
                    }
                    
                    int itemChoice;
                    cin >> itemChoice;
                    
                    if (itemChoice >= 1 && itemChoice <= itemCount) {
                        int index = itemChoice - 1;
                        if (selectedShop.money >= items[index].sellPrice) {
                            cout << "You sold the " << items[index].name << "!" << endl;
                            playerMoney += items[index].sellPrice;
                            selectedShop.money -= items[index].sellPrice;
                        } else {
                            cout << "The shop doesn't have enough money to buy that item!" << endl;
                        }
                    } else {
                        cout << "Invalid choice!" << endl;
                    }
                } else if (choice == 3) {
                    cout << "Exiting " << selectedShop.name << "..." << endl;
                    break;
                } else {
                    cout << "Invalid choice!" << endl;
                }
            }
        } else if (shopChoice == shopCount + 1) {
            cout << "Exiting the game..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    
    cout << "\nGame over! You're out of money." << endl;
    
    return 0;
}
