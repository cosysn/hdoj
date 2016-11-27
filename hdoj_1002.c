nclude <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(char *opr3, char *opr1, char *opr2)
{
    int len1, len2;
    int i1, i2, i3;
    int carry;
    int temp;
    char ch;

    len1 = strlen(opr1); len2 = strlen(opr2);
    i1 = len1 - 1;
    i2 = len2 - 1;
    i3 = carry = 0;

    for (; i1 >= 0 && i2 >= 0; i1--, i2--) {
        temp = opr1[i1] - '0' + opr2[i2] - '0' + carry;
        carry = temp / 10;
        opr3[i3++] = temp % 10 + '0';
    }

    while (i1 >= 0) {
        temp = opr1[i1--] - '0' + carry;
        carry = temp / 10;
        opr3[i3++] = temp % 10 + '0';
    }

    while (i2 >= 0) {
        temp = opr2[i2--] - '0' + carry;
        carry = temp / 10;
        opr3[i3++] = temp % 10 + '0';
    }

    if (carry) opr3[i3++] = carry + '0';
    opr3[i3] = '\0';

    i2 = i3--;
    for (i1 = 0; i1 < i3; i1++, i3--) {
        ch = opr3[i1]; opr3[i1] = opr3[i3]; opr3[i3] = ch;
    }

    return i2;
}

int main(int argc, char const *argv[])
{
    int n;
    int i;
    char opr1[1001], opr2[1001], opr3[1002];

    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%s %s", opr1, opr2);
        add(opr3, opr1, opr2);

        if (i == 1) printf("Case %d:\n%s + %s = %s\n", i, opr1, opr2, opr3);
        else printf("\nCase %d:\n%s + %s = %s\n", i, opr1, opr2, opr3);
    }

    return 0;
}
