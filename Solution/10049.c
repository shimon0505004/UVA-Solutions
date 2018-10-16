#include<stdio.h>
#define MAX 673368
int main(){
	int slf_dscr[MAX];
	int now,i,head,tail,mid,n;
	slf_dscr[1]=1,slf_dscr[2]=2,slf_dscr[3]=4;
	now=2;
	for(i=3;slf_dscr[i]<=2000004512;i++){
		if(i<slf_dscr[now+1])
			slf_dscr[i+1]=slf_dscr[i]+now;
		else now++,slf_dscr[i+1]=slf_dscr[i]+now;
	}
	while(scanf("%d",&n),n){
		head=0,tail=MAX,mid=(head+tail)/2;
		while(tail>head+1){
			if(slf_dscr[mid]>n) tail=mid,mid=(tail+head)/2;
			else if(slf_dscr[mid]<n) head=mid,mid=(tail+head)/2;
			else break;
		}
		if(slf_dscr[mid]==n) printf("%d\n",mid);
		else printf("%d\n",head);
	}
	return 0;
}
