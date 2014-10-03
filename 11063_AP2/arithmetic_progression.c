#include<stdio.h>

void print_ap(long long a, long long d, long long n)
{
    long long i;
    printf("%lld \n", n);

    for (i = 0; i < n; i++) {
        printf("%lld ", a + (i*d));
    }

}
void ap(long long third_num, long long last_third_num, long long sum)
{
    long long a, n, d;

    n = (2 * sum)/ (third_num + last_third_num);

    d = (last_third_num - third_num)/(n - 5);
    a = third_num - (2 * d);

    print_ap(a, d, n);

}

int main()
{
    int tries;
    long long third_num, last_third_num, sum;

    scanf("%d", &tries);

    while(tries--) {
        scanf("%lld %lld %lld", &third_num, &last_third_num, &sum);
        ap(third_num, last_third_num, sum);
    }
    return 0;
}
