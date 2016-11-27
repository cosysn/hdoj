#include <stdio.h>

int main()
{
    int n, i;

    long long int arr[40] = {3, 8};

    for (i = 2; i < 40; i++)
        arr[i] = (arr[i-1] + arr[i-2]) << 1;

    while (scanf("%d", &n) != EOF) {
        printf("%I64d\n", arr[n-1]);
    }

    return 0;
}