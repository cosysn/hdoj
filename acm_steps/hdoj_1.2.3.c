#include <stdio.h>

#define N 51

int stack[N];

int main(int argc, char *argv[])
{
    int i = 0, n = 0;
    int avg = 0;
    int sum = 0;
    int moved = 0;
    int set = 0;  

    while((scanf("%d", &n) != EOF) && (n != 0)) {
        sum = 0;
        moved = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &stack[i]);
            sum += stack[i];
        }

        avg = sum / n;
        for (i = 0; i < n; i++) {
            if (stack[i] > avg) {
                moved += stack[i] - avg;
            }
        }
        set++;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", set, moved);
    }
    return 0;
}
