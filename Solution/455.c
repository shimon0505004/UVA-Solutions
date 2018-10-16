#include<stdio.h>
#include<string.h>
int main()
{
	int i,step,len,cases;
	char string[100];
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",string);
		len=strlen(string);
		for(step=1;step<=len;step++){
			if(len%step) continue;
			for(i=1;i<len/step;i++)
				if(strncmp(string,string+step*i,step)) break;
			if(i==len/step){
				printf("%d\n",step);
				break;
			}
		}
		if(cases) puts("");
	}
	return 0;
}
