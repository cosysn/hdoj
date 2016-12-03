#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_NUM_MAX 10
#define STUDENT_NUM_MAX 1000

int score[TEST_NUM_MAX];

struct student {
    char examinee[21];
    int ac;
    int score;
} arr[STUDENT_NUM_MAX];

int comp(const void *a, const void *b)
{
    struct student *c = (struct student *)a;
    struct student *d = (struct student *)b;
    if (c->score > d->score) {
        return -1;
    } else if(c->score == d->score){
        return strcmp(c->examinee, d->examinee);
    } else {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int i, j;
    int m, n, g;
    int s;
    int num;

    while((scanf("%d", &n) != EOF) && (n != 0)) {
        scanf("%d %d", &m, &g);
        for(i = 0; i < m; i++) {
            scanf("%d", &score[i]);
        }

        num = 0;
        for (i = 0; i < n; i++) {
            scanf("%s %d", arr[num].examinee, &arr[num].ac);
            arr[num].score = 0;
            for(j = 0; j < arr[num].ac; j++) {
                scanf("%d", &s);
                arr[num].score += score[s-1];
            }

            if (arr[num].score >= g)
                num++;
        }

        qsort(arr, num, sizeof(struct student), comp);

        printf("%d\n", num);
        for (i = 0; i < num; i++) {
            printf("%s %d\n", arr[i].examinee, arr[i].score);
        }
    }

    return 0;
}
