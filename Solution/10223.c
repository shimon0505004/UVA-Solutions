#include<stdio.h>
#include<string.h>
int main()
{
	unsigned tree[100],i,j,num;
	memset(tree,0,sizeof(tree));
	tree[0]=tree[1]=1;
	for(i=2;i<20;i++)
		for(j=0;j<i;j++)
			tree[i]+=tree[j]*tree[i-j-1];
	while(scanf("%u",&num)==1){
		if(num==1)
			printf("1\n");
		else
			for(i=2;i<20;i++)
				if(num==tree[i]){
					printf("%u\n",i);
					break;
				}
	}
	return 0;
}
