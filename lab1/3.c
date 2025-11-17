#include "stdio.h"

void main ()
{
    int n,count=0; 
    printf("give a no.");
    scanf("%d",&n);

    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            count++;
        }
        
    }
    if (count >1)
    {
        printf("prime");
    }
    else 
    {
        printf("np");
    }
    
    
}