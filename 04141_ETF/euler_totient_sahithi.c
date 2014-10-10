#include <stdio.h>
#include <math.h>


#define MAX_NUM 1000000
int pns[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

int prime[MAX_NUM];

int is_prime(int n)
{
	int i;
    int limit = sqrt(n);
 	for (i = 0;  pns[i] <= limit && i < sizeof(pns)/sizeof(pns[0]) ; i++) {
		if (n % pns[i] == 0)
			return 0;
	}
	return 1;
}



void gen_primes(int n)
{
    int i, j;

    j = 0;
    for (i = 2; i <= n; i++){
        if (is_prime(i)) {
            prime[j++] = i;
        }
    }
}

int search_prime(int n, int l, int h)
{
    int mid, m;
    if (l > h)
        return 0;

    m = (l + h) / 2;
    mid = prime[m];

    if (n == mid)
        return 1;
    else if(n > mid) 
        return search_prime(n, m+1, h);
    else
        return search_prime(n, l, m-1);
}


int euler_totient(int n)
{
    int et, f, p, i;
    
    if (search_prime(n, 0, sizeof(pns)/sizeof(int) -1 ))
        return (n-1);

    et = n;
    f = 0;
    i = 0;
    p = prime[i];
    while (n > 1) {
        if (n%p == 0) {
            n = n/p;
            f++;
        } else {
            if (f > 0) {
                et *= (1 - 1.0/p);
                f = 0;
            }
            i++;
            p = prime[i];
        }
    }
    return (et*(1-1.0/p));
        
}

int main()
{
    int t, n;
    gen_primes(MAX_NUM);
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        if (n == 1) 
            printf("%d \n", 1);
        else 
            printf("%d \n", euler_totient(n));
    }
    return 0;
}

