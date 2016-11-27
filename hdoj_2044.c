#include <stdio.h>

int main()
{
    int n, i;
    int start, end, len;
    long long fn, fn1, fn2;

    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &start, &end);

        len = end - start;
        if (len == 1) fn = 1;
        else if(len == 2) fn = 2;
        else {
            fn1 = 2;
            fn2 = 1;
            for (i = 3; i <= len; i++) {
                fn = fn1 + fn2;
                fn2 = fn1;
                fn1 = fn;
            }
        }

        printf("%I64d\n", fn);
    }

    return 0;
}