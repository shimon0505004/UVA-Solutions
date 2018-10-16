#include<stdio.h>
int main()
{
	int cases,i;
	int XUR[2],YUR[2],XLL[2],YLL[2];
	int xur,yur,xll,yll;
	scanf("%d",&cases);
	while(cases--){
		for(i=0;i<2;i++)
			scanf("%d%d%d%d",&XLL[i],&YLL[i],&XUR[i],&YUR[i]);
		if(XLL[0]>=XUR[1]||XLL[1]>=XUR[0])
			puts("No Overlap");
		else if(YLL[0]>=YUR[1]||YLL[1]>=YUR[0])
			puts("No Overlap");
		else{
			if(XUR[0]>XUR[1])
				xur=XUR[1];
			else
				xur=XUR[0];
			if(YUR[0]>YUR[1])
				yur=YUR[1];
			else
				yur=YUR[0];
			if(XLL[0]<XLL[1])
				xll=XLL[1];
			else
				xll=XLL[0];
			if(YLL[0]<YLL[1])
				yll=YLL[1];
			else
				yll=YLL[0];
			printf("%d %d %d %d\n",xll,yll,xur,yur);
		}
		if(cases) puts("");
	}
	return 0;
}
