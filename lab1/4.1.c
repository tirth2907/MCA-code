// /gcd with recursion
#include<stdio.h>
int gcd(int n, int m){
    if(m == 0){
        return n;
    }
    return gcd(m, n % m);
}
void main(){
    int n,m;
    printf("give two no :");
    scanf("%d %d",&n,&m);
    int result = gcd(n, m);
    printf("GCD is %d", result);
}