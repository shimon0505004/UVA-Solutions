#include<stdio.h>
int main()
{
	double rec[10][4]={0},Px,Py;
	char test[10][100],*tokenPtr;
	int i=0,j=0,k,flag;
	while(1){
		gets(test[i]);
		if(test[i][0]=='*') break;
		tokenPtr=test[i]+2;
		sscanf(tokenPtr,"%lf%lf%lf%lf",&rec[i][0],&rec[i][1],&rec[i][2],&rec[i][3]);
		i++;
	}
	k=0;
	while(1){
		k++;
		flag=0;
		scanf("%lf%lf",&Px,&Py);
		if(Px==9999.9 && Py==9999.9) break;
		for(j=0;j<i;j++){
			if((Px-rec[j][0])*(Px-rec[j][2])<0)
				if((Py-rec[j][1])*(Py-rec[j][3])<0){
					printf("Point %d is contained in figure %d\n",k,j+1);
					flag=1;
				}
		}
		if(flag==0) printf("Point %d is not contained in any figure\n",k);
	}
	return 0;
}
