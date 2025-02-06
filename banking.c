#include <stdio.h>

#define MAX_CUSTOMERS 200

// Structure to store customer details
struct Customer {
    int accountNumber;
    char name[50];
    float balance;
};

// Function to print customers with balance below Rs. 100
void printLowBalanceCustomers(struct Customer customers[], int count) {
    printf("\nCustomers with balance below Rs. 100:\n");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (customers[i].balance < 100) {
            printf("Account No: %d, Name: %s\n", customers[i].accountNumber, customers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No customers found with balance below Rs. 100.\n");
    }
}

// Function to handle deposit and withdrawal transactions
void processTransaction(struct Customer customers[], int count, int acctNo, float amount, int code) {
    for (int i = 0; i < count; i++) {
        if (customers[i].accountNumber == acctNo) {
            if (code == 1) { // Deposit
                customers[i].balance += amount;
                printf("Deposit successful. New balance: Rs. %.2f\n", customers[i].balance);
            } else if (code == 0) { // Withdrawal
                if (customers[i].balance - amount < 100) {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                } else {
                    customers[i].balance -= amount;
                    printf("Withdrawal successful. New balance: Rs. %.2f\n", customers[i].balance);
                }
            } else {
                printf("Invalid transaction code.\n");
            }
            return;
        }
    }
    printf("Account number not found.\n");
}

// Main function
int main() {
    struct Customer customers[MAX_CUSTOMERS];
    int n, acctNo, code;
    float amount;

    // Input number of customers
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    // Input customer details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &customers[i].accountNumber);
        printf("Name: ");
        scanf(" %[^\n]", customers[i].name); // Reads string with spaces
        printf("Balance: Rs. ");
        scanf("%f", &customers[i].balance);
    }

    // Print customers with balance below Rs. 100
    printLowBalanceCustomers(customers, n);

    // Process transactions
    while (1) {
        printf("\nEnter transaction details (Acct.No, Amount, Code [1 for deposit, 0 for withdrawal], -1 to exit): ");
        scanf("%d", &acctNo);
        if (acctNo == -1) break; // Exit condition
        scanf("%f %d", &amount, &code);

        processTransaction(customers, n, acctNo, amount, code);
    }

    return 0;
}
