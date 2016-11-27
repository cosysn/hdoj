#include <stdio.h>

int main()
{
    int i, n;
    long long int arr[51] = {1, 2};

    for (i = 2; i < 50; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    while (scanf("%d", &n) != EOF) {
        printf("%I64d\n", arr[n-1]);
    }

    return 0;
}