#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM_LEN 100

void strrev(char *s, int l);

void process(char *s)
{
    int i, l;
    strrev(s, strlen(s));
    for (i = 0; i < strlen(s);  i++)
        s[i] = s[i] - '0';

}

void reprocess(char *s)
{
    int i, l;
    
    for (i = 0; i < strlen(s);  i++)
        s[i] = s[i] + '0';
    strrev(s, strlen(s));

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


    //strrev(s1, s1_len);
    //strrev(s2, s2_len);

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
    //strrev(sum, max_len);
    sum[j+1] = '\0';
    reprocess(sum);
    return;

}



char *truncate_leading_zeros(char *s)
{
    for (;*s == '0'; s++);

    if (*s == '\0')
        s--;
    return s;
}

void complement(char *s, int l, int n)
{
    int i, j;
    char sum[MAX_NUM_LEN];
    char s2;

    memset(sum, 9, n-l);

    for (i = n-l,j = 0; j < l; i++,j++) {
        sum[i] = 9 - s[j];
    }
    sum[i] = '\0';
    s2 = 1;
    add(sum, &s2, s, n, 1,  1);

}

int sub(char *s1, char *s2, char *sum)
{
    char sign;
    char s1_sign, s2_sign;
    int s1_len, s2_len, max_len, min_len;
    char *max, *min;
    int ret;

    s1_sign = s1[0];
    s2_sign = s2[0];

    if (s1_sign != '-')  
        s1_sign = '+';
    else
        s1++;

    if (s2_sign != '-') 
        s2_sign = '+';
    else 
        s2++;

    s1 = truncate_leading_zeros(s1);
    s2 = truncate_leading_zeros(s2);

    s1_len = strlen(s1);
    s2_len = strlen(s2);

    if (s1_len < s2_len) {
        min = s1;
        max = s2;
    } else if (s1_len > s2_len) {
        min = s2;
        max = s1;
    } else {
        /* If both numbers are equal return 0; */
        ret = strcmp(s1, s2);
        if (ret == 0) {
            sum[0] = '0';
            sum[1] = '\0';
            return;
        } else if (ret == -1) {
            min = s1;
            max = s2;
        } else {
            min = s2;
            max = s1;
        }
    }
    max_len = strlen(max);
    min_len = strlen(min);

    process(min);
    process(max);

    //Always complement minimum magnitude number
    complement(min, min_len, max_len);
    if ((max == s1 && s1_sign == '-') || (max == s2 && s2_sign == '-')) {
        sum[0] = '-';
        add(max, min, &sum[1], max_len, min_len, 1);
    } else {
        add(max, min, &sum[0], max_len, min_len, 1);
    }

}

add_subtract(char *s1, char *s2, char *sum)
{

    char sign;
    char s1_sign, s2_sign;
    int s1_len , s2_len;

    s1_sign = s1[0];
    s2_sign = s2[0];

    if (s1_sign != '-') 
        s1_sign = '+';

    if (s2_sign != '-') 
        s2_sign = '+';

    if (s1_sign == s2_sign) {
        if (s1_sign == '-') {
            sum[0] = '-';
            sum++;
            s1++;
            s2++;
        }
        s1 = truncate_leading_zeros(s1);
        s2 = truncate_leading_zeros(s2);
        s1_len = strlen(s1);
        s2_len = strlen(s2);
        process(s1);
        process(s2);

        add(s1, s2, sum, s1_len, s2_len, 0);
    } else {
        sub(s1, s2, sum);
    }
    return;
}

int main()
{
    char sum[MAX_NUM_LEN];

    char s1[MAX_NUM_LEN];
    char s2[MAX_NUM_LEN];
    
    scanf("%s", s1); 
    printf("+\n");
    scanf("%s", s2); 
    printf("=\n");
    add_subtract(s1, s2, sum);
    //reprocess(sum);
    printf("%s\n", sum);
}


