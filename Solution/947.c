#include<stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
void guess(int N,int len,int *a,int *b,int gue){
	int digits[5],i,g[5];
	int countN[10]={0},countG[10]={0};
	*a=*b=0;
	for(i=len-1;i>=0;i--) digits[i]=N%10,N/=10,countN[digits[i]]++;
	for(i=len-1;i>=0;i--) g[i]=gue%9+1,gue/=9,countG[g[i]]++;
	for(i=0;i<len;i++)
		if(digits[i]==g[i])
			(*a)++,countN[digits[i]]--,countG[g[i]]--;
	for(i=1;i<=9;i++)
		*b+=MIN(countN[i],countG[i]);
}
int main(){
	int len,N,A,B;
	int cases,i;
	int count;
	int pow_10[6]={1,10,100,1000,10000,100000};
	int pow_9[6]={1,9,81,729,6561,59049};
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&N,&A,&B);
		for(len=0;pow_10[len]<=N;len++);
		count=0;
		for(i=0;i<pow_9[len];i++){
			int a,b;
			guess(N,len,&a,&b,i);
			if(a==A&&b==B) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
