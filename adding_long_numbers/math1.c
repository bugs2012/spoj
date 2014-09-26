#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NUM_LEN 100

void strrev(char *s1, char *n1)
{
    int i, len;

    len = strlen(s1) -1;
    for (i = 0; i <= len; i++) {
        n1[i] = s1[len - i];
    }
    n1[i] = '\0';

}

int char_to_int(char n)
{
    return (int)(n-'0');

}

char int_to_char(int n)
{
    return(char)(n+'0');
}

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

char *minimum(char *str1, char *str2)
{
    unsigned long long l1, l2;
    char *s1, *s2;

    s1 = str1;
    s2 = str2;

    l1 = strlen(s1);
    l2 = strlen(s2);

    if (l1 < l2) {
        return str1;
    } else if (l1 > l2) {
        return str2;
    } else {
        while (*s1 && *s2) {
            if (*s1 < *s2)
                return s1;
            else if (*s1 > *s2)
                return s2;
            s1++;
            s2++;
        }
    }
    return str1;
}

void complement(char *s, int n)
{
    int i, j;
    int l;
    char sum[MAX_NUM_LEN];

    l = strlen(s);
    memset(sum, '9', n-l);

    for (i = n-l,j = 0; j < l; i++,j++) {
        sum[i] = int_to_char('9' - s[j]);
    }
    sum[i] = '\0';
    add(sum, "1", s, 0);

}
#if 0
void append(char *s, unsigned long long n)
{
    char res[MAX_NUM_LEN];
    unsigned long long i;
    unsigned long long l;
    l = strlen(s);

    memset(res,'0', n - l);
    strncpy(&res[n-l], s, l);
    res[n] = '\0';
    strcpy(s, res);
}
#endif

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

int main()
{
    char sum[MAX_NUM_LEN];

    char s1[MAX_NUM_LEN];
    char s2[MAX_NUM_LEN];
    
    scanf("%s", s1); 
    printf("+\n");
    scanf("%s", s2); 
    printf("=\n");
    addition(s1, s2, sum);
}


