#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int main(void)
{
    int** arr;
    int N;

    scanf("%d", &N);

    arr = (int**)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++)
    {
        arr[i] = malloc(sizeof(int) * N);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = 0;
        }
    }

    int x = 1;
    int y = 1;

    char* str = (char*)malloc(sizeof(char) * 50);
    scanf("%s", str);

    char* p;
    p = str;
    while (*p != '\0')
    {
        if (*p == 'D')
        {
            if (x + 1 > N)
            {
                p++;
                continue;
            }
            else
            {
                x++;
                arr[x - 1][y - 1] = 1;
                p++;
            }
        }
        else if (*p == 'L')
        {
            if (y - 1 == 0)
            {
                p++;
                continue;
            }
            else
            {
                y--;
                arr[x - 1][y - 1] = 1;
                p++;
            }
        }
        else if (*p == 'R')
        {
            if (y + 1 > N)
            {
                p++;
                continue;
            }
            else
            {
                y++;
                arr[x - 1][y - 1] = 1;
                p++;
            }
        }
    }

    printf("\n(%d, %d)", x, y);
}