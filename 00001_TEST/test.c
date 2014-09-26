#include<stdio.h>
int main()
{
    int i;

    while(1) {
        scanf("%d", &i);
        if (i == 42)
            return 0;
        else
            printf("%d\n", i);
    }

}
