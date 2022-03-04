#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 2 * h - 1

void print(char c, int n) {
    for (int i = 0; i < n; i++)
        printf("%c", c);
}
void sapin(int h, int lt, int ht)
{
    for (int i = 0; i < h; i++)
    {
        int tmp = (L - (2 * i + 1)) / 2;
        print(' ', tmp);
        print('*', 2 * i + 1);
        print(' ', tmp);
        printf("\n");
    }

    for (int i = 0; i < ht; i++)
    {
        int tmp = (L - lt) / 2;
        print(' ', tmp);
        print('|', lt);
        print(' ', tmp);
        printf("\n");
    }
}

void sapin2(int h, int lt, int ht, int e, int p)
{
    for (int i = 0; i < h; i++)
    {
        int tmp = (L - (2 * i + 1)) / 2;
        print(' ', tmp);
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (i == h - e && j == p - 1)
                printf("0");
            else
                printf("*");
        }

        print(' ', tmp);
        printf("\n");
    }

    for (int i = 0; i < ht; i++)
    {
        int tmp = (L - lt) / 2;
        print(' ', tmp);
        print('|', lt);
        print(' ', tmp);
        printf("\n");
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int vals[5];
    for (int i = 0; i < 3; i++)
    {
        vals[i] = rand() % 50;
    }
    vals[3] = rand() % vals[0];
    vals[4] = rand() % (2 * vals[0] - 1 -2*vals[3]);
    sapin2(vals[0], vals[1], vals[2], vals[3], vals[4]);
    return 0;
}
