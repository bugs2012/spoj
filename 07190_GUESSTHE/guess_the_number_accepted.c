#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUMS 30
#define MAX_PRIMES 8
int primes[MAX_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19};

void update(int *gprimes, int *lprimes)
{
    int i;
    for (i = 0; i < MAX_PRIMES; i++) {
        if (lprimes[i] > gprimes[i])
            gprimes[i] = lprimes[i];
    }
}

int lcm(char *s) 
{
    int i, num, j, k;
    int n[MAX_NUMS] = {0};
    int gprimes[MAX_PRIMES] = {0};
    int lprimes[MAX_PRIMES] = {0};
    int lcm;

    i = 1;
    while (*s) {
        /* Process string and look for valid numbers */
        if (*s == 'N') {
            i++;
            s++;
            continue;
        }
        n[i] = i;
        num = i;
        k = 0;
        /* Find prime factorization of the number (num) */
        memset(lprimes, 0, sizeof(lprimes));
        while (num != 1) {
            if (num%primes[k] == 0) {
                num = num/primes[k];
                lprimes[k]++;
            } else {
                k++;
            }
        }
        /* 
         * update the global primes factors(gprimes) 
         * global prime factors are the most times any prime factor can appear 
         * in any  number of the set
         */
        update(gprimes, lprimes);

        i++;
        s++;
    }

    lcm = 1;
    /* lcm = product of all the global prime factors */
    for (j = 0; j < MAX_PRIMES; j++) {
        if (gprimes[j] != 0) {
            lcm *= pow(primes[j], gprimes[j]);
        }
    }

    /* Check for cheating */
    for (j = 1; j < i; j++) {
        if ((lcm%j == 0) && (n[j] != j)) 
            return -1;
    }
    return lcm;


}
int main()
{
    char s[MAX_NUMS];
    
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "*")) 
            break;
        printf("%d\n", lcm(s));
    }
    return 0;

}
