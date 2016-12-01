#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int i, t;
    int a, b, c;
    int rt;

    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d %d %d", &a, &b, &c);

        a *= a;
        b *= b;
        c *= c;
        if ((a+b == c) || (a+c == b) || (b+c == a)) {
            printf("Scenario #%d:\nyes\n", i);
        } else {
            printf("Scenario #%d:\nno\n", i);
        }

        printf("\n");
    }

    return 0;
}
