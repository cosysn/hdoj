#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1001

int dp[MAXSIZE][MAXSIZE];        //用来保存状态

int lcm(char *src1, char *src2)
{
    int n = strlen(src1), m = strlen(src2);
    int i, j;

    dp[0][0] = 0;
    for (i = 1; i <= n; i++) dp[i][0] = 0;
    for (i = 1; i <= m; i++) dp[0][i] = 0;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (src1[i-1] == src2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else if (dp[i][j-1] > dp[i-1][j]) dp[i][j] = dp[i][j-1];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][m];
}



int main(int argc, const char *argv[])
{
    char src1[MAXSIZE], src2[MAXSIZE];

    while ( scanf("%s %s", src1, src2) != EOF) {
        printf("%d\n", lcm(src1, src2));
    }
}