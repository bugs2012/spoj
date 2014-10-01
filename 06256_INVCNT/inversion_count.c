#include<stdio.h>

#define MAX_ELEMENTS (200000+100) 

long long  count_inv(int *A, int l, int r)
{
    int i, j, k;
    int m;
    int tmp[MAX_ELEMENTS];
    long long inv;

    m = (l + r)/2;

    i = l; 
    j = m+1; 
    k = 0;
    inv = 0;

    while ((i <= m) && (j <= r)) {
        if (A[i] > A[j]) {
            tmp[k] = A[j];
            inv += (m - i + 1);
            j++;
        } else {
            tmp[k] = A[i];
            i++;
        }
        k++;
    }

    while (i <= m) {
        tmp[k++] = A[i++];
    }

    while (j <= r) {
        tmp[k++] = A[j++];
    }

    i = l;
    k = 0; 
    while (i <= r) {
        A[i++] = tmp[k++];
    }

    return inv;
}
void partition_and_count(int *A, int l, int r, long long *inv_count)
{
    int m;

    if (l >= r) 
        return;

    m = (l + r)/2;
    partition_and_count(A, l, m, inv_count);
    partition_and_count(A, m+1, r, inv_count);
    *inv_count += count_inv(A, l, r);

}


int main()
{
    int tries;
    int A[MAX_ELEMENTS];// = {0}; 
    int n, i;
    long long inv_count;

    scanf("%d", &tries);

    while (tries--) {
        scanf("%d", &n);

        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        inv_count = 0;
        partition_and_count(A, 0, n-1, &inv_count);
        printf("%lld\n", inv_count);
    }
    return 0;

}
