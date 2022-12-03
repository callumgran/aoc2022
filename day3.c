#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define UPPERCASE_ASCII_DOWN_VAL (65 - 27)
#define LOWERCASE_ASCII_DOWN_VAL (97 - 1)
#define CASE_DELIMITER '['

int task_1()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    char buffer[128];

    memset(buffer, 0, 128);

    int total = 0;
    int shared = 0;

    while (fgets(buffer, 128, fp) != NULL) {
        int half_len = strlen(buffer) >> 1;
        for (int i = 0; i < half_len; i++) {
            for (int j = half_len; j < half_len << 1; j++) {
                if (*(buffer + i) == *(buffer + j)) {
                    shared = *(buffer + i);
                    if (shared < CASE_DELIMITER)
                        total += (shared - UPPERCASE_ASCII_DOWN_VAL);
                    else
                        total += (shared - LOWERCASE_ASCII_DOWN_VAL);
                    goto next_one;
                }
            }
        }
next_one:
    continue;
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

    char buffer[3][128];

    int total = 0;
    int shared = 0;

    int l = 0;
    while (fgets(buffer[l++], 128, fp) != NULL) {
        if (l == 3) {
            l = 0;
            
            int len1 = strlen(buffer[0]);
            int len2 = strlen(buffer[1]);
            int len3 = strlen(buffer[2]);
            for (int i = 0; i < len1; i++) {
                for (int j = 0; j < len2; j++) {
                    if (*(buffer[0] + i) == *(buffer[1] + j)) {
                        shared = *(buffer[0] + i);
                        for (int k = 0; k < len3; k++) {
                            if (*(buffer[2] + k) == shared) {
                                shared = *(buffer[2] + k);
                                if (shared < CASE_DELIMITER)
                                    total += (shared - UPPERCASE_ASCII_DOWN_VAL);
                                else
                                    total += (shared - LOWERCASE_ASCII_DOWN_VAL);
                                goto next_two;
                            }
                        }
                    }
                }
            }
        }
next_two:
    continue;
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