#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int height[100001];
int l[100001], r[100001];

int main(int argc, const char *argv[])
{
    int n, i;
    long long max ;
    long long area;

    while (scanf("%d", &n) && n) {
        for (i = 0; i < n; i++) {
            scanf("%d", height+i);
            l[i] = i;
            r[i] = i;
        }

        for (i = 0; i < n; i++) {
            while (l[i] > 0 && height[l[i] - 1] >= height[i]) l[i] = l[l[i] - 1];
        }

        for (i = n-1; i > -1; i--) {
            while (r[i] < n-1 && height[r[i] + 1] >= height[i]) r[i] = r[r[i] + 1];
        }

        max = 0;
        for (i = 0; i < n; i++) {
            area = (long long)(r[i] - l[i] + 1) * height[i];

            if (area > max) {
                max = area;
            }
        }

        printf("%I64d\n", max);
    }

    return 0;
}