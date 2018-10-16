#include<stdio.h>
#define MaxFactorys 1024
int main()
{
	int wants,facs,supports[MaxFactorys];
	int i,n=0,j,maxneeds,maxi;
	char w[100],facname[MaxFactorys][100]={0},temp;
	float price[MaxFactorys],lowprice;
	while(1){
		maxneeds=0;
		scanf("%d%d",&wants,&facs);
		getchar();
		if(wants+facs==0) break;
		if(n) printf("\n");
		for(i=0;i<wants;i++)
			fgets(w,85,stdin);
		for(i=0;i<facs;i++){
			fgets(facname[i],85,stdin);
			facname[i][strlen(facname[i])-1]=0;
			scanf("%f%d",&price[i],&supports[i]);
			getchar();
			for(j=0;j<supports[i];j++)
				fgets(w,85,stdin);
		}
		for(i=0;i<facs;i++)
			if(maxneeds<supports[i]){
				lowprice=price[i];
				maxneeds=supports[i];
				maxi=i;
			}
			else if(maxneeds==supports[i])
				if(price[i]<lowprice){
					lowprice=supports[i];
					maxi=i;					
				}
		printf("RFP #%d\n%s\n",++n,facname[maxi]);
	}
	return 0;
}
