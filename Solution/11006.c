#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
struct FRAC{
	int num,den;
};
struct POINT{
	int x,y;
};
char table[SIZE][SIZE]={{0}};
int insert_fracs(int n,struct FRAC frac[]){
	int i,j,sum=1,count=0;
	for(i=2;i<SIZE;i++)
		for(j=1;j<i;j++){
			if(table[i-j][j]==0){
				sum+=i;
				frac[count].num=j,frac[count].den=i-j;
				count++;
				if(sum==n) return count;
				if(sum>n) return count-1;
			}
		}
	return 0;
}
int compar(const void *a,const void *b){
	struct FRAC *f1=(struct FRAC *)a,*f2=(struct FRAC *)b;
	return f1->den*f2->num-f1->num*f2->den;
}
int main(){
	int n;
	int i,j,k,n_frac;
	struct FRAC frac[2000],sum;
	struct POINT p;
	for(i=2;i<SIZE;i++) table[i][i]=1;
	for(i=1;i<SIZE;i++){
		for(j=1;j<i;j++){
			if(table[i][j]) continue;
			for(k=2;(i+j)*k<SIZE;k++)
				table[i*k][j*k]=table[j*k][i*k]=1;
		}
	}
	while(scanf("%d",&n),n){
		n_frac=insert_fracs(n,frac);
		sum.num=sum.den=0;
		for(i=0;i<n_frac;i++)
			sum.num+=frac[i].num,sum.den+=frac[i].den;
		frac[n_frac].num=n-sum.num-sum.den,frac[n_frac].den=0;
		n_frac++;
		qsort(frac,n_frac,sizeof(struct FRAC),compar);
		p.x=sum.den,p.y=0;
		printf("(%d,%d)\n",p.x,p.y);
		for(i=0;i<n_frac;i++){
			p.x+=frac[i].num,p.y+=frac[i].den;
			printf("(%d,%d)\n",p.x,p.y);
		}
		for(i=0;i<n_frac;i++){
			p.x-=frac[i].den,p.y+=frac[i].num;
			printf("(%d,%d)\n",p.x,p.y);
		}
		for(i=0;i<n_frac;i++){
			p.x-=frac[i].num,p.y-=frac[i].den;
			printf("(%d,%d)\n",p.x,p.y);
		}
		for(i=0;i<n_frac-1;i++){
			p.x+=frac[i].den,p.y-=frac[i].num;
			printf("(%d,%d)\n",p.x,p.y);
		}
		puts("");
	}
	return 0;
}
