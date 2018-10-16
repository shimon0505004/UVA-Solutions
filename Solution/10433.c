#include<stdio.h>
#include<string.h>
#define SIZE 250
#define MODULI 1000000000
struct BigInt{
	int d[SIZE];
};
int len;
int offset,rest;
int pow_10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
char equal(struct BigInt *n1,struct BigInt *n2){
	int i;
	if(n1->d[offset]%pow_10[rest]!=n2->d[offset]%pow_10[rest]) return 0;
	for(i=offset-1;i>=0;i--)
		if(n1->d[i]!=n2->d[i]) return 0;
	return 1;
}
void square(struct BigInt *dest,struct BigInt *src){
	long long tmp[SIZE]={0};
	int i,j;
	memset(dest,0,sizeof(struct BigInt));
	for(i=0;i<=offset;i++)
		for(j=0;i+j<=offset;j++){
			tmp[i+j]+=(long long)src->d[i]*src->d[j];
			tmp[i+j+1]+=tmp[i+j]/MODULI,tmp[i+j]%=MODULI;
		}
	for(i=0;i<=offset;i++)
		dest->d[i]=tmp[i]%MODULI,tmp[i+1]+=tmp[i]/MODULI;
}
int main(){
	struct BigInt b1,b2;
	char input[2005],*ptr;
	while(scanf("%s",input)==1){
		len=strlen(input);
		if(input[len-1]=='0'||input[len-1]=='1') puts("Not an Automorphic number.");
		else{
			int i;
			char tmp[10]={0};
			offset=(len-1)/9,rest=(len-1)%9+1;
			memset(&b1,0,sizeof(b1));
			strncpy(tmp,input,rest);
			sscanf(tmp,"%d",&b1.d[offset]);
			ptr=input+rest;
			for(i=offset-1;i>=0;i--,ptr+=9)
				sscanf(ptr,"%9d",&b1.d[i]);
			square(&b2,&b1);
			if(equal(&b1,&b2)) printf("Automorphic number of %d-digit.\n",len);
			else puts("Not an Automorphic number.");
		}
	}
	return 0;
}
