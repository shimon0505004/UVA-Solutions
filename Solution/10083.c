#include<stdio.h>
#include<math.h>
#include<string.h>
void add(int dest[],int src[]){
	int i;
	for(i=0;i<105;i++)
		dest[i]+=src[i];
	for(i=1;i<105;i++)
		dest[i]+=dest[i-1]/10,dest[i-1]%=10;
}
void multiply(int dest[],int src[]){
	int i,j;
	int temp[105];
	memset(temp,0,sizeof(temp));
	for(i=0;i<105;i++)
		for(j=0;j+i<105;j++)
			temp[i+j]+=dest[i]*src[j];
	for(i=1;i<105;i++)
		temp[i]+=temp[i-1]/10,temp[i-1]%=10;
	memcpy(dest,temp,sizeof(temp));
}
void makeratio(int ratio[],int t,int b){
	int temp[105],i;
	memset(temp,0,sizeof(temp));
	temp[0]=t;
	for(i=1;i<105;i++)
		temp[i]+=temp[i-1]/10,temp[i-1]%=10;
	for(i=1;i<=b;i<<=1){
		if(i&b) multiply(ratio,temp);
		multiply(temp,temp);
	}
}
void clearto1(int n[]){
	memset(n,0,sizeof(int[105]));
	n[0]=1;
}
int main(){
	int t,a,b,i;
	int result[105],ratio[105],addition[105];
	while(scanf("%d%d%d",&t,&a,&b)==3){
		printf("(%d^%d-1)/(%d^%d-1) ",t,a,t,b);
		if(t==1||a%b!=0||(a-b)*log(t)/log(10)>100){
			puts("is not an integer with less than 100 digits.");
			continue;
		}
		clearto1(ratio);
		clearto1(addition);
		clearto1(result);
		makeratio(ratio,t,b);
		for(i=a/b-1;i>0;i--){
			multiply(addition,ratio);
			add(result,addition);
		}
		for(i=100;result[i]==0&&i>0;i--);
		for(;i>=0;i--) printf("%d",result[i]);
		puts("");
	}
	return 0;
}
