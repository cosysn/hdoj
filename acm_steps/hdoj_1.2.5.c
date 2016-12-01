#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, n;
    int num;
    int res;

    while((scanf("%d", &n) != EOF) && (n != 0)) {
        res = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &num);
            res ^= num;
        }

        printf("%d\n", res);
    }

    return 0;
}