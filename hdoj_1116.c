#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//#define _REOPEN

#define NODE_MAX 26
#define STR_LEN 2002

int bin[NODE_MAX]; //并查集
int in[NODE_MAX], out[NODE_MAX];
int data[NODE_MAX];
int flag[NODE_MAX];

void euler_init(int size)
{ //初始化集合，只有当bin[i] == i时，代表有集合i
    for (int i = 0; i < size; i++) bin[i] = i;
    return ;
}

int euler_find(int x)
{// 查找元素x所属的集合
    int r = x;

    while (r != bin[r]) r = bin[r];

    return r;
}

int euler_merge(int x, int y)
{// 将x 和 y的集合合并
    int m, n;

    m = euler_find(x);
    n = euler_find(y);

    if (m > n) {
        int t = m;
        m = n;
        n = t;
    }

    if (m != n) {
        bin[m] = n; //  将集合n中的元素合并到m中
        return 1;
    }

    return 0;
}

int main(int argc, const char *argv[])
{
    int n, m;
    int i, j, k;
    int count; //连通分支数
    char temp[STR_LEN];
    int s, e;

    #ifdef _REOPEN
    freopen("1.txt", "r", stdin);
    #endif // _REOPEN

    scanf("%d", &n);
    while (n--) {
        scanf("%d", &m);

        euler_init(26);

        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        memset(flag, 0, sizeof(flag));
        count = 0;
        k = 0;

        for (i = 0; i < m; i++) {
            scanf("%s", temp);
            s = temp[0] - 'a';
            e = temp[strlen(temp)-1] - 'a';
            euler_merge(s, e);
            in[e]++, out[s]++; //节点的初度与入度
            flag[s] = flag[e] = 1;
        }

        for (i = 0; i < 26; i++) {
            if (flag[i] && bin[i] == i) //出现一个连通分支
                count ++;
        }

        if (count > 1) { //图的连通性
            printf("The door cannot be opened.\n");
            continue;
        }

        for (i = 0; i < NODE_MAX; i++) {
            if (flag[i] && in[i] != out[i]) data[k++] = i;
        }

        if (k == 0) {
            printf("Ordering is possible.\n");
            continue;
        }

        i = data[0], j = data[1];
        if (k == 2 && ((in[i]-out[i] == 1 && out[j]-in[j] == 1) || (out[i]-in[i] == 1 && in[j]-out[j] == 1))) {
            printf("Ordering is possible.\n");
            continue;
        }

        printf("The door cannot be opened.\n");
    }

    return 0;
}
