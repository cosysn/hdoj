#include <stdio.h>
#include <string.h>

#define N 102
#define V 102
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

int main(int argc, const char *argv[])
{
    int n;
    int q;
    int i, j;
    int x, y;

    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &cost[i][j]);
            }
        }

        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            scanf("%d %d", &x, &y);
            cost[x-1][y-1] = cost[y-1][x-1] = 0;
        }

        int num = prim(cost, n);

        if (num != -1)  printf("%d\n", num);
    }

    return 0;
}