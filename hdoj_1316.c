#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MROWS 600
#define MCOLS 102

char re[MROWS][MCOLS] = {"1", "2"};

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

    i3--;
    while (opr3[i3] == '0' && i3 > 0) --i3;
    opr3[++i3] = '\0';

    i2 = i3--;
    for (i1 = 0; i1 < i3; i1++, i3--) {
        ch = opr3[i1]; opr3[i1] = opr3[i3]; opr3[i3] = ch;
    }

    return i2;
}

int cmp(char *str1, char *str2)
{
    int i;
    int len1 = strlen(str1), len2 = strlen(str2);

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;
    i = 0;
    while (i < len1 && str1[i] == str2[i]) i++;

    return str1[i] - str2[i];
}

int main(int argc, const char *argv[])
{
    int k = 2, i, count = 0;
    char fn0[MCOLS] = "1", fn1[MCOLS]= "2";
    char fn[MCOLS];

    while (1) {
        if (add(fn, fn0, fn1) > 100) break;
        strcpy(re[k], fn);
        strcpy(fn0, fn1);
        strcpy(fn1, fn);
        k++;
    }

    while (scanf("%s %s", fn0, fn1) &&
        (strcmp(fn0, "0") || strcmp(fn1, "0"))) {
        count = 0;
        for(i = 0; i <= k; i++) {
            if (cmp(fn0, re[i]) <= 0 && cmp(fn1, re[i]) >= 0) {
                //printf("%s\n", re[i]);
                count ++;
            }
        }

        printf("%d\n", count);
    }


    return 0;
}