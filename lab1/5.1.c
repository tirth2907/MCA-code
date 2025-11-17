#include "stdio.h"

void main (){
    int n,m;
    printf("give two no :");
    scanf("%d %d",&n,&m);

    int ans = pow(n,m);
    printf("Power is %d", ans);
}

int pow(int n, int m){
    if(m == 0){
        return 1;
    }
    else{
        return n * pow(n, m-1);
    }
}