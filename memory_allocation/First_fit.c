#include<stdio.h>
typedef struct{
	int no;
	int size;
	int allc;
}pb;
pb p[20],b[20];
int main(){
	int nb,np,i,j;
	printf("Enter the number of mem blocks : ");
	scanf("%d",&nb);
	printf("Enter the size of memory blocks : ");
	for(i=0;i<nb;i++){
		scanf("%d",&b[i].size);
		b[i].no=i+1;
	}
	printf("Enter the number of process : ");
	scanf("%d",&np);
	printf("Enter the processSize : ");
	for(i=0;i<np;i++){
		scanf("%d",&p[i].size);
		p[i].no=i+1;
		p[i].allc=-1;
	}
	for(i=0;i<np;i++){
		for(j=0;j<nb;j++){
			if(b[j].size>p[i].size){
				b[j].size-=p[i].size;
				p[i].allc=b[j].no;
				break;
			}
		}
	}
	for(i=0;i<np;i++){
		if(p[i].allc==-1){
			printf("\nprocess %d not allocated\n",p[i].no);
		}
		else{
			printf("\nprocess %d allocated to block %d \n",p[i].no,p[i].allc);
		}
	}
	return 0;
}
