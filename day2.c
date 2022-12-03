#include <stdlib.h>
#include <stdio.h>

#define ROCK_SIGN 'A'
#define PAPER_SIGN 'B'
#define SCISSORS_SIGN 'C'
#define ENC_PAPER_SIGN 'Y'
#define ENC_ROCK_SIGN 'X'
#define ENC_SCISSORS_SIGN 'Z'
#define NEED_WIN 'Z'
#define NEED_DRAW 'Y'
#define NEED_LOSS 'X'
#define PAPER_POINTS 2
#define ROCK_POINTS 1
#define SCISSORS_POINTS 3
#define VICTORY 6
#define DRAW 3
#define LOSS 0

int task_1()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    char move = '\0';
    char encrypted = '\0';
    int total = 0;

    while (fscanf(fp, "%c %c \n", &move, &encrypted) != EOF) {
        switch (move) {
            case ROCK_SIGN:
                if (encrypted == ENC_PAPER_SIGN)
                    total += PAPER_POINTS + VICTORY;
                else if (encrypted == ENC_ROCK_SIGN)
                    total += ROCK_POINTS + DRAW;
                else
                    total += SCISSORS_POINTS + LOSS;
                break;

            case PAPER_SIGN:
                if (encrypted == ENC_PAPER_SIGN)
                    total += PAPER_POINTS + DRAW;
                else if (encrypted == ENC_ROCK_SIGN)
                    total += ROCK_POINTS + LOSS;
                else
                    total += SCISSORS_POINTS + VICTORY;
                break;

            case SCISSORS_SIGN:
                if (encrypted == ENC_PAPER_SIGN)
                    total += PAPER_POINTS + LOSS;
                else if (encrypted == ENC_ROCK_SIGN)
                    total += ROCK_POINTS + VICTORY;
                else
                    total += SCISSORS_POINTS + DRAW;
                break;
        }
    }

    fclose(fp);

    return total;
}

int task_2()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    char move = '\0';
    char encrypted = '\0';
    int total = 0;

    while (fscanf(fp, "%c %c \n", &move, &encrypted) != EOF) {
        switch (encrypted) {
            case NEED_WIN:
                if (move == PAPER_SIGN)
                    total += SCISSORS_POINTS;
                else if (move == ROCK_SIGN)
                    total += PAPER_POINTS;
                else
                    total += ROCK_POINTS;
                
                total += VICTORY;
                break;

            case NEED_DRAW:
                if (move == PAPER_SIGN)
                    total += PAPER_POINTS;
                else if (move == ROCK_SIGN)
                    total += ROCK_POINTS;
                else
                    total += SCISSORS_POINTS;
                
                total += DRAW;
                break;

            case NEED_LOSS:
                if (move == PAPER_SIGN)
                    total += ROCK_POINTS;
                else if (move == ROCK_SIGN)
                    total += SCISSORS_POINTS;
                else
                    total += PAPER_POINTS;
                break;
        }
    }

    fclose(fp);

    return total;
}

int main()
{
    printf("Points: %d\n", task_1());
    printf("Points: %d\n", task_2());
    return 0;
}