#include<stdio.h>
int main()
{
	int n,k,butt,tot;
	while(scanf("%d%d",&n,&k)!=EOF){
		tot=0;
		butt=0;
		while(1){
			tot+=n;
			butt+=n;
			if(butt<k)
				break;
			n=butt/k;
			butt%=k;	
		}
		printf("%d\n",tot);
	}
	return 0;
}
