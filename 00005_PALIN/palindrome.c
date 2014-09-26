#include<stdio.h>

int is_palindrome(int n)
{
    
}

int main()
{
    int t, n, i, inp;

    for (i = 0; i < t; i++) {
        scanf("%d", &inp);
        for (n = inp + 1; ; n++) {
            if (is_palindrome(n)) {
                printf("%d\n", n);
                break;
            }
        }
    }
}
