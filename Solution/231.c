#include<stdio.h>
#include<stdint.h>
int FindLDS(int*input,int n){
	int len=0;
	int i,j,end;
	int output[32780];
	output[0]=INT32_MAX;
	output[1]=-1;
	for(i=0;i<n;i++){
		for(j=0;;j++){
			if(output[j]<input[i]){
				output[j]=input[i];
				if(j>len){
					len++;
					end=i;
					output[len+1]=-1;
					break;
				}
				break;
			}
		}
	}
	return len;
}
int main(){
	int cases=0,n,missile[32780];
	while(1){
		for(n=0;scanf("%d",&missile[n]),missile[n]>=0;n++);
		if(n==0) break;
		if(cases) puts("");
		printf("Test #%d:\n",++cases);
		printf("  maximum possible interceptions: %d\n",FindLDS(missile,n));
	}
	return 0;
}
