#include <stdio.h>

int main()
{
    int a, b;
    char choice;

    do
    {
        printf("Enter a number: ");
        scanf("%d", &a);           // read input from user
        b = a * 3 % 11;            // perform the required operation
        printf("Result: %d\n", b); // print the result

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // read user's choice

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
