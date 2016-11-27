#include <stdio.h>
#include <stdlib.h>

int score[100][100];

int func(int num)
{
    int i, j;
    int max;

    for (i = 1; i <= num; i++) {
        for (j = 1; j <= i; j++) {
            scanf("%d", &score[i][j]);
        }
    }

    for (i = num-1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            max = score[i+1][j] > score[i+1][j+1] ? score[i+1][j] : score[i+1][j+1];
            score[i][j] = max + score[i][j];
        }
    }

    return score[1][1];
}

int main()
{
    int num, height;

    scanf("%d", &num);
    while (num--) {
        scanf("%d", &height);

        printf("%d\n", func(height));
    }

    return 0;
}