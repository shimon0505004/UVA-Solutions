#include<stdio.h>
#include<math.h>
int main(){
	int M,W,C;
	int i;
	while(scanf("%d%d%d",&M,&W,&C),M|W){
		if(W==0){
			if(C%2==0) printf("%.7lf\n",1.0);
			else printf("%.7lf\n",0.0);
		}else if(M==0) printf("%.7lf\n",1.0);
		else{
			double t=0,r=(double)M/(M+W),c;
			for(i=0,c=1;i<=C;c*=(double)(C-i)*(C-i-1)/(i+1)/(i+2),i+=2)
				t+=c*exp(log(r)*i+log(1-r)*(C-i));
			printf("%.7lf\n",t);
		}
	}
	return 0;
}
