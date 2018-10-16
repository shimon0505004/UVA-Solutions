#include<stdio.h>
#include<math.h>
double distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double area(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double s1,s2,s3,area,s;
	s1=distance(x1,y1,x2,y2);
	s2=distance(x1,y1,x3,y3);
	s3=distance(x2,y2,x3,y3);
	s=(s1+s2+s3)/2.0;
	return sqrt(s*(s-s1)*(s-s2)*(s-s3));
}
int main()
{
	double fig[10][6]={0},Px,Py;
	char test[10][100],*tokenPtr;
	int i=0,j=0,k,flag;
	double area1,area2,area3,areatri;
	while(1){
		gets(test[i]);
		if(test[i][0]=='*') break;
		if(test[i][0]=='r'){
			tokenPtr=test[i]+2;
			sscanf(tokenPtr,"%lf%lf%lf%lf",&fig[i][0],&fig[i][1],&fig[i][2],&fig[i][3]);
		}
		else if(test[i][0]=='c'){
			tokenPtr=test[i]+2;
			sscanf(tokenPtr,"%lf%lf%lf",&fig[i][0],&fig[i][1],&fig[i][2]);
		}
		else{
			tokenPtr=test[i]+2;
			sscanf(tokenPtr,"%lf%lf%lf%lf%lf%lf",&fig[i][0],&fig[i][1],&fig[i][2],&fig[i][3],&fig[i][4],&fig[i][5]);
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
			else if(test[j][0]=='c'){
				if((Px-fig[j][0])*(Px-fig[j][0])+(Py-fig[j][1])*(Py-fig[j][1])<fig[j][2]*fig[j][2]){
					printf("Point %d is contained in figure %d\n",k,j+1);
					flag=1;
				}
			}
			else{
				areatri=area(fig[j][0],fig[j][1],fig[j][2],fig[j][3],fig[j][4],fig[j][5]);
				area1=area(fig[j][0],fig[j][1],fig[j][2],fig[j][3],Px,Py);
				area2=area(fig[j][2],fig[j][3],fig[j][4],fig[j][5],Px,Py);
				area3=area(fig[j][0],fig[j][1],fig[j][4],fig[j][5],Px,Py);
				if(area1&&area2&&area3)
					if(fabs(area1+area2+area3-areatri)<0.0001){
						printf("Point %d is contained in figure %d\n",k,j+1);
						flag=1;
					}
			}

		}
		if(flag==0) printf("Point %d is not contained in any figure\n",k);
	}
	return 0;
}
