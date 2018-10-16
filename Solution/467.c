#include<stdio.h>
#include<string.h>
int main(){
	char line[50],*ptr;
	int n_signal,signal[10],len;
	int i,j;
	int cases;
	char notgreen[3601];
	for(cases=1;fgets(line,50,stdin)!=NULL;cases++){
		memset(notgreen,0,sizeof(notgreen));
		for(ptr=line,n_signal=0;sscanf(ptr,"%d%n",&signal[n_signal],&len)==1;ptr+=len,n_signal++);
		for(i=0;i<n_signal;i++)
			for(j=0;j<3601;j++)
				if(j%(signal[i]*2)>=signal[i]-5) notgreen[j]=1;
		for(i=0;notgreen[i]==0;i++);
		for(;notgreen[i]!=0&&i<=3600;i++);
		if(i<=3600) printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",cases,i/60,i%60);
		else printf("Set %d is unable to synch after one hour.\n",cases);
	}
	return 0;
}
