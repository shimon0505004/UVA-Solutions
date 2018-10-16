#include<stdio.h>
int greedy(int *in,int need){
	int result;
	if(!need) return 0;
	if((*in)>=need){
		(*in)-=need;
		return 0;
	}else{
		result=need-(*in);
		(*in)=0;
		return result;
	}
}
int main()
{
	int package[7],i,all,t;
	while(1){
		t=0;
		for(i=1;i<=6;i++){
			scanf("%d",&package[i]);
			t+=package[i];
		}
		if(!t) break;
		all=package[6];
		all+=t=package[5];
		package[1]-=t*11;
		all+=t=package[4];
		if(package[2]>=5*t){
			package[2]-=5*t;
			t=0;
		}else{
			t=20*t-package[2]*4;
			package[2]=0;
		}
		package[1]-=t;
		all+=package[3]/4;
		package[3]%=4;
		if(package[3]){
			t=greedy(&package[2],7-package[3]*2);
			greedy(&package[1],8-package[3]+4*t);
			package[3]=0;
			all++;
		}
		all+=package[2]/9;
		package[2]%=9;
		if(package[2]){
			greedy(&package[1],36-package[2]*4);
			package[2]=0;
			all++;
		}
		if(package[1]<0) package[1]=0;
		all+=package[1]/36;
		package[1]%=36;
		if(package[1]) all++;
		printf("%d\n",all);
	}
	return 0;
}
