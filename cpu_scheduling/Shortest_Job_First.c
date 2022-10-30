#include<stdio.h>
typedef struct{
	int wt;
	int bt;
	int tt;
	int ct;
	int at;
	int flag;
}process;
process p[20],temp;
int main(){
	int n,i,j,com=0,min;
	float tTT=0,tWT=0,avgTT,avgWT;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the burst time of p%d ",i);
		scanf("%d",&p[i].bt);
		printf("Enter the arival time of p%d ",i);
		scanf("%d",&p[i].at);
		p[i].flag=0;
	}
	for(i =0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(p[j].bt>p[j+1].bt){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;  // sorting array in ascending order
			}
		}
	}
	for(i=0;i<n;i++){
		// min=i;
		if(com<p[i].at){
			com=p[i].at;
		}
		// for(j=i;j<n && p[j].at<=com;j++){
		// 	if(p[j].flag==0 && p[j].bt<p[min].bt){
		// 		min=j;
		// 	}
		// }
		p[i].flag=1;
		p[i].ct=com+p[i].bt; //completion time
		p[i].tt=p[i].ct-p[i].at; //turnaround time
		p[i].wt=p[i].tt-p[i].bt; //waiting time
		com=p[i].ct;
	}
	printf("Process\ttt\tbt\tat\twt\n\n");
	for(i=0;i<n;i++){
		printf("p%d\t%d\t%d\t%d\t%d\t\n",i,p[i].tt,p[i].bt,p[i].at,p[i].wt);
		tTT+=p[i].tt;
		tWT+=p[i].wt;
	}
	avgTT=tTT/n; //average turnaround time
	avgWT=tWT/n; //average waiting time
	printf("The average waiting time is : %.2f\n",avgWT);
	printf("The average turn around time is : %.2f\n",avgTT);
	return 0;
}
	
	
	
		
