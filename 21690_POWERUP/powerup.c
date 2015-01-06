#include<stdio.h>
#include<stdlib.h>
//typedef unsigned long long long long;
/* Computing (a^p)%m */
long long fastpower(long long a, long long p, long long m)
{
    long long c;
    if (a == 0 && p != 0)
        return 0;

    if (a % m == 0) {
        if (p == 0)
            return 1;
        return 0;
    }

    c = 1;
    while (p) {
        if (p & 1) 
            c = (c * a) % m;
        a = (a * a) % m;
        p = p >> 1;
    }
    return c;
}

int main()
{
    long long a, b, c;
    long long p, t, r;
        
    p = 1000000007;

    while(1) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;

        if (a % p == 0) {
            r = 0;
            if (b == 0 && c != 0)
                r = 1;
        }
        else {
            t = fastpower(b, c, p-1); 
            r = fastpower(a, t, p);
        }
        printf("%lld\n", r);
    }
    return 0;
}
