#include<stdio.h>
#include<string.h>
int cal_digit(char rule[]){
	int result=0,len=strlen(rule);
	int i;
	for(i=0;i<len;i++) if(rule[i]=='0') result++;
	return result;
}
int main(){
	int n_word,n_rule;
	int n_digit,i,j,k,len,count,combination;
	int pow_10[8]={1,10,100,1000,10000,100000,1000000,10000000};
	char dictionary[105][260];
	char rule[260];
	while(scanf("%d",&n_word)==1){
		for(i=0;i<n_word;i++) scanf("%s",dictionary[i]);
		scanf("%d",&n_rule);
		puts("--");
		while(n_rule--){
			scanf("%s",rule);
			len=strlen(rule);
			n_digit=cal_digit(rule);
			combination=pow_10[n_digit];
			for(i=0;i<n_word;i++){
				for(j=0;j<combination;j++){
					count=n_digit;
					for(k=0;k<len;k++){
						if(rule[k]=='#') printf("%s",dictionary[i]);
						else printf("%d",(j/pow_10[--count])%10);
					}
					puts("");
				}
			}
		}
	}
	return 0;
}
