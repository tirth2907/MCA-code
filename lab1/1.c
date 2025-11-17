#include "stdio.h"

void main(){
    int n; 
    printf("add no:");
    scanf("%d",&n);
    int ans=1;
    if (n = 0)
    {
        printf("1");
    }
    else
    {   
        for (int i = 0; i < n; i++)
        {
            ans*=i;
        }
    }

    printf("ans = %d",ans);
}