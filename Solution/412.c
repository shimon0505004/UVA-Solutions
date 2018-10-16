#include<stdio.h>
#include<math.h>
int relaprime(int,int);
int main()
{
	int n,i,j,reprime[50],cases,totalcases;
	double pi;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		totalcases=cases=0;
		for(i=0;i<n;i++)
			scanf("%d",&reprime[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++){
				if(relaprime(reprime[i],reprime[j]))
					cases++;
				totalcases++;
			}
		if(!cases)
			printf("No estimate for this data set.\n");
		else{
			pi=(double)totalcases/cases;
			pi=sqrt(6*pi);
			printf("%.6lf\n",pi);
		}
	}
	return 0;
}
int relaprime(int n1,int n2)
{
	int temp;
	while(1){
		temp=n2%n1;
		if(temp==0)
			if(n1==1)
				return 1;
			else
				return 0;
		n2=n1;
		n1=temp;
	}
}
