#include<stdio.h>
#include<string.h>
unsigned long long factorial(unsigned long long num)
{
    if (num == 1 || num == 0)
        return 1;

    return (num  * factorial(num -1));
}

int fact_zeros(int num)
{
    int i, c, j, t;
    
    c = 0;
    j = 1;

    for (i = 5; i <= num; i+= 5, j++) {
        if (j%5 == 0) {
            t = i;
            while(t >= 5) {
                t = t/5;
                c++;
            }
        } else {
            c++;
        }
    }
    return c;

}

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
}

