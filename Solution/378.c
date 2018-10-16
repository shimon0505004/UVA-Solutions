#include<stdio.h>
int main()
{
	int cases,i,j,k,L[2][2][2],l;
	int a1,a2,b1,b2,x1,x2,y1,y2;
	double x,y;
	scanf("%d",&cases);
	printf("INTERSECTING LINES OUTPUT\n");
	for(l=0;l<cases;l++){
		for(i=0;i<2;i++)
			for(j=0;j<2;j++)
				for(k=0;k<2;k++)
					scanf("%d",&L[i][j][k]);
		if((L[0][0][1]-L[0][1][1])*(L[1][0][0]-L[1][1][0])==(L[1][0][1]-L[1][1][1])*(L[0][0][0]-L[0][1][0]))
			if((L[1][0][1]-L[0][0][1])*(L[1][0][0]-L[0][1][0])==(L[1][0][1]-L[0][1][1])*(L[1][0][0]-L[0][0][0]))
					printf("LINE\n");
			else	
				printf("NONE\n");
		else{
			a1=L[1][1][1]-L[1][0][1];
			a2=L[0][1][1]-L[0][0][1];
			b1=L[1][1][0]-L[1][0][0];
			b2=L[0][1][0]-L[0][0][0];
			x1=L[1][1][0];
			x2=L[0][1][0];
			y1=L[1][1][1];
			y2=L[0][1][1];
			x=(double)(a1*b2*x1-a2*b1*x2-b1*b2*y1+b2*b1*y2)/(a1*b2-a2*b1);
			y=(double)(a1*a2*(x1-x2)+b2*a1*y2-b1*a2*y1)/(a1*b2-a2*b1);
			printf("POINT %.2lf %.2lf\n",x,y);
		}
			
	}
	printf("END OF OUTPUT\n");
	return 0;
}
