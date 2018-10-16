#include<stdio.h>
int main()
{
	int tree[1<<19]={0};
	int arctree[1<<19+1]={0};
	int cases,D,I,count,i,p;
	tree[0]=1;
	for(i=0;i<(1<<18);i++)
		for(p=18;p>=0;p--)
			if(!tree[i+(1<<p)]){
				tree[i+(1<<p)]=tree[i]+(1<<(18-p));
				arctree[tree[i+(1<<p)]]=(i+(1<<p));
			}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&D,&I);
		printf("%d\n",arctree[I]/(1<<(20-D))+(1<<(D-1)));
	}
	return 0;
}
