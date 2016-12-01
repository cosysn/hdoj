#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int n, r, e, c;
    int revenues;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &r, &e, &c);
        revenues = e-c-r;

        if (revenues > 0) {
            printf("advertise\n");
        } else if (revenues == 0) {
            printf("does not matter\n");
        } else {
            printf("do not advertise\n");
        }
    }
}