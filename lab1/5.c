#include<stdio.h>
void main(){
    int n,m;
    printf("give two no :");
    scanf("%d %d",&n,&m);
    int pow=1;
    for (int i = 1; i <= m; i++)
    {
        pow = pow*n;
    }
    printf("Power is %d", pow);

}