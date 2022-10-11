#include<stdio.h>
int fQ[10],frames[10],pages[50],front=-1,rear=-1;
int pop(){
	int t = fQ[rear];
	rear=(rear+1)%10;
	return t;
}
void push(int n){
	
	front=(front+1)%10;
	fQ[front]=n;
}
int main(){
	int i,j,nf,np,fPos,flag;
	printf("Enter the number of pages : ");
	scanf("%d",&np);
	printf("Enter the reference string : ");
	for(i=0;i<np;i++)
		scanf("%d",&pages[i]);
	printf("Enter the number of frames : ");
	scanf("%d",&nf);
	for(i=0;i<nf;i++)
		frames[i]=-1;
	printf("Page\t\tFrames\n");
	for(i=0;i<np;i++){
		flag=0;
		for(j=0;j<nf;j++){
			if(frames[j]==pages[i]){
				flag=1;
				push(j);
				break;
			}else if(frames[j]==-1){
				frames[j]=pages[i];
				push(j);
				flag=-1;
				break;
			}
		}
		if(flag==0){
			fPos=pop();
			frames[fPos]=pages[i];
			push(fPos);
		}
		printf("%d\t\t",pages[i]);
		if(flag<1){
			for(j=0;j<nf;j++){
				printf("%d\t",frames[j]);
			}
			printf("\n");
		}
		else{
			printf("page hit\n");
		}
		
	}
	return 0;
}
		
		
	
	
	
