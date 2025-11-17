#include "stdio.h"
void main(){
    int start,end;
    printf("give two no :");
    scanf("%d %d",&start,&end);
    for (int i = start; i<=end; i++)
    {
        int temp=0;
        for (int j = 2; j <=i/2; j++)
        {
            if(i%j==0){
                temp=1;
                break;
            }
        }
        if(temp==0 && i!=1){
            printf("%d ", i);
        }
    }
}
