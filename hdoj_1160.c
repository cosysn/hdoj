#include <stdio.h>
#include <stdlib.h>

#define M 1005

struct tu
{
    int w;
    int s;
    int ID;
}a[M];

int dp[M];
int flag[M];
int temp[M];


int compare(const void *a, const void *b)
{
    struct tu *t1 = (struct tu *)a;
    struct tu *t2 = (struct tu *)b;
    return t1->w - t2->w;
}

int main()
{
    int n,i,j;
    int nMax,r;
    n= 0;
    while(scanf("%d %d",&a[n].w,&a[n].s) != EOF)
    {
        a[n].ID = n + 1;
        ++n;
    }

    //按体重升序排列
    qsort(a,n,sizeof(a[0]), compare);

    nMax = 0;
    for(i = 0; i < n; ++i)
    {
        dp[i] = 1;
        flag[i] = -1;
        for(j = 0; j < i; ++j)
        {
            if(a[j].s > a[i].s && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                flag[i] = j;//记下到i的最大的j的编号
            }
        }
        if(dp[i] > nMax)
        {
            nMax = dp[i];
            r = i;
        }
    }

    printf("%d\n",nMax);

    i = 0;
    while(r >= 0)
    {
        temp[i++] = r;//用temp数组来辅助，把结果反转过来输出
        r = flag[r];
    }

    for(; i > 0; --i)
    {
        printf("%d\n",a[temp[i - 1]].ID);
    }
    return 0;
}