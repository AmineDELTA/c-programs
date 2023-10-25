#include <stdio.h>
#include <ctype.h>

int main()
{
    char questions[][100] = {".1\\ What year did the C language debut ? : ",
                             ".2\\ Who is credited with creating C ? : ",
                             ".3\\ what is the predecessor of C ? : "};

    char options[][100] = {"A. 1969", "B. 1972", "C. 1965", "D. 1999",
                           "A. Dennis Ritchie", "B. Nikola Teala", "C. John Carmack", "D. Doc Brown",
                           "A. Objective C", "B. B", "C. C++", "D. C#"};

    char answers[3] = {'B', 'A', 'B'};
    int numberOFquestions = sizeof(questions) / sizeof(questions[0]);

    char guess;
    int score;
    score = 0;

    printf("QUIZ GAME !\n");

    for (int i = 0; i < numberOFquestions; i++)
    {
        printf("------------------------------------\n");
        printf("%s\n", questions[i]);

        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("%s\n", options[j]);
        }

        printf("guess: ");
        scanf("%c", &guess);
        char temp;
        scanf("%c", &temp); // second scanf helps clear \n from the input buffer

        // accept lowercase answers
        guess = toupper(guess);

        if (guess == answers[i])
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong!\n");
        }
    }

    printf("**********************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberOFquestions);

    return 0;
}