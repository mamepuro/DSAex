#include <stdio.h>
#include <stdlib.h>
int recursive(int n, int m) {
    // Let n be the smaller number.
    if (n < m) {
    int tmp = m;
    m = n;
    n = tmp;
    }
    int r = n%m;
    n = m;
    m = r;
    if(r == 0)
    {
        return n;
    }
    n = recursive(n,m);
    return n;
}