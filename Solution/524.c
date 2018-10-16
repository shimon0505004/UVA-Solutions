#include<stdio.h>
int n;
int count;
typedef struct n{
	int digit[20];
}NUM;
char isprime[32]={0};
void printlist(NUM list,int delete,int pre[])
{
	int i;
	if(delete+1)
		list.digit[delete]=0;
	for(i=1;i<n;i++)
		if(list.digit[i]){
			if(isprime[i+1+pre[count-1]]) continue;
			pre[count++]=i+1;
			if(count==n){
				if(!isprime[pre[count-1]+1]){
					for(i=0;i<n;i++){
						if(i) printf(" ");
						printf("%d",pre[i]);
					}
					puts("");
				}
			}
			printlist(list,i,pre);
		}
	count--;
}
int main()
{
	int i,j,cases;
	NUM list;
	int pre[20];
	isprime[0]=isprime[1]=1;
	for(i=2;i<16;i++)
		if(!isprime[i])
			for(j=2;i*j<32;j++)
				isprime[i*j]=1;
	for(cases=1;scanf("%d",&n)==1;cases++){
		if(cases-1) puts("");
		printf("Case %d:\n",cases);
		for(i=0;i<n;i++)
			list.digit[i]=1;
		count=1;
		pre[0]=1;
		printlist(list,0,pre);
	}
	return 0;
}
