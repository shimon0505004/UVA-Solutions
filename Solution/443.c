#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 2000000000
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
int main()
{
	int humble[6000];
	int i,j,k,l,count=0,n,check;
	double result;
	for(i=0;;i++){
		for(j=0;;j++){
			for(k=0;;k++){
				for(l=0;;l++){
					result=pow(2,i)*pow(3,j)*pow(5,k)*pow(7,l);
					if(result<=max)
						humble[count++]=(int)result;
					else
						break;
				}
				if(pow(2,i)*pow(3,j)*pow(5,k)>max) break;
			}
			if(pow(2,i)*pow(3,j)>max) break;
		}
		if(pow(2,i)>max) break;
	}
	qsort(humble,count,sizeof(int),cmp);
	while(scanf("%d",&n)&&n){
		check=n%100;
		if(check==11||check==12||check==13)
			printf("The %dth humble number is ",n);
		else if(n%10==1)
			printf("The %dst humble number is ",n);
		else if(n%10==2)
			printf("The %dnd humble number is ",n);
		else if(n%10==3)
			printf("The %drd humble number is ",n);
		else
			printf("The %dth humble number is ",n);
		printf("%d.\n",humble[n-1]);
	}
	return 0;
}
