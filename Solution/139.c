#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PLACE{
	char code[10];
	char locality[30];
	int zeros;
	double price;
};
struct CALL{
	char number[100];
	double duration;
};
int compar(const void *a,const void *b){
	return strcmp(((struct PLACE *)a)->code,((struct PLACE *)b)->code);
}
int main(){
	struct PLACE p[10000];
	struct CALL call;
	int n,Ubound,Lbound,s,len;
	for(n=0;scanf("%s",p[n].code),strcmp(p[n].code,"000000");n++){
		if(p[n].code[1]=='0') p[n].zeros=2;
		else p[n].zeros=1;
		scanf(" %[^$]%*c%lf",p[n].locality,&p[n].price);
	}
	qsort(p,n,sizeof(struct PLACE),compar);
	while(scanf("%s%lf",call.number,&call.duration)==2){
		Lbound=0,Ubound=n,s=n/2;
		for(s=0;s<n;s++)
			if(strncmp(call.number,p[s].code,strlen(p[s].code))==0){
				len=strlen(call.number)-strlen(p[s].code);
				if(p[s].zeros==2){
					if(len<4||len>10) continue;
				}else
					if(len<4||len>7) continue;
				break;
			}
		len=strlen(call.number)-strlen(p[s].code);
		printf("%-16s",call.number);
		if(s==n)
			if(*call.number=='0')
				printf("%-25s%15.0lf%13.2lf\n","Unknown",call.duration,-1.0);
			else
				printf("%s%30s%5.0lf%6.2lf%7.2lf\n","Local",call.number,call.duration,0.0,0.0);
		else
			printf("%-25s%10s%5.0lf%6.2lf%7.2lf\n",p[s].locality,call.number+strlen(p[s].code),call.duration,p[s].price/100,p[s].price*call.duration/100);
	}
	return 0;
}
