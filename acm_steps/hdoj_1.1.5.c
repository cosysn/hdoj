#include <stdio.h>
int main(int argc, char **argv)
{
    int i, j;
    int n, m;
    int sum;
    int a;

   scanf("%d", &n);
   for (i = 0; i < n; i++) {
        scanf("%d", &m);
        sum = 0;
        for (j = 0; j < m; j++) {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
    return 0;
}
