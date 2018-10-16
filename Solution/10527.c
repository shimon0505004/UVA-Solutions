#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char One(char n[]){
	int i,len=strlen(n);
	for(i=0;i<len-1;i++) if(n[i]!='0') return 0;
	if(n[len-1]=='1') return 1;
	return 0;
}
int main(){
	char number[2][1005];
	int len,i,j,total;
	int factor[10];
	char *now,*next;
	int rest,quotient;
	char divide_exactly;
	while(scanf("%s",number[0]),number[0][0]!='-'){
		if(atoi(number[0])==0){
			puts("10");
			continue;
		}else if(atoi(number[0])==1){
			puts("11");
			continue;
		}
		len=strlen(number[0]);
		memset(factor,0,sizeof(factor));
		number[1][len]=0;
		now=number[0],next=number[1];
		divide_exactly=0;
		for(i=9;i>=2&&divide_exactly==0;i--){
			for(;;){
				rest=0;
				quotient=0;
				for(j=0;j<len;j++){
					int q;
					rest*=10;
					q=rest+now[j]-'0';
					next[j]=q/i+'0';
					quotient+=q/i;
					rest=q%i;
				}
				if(rest!=0) break;
				factor[i]++;
				if(One(next)){
					divide_exactly=1;
					break;
				}
				{char *tmp=next;next=now;now=tmp;}
			}
		}
		if(divide_exactly){
			total=0;
			for(i=2;i<=9;i++)
				total+=factor[i];
			if(total==1){
				printf("1");
				for(i=2;i<=9;i++)
					if(factor[i]){
						printf("%d\n",i);
						break;
					}
			}else{
				for(i=2;i<=9;i++)
					for(j=0;j<factor[i];j++)
						printf("%d",i);
				puts("");
			}
		}else puts("There is no such number.");
	}
	return 0;
}
