#include <stdio.h>
int main(int argc, char **argv)
{
    int n;
    int i;
    int a,b;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&a, &b);
        printf("%d\n", a+b);
    }
    return 0;
}
