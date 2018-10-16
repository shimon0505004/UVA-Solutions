#include<stdio.h>
struct FRAC{
	int den,num;
};
int gcd(int a,int b){
	int temp;
	while(a%b!=0) temp=a%b,a=b,b=temp;
	return b;
}
int main(){
	struct FRAC rational[500800];
	int n,count,phi;
	int i,j,prev;
	rational[0].num=1,rational[0].den=1;
	rational[1].num=0,rational[1].den=1;
	rational[2].num=-1,rational[2].den=1;
	count=3;
	for(i=2;i<=641;i++){
		prev=count;
		for(j=i-1;j>0;j--){
			if(gcd(i,j)==1){
				rational[count].num=-i,rational[count].den=j;
				count++;
			}
		}
		phi=count-prev;
		for(j=0;j<phi;j++){
			rational[count+j].num=-rational[count-j-1].num;
			rational[count+j].den=rational[count-j-1].den;
		}
		count+=phi;
		for(j=0;j<phi;j++){
			rational[count+j].num=rational[count-j-1].den;
			rational[count+j].den=rational[count-j-1].num;
		}
		count+=phi;
		for(j=0;j<phi;j++){
			rational[count+j].num=-rational[count-j-1].num;
			rational[count+j].den=rational[count-j-1].den;
		}
		count+=phi;
	}
	while(scanf("%d",&n)==1)
		printf("%d / %d\n",rational[n].num,rational[n].den);
	return 0;
}
