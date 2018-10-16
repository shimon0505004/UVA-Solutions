#include<stdio.h>
int main(){
	int m,n,t,i,ham,beer,y;
	while(scanf("%d%d%d",&m,&n,&t)==3){
		if(n>m){
			int temp=n;
			n=m,m=temp;
		}
		if(t%m==0&&t%n==0)
			ham=t/n,beer=0;
		else if(n>t)
			ham=0,beer=t;
		else if(m>t)
			ham=t/n,beer=t%n;
		else if(m==n)
			ham=t/n,beer=t%n;
		else{
			ham=0,beer=t;
			for(i=0;m*i<=t;i++){
				y=(t-m*i)/n;
				if(beer>t-(m*i+y*n)) beer=t-(m*i+y*n),ham=i+y;
				else if(beer==t-(m*i+y*n)&&ham<i+y) ham=i+y;
			}
		}
		printf("%d",ham);
		if(beer) printf(" %d\n",beer);
		else puts("");
	}
	return 0;
}
