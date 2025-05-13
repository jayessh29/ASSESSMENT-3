#include <iostream>
#include <ctime> /
using namespace std;


class ATM {
private:
    int correctPIN;
    int initialBalance;
    int currentBalance;

public:
    
    ATM() : correctPIN(12345), initialBalance(60000), currentBalance(20000) {}

   
    void showDateTime() {
        time_t now = time(0); // get current time
        char* dt = ctime(&now);
        cout << "Current Date & Time: " << dt << endl;
    }

  
    bool authenticate(int enteredPin) {
        return (enteredPin == correctPIN);
    }

    
    void showHelp() {
        cout << "\n========== HELP SCREEN ==========\n";
        cout << "1. Enter correct 5-digit ATM PIN to access account.\n";
        cout << "2. You have only ONE attempt to enter the PIN correctly.\n";
        cout << "3. After correct login, you can:\n";
        cout << "   - Check Balance\n";
        cout << "   - Deposit Money\n";
        cout << "   - Withdraw Money\n";
        cout << "4. Exit to leave the ATM safely.\n";
        cout << "=================================\n";
    }

    
    void showBankMenu() {
        int choice;
        do {
            cout << "\n======= ATM MAIN MENU =======\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select between 1 to 4.\n";
            }
        } while (choice != 4);
    }

    
    void checkBalance() const; 

    
    void deposit() {
        int amount;
        cout << "Enter amount to deposit: Rs. ";
        cin >> amount;
        if (amount > 0) {
            currentBalance += amount;
            cout << "\nDeposit Successful!\n";
            cout << "Initial Balance: Rs. " << initialBalance << endl;
            cout << "Current Balance: Rs. " << currentBalance << endl;
        } else {
            cout << "Invalid amount. Try again.\n";
        }
    }

   
    void withdraw() {
        int amount;
        cout << "Enter amount to withdraw: Rs. ";
        cin >> amount;
        if (amount <= currentBalance && amount > 0) {
            currentBalance -= amount;
            cout << "\nWithdrawal Successful!\n";
            cout << "Remaining Balance: Rs. " << currentBalance << endl;
        } else {
            cout << "\n***** Withdrawal Unsuccessful *****\n";
            cout << "Reason: Insufficient Balance or Invalid Amount.\n";
        }
    }
};


void ATM::checkBalance() const {
    cout << "\n====== ACCOUNT BALANCE ======\n";
    cout << "Initial Balance: Rs. " << initialBalance << endl;
    cout << "Current Balance: Rs. " << currentBalance << endl;
    cout << "=============================\n";
}

int main() {
    ATM atm;
    int choice, enteredPin;

    cout << "===========================================\n";
    cout << "     WELCOME TO XYZ BANK ATM SYSTEM\n";
    cout << "===========================================\n";

    // Display date and time
    atm.showDateTime();

    // Display main entry menu
    cout << "\n======= MAIN MENU =======\n";
    cout << "1. Enter ATM PIN\n";
    cout << "2. Help\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        // Only ONE attempt for PIN
        cout << "Enter ATM PIN: ";
        cin >> enteredPin;

        if (atm.authenticate(enteredPin)) {
            cout << "\nAccess Granted. Welcome!\n";
            atm.showBankMenu();
        } else {
            cout << "\nIncorrect PIN. Exiting the system...\n";
        }
    } else if (choice == 2) {
        atm.showHelp();
    } else {
        cout << "Invalid option selected.\n";
    }

    return 0;
}
