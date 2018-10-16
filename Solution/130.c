#include<stdio.h>
#include<stdlib.h>
typedef struct Josephus{
	struct Josephus *prev;
	struct Josephus *next;
	int NO;
}J;
typedef J *Jptr;
void repair(Jptr Rptr){
	Rptr->next->prev=Rptr->prev;
	Rptr->prev->next=Rptr->next;
}
int kill(int nofp,int step,Jptr now){
	Jptr Kptr,Cptr,prev,next;
	int i;
	Kptr=now;
	for(i=0;i<step;i++)
		Kptr=Kptr->next;
	prev=Kptr->prev;
	next=Kptr->next;
	repair(Kptr);
	Cptr=prev;
	for(i=0;i<step;i++)
		Cptr=Cptr->next;
	if(--nofp==1)
		return Cptr->NO;
	if(Cptr!=next&&Cptr!=prev){
		repair(Cptr);
		prev->next=Cptr;
		next->prev=Cptr;
		Cptr->prev=prev;
		Cptr->next=next;
	}
	return kill(nofp,step,Cptr);
}
int main()
{
	int n,k,i;
	J j[105];
	while(scanf("%d%d",&n,&k)==2&&n){
		if(n==1){
			puts("1");
			continue;
		}
		for(i=1;i<=n;i++){
			int a;
			for(a=1;a<=n;a++){
				j[a].NO=a;
				j[a].next=&(j[a+1]);
				j[a].prev=&(j[a-1]);
			}
			j[1].prev=&(j[n]);
			j[n].next=&(j[1]);
			if(kill(n,k,&(j[i]))==1){
				printf("%d\n",(i%n)+1);
				break;
			}
		}
	}
	return 0;
}
