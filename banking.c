#include <stdio.h>

#define MAX_CUSTOMERS 200

struct Customer 
{
    int accountNumber;
    char name[50];
    float balance;
};

void printLowBalanceCustomers(struct Customer customers[], int count) 
{
    printf("\nCustomers with balance below Rs. 100:\n");
    int found = 0;
    for (int i = 0; i < count; i++) 
    {
        if (customers[i].balance < 100) 
        {
            printf("Account No: %d, Name: %s\n", customers[i].accountNumber, customers[i].name);
            found = 1;
        }
    }
    if (!found) 
    {
        printf("No customers found with balance below Rs. 100.\n");
    }
}

void processTransaction(struct Customer customers[], int count, int acctNo, int code) 
{
    float amount;
    for (int i = 0; i < count; i++) 
    {
        if (customers[i].accountNumber == acctNo) 
        {
            printf("\nHello, %s !:)",customers[i].name);
            printf("\nBalance: %.2f",customers[i].balance);
            if (code == 1) 
            { 
                printf("\nEnter the amount to deposit: ");
                scanf("%f",&amount);
                customers[i].balance += amount;
                printf("Deposit successful. New balance: Rs. %.2f\n", customers[i].balance);
            } 
            else 
            { 
                printf("\nEnter the amount for withdrawal: ");
                scanf("%f",&amount);
                if (customers[i].balance - amount < 100) 
                {
                    printf("The balance is insufficient for the specified withdrawal.\n");
                } 
                else 
                {
                    customers[i].balance -= amount;
                    printf("Withdrawal successful. New balance: Rs. %.2f\n", customers[i].balance);
                }
            }
        }
        else
        {
               printf("Account number not found.\n");
        }
         
    }
    
}


int main()
{
    struct Customer customers[MAX_CUSTOMERS];
    int n, acctNo, code;

    printf("Enter the number of customers: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter details for customer %d:\n", i + 1);
        printf("Account Number: ");
        scanf("%d", &customers[i].accountNumber);
        printf("Name: ");
        scanf(" %[^\n]", customers[i].name);
        printf("Balance: Rs. ");
        scanf("%f", &customers[i].balance);
    }
    printLowBalanceCustomers(customers, n);

    while (1) 
    {
        printf("\nEnter transaction details (Acct.No, Amount, Code [1 for deposit, 0 for withdrawal], 2 to exit): ");
        printf("\nEnter the code: ");
        scanf("%d", &code);
        if (code == 2) 
            break;
        printf("\nEnter the account no.: ");
        scanf("%d",&acctNo);
        processTransaction(customers,n,acctNo,code);
    }
    return 0;
}
