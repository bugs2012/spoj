#include<stdio.h>
#include<string.h>

unsigned long long factorial(unsigned long long num)
{
    if (num == 1 || num == 0)
        return 1;

    return (num  * factorial(num -1));
}

#if 1
int fact_zeros(int num)
{
    int n, m , x, c;

    c = 0;
    m = 1;
    n = num/5;
    while (n >= 1) {
        x = n - n/5;
        c += x * m;
        n /= 5;
        m++;
    }

    return c;

}
#else
int fact_zeros(int num)
{
    int i, c, t;
    c = 0;
    for (i = 5; i <= num; i+= 5) {
        t = i;
        while (t%5 == 0) {
            t = t/5;
            c++;
        }
    }
    return c;

}
#endif

int main()
{
    int tries;
    int num;

    scanf("%d", &tries);

    while(tries--) {
        scanf("%d", &num);
        printf("%d\n", fact_zeros(num));
        //printf("%llu\n", factorial(num));
    }
    return 0;
}
