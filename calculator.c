#include <stdio.h>

int main() 
{
    char operator;
    double n1, n2, result;
    printf("Enter 1 for addition\nEnter 2 for subtraction\nEnter 3 for multiplication\nEnter 4 for division ");
    printf("\nEnter an option: ");
    scanf(" %c", &operator);
    
    printf("Enter two numbers: ");
    scanf("%lf %lf",&n1,&n2);
    
    switch(operator) 
    {
        case 1:
            result = n1 + n2;
            break;
        case 2:
            result = n1 - n2;
            break;
        case 3:
            result = n1 * n2;
            break;
        case 4:
            if (n2!=0)
                result = n1 / n2;
            else
            {
                printf("Error! Division by zero is not allowed.\n");
                return 1;
            }
            break;
        default:
            printf("Invalid operator!\n");
    }
    
    printf("Result: %.2lf\n", result);
    
    return 0;
}
