#include <stdio.h>
#include <math.h>


#define MAX_NUM 1000000
int prime[MAX_NUM];

void seive(int n)
{
    int i;
    long long j;

    prime[0] = 1;
    prime[1] = 1;
    for (i = 2; i <= n; i++) {
        if (!prime[i]) {
            prime[i] = i;
            for (j = 1; j*i <= n; j++) 
                prime[j*i] = i;
        }
    }
}

int euler_totient(int n)
{
    int res, p;
    // Check if n is prime
#if 0
    if (n == 1)
        return 1;

    if (prime[n] == n) 
        return n-1;
#endif
    res = n;
    while (n > 1) {
        p = prime[n];
        res -= res/p;
        do {
            n = n/p;
        } while (n%p == 0);
    }

    return res;
        
}

int main()
{
    int t, n;
    seive(MAX_NUM);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        printf("%d\n", euler_totient(n));
    }
    return 0;
}

