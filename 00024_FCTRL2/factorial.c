#include<stdio.h>

long long unsigned int factorial(long long unsigned int n)
{
    long long unsigned int res;
    res = 1;

    while (n) {
        res *= n;
        n--;
    }

    return res;
}

int main()
{
    int tries;
    int num;

    scanf("%d", &tries);
    while (tries--) {
        scanf("%d", &num);
        printf("%llu\n", factorial(num));
    }
return 0;
}

