#include<stdio.h>
int main()
{
	double fig[10][4]={0},Px,Py;
	char test[10][100],*tokenPtr;
	int i=0,j=0,k,flag;
	while(1){
		gets(test[i]);
		if(test[i][0]=='*') break;
		if(test[i][0]=='r'){
			tokenPtr=test[i]+2;
			sscanf(tokenPtr,"%lf%lf%lf%lf",&fig[i][0],&fig[i][1],&fig[i][2],&fig[i][3]);
		}
		else{
			tokenPtr=test[i]+2;
			sscanf(tokenPtr,"%lf%lf%lf",&fig[i][0],&fig[i][1],&fig[i][2]);
		}
		i++;
	}
	k=0;
	while(1){
		k++;
		flag=0;
		scanf("%lf%lf",&Px,&Py);
		if(Px==9999.9 && Py==9999.9) break;
		for(j=0;j<i;j++){
			if(test[j][0]=='r'){
				if((Px-fig[j][0])*(Px-fig[j][2])<0)
					if((Py-fig[j][1])*(Py-fig[j][3])<0){
						printf("Point %d is contained in figure %d\n",k,j+1);
						flag=1;
					}
			}
			else if(test[j][0]=='c')
				if((Px-fig[j][0])*(Px-fig[j][0])+(Py-fig[j][1])*(Py-fig[j][1])<fig[j][2]*fig[j][2]){
					printf("Point %d is contained in figure %d\n",k,j+1);
					flag=1;
				}
		}
		if(flag==0) printf("Point %d is not contained in any figure\n",k);
	}
	return 0;
}
