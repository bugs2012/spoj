#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM_LEN 10000
char * process(char *s, int *l)
{
    int i;
    int len = *l;
  //  strrev(s, strlen(s));
    while (*s == '0') {
        s++;
        len--;
    }
    *l = len;   

    for (i = 0; i < strlen(s);  i++)
        s[i] = s[i] - '0';
    return s;

}
char * reprocess(char *s)
{
    int i, l;
    
    for (i = 0; i < strlen(s);  i++)
        s[i] = s[i] + '0';
//    strrev(s, strlen(s));
    for (;*s == '0'; s++);

    return s;

}



void strrev(char *s, int l)
{
    int i;
    char t;

    l--;
    for (i = 0; i <= l/2; i++) {
        t = s[i];
        s[i] = s[l - i];
        s[l-i] = t;
    }
}

void add(char *s1, char *s2 ,char *sum, int s1_len, int s2_len, int discard_final_carry)
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
    return;

}


#if 0
void add(char *s1, char *s2 ,char *sum, int discard_final_carry)
{
    char n1[MAX_NUM_LEN];
    char n2[MAX_NUM_LEN];
    char res[MAX_NUM_LEN];

    memset(n1, 0, sizeof(n1));
    memset(n2, 0, sizeof(n2));
    memset(res, 0, sizeof(res));
    memset(sum, 0, sizeof(sum));

    strrev(s1, n1);
    strrev(s2, n2);

#ifdef DEBUG
    printf("%s \n", n1);
    printf("%s \n", n2);
#endif

    int i, j, carry, r;
    char *rem;
    i = 0;
    carry = 0;

    while (n1[i] && n2[i]) {
        //r = ((int)n1[i] - 48) + ((int)n2[i] - 48)+ carry;
        r = char_to_int(n1[i]) + char_to_int(n2[i]) + carry;
        res[i] = int_to_char(r%10) ;
        carry = r/10;
        i++;
    }

    if (n1[i]) {
        rem = &n1[i];
    } else if (n2[i]) {
        rem = &n2[i];
    } else {
        rem = NULL;
    }

    while (rem && *rem) {
        r = char_to_int(*rem) + carry;
        res[i] = int_to_char(r%10) ;
        carry = r/10;
        i++;
        rem++;
    }
    if (!discard_final_carry)
        res[i++] = int_to_char(carry);

    /* Truncate ending 0's which are not valid when res is reversed */

    for (j = i-1; j >= 0 && res[j] == '0'; j--);
    
    if (j == -1)
        j = 0;

    res[j+1] = '\0';

    strrev(res, sum);
        
    return;

}

int addition(char *s1, char *s2, char *sum)
{

    char sign;
    char *min_num, *max_num;
    char s1_sign, s2_sign;
    int discard_carry;

    s1_sign = s1[0];
    s2_sign = s2[0];

    if (s1_sign == '-') {
        s1++;
    } else {
        s1_sign = '+';
    }

    if (s2_sign == '-') {
        s2++;
    } else {
        s2_sign = '+';
    }

    max_num = s1;
    min_num = s2;

    discard_carry = 0;

    if (s1_sign == '+' && s2_sign == '+') {
        sum[0] = '+';
    } else if (s1_sign == '-' && s2_sign == '-') {
        sum[0] = '-';
    } else if (s1_sign == '-' && s2_sign == '+') {
        min_num = minimum(s1, s2);

        if (min_num == s1) {
            sum[0] = '+';
            max_num = s2;
        } else {
            sum[0] = '-';
            max_num = s1;
        }
        //Always complement minimum magnitude number
        complement(min_num, strlen(max_num));
        discard_carry = 1;


    } else if (s1_sign == '+' && s2_sign == '-') {
        // Compare magnitudes of both numbers
        min_num = minimum(s1, s2);
        if (min_num == s1) {
            sum[0] = '-';
            max_num = s2;
        } else {
            sum[0] = '+';
            max_num = s1;
        }
        
        //Always complement minimum magnitude number
        complement(min_num, strlen(max_num));
        discard_carry = 1;
    }

    add(max_num, min_num, &sum[1], discard_carry);

    if (discard_carry) { 
        sum[1] = sum[0];
        sum++;
    }
    
    for (; *sum == '0'; sum++);

    //removes leading +'s 
    if (sum[0] == '+')
        sum++;


    if (*sum == '\0')
        sum--;

    printf("%s \n", sum);

}

#endif

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
            s1_len = strlen(s1);
            s2_len = strlen(s2);
			strrev(s1, strlen(s1));
			strrev(s2, strlen(s2));

			sr1 = process(s1, &s1_len);
			sr2 = process(s2, &s2_len);

			add(sr1, sr2, sum, s1_len, s2_len, 0);
			//printf("%s \n", sum);
			strrev(sum, strlen(sum));
			res = reprocess(sum);
			printf("%s \n", res);
	}
}


