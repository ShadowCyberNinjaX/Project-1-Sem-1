#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100

// Structure to store item details
struct Item 
{
    char name[1000];
    int quantity;
    int price;
    int discount;
    long int bill;
};

void addItem(struct Item items[], int *count, long int *total);
void displayBill(struct Item items[], int count, long int total, int extraDiscount);
int main() 
{
    struct Item items[MAX_ITEMS];
    int count = 0,choice,extraDiscount = 0;
    long int total = 0;

    while (1)
    {
        printf("\n===== Billing System Menu =====\n");
        printf("1. Add Item\n");
        printf("2. Display Bill\n");
        printf("3. Apply Extra Discount\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem(items, &count, &total);
                break;
            case 2:
                displayBill(items, count, total, extraDiscount);
                break;
            case 3:
                printf("Enter extra discount: ");
                scanf("%d", &extraDiscount);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addItem(struct Item items[], int *count, long int *total)
{
    if(*count >= MAX_ITEMS) 
    {
        printf("Item limit reached!\n");
        return;
    }

    struct Item newItem;
    while(1)
    {
        getchar(); 

        printf("Enter item name (or 'x' to stop): ");
        fgets(newItem.name, 1000, stdin);
        newItem.name[strcspn(newItem.name, "\n")] = '\0';  // Remove newline

        if (strcmp(newItem.name, "x") == 0)
            break; 
        printf("Enter quantity: ");
        scanf("%d", &newItem.quantity);
        printf("Enter price per item: ");
        scanf("%d", &newItem.price);
        printf("Enter discount: ");
        scanf("%d", &newItem.discount);

        newItem.bill = (newItem.quantity * newItem.price) - newItem.discount;
        *total += newItem.bill;

        items[*count] = newItem;
        (*count)++;

        printf("Item added successfully!\n");
    }
}


void displayBill(struct Item items[], int count, long int total, int extraDiscount) 
{
    if (count == 0) 
    {
        printf("No items in the bill!\n");
        return;
    }

    printf("\n--------------------------------------BILL--------------------------------------\n");
    printf("Sl. Name                                   Quantity    Price    Discount    Bill\n");
    for (int i = 0; i < count; i++) 
    {
        printf("%-3d %-40s %-10d %-8d %-10d %-10ld\n",
               i + 1, items[i].name, items[i].quantity, items[i].price, items[i].discount, items[i].bill);
    }
    printf("---------------------------------------------------------------------------------\n");

    printf("\nExtra Discount: %d\n", extraDiscount);
    printf("Final Total: %ld\n", total - extraDiscount);
}

