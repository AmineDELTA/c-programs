#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// problem : ** infinite loop if input = <number> + anything other than a number **

int main()
{
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses;
    int answer;
    guesses = 0;
    // uses current time as a seed
    srand(time(0));

    // generate a random number between MIN & MAX(1-100)
    answer = (rand() % MAX) + MIN;

    do
    {
        printf("Enter a guesss: ");
        scanf("%d", &guess);
        if (guess > answer)
        {
            printf("Too high!\n");
        }
        else if (guess < answer)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("Correct!\n");
        }
        guesses++;
    } while (guess != answer);

    printf("**********************\n");
    printf("answer: %d\n", answer);
    printf("guesses: %d\n", guesses);
    printf("**********************");

    return 0;
}