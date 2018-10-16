#include<stdio.h>
int max(int n1,int n2)
{
	if(n1>n2)
		return n1;
	else
		return n2;
}
int main()
{
	int n[10050],count,i,s=0,c[10050],m;
	while(scanf("%d",&count)==1&&count){
		for(i=0;i<count;i++)
			scanf("%d",&n[i]);
		c[0]=n[0];
		for(i=1,m=c[0];i<count;i++){
			c[i]=max(n[i],c[i-1]+n[i]);
			if(c[i]>m)
				m=c[i];
		}
		if(m<=0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n",m);
	}
	return 0;
}
