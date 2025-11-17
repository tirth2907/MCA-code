#include "stdio.h"
int fact(int n);
void main(){
    int n;
    printf("gove a no :");
    scanf("%d",&n);
    int ans = fact(n);
    printf("%d",ans);

}

int fact(int n){
     if (n ==0)
     {
        return 1;
     }
     else
     {
        return n*(fact(n-1));
     }
     
}