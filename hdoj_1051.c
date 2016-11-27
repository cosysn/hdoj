#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1000000

struct stick
{
    int l, w;
} s[5001];

int cmp(const void *a, const void *b)
{
    struct stick *s1, *s2;

    s1 = (stick *)a, s2 = (stick *)b;

    if (s1->l != s2->l)
        return s1->l - s2->l;
    else
        return s1->w - s2->w;
}

int func(struct stick *s, int n)
{
    int i, j, k;
    int gr[5001];
    int count = 0;
    int min, p = -1;

    qsort(s, n, sizeof(stick), cmp); //°′3¤&#182;è&#197;&#197;Dò

 /*   for (i = 0; i < n; i++) {
            printf("%d %d\n", s[i].l, s[i].w);
        }
*/
    gr[0] = s[0].w;
    count = 1, k = 1;
    for (i = 1; i < n; i++) {

        min = INF, p = -1;

        for (j = 0; j < k; j++) {
            int temp = s[i].w - gr[j];
            if (temp >= 0 && min > temp) {
                min = temp;
                p = j;
            }
        }

        if (p >= 0) {
            gr[p] = s[i].w;
        } else {
            gr[k++] = s[i].w;
            count++;
        }
    }

    return count;
}

int main(int argc, const char *argv[])
{
    int t, n;
    int i;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d %d", &s[i].l, &s[i].w);
        }

        printf("%d\n", func(s, n));
    }

    return 0;
}