#include<stdio.h>

void main(){
    int n,m;
    printf("give two no :");
    scanf("%d %d",&n,&m);
    int gcd=1;
    for (int i = 1; i <= n && i <= m; i++)
    {
        if (n%i ==0 && m%i ==0)
        {
            gcd = i;
        }
    }
    printf("GCD is %d", gcd);
}