#include<stdio.h>
int main(){
	int i,k,sqar;
	int a[1000],b[1000],count;
	while(scanf("%d",&k)==1){
		sqar=k*k;
		for(i=1,count=0;i*i<=sqar;i++)
			if(sqar%i==0)
				a[count]=i+k,b[count]=sqar/i+k,count++;
		printf("%d\n",count);
		for(i=0;i<count;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,b[i],a[i]);
	}
	return 0;
}
