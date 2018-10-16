#include<stdio.h>
struct SYSTEM{
	int source,time,duration,target;
};
int call_forward(struct SYSTEM sys[],int n_sys,int call,int target){
	int i;
	char used[10]={0};
	do{
		for(i=0;i<n_sys;i++){
			if(sys[i].source==target&&call>=sys[i].time&&call<=sys[i].time+sys[i].duration){
				if(used[i]) return 9999;
				used[i]=1;
				target=sys[i].target;
				break;
			}
		}
	}while(i<n_sys);
	return target;
}
int main(){
	int T,cases,n_sys,call,target,ring;
	struct SYSTEM sys[15];
	scanf("%d",&T);
	puts("CALL FORWARDING OUTPUT");
	for(cases=1;cases<=T;cases++){
		for(n_sys=0;scanf("%d",&sys[n_sys].source),sys[n_sys].source!=0;n_sys++)
			scanf("%d%d%d",&sys[n_sys].time,&sys[n_sys].duration,&sys[n_sys].target);
		printf("SYSTEM %d\n",cases);
		while(scanf("%d",&call),call!=9000){
			scanf("%d",&target);
			ring=call_forward(sys,n_sys,call,target);
			printf("AT %.4d CALL TO %.4d RINGS %.4d\n",call,target,ring);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
