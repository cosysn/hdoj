#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#define _REOPEN 1

int set[1002];

int find (int x)
{
    int r = x;

    while (set[r] != r) r = set[r];

    return r;
}

void merge(int x, int y)
{
    int m, n;

    m = find(x);
    n = find(y);

    if (m != n) set[m] = n;

    return ;
}

int main(int argc, const char *argv[])
{

    int n, m;
    int x, y;
    int i;
    int count;

    #ifdef _REOPEN
        freopen("1.txt", "r", stdin);
    #endif // _REOPEN

    while (scanf("%d", &n) && n && scanf("%d", &m)) {
        for (i = 1; i <= n; i++) set[i] = i;
        for (i = 1; i <= m; i++) {
            scanf("%d %d", &x, &y);
            merge(x, y);
        }

        for (count = -1, i = 1; i <= n; i++) {
            if (set[i] == i) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
