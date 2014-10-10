#include<stdio.h>
#include<string.h>

void print_inp(char *str, int n)
{
    char nstr[30] = {0};
    strcpy(nstr, str);
    if (n == 0) {
        printf("%s\n", str);
    }
    else {
            strcat(str, "Y");
            print_inp(str, n-1);

            strcat(nstr, "N");
            print_inp(nstr, n-1);
    }
    return;

}

int main()
{
    int i;
    char str[30];
    for (i = 1; i <= 3; i++) {
        str[0] = 'Y';
        print_inp(str, i-1);
        str[0] = 'N';
        print_inp(str, i-1);

    }
}
