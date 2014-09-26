#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM_LEN 10000
char * truncate_leading_zeros(char *s)
{
    while (*s == '0') {
        s++;
    }
    return s;
}

void process(char *s)
{
    while (*s) {
        *s = *s - '0';
        s++;
    }
}
void reprocess(char *s, int l)
{
    int i;
    for (i = 0; i < l; i++)
        s[i] = s[i] + '0';
}


void strrev(char *s, int l)
{
    char *e = s + l - 1;
    char t;
    while (s < e) {
        t = *s;
        *s = *e;
        *e = t;
        s++;
        e--;
    }
}

int add(char *s1, char *s2 ,char *sum, int s1_len, int s2_len, int discard_final_carry)
{
    char *min, *max;
    int i, j, carry, r;
    int min_len, max_len;

    strrev(s1, s1_len);
    strrev(s2, s2_len);

    if (s1_len <= s2_len) {
        min = s1;
        min_len = s1_len;

        max = s2;
        max_len = s2_len;
    } else {
        min = s2;
        min_len = s2_len;

        max = s1;
        max_len = s1_len;
    }

    carry = 0;
    for (i = 0; i < min_len; i++) {
        r = min[i] + max[i] + carry;
        sum[i] = r%10 ;
        carry = r/10;
    }

    for (i = min_len; i < max_len; i++) {
#if 0
        if (carry == 0) {
            strncpy(&sum[i], &max[i], max_len - i);
            break;
        }
#endif
        r = max[i] + carry;
        sum[i] = r%10 ;
        carry = r/10;
    }

    if (!discard_final_carry && carry)
        sum[max_len++] = carry;

    /* Truncate ending 0's which are not valid when sum is reversed */

    for (j = max_len-1; j >= 0 && sum[j] == 0; j--);
    
    if (j == -1)
        j = 0;
    sum[j+1] = '\0';
    strrev(sum, max_len);
    //reprocess(sum);
    return j+1;

}



int main()
{
    char sum[MAX_NUM_LEN];

    char s1[MAX_NUM_LEN];
    char s2[MAX_NUM_LEN];
    char *sr1, *sr2, *res;
    int s1_len ,s2_len;
	int num_tries;

	scanf("%d", &num_tries);
	while(num_tries--) {
			scanf("%s", s1); 
			scanf("%s", s2); 
            
            /* Trucate leading zeros in input */
            sr1 = truncate_leading_zeros(s1); 
            sr2 = truncate_leading_zeros(s2); 

            /* Reverse the input */
			strrev(sr1, strlen(sr1));
			strrev(sr2, strlen(sr2));

            /* Trucate leading zeros in reversed input */
            sr1 = truncate_leading_zeros(sr1); 
            sr2 = truncate_leading_zeros(sr2); 

            s1_len = strlen(sr1);
            s2_len = strlen(sr2);

			process(sr1);
			process(sr2);
            int k;
			k = add(sr1, sr2, sum, s1_len, s2_len, 0);

			reprocess(sum, k);
            reprocess(sr1, s1_len);
            reprocess(sr2, s2_len);
           // printf("%s %s: %s", sr1, sr2, sum);
			strrev(sum, strlen(sum));
            res = truncate_leading_zeros(sum);
			printf("%s\n", res);
	}
    return 0;
}


