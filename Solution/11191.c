#include<stdio.h>
#include<string.h>
int main(){
	int cases;
	int i,j,size=1<<11;
	long long vec[1<<11];
	int prime[10]={2,3,5,7,11,13,17,19,23,29};
	scanf("%d",&cases);
	while(cases--){
		long long n_zero=0,n;
		long long c_n_2=0,c_n_3=0;
		memset(vec,0,sizeof(vec));
		scanf("%lld",&n);
		for(i=0;i<n;i++){
			int index=0;
			long long value;
			scanf("%lld",&value);
			if(value==0) n_zero++;
			else{
				int t;
				if(value<0) value=-value,index^=1<<10;
				for(j=0,t=1;j<10;j++,t<<=1){
					while(value%prime[j]==0){
						index^=t;
						value/=prime[j];
					}
				}
				vec[index]++;
			}
		}
		for(i=0;i<size;i++) c_n_2+=vec[i]*(vec[i]-1)/2;
		c_n_2+=n_zero*(n-n_zero)+n_zero*(n_zero-1)/2;
		c_n_3+=vec[0]*(vec[0]-1)/2*(vec[0]-2)/3;
		for(i=1;i<size;i++) c_n_3+=vec[i]*(vec[i]-1)/2*vec[0];
		for(i=1;i<size;i++)
			for(j=i+1;j<size;j++)
				if((i^j)>j)
					c_n_3+=vec[i]*vec[j]*vec[i^j];
		c_n_3+=n_zero*(n_zero-1)/2*(n_zero-2)/3;
		c_n_3+=n_zero*(n_zero-1)/2*(n-n_zero);
		c_n_3+=(n-n_zero)*(n-n_zero-1)/2*n_zero;
		printf("%lld %lld\n",c_n_2,c_n_3);
	}
	return 0;
}
