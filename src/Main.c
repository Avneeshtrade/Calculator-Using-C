#include <stdio.h>
#include "../include/header_files/calculator.h"
#include "../include/header_files/greet.h"

int main()
{
    int i = 0, count = 10, choice = 1, isRepeatAgain = 1;
    greet("Welcome to my Calculator \n");
    printf("=========================================== \n");
    while (isRepeatAgain != 0)
    {
        greet("\n1. Add ");
        greet("2. Subtract ");
        greet("3. Multiply ");
        greet("4. Divide ");
        greet("5. Modulus ");
        greet("6. Exponent ");
        greet("7. Exit ");
        greet("=========================================== ");
        greet("Enter your choice ! ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("The result of addition is %f", add());
            break;

        case 2:
            printf("The result of subtraction is %d",subtract());
            break;

        case 3:
            printf("The result of multiply is %lf", multiply());
            break;

        case 4:
            printf("The result of divide is %lf", divide());
            break;

        case 5:
            printf("The result of modulus is %d", modulus());
            break;

        case 6:
            printf("The result of exponent is %lf", exponent());
            break;

        case 7:
            exitApp(&isRepeatAgain);
            break;

        default:
            exitApp(&isRepeatAgain);
            break;
        }
        while (getchar() != '\n');
    }

    return 0;
}