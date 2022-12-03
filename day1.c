#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define swap(a, b)      \
        do {            \
            int c = a;  \
            a = b;      \
            b = c;      \
        } while(0);     \

int task_one()
{
    FILE *fp;
    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    int max = 0;
    int temp = 0;
    char ch;
    char buffer[128];

    memset(buffer, 0, 128);

    while (fgets(buffer, 128, fp) != NULL) {
        if (*buffer == '\n') {
            if (max < temp) {
                max = temp;
            }
            temp = 0;
        } else {
            temp += atoi(buffer);
        }
    }

    fclose(fp);

    return max;
}

int task_two()
{
    FILE *fp;
    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        fclose(fp);
        exit(1);
    }

    int temp = 0;
    int max = 0;
    char ch;
    char buffer[128];
    int arr[3];

    memset(buffer, 0, 128);
    memset(arr, 0, 3);

    while (fgets(buffer, 128, fp) != NULL) {
        if (*buffer == '\n') {
            for (int i = 0; i < 3; i++) {
                if (arr[i] < temp) {
                    arr[i] = temp;
                    if (arr[0] > arr[1] && arr[0] > arr[2]) {
                        swap(arr[0], arr[1]);
                        swap(arr[1], arr[2]);
                    } else if (arr[0] < arr[1] && arr[0] > arr[2]) {
                        swap(arr[0], arr[2]);
                    } else if (arr[0] > arr[1]) {
                        swap(arr[0], arr[1]);
                    } else if (arr[1] > arr[2]) {
                        swap(arr[1], arr[2]);
                    }
                    break;
                }
            }
            temp = 0;
        } else {
            temp += atoi(buffer);
        }
    }
    fclose(fp);

    return arr[0] + arr[1] + arr[2];
}

int main()
{
    printf("%d\n", task_one());
    printf("%d\n", task_two());
    return 0;
}