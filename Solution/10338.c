#include<stdio.h>
int main()
{
	long long int result;
	int n,i,j,k,tot,words[30]={0};
	char a;
	scanf("%d ",&n);
	for(i=0;i<n;i++){
		for(j=0;j<30;j++)
			words[j]=0;
		tot=0;
		result=1;
		while(1){
			a=getchar();
			if(a!='\n'){
				words[a-'A']++;
				continue;
			}
			else{
				for(j=0;j<30;j++)
					tot+=words[j];
				for(j=1;j<=tot;j++)
					result*=j;
				for(j=0;j<30;j++)
					if(words[j]>0)
						for(k=1;k<=words[j];k++)
							result/=k;
				break;
			}
		}
		printf("Data set %d: %lld\n",i+1,result);
	}
	return 0;
}
