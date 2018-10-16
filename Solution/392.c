#include<stdio.h>
#include<math.h>
int main()
{
	int poly[10],i,start,plus,endpoly,minus=0;
	while(1){
		for(i=8;i>=0;i--)
			if(scanf("%d",&poly[i])==EOF) return 0;
		start=0;
		endpoly=-1;
		for(i=0;i<=8;i++)
			if(poly[i]){
				endpoly=i;
				break;
			}
		for(i=8;i>=0;i--){
			if(endpoly==-1){
				printf("0");
				break;
			}
			if(!poly[i])
				continue;
			start++;
			plus=minus=1;
			if(start==1){
				plus=0;
				minus=0;
			}
			switch(i){
				case 0:
					printf("%s%d",(poly[0]>0?(plus?"+ ":""):(minus?"- ":"-")),abs(poly[0]));
					break;
				case 1:
					switch(poly[1]){
						case 1:
							printf("%sx",(plus?"+ ":""));
							break;
						case -1:
							printf("%sx",(minus?"- ":"-"));
							break;
						default:
							printf("%s%dx",poly[i]>0?(plus?"+ ":""):(minus?"- ":"-"),abs(poly[i]));
					}
					break;
				default:
					switch(poly[i]){
						case 1:
							printf("%sx^%d",plus?"+ ":"",i);
							break;
						case -1:
							printf("%sx^%d",minus?"- ":"-",i);
							break;
						default:
							printf("%s%dx^%d",(poly[i]>0?(plus?"+ ":""):(minus?"- ":"-")),abs(poly[i]),i);
					}
					break;
			}
			if(i>endpoly) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
