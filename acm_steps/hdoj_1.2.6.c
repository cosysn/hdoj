#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int nn_rightmost(int n)
{
    int rt, off;
    static int map[10][5] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {4, 2, 4, 8, 6},
        {4, 3, 9, 7, 1},
        {2, 4, 6, 0, 0},
        {1, 5, 0, 0, 0},
        {1, 6, 0, 0, 0},
        {4, 7, 9, 3, 1},
        {4, 8, 4, 2, 6},
        {2, 9, 1, 0, 0}
    };

    rt = n % 10;
    if (map[rt][0] == 1)
        return map[rt][1];

    off = (n - 1) % map[rt][0] + 1;
    return map[rt][off];
}

int main(int argc, char const *argv[])
{
    int i, t;
    int n;
    int rt;

    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        rt = nn_rightmost(n);
        printf("%d\n", rt);
    }

    return 0;
}
