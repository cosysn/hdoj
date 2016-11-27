#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 301

int c1[MAX], c2[MAX];

int main(int argc, const char *argv[])
{
    int n;
    int i, j, k;

    while (scanf("%d", &n) && n) {
        for (i = 0; i <= n; i++) {
            c1[i] = 1;
            c2[i] = 0;
        }

        for (i = 2; i <= 17; i++) {
            for (j = 0; j <= n; j++) {
                for (k = 0; k + j <= n; k += i * i) {
                    c2[k + j] += c1[j];
                }
            }

            for (j = 0; j <= n; j++) {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }

        printf("%d\n", c1[n]);
    }

    return 0;
}