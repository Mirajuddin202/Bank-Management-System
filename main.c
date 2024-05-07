#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100 // Maximum number of accounts

// Structure to hold account information
struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS]; // Array of accounts
int numAccounts = 0; // Number of accounts currently stored

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccount();

int main() {
    int choice;

    while (1) {
        printf("\nBank Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Display Account Information\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                displayAccount();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }

    struct Account acc;

    acc.accountNumber = numAccounts + 1;

    printf("Enter name: ");
    scanf("%s", acc.name);
    printf("Enter initial balance: ");
    scanf("%f", &acc.balance);

    accounts[numAccounts++] = acc;

    printf("Account created successfully!\n");
    printf("Account Number: %d\n", acc.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    accounts[accountNumber - 1].balance += amount;

    printf("Deposited %.2f into account %d successfully!\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;

    printf("Withdrawn %.2f from account %d successfully!\n", amount, accountNumber);
}

void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Balance for account %d is %.2f\n", accountNumber, accounts[accountNumber - 1].balance);
}

void displayAccount() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > numAccounts) {
        printf("Invalid account number!\n");
        return;
    }

    struct Account acc = accounts[accountNumber - 1];

    printf("Account Number: %d\n", acc.accountNumber);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}
