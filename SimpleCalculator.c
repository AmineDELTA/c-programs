#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char operator;
    double num1;
    double num2;
    double result;

    printf("\n Pls entrer an operator from the following list (+ - * /) : ");
    scanf("%c", &operator);

    printf("Enter your first number : ");
    scanf("%lf", &num1);

    printf("Enter your second number : ");
    scanf("%lf", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("\nresult : %.2lf", result);
        break;

    case '-':
        result = num1 - num2;
        printf("\nresult : %.2lf", result);
        break;

    case '*':
        result = num1 * num2;
        printf("\nresult : %.2lf", result);
        break;

    case '/':
        result = num1 / num2;
        printf("\nresult : %.2lf", result);
        break;

    default:
        printf("%c is not valid", operator);
    }
    return 0;
}