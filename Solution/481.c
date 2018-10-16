#include<stdio.h>
#define Ubound 100005
int search(int n,int s,int mintail[],int a[]){
	int i;
	int head=1,tail=n,mid=(n+1)/2;
	while(tail>head+1){
		if(a[mintail[mid]]>=s)
			tail=mid,mid=(mid+head)/2;
		else
			head=mid,mid=(mid+tail)/2;
	}
	return tail;
}
void printLIS(int now,int pred[],int a[]){
	if(pred[now]!=-1) printLIS(pred[now],pred,a);
	printf("%d\n",a[now]);
}
int main(){
	int mintail[Ubound];
	int pred[Ubound];
	int a[Ubound],n,i;
	for(n=0;scanf("%d",&a[n])==1;n++);
	pred[0]=-1;
	mintail[1]=0;
	a[n]=2147483647;
	for(i=2;i<n;i++)
		mintail[i]=n;
	for(i=1;i<n;i++){
		int s=search(i+1,a[i],mintail,a);
		pred[i]=mintail[s-1];
		mintail[s]=i;
	}
	for(i=n-1;mintail[i]==n;i--);
	printf("%d\n-\n",i);
	printLIS(mintail[i],pred,a);
	return 0;
}
