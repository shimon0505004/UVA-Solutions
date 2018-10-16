#include<stdio.h>
#include<string.h>
int main()
{
	int i,step,len;
	char string[1000010];
	while(scanf("%s",string)==1&&*string!='.'){
		len=strlen(string);
		for(step=1;step<=len;step++){
			if(len%step) continue;
			for(i=1;i<len/step;i++)
				if(strncmp(string,string+step*i,step)) break;
			if(i==len/step){
				printf("%d\n",len/step);
				break;
			}
		}
	}
	return 0;
}
