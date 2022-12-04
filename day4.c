#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define UPPERCASE_ASCII_DOWN_VAL (65 - 27)
#define LOWERCASE_ASCII_DOWN_VAL (97 - 1)
#define CASE_DELIMITER ','

int task_1()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    int total = 0;
    int from_shelf_one;
    int from_shelf_two;
    int to_shelf_one;
    int to_shelf_two;
    char placeholder;
    char placeholder2;
    char placeholder3;

    while (fscanf(fp, "%d %c %d %c %d %c %d \n", 
            &from_shelf_one, &placeholder, &to_shelf_one, 
            &placeholder2, &from_shelf_two, &placeholder3, &to_shelf_two )
            != EOF) {
        if (from_shelf_one >= from_shelf_two && to_shelf_one <= to_shelf_two)
            total++;
        else if (from_shelf_two >= from_shelf_one && to_shelf_two <= to_shelf_one)
            total++;
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

    int total = 0;
    int from_shelf_one, from_shelf_two, to_shelf_one, to_shelf_two;
    char placeholder, placeholder2, placeholder3;

    while (fscanf(fp, "%d %c %d %c %d %c %d \n", 
            &from_shelf_one, &placeholder, &to_shelf_one, 
            &placeholder2, &from_shelf_two, &placeholder3, &to_shelf_two )
            != EOF)
        if (!(to_shelf_one < from_shelf_two || to_shelf_two < from_shelf_one))
            total++;

    fclose(fp);

    return total;
}


int main()
{
    printf("Points: %d\n", task_1());
    printf("Points: %d\n", task_2());
    return 0;
}