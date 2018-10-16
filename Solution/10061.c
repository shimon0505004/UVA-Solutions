#include<stdio.h>
#include<string.h>
#include<math.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
double fac[1<<20];
int main(){
	int i,j;
	int N,B;
	int vec[4][2],v_size;
	int c_vec[4];
	int prime[10]={2,3,5,7,11,13,17,19,23,29};
	fac[0]=0;
	for(i=1;i<1<<20;i++) fac[i]=fac[i-1]+log(i);
	while(scanf("%d%d",&N,&B)==2){
		int t,tz=2147483647;
		memset(vec,0,sizeof(vec));
		memset(c_vec,0,sizeof(c_vec));
		v_size=0;
		t=B;
		for(i=0;prime[i]*prime[i]<=t;i++){
			if(t%prime[i]==0){
				vec[v_size][0]=prime[i];
				while(t%prime[i]==0) vec[v_size][1]++,t/=prime[i];
				v_size++;
			}
		}
		if(t>1) vec[v_size][0]=t,vec[v_size++][1]=1;
		for(i=0;i<v_size;i++){
			t=N;
			while(t>vec[v_size][0])
				c_vec[i]+=t/vec[i][0],t/=vec[i][0];
		}
		for(i=0;i<v_size;i++) tz=MIN(tz,c_vec[i]/vec[i][1]);
		printf("%d %d\n",tz,(int)(fac[N]/log(B)+1e-5+1));
	}
	return 0;
}
