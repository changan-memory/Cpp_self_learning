#include <stdio.h>

extern int Add(int a, int b);

int main() {
    int a = 10, b = 20;
    int res = Add(a, b);
    printf("%d\n", res);
    return 0;
}