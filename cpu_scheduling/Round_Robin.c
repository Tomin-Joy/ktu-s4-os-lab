#include<stdio.h>
typedef struct {
	int at;
	int bt;
	int wt;
	int tt;
	int ct;
	int tbt;
}process;
process p[10],temp;
int main(){
	int n,i,j,quanta,com=0,flag;
	float tTT=0,tWT=0,avgTT,avgWT;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	printf("Enter the quanta of process : ");
	scanf("%d",&quanta);
	for(i=0;i<n;i++){
		printf("Enter burst time of process p%d : ",i);
		scanf("%d",&p[i].bt);
		p[i].tbt=p[i].bt;
	}
	for(i=0;i<n;i++){
		scanf("%d",&p[i].at);
	}
	do{
		flag=0;
		for(i=0;i<n;i++){
			if(p[i].tbt>0 && p[i].tbt>quanta){
				p[i].tbt-=quanta;
				com+=quanta;
				flag=1;
			}
			else if(p[i].tbt>0){
				com+=p[i].tbt;
				p[i].tbt=0;
				p[i].ct=com;
				p[i].tt=p[i].ct-p[i].at;
				p[i].wt=p[i].tt-p[i].bt;
				flag=1;
			}
		}
	}while(flag!=0);
	printf("Process\tct\ttt\tbt\tat\twt\n\n");
	for(i=0;i<n;i++){
		printf("p%d\t%d\t%d\t%d\t%d\t%d\t\n",i,p[i].ct,p[i].tt,p[i].bt,p[i].at,p[i].wt);
		tTT+=p[i].tt;
		tWT+=p[i].wt;
	}
	avgTT=tTT/n;
	avgWT=tWT/n;
	printf("The average waiting time is : %.2f\n",avgWT);
	printf("The average turn around time is : %.2f\n",avgTT);
	return 0;
}

	
	
	
	
	
	
	
	
