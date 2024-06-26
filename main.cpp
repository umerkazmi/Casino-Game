#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

long long amount_money;

// Function to generate a random number between 1 and 10
int rand_num() {
    return rand() % 10 + 1;
}

int main() {
    // Seed the random number generator
    srand(time(0));
    
    cout << "Enter deposit amount to play game: $";
    cin >> amount_money;

    while (true) {
        if (amount_money == 0) {
            cout << "Sorry, you lost all your money. Your balance is now $0." << endl;
            return 0;
        }

        long long betting_amount;
        cout << "Enter betting amount: ";
        cin >> betting_amount;

        if (betting_amount > amount_money) {
            cout << "You don't have enough money." << endl;
            continue;
        }

        cout << "Guess one number (1-10): ";
        int n;
        cin >> n;

        if (n > 10 || n <= 0) {
            cout << "Wrong number, try again." << endl;
            continue;
        } else {
            int r = rand_num();
            if (r == n) {
                amount_money += betting_amount * 10;
                cout << "Winner! Your balance now is $" << amount_money << endl;
            } else {
                amount_money -= betting_amount;
                cout << "Loser. Your balance now is $" << amount_money << endl;
            }
        }
    }

    return 0;
}
