#include<stdio.h>
char shortage(int books[],int k,int m,long long bound){
	int i,now=0;
	long long tmp=0;
	for(i=0;i<m;i++){
		while(now<k&&tmp+books[now]<=bound)
			tmp+=books[now++];
		tmp=0;
	}
	if(now<k) return 1;
	return 0;
}
int main(){
	int cases;
	int k,m,i,j;
	int books[505];
	long long sum,Lbound,Ubound,middle,tmp;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&k,&m);
		Lbound=10000000;
		for(sum=i=0;i<k;i++){
			scanf("%d",&books[i]);
			sum+=books[i];
			if(books[i]<Lbound) Lbound=books[i];
		}
		Ubound=sum;
		middle=(Ubound+Lbound)/2;
		while(Lbound+1<Ubound){
			if(shortage(books,k,m,middle)) Lbound=middle;
			else Ubound=middle;
			middle=(Ubound+Lbound)/2;
		}
		middle++;
		for(i=j=0;i<m;i++){
			if(i) printf(" / ");
			printf("%d",books[j]);
			tmp=books[j++];
			while(j<k&&tmp+books[j]<=middle&&shortage(books+j,k-j,m-i-1,middle)==1){
				tmp+=books[j];
				printf(" %d",books[j++]);
			}
			tmp=0;
		}
		puts("");
	}
	return 0;
}
