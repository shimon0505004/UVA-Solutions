#include<stdio.h>
int mintail[62600];
int search(int n,int key,int a[]){
	int head=1,tail=n,mid=(head+tail)/2;
	while(head+1<tail){
		if(a[mintail[mid]]>=key) tail=mid;
		else head=mid;
		mid=(tail+head)/2;
	}
	return tail;
}
int find_LIS(int seq[],int n){
	int i;
	mintail[1]=1;
	for(i=2;i<=n;i++){
		int s=search(i,seq[i],seq);
		mintail[s]=i;
	}
	for(i=n;i>=0&&mintail[i]==n+1;i--);
	return i;
}
int main(){
	int T,cases;
	int n,p,q;
	int i,t;
	int seq1[62600],seq2[62600];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d%d",&n,&p,&q);
		n*=n;
		for(i=1;i<=n;i++) seq1[i]=n;
		for(i=1;i<=p+1;i++) scanf("%d",&t),seq1[t]=i;
		for(i=1;i<=q+1;i++) scanf("%d",&t),seq2[i]=seq1[t],mintail[i]=q+2;
		seq2[q+2]=n;
		printf("Case %d: %d\n",cases,find_LIS(seq2,q+1));
	}
	return 0;
}
