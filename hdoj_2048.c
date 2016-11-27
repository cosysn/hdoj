#include <stdio.h>
#include <stdlib.h>

long long int fn[20] = {0, 1};
long long int jiecheng[20] = {1, 2};

int main(int argc, char *argv[])
{
    int i;
    int lines;
    int num;

    for (i = 2; i < 20; i++) {
        fn[i] = i*(fn[i-1]+fn[i-2]);
        jiecheng[i] = (i+1) *jiecheng[i-1];
    }

    scanf("%d", &lines);
    while (lines--) {
        scanf("%d", &num);
        num--;
        printf("%.2lf%c\n", (double)fn[num]/jiecheng[num]*100, '%');
    }

    return 0;
}