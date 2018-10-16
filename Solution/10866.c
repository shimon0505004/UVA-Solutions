#include<stdio.h>
#include<string.h>
int main(){
	int prime,i;
	char output[100005];
	while(scanf("%d",&prime),prime){
		if(prime==2) puts("Impossible");
		else{
			memset(output,'1',sizeof(output));
			output[prime-1]=0;
			for(i=1;i<prime;i++)
				output[(long long)i*i%prime-1]='0';
			puts(output);
		}
	}
	return 0;
}
