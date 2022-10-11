#include<stdio.h>
typedef struct {
    int no;
    int need[10];
    int alloc[10];
    int max[10];
    int com;
}process;
process p[10];

int np,nr,ps[10],avail[11][10];
int compare(int n[],int a[]){
    int flag=0;
    for(int i =0;i<nr;i++){
        if(n[i]>a[i]){
            flag=1;
            break;
        }
    }
    if(flag){
        return 0;
    }
    return 1;
}
int main(){
    int i,j,flag;
    int pId=0;
    printf("Enter the number of process and resources : ");
    scanf("%d %d",&np,&nr);
    printf("Enter the allocation matrix : \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&p[i].alloc[j]);
        }
    }
    printf("Enter the max matrix : \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            scanf("%d",&p[i].max[j]);
        }
    }
    printf("Enter available : ");
    for(i=0;i<nr;i++){
        scanf("%d",&avail[0][i]);
    }
    printf("Need matrix is \n");
    for(i=0;i<np;i++){
        for(j=0;j<nr;j++){
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];
            printf("%d ",p[i].need[j]);
        }
        printf("\n");
        p[i].no=i+1;
        p[i].com=0;
    }
    do{
        flag=0;
        for(i=0;i<np;i++){
            if(!p[i].com){
                int b=compare(p[i].need,avail[pId]);
                if(b){
                    for(j=0;j<nr;j++){
                        avail[pId+1][j]=p[i].alloc[j]+avail[pId][j];
                    }
                    p[i].com=1;
                    flag=1;
                    ps[pId]=i;
                    pId+=1;
                }
            }
        }
    }while(flag);
    if(pId==np){
        printf("The system is in safe state \n safe sequence is : ");
        for(i=0;i<np;i++){
            printf("p%d  ",ps[i]);
        }
        printf("\n");
    }else{
        printf("The system is not in safe state\n");
    }
    return 0;
}