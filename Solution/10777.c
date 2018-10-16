#include<stdio.h>
int main()
{
	double ps,pw,hs,hw,result,p,h;
	int cases,doors,i,j;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d",&doors);
		ps=hs=pw=hw=0;
		for(j=0;j<doors;j++){
			scanf("%lf%lf",&h,&p);
			if(h>0){
				ps+=p;
				hs+=h*p;
			}
			else{
				pw+=p;
				hw-=h*p;
			}
		}
		hs/=ps;
		if(pw)
			hw/=pw;
		else
			hw=0;
		printf("Case %d: ",i+1);
		if(ps==0||hs==0||doors==0)
			printf("God! Save me\n");
		else{
			result=ps*hw*pw/((1.0-pw)*(1.0-pw))+ps*hs/(1.0-pw);
			printf("%.2lf\n",result);
		}
	}
	return 0;
}
