#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct FRACTION{
	int den,num;
}Fraction;
int compar(const void *a,const void *b){
	Fraction *f1=(Fraction *)a,*f2=(Fraction *)b;
	if(f1->num*f2->den>f1->den*f2->num)
		return 1;
	return -1;
}
char Reducible(Fraction *f){
	int temp,a=f->den,b=f->num;
	while(a%b!=0)
		temp=a,a=b,b=temp%b;
	return b!=1;
}
int main(){
	int n,k;
	int i,j,count;
	Fraction F[304200];
	F[0].den=F[0].num=1;
	for(i=2,count=1;i<=1000;i++){
		for(j=1;j<=i;j++){
			F[count].den=i,F[count].num=j;
			if(!Reducible(F+count)) count++;
		}
	}
	qsort(F,count,sizeof(Fraction),compar);
	while(scanf("%d%d",&n,&k)==2){
		for(i=0;i<count;i++)
			if(F[i].den<=n)
				if(--k==0){
					printf("%d/%d\n",F[i].num,F[i].den);
					break;
				}
	}
	return 0;
}
