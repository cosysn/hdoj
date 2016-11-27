#include <stdio.h>

int main(int argc, const char *argv[])
{
  int n, m, x, y;
  int t;
  int lcm;

  while (scanf("%d %d", &x, &y) != EOF) {
    n = x, m = y;
    for (; (t = n % m); n = m, m = t) ;
    lcm = x / m * y;

    printf("%d\n", lcm);
  }
}