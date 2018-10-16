#include<stdio.h>
#include<string.h>
#define voltage 1
#define current 2
#define power 4
int main()
{
	int cases,i,j,flag,total;
	char ques[10000],*Ptr;
	double n[3];
	scanf("%d ",&cases);
	for(i=1;i<=cases;i++){
		printf("Problem #%d\n",i);
		fgets(ques,10000,stdin);
		total=0;
		Ptr=ques;
		for(j=0;j<2;j++){
			Ptr=strchr(Ptr,'=');
			if(*(Ptr-1)=='U') flag=voltage;
			else if(*(Ptr-1)=='I') flag=current;
			else if(*(Ptr-1)=='P') flag=power;
			total+=flag;
			sscanf(Ptr+1,"%lf",&n[flag]);
			Ptr+=strspn(Ptr+1,"0123456789.")+1;
			switch(*Ptr){
				case 'm':
					n[flag]/=1000;
					break;
				case 'k':
					n[flag]*=1000;
					break;
				case 'M':
					n[flag]*=1000000;
					break;
			}
		}
		switch(total){
			case voltage+current:
				printf("P=%.2lfW",n[voltage]*n[current]);
				break;
			case voltage+power:
				printf("I=%.2lfA",n[power]/n[voltage]);
				break;
			case current+power:
				printf("U=%.2lfV",n[power]/n[current]);
				break;
		}
		printf("\n\n");
	}
	return 0;
}
