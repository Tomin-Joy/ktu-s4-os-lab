#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,init,np,dir,temp,size,totalDisk=0,req[50];
    printf("Enter the number of process : ");
    scanf("%d",&np);
    printf("Enter the request sequence : ");
    for(i=0;i<np;i++){
        scanf("%d",&req[i]);
    }
    printf("Enter disk size : ");
    scanf("%d",&size);
    size-=1;
    printf("Enter the initial disk position : ");
    scanf("%d",&init);
    for(i=0;i<np;i++){
        totalDisk+=abs(req[i]-init);
        init=req[i];
    }
    
    printf("The total disk movement : %d\n",totalDisk);
    return 0;
}