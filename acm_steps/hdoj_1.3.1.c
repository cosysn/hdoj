#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

struct room {
    int j, f;
    double r;
} arr[MAX];

int comp(const void *a, const void *b)
{
    if (((struct room *)b)->r >= ((struct room *)a)->r)
        return 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    int i;
    int m, n;
    double ans;

    while((scanf("%d %d", &m, &n) != EOF) &&
                 ((m != -1) || (n != -1))) {
        for (i = 0; i < n; i++) {
            scanf("%d %d", &arr[i].j, &arr[i].f);
            arr[i].r = arr[i].j * 1.0 / arr[i].f;
        }

        qsort(arr, n, sizeof(struct room), comp);

        ans = 0;
        for (i = 0; i < n; i++) {
            if (m >= arr[i].f) {
                ans += arr[i].j;
                m -= arr[i].f;
            } else {
                ans += (double)m / arr[i].f * arr[i].j;
                break;
            }
        }

        printf("%.3lf\n", ans);
    }

    return 0;
}
