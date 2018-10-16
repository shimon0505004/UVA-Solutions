#include<stdio.h>
#define Max 200
int main()
{
	int i,j,k,l,a,b,c,d;
	for(i=6;i<=Max;i++){
		a=i*i*i;
		for(j=2;j<Max;j++){
			b=j*j*j;
			if(b>a) break;
			for(k=j;k<Max;k++){
				c=k*k*k;
				if(b+c>a) break;
				for(l=k;l<Max;l++){
					d=l*l*l;
					if(b+c+d>a) break;
					else if(b+c+d==a)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
				}
			}
		}
	}
	return 0;
}
