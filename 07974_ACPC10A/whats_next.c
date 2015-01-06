#include<stdio.h>
#include<string.h>

void find_ap_gp(int n1, int n2, int n3)
{
    int d;

    d = n2 - n1;

    if (n3 == n2 + d) {
        printf("%s %d\n", "AP", n3 + d);
        return;
    }

    float r;
    if (n2 * n2 == n1 * n3) {
        r = (n2 * 1.0)/ n1 ;
        printf("%s %d\n", "GP", (int)(n3 *  r));
        return;
    }
}

int main()
{
    int n1, n2, n3;

    while (1) {
        scanf("%d %d %d", &n1, &n2, &n3);
        
        if ((n1 == 0) && (n2 == 0) && (n3 == 0)) 
            break;

        find_ap_gp(n1, n2, n3);
    }
    return 0;
}
