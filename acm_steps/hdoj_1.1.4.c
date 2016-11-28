#include <stdio.h>
int main(int argc, char **argv)
{
    int i;
    int n;
    int sum;
    int a;

   while ((scanf("%d", &n) != EOF) && (n != 0)) {
        sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a);
            sum += a;
        }
        printf("%d\n", sum);
    }
    return 0;
}
