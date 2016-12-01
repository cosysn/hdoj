#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001
char buf[MAX];
int count[26];

int main(int argc, char const *argv[])
{
    int i;
    char *p;

    while(gets(buf)) {
        memset(count, 0x0, sizeof(count));

        for (p = buf; *p; p++) {
            if (*p >= 'a' && *p <= 'z') {
                count[*p-'a']++;
            }
        }

        for (i = 0; i < 26; i++) {
            printf("%c:%d\n", 'a'+i, count[i]);
        }
        printf("\n");
    }

    return 0;
}
