#include <stdio.h>
#include <stdlib.h>

struct point
{
    double x, y;
};

struct line
{
    point s, e;
};

double max(int i, int j)
{
    return (i > j) ? i : j;
}

double min(int i, int j)
{
    return (i > j) ? j : i;
}

double mulxi(point p0, point p1, point p2)
{
    return ((p1.x-p0.x) * (p2.y-p0.y) - (p2.x-p0.x) * (p1.y-p0.y));
}

int onsegment(point pi, point pj, point pk)
{
    if (min(pi.x, pj.x) <= pk.x && max(pi.x, pj.x) >= pk.x &&
        min(pi.y, pj.y) <= pk.y && max(pi.y, pj.y) >= pk.y)
        return 1;
    else
        return 0;
}

int intersect(point p1, point p2, point p3, point p4)
{
    double d1, d2, d3, d4;

    d1 = mulxi(p3, p4, p1);
    d2 = mulxi(p3, p4, p2);
    d3 = mulxi(p1, p2, p3);
    d4 = mulxi(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return 1;

    if (d1 == 0 && onsegment(p3, p4, p1))
        return 1;
    if (d2 == 0 && onsegment(p3, p4, p2))
        return 1;
    if (d3 == 0 && onsegment(p1, p2, p3))
        return 1;
    if (d4 == 0 && onsegment(p1, p2, p4))
        return 1;

    return 0;
}

int main(int argc, const char *argv[])
{
    int n, i, j;
    int num;
    line l[100];

    while (scanf("%d", &n) && n) {
        for (i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &l[i].s.x, &l[i].s.y, &l[i].e.x, &l[i].e.y);
        }

        num = 0;
        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++) {
                if (intersect(l[i].s, l[i].e, l[j].s, l[j].e)) {
                    num++;
                }
            }
        }

        printf("%d\n", num);
    }

    return 0;
}