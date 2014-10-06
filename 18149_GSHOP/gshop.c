#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 100

int comp(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}
#if 0
    int i, j, res;
    i = *(int *)a;
    j = *(int *)b;

    res = 0;
    if (i < j) 
        res = -1;
    else if (i > j)
        res = 1;
    return res;
#endif

void print_array(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

}

int find_least_num(int *a, int n, int i)
{

    if (i == 0) 
        return i;

    if (i == n)
        return n-1;
     
    if (a[i-1] < a[i]) 
        return i-1;
    else 
        return i;

}

long long max_sum(int *a, int n, int k)
{
    long long sum;
    int index, i;

    qsort(a, n, sizeof(int), comp);
    //print_array(a, n);

    for (i = 0; i < k && i < n; i++) {
        if (a[i] >= 0)
            break;
        a[i] = -a[i];
    }
    /* i < k < n or i < n < k */
    if (i < k) {
        /* odd operations remaining */
        if ((k-i)%2 != 0)  {
            index = find_least_num(a, n, i);
            a[index] = -a[index];
        }
    }

    sum = 0;
    for (i = 0; i < n; i++) 
        sum += a[i];
    return sum;
}



int main()
{
    int tries, n, k, i;

    int a[MAX_ELEMENTS];

    scanf("%d", &tries);
    while (tries--) {
        scanf("%d %d", &n, &k);
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%lld\n", max_sum(a, n, k));
    }

    return 0;
}
