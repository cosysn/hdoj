#include <stdio.h>
#include <stdlib.h>

long long int cuopai[21] = {1, 0, 1};
long long int jiecheng[21] = {1, 1, 2, 6};

int main(int argc, char **argv)
{
    int lines;
    int m, n;
    long long int result, cnm;
    int i;

    for (i = 3; i < 21; i++)
    {
        cuopai[i] = (i-1)*(cuopai[i-1]+cuopai[i-2]);
        jiecheng[i] = i * jiecheng[i-1];
    }

    scanf("%d", &lines);
    while (lines--)
    {
        scanf("%d %d", &n, &m);
        cnm = (jiecheng[n]/jiecheng[m])/jiecheng[n-m];
        result = m!=1 ? cnm*cuopai[m] : cnm;
        printf("%I64d\n", result);
    }
    return 0;
}