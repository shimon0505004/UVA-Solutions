#include<stdio.h>
int main()
{
	int n1,n2,t,temp;
	while(scanf("%d%d",&n1,&n2)==2&&n1){
		if(n1<n2)
			temp=n1,n1=n2,n2=temp;
		t=0;
		if(n1!=n2)
			while(n1/n2==1){
				t++;
				temp=n2;
				n2=n1%n2;
				n1=temp;
			}
		if(t%2)
			puts("Ollie wins");
		else
			puts("Stan wins");
	}
	return 0;
}
