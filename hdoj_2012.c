#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#define _REOPEN
//#define N 1000000

int isprime(int n)
{
    int s, e = (int)(sqrt(n) + 1);
    for (s = 2; s < e; s++) {
        if (n % s == 0) return 0;
    }
    return 1;
}

int main(int argc, const char *argv[])
{
    int x, y;
    int i;
    int ov;

    #ifdef _REOPEN
    freopen("1.txt", "r", stdin);
    #endif // _REOPEN

    while (scanf("%d %d", &x, &y) && (x != 0 || y != 0)) {
        ov = 1;
        for (i = x; i <= y; i++) {
            if (!isprime(i*i + i + 41)){
                ov = 0;
                break;
            }
        }

        if (ov)
            printf("OK\n");
        else
            printf("Sorry\n");
    }

    return 0;
}