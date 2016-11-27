#include<stdio.h>
 #include<string.h>

 int prime[38]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};
 int visit[21],result[21];
 int n;

 int dfs(int num)
 {
     int print(int m);
     int i;
     if(num==n && prime[result[num]+result[1]])
         print(num);
     else
     {
         for(i=2;i<=n;i++)
         {
             if(prime[result[num]+i] && !visit[i])
             {
                 result[num+1]=i;
                 visit[i]=1;
                 dfs(num+1);
                 visit[i]=0;
             }
         }
     }
     return 0;
 }

 int print(int m)
 {
     int i;
     printf("%d",result[1]);
     for(i=2;i<=m;i++)
         printf(" %d",result[i]);
     printf("\n");
     return 0;
 }

 int main()
 {
     int i=1;
     while(scanf("%d",&n)==1)
     {
         printf("Case %d:\n",i++);
         memset(visit,0,sizeof(visit));
         visit[1]=1;
         result[1]=1;
         dfs(1);
         printf("\n");
     }
     return 0;
 }
