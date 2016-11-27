#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define N 30
#define V 30
#define INF 100000000

int cost[V][V];
int vis[V], lowc[V];

int prim(int cost[][N], int n)
{//The Graph has n vertex
    int i, j;
    int p; // work point
    int mcost;
    int r = 0;

    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i = 0; i < n; i++) lowc[i] = cost[0][i];

    for (i = 1; i < n; i++) {
        mcost = INF;
        p = -1;

        for (j = 1; j < n; j++) {
            if (vis[j] == 0 && mcost > lowc[j]) {
                mcost = lowc[j];
                p = j;
            }
        }

        if (mcost == INF) return -1;
        r += mcost;
        vis[p] = 1;

        for (j = 1; j < n; j++) {
            if (vis[j] == 0 && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
        }
    }

    return r;
}

int main(int argc, const char *argv[]){
    int i, j;
    int n, m, len;
    char start, end;

    while(scanf("%d",&n)!=EOF && n){
        for(i = 0;i <= n; i++) {
            for(j = 0;j <= n;j++)
                cost[i][j] = INF;
        }

        for(i = 0; i < n-1; i++){
            cin >> start >> m;
            for(j = 0; j < m; j++){
                cin >> end >> len;
                cost[i][end-'A'] = len;
                cost[end-'A'][i] = len;
            }
        }

        cout << prim(cost, n) << endl;
    }

    return 0;
}