#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUMS 30
#define MAX_PRIMES 8
int primes[MAX_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19};
int pfactors[MAX_NUMS][MAX_PRIMES] =     {{0, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 0},
                                         {1, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 1, 0, 0, 0, 0, 0, 0},
                                         {2, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 1, 0, 0, 0, 0, 0},
                                         {1, 1, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 1, 0, 0, 0, 0},
                                         {3, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 2, 0, 0, 0, 0, 0, 0},
                                         {1, 0, 1, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 1, 0, 0, 0},
                                         {2, 1, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 1, 0, 0},
                                         {1, 0, 0, 1, 0, 0, 0, 0},
                                         {0, 1, 1, 0, 0, 0, 0, 0},
                                         {4, 0, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 1, 0},
                                         {1, 2, 0, 0, 0, 0, 0, 0},
                                         {0, 0, 0, 0, 0, 0, 0, 1},
                                         {2, 0, 1, 0, 0, 0, 0, 0},
                                         };
int max_factors[MAX_PRIMES] = {4, 2, 1, 1, 1, 1, 1, 1};
int pfactor_index[MAX_NUMS] = {0 , 0, 1, 2, 1, 3, 2, 4, 1, 2, 3, 5, 2, 6, 4, 3, 1, 7, 2, 8, 3};   

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
	int yes[MAX_NUMS], no[MAX_NUMS];
	int yi, ni; 
    int n[MAX_NUMS] = {0};
    int gprimes[MAX_PRIMES] = {0};
    int *lprimes;
    int lcm;

    i = 1;
	yi = 0;
	ni = 0;
    while (*s) {
        /* Process string and look for valid numbers */
        if (*s == 'N') 
			no[ni++] = i;
		else 
			yes[yi++] = i;
		i++;
        s++;
	}
	/* check for cheating */
	if (ni > 0) {
		if (yi == 0)
			return -1;
		for (i = 0; i < yi; i++) {
			for (j = 0; j < ni; j++) { 
				if (yes[i] % no[j] == 0)
					return -1;
			}
		}
	}
	for (i = 0; i < yi; i++) {
        num = yes[i];
	    for (j = 0; j < pfactor_index[num]; j++) {
		    if (pfactors[num][j] > gprimes[j])
			    gprimes[j] = pfactors[num][j];
		}

    }
    lcm = 1;
    for (j = 0; j < MAX_PRIMES; j++) {
        lcm *= pow(primes[j], gprimes[j]);
    }
#if 1
    /* Check for cheating */
    for (j = 0; j < ni; j++) {
        if (lcm%no[j] == 0) 
            return -1;
    }
#endif
    return lcm;


}
int main()
{
    char s[MAX_NUMS];                   //2  3  5  7 11 13 17 19       
        
    while (1) {
        scanf("%s", s);
        if (!strcmp(s, "*")) 
            break;
        printf("%d\n", lcm(s));
    }
    return 0;

}
