#include<stdio.h>
int flapjack[30];
void flip(int pos){
	int i,temp;
	for(i=0;i<=pos/2;i++){
		temp=flapjack[i];
		flapjack[i]=flapjack[pos-i];
		flapjack[pos-i]=temp;
	}
}
int main()
{
	int i,n,max,maxi,j,k,start;
	char temp;
	for(;;){
		temp='\0';
		for(n=0;temp!='\n';n++)
			if(scanf("%d%c",&flapjack[n],&temp)!=2) break;
		if(feof(stdin)) break;
		printf("%d",flapjack[0]);
		for(i=1;i<n;i++)
			printf(" %d",flapjack[i]);
		puts("");
		start=0;
		for(j=0;j<n;j++){
			max=-1;
			for(i=0;i<n-j;i++)
				if(max<flapjack[i]){
					max=flapjack[i];
					maxi=i;
				}
			if(maxi<n-j-1){
				if(maxi>0){
					if(start) putchar(' ');
					printf("%d",n-maxi);
					start=1;
					flip(maxi);
				}
				if(start) putchar(' ');
				printf("%d",j+1);
				start=1;
				flip(n-1-j);
			}
		}
		if(start) putchar(' ');
		puts("0");
	}
	return 0;
}
