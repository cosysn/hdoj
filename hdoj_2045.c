#include <stdio.h>

/*
 * f(1) = 3;
 * f(2) = 6;
 * f(3) = 6;
 * f(n) = f(n-1) + 2 * f(n-2);
 */

int main()
{
    int i, n, end;
    long long int fn1, fn2, fn;

    while (scanf("%d", &n) != EOF) {
        switch (n) {
            case 1: fn = 3; break;
            case 2: fn = 6; break;
            case 3: fn = 6; break;
            default :
                end = n - 3;
                fn1 = 6;
                fn2 = 6;

                for (i = 0; i < end; i++) {
                    fn = fn1 + (fn2 << 1);
                    fn2 = fn1;
                    fn1 = fn;
                }
        }
        printf("%I64d\n", fn);
        //printf("%lld\n", fn);
    }

    return 0;
}