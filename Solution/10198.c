#include<stdio.h>
#include<string.h>
#define MAX_DIGIT 410
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
typedef struct BIG_NUM{
	char n[MAX_DIGIT];
	int digits;
}BigNum;
void printBigNum(BigNum n){
	int i;
	for(i=n.digits-1;i>=0;i--) putchar(n.n[i]);
	puts("");
}
BigNum add(BigNum n1,BigNum n2){
	BigNum result;
	int mind=min(n1.digits,n2.digits),maxd=max(n1.digits,n2.digits);
	int i;
	memset(&result,0,sizeof(BigNum));
	for(i=0;i<mind;i++)
		result.n[i]=n1.n[i]+n2.n[i]-'0';
	for(i=mind;i<maxd;i++)
		result.n[i]=n1.n[i]+n2.n[i];
	for(i=1;i<=maxd;i++){
		result.n[i]+=(result.n[i-1]-'0')/10;
		result.n[i-1]=(result.n[i-1]-'0')%10+'0';
	}
	result.digits=maxd;
	if(result.n[maxd]) result.n[maxd]+='0',result.digits++;
	return result;
}
int main(){
	BigNum a,b;
	BigNum Count[1005]={0};
	int i,n;
	strcpy(Count[0].n,"1");
	Count[0].digits=1;
	strcpy(Count[1].n,"2");
	Count[1].digits=1;
	strcpy(Count[2].n,"5");
	Count[2].digits=1;
	for(i=3;i<=1000;i++)
		Count[i]=add(add(add(Count[i-1],Count[i-1]),Count[i-2]),Count[i-3]);
	while(scanf("%d",&n)==1)
		printBigNum(Count[n]);
	return 0;
}
