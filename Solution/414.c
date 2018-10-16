#include<stdio.h>
int main()
{
	int i,n,X[20]={0},j,max,tot;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		getchar();
		max=0;
		tot=0;
		for(i=0;i<20;i++)
			X[i]=0;
		for(i=0;i<n;i++){
			for(j=0;j<25;j++)
				if(getchar()=='X')
					X[i]++;
			tot+=X[i];
			getchar();
		}
		for(i=0;i<n;i++)
			if(X[i]>max)
				max=X[i];
		printf("%d\n",n*max-tot);
	}
	return 0;
}
