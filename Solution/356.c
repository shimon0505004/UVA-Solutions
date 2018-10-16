#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,tot,cell,previous,scell,start=0;
	double r,point;
	while(scanf("%d",&n)!=EOF){
		if(start)
			printf("\n");
		start=1;
		r=n-0.5;
		tot=0;
		scell=0;
		previous=n-1;
		for(i=1;i<n;i++){
			point=0;
			point=sqrt(r*r-pow(i,2));
			point=floor(point);
			tot+=point;
			scell+=previous-point+1;
			previous=point;
		}
		scell+=previous+1;
		cell=tot*4;
		scell*=4;
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,scell);
		printf("There are %d cells completely contained in the circle.\n",cell);
	}
	return 0;
}
