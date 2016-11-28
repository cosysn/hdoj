#include <stdio.h>

int gcd(int a, int b)
{
    int r;
    
    if (a < b) { /*求a和b的最大公约数时，保证a>b*/
        r = a;
        a = b;
        b = r;
    }

    /*辗转相除*/
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
 
    return a;   
}


int main(int argc, char *argv[])
{
    int n, m;
    
    while ((scanf("%d %d", &n, &m) != EOF) && (m != -1 && n != -1)) {
        if (gcd(n, m) == 1) {
            printf("YES\n");
        } else {
            printf("POOR Haha\n");
        }
    }
}
