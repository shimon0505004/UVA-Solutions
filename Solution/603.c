#include<stdio.h>
#include<stdlib.h>
int main(){
	int cases;
	int cars[25],orig[25];
	int park[25];
	int n_car,outcar,i,min,mini;
	char out[5];
	scanf("%d",&cases);
	while(cases--){
		for(n_car=0;;n_car++){
			scanf("%d",&orig[n_car]);
			if(orig[n_car]==99) break;
			cars[n_car]=orig[n_car]-1;
		}
		getchar();
		for(i=0;i<n_car;i++) park[i]=-1;
		while(fgets(out,5,stdin)!=NULL&&*out!='\n'){
			outcar=atoi(out)-1;
			min=20;
			for(i=0;i<n_car;i++)
				if(park[i]==-1) if((20+outcar-cars[i])%20<min) min=(20+outcar-cars[i])%20,mini=i;
			if(min<20){
				park[mini]=outcar;
				for(i=0;i<n_car;i++)
					if(park[i]==-1) cars[i]=(cars[i]+min)%20;
			}
		}
		for(i=0;i<n_car;i++){
			printf("Original position %d ",orig[i]);
			if(park[i]==-1) puts("did not park");
			else printf("parked in %d\n",park[i]+1);
		}
		if(cases) puts("");
	}
	return 0;
}
