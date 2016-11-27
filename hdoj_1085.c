#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 8001

int c1[MAX], c2[MAX];

int main(int argc, const char *argv[])
{
    int i, j, k;
    int to;
    int num[3], elem[3] = {1, 2, 5};

    while (scanf("%d %d %d", &num[0], &num[1], &num[2]) && !(num[0] == 0 && num[1] == 0 && num[2] == 0)) {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));

        for (i = 0; i <= num[0]; i++) {
            c1[i] = 1;
        }

        to = num[0] * elem[0];
        for (i = 1; i < 3; i++) {
            to += num[i] * elem[i];
            for (j = 0; j <= to; j++) {
                for (k = 0; k + j <= to; k += elem[i]) {
                    c2[k + j] += c1[j];
                }
            }

            for (j = 0; j <= to; j++) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }

       for (i = 1; i <= MAX && c1[i]; i++) ;

       printf("%d\n", i);
    }

    return 0;
}