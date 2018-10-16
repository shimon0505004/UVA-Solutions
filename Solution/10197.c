#include<stdio.h>
#include<string.h>
int main(){
	int type,i,len;
	char *suffix[3][6]={{"o","as","a","amos","ais","am"},
		{"o","es","e","emos","eis","em"},
		{"o","es","e","imos","is","em"}};
	unsigned char pronoun[6][10]={"eu","tu","ele/ela","n\xF3s","v\xF3s","eles/elas"};
	char v1[35],v2[35],tv,start=0;
	while(scanf("%s%*c%[^\n]",v1,v2)==2){
		if(start) puts("");
		start=1;
		printf("%s (to %s)\n",v1,v2);
		len=strlen(v1);
		tv=v1[len-2];
		if(v1[len-1]=='r'){
			if(tv=='a') type=0;
			else if(tv=='e') type=1;
			else if(tv=='i') type=2;
			else{
				puts("Unknown conjugation");
				continue;
			}
			v1[len-2]='\0';
			for(i=0;i<6;i++) printf("%-10s%s%s\n",pronoun[i],v1,suffix[type][i]);
		}else puts("Unknown conjugation");
	}
	return 0;
}
