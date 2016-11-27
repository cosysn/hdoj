#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1002

struct hwork
{
    int deadline;
    int score;
} work[MAX];

int flag[MAX];

int cmp(const void *a, const void *b)
{
    hwork *a1 = (hwork *)a, *b1 = (hwork *)b;

    if (a1->score != b1->score)
        return b1->score - a1->score;
    else
        return a1->deadline - b1->deadline;
}

int func(hwork *work, int n)
{
    int sum = 0;
    int i, j;

    memset(flag, 0, sizeof(flag));

    qsort(work, n, sizeof(hwork), cmp);

    for (i = 0; i < n; i++) {
        for (j = work[i].deadline; j > 0; j--) {
            if (flag[j] == 0) {
                flag[j] = 1;
                break;
            }
        }

        if (j == 0) sum += work[i].score;
    }

    return sum;
}

int main(int argc, const char *argv[])
{
    int t, n;
    int i;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &work[i].deadline);
        }

        for (i = 0; i < n; i++) {
            scanf("%d", &work[i].score);
        }

        printf("%d\n", func(work, n));
    }

    return 0;
}
[ Copy to Clipboard ]    [ Save to File]
