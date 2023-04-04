#include "stack.h"

void conversion(int n, int d) {
    sqstack S; int k, e;
    Init_Stack(&S);
    while (n > 0) { k = n % d; Push(&S, k); n /= d;}
    while(S.top != 0) {
        Pop(&S, &e);
        printf("%d", e);
    }
    printf("\n");
}

int main()
{
    conversion(9, 2);
    return 0;
}