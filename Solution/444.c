#include<stdio.h>
#include<string.h>
void reverse(char num[])
{
	char hold;
	int i;
	for(i=0;i<strlen(num)/2;i++){
		hold=num[i];
		num[i]=num[strlen(num)-1-i];
		num[strlen(num)-1-i]=hold;
	}
}
int main()
{
	char inp[250]={0},outp[250]={0};
	int i,counter,len;
	while(gets(inp)){
		counter=0;
		if(inp[0]>='0' && inp[0]<='9'){
			reverse(inp);
			for(i=0;inp[counter]!=0;i++){
				if(inp[counter]=='1'){
					sscanf(inp+counter,"%3d",&outp[i]);
					counter+=3;
				}
				else{
					sscanf(inp+counter,"%2d",&outp[i]);
					counter+=2;
				}
			}
		}
		else{
			len=strlen(inp);
			for(i=0;inp[i]!=0;i++){
				sprintf(outp+counter,"%d",inp[i]);
				if(inp[i]<100)
					counter+=2;
				else
					counter+=3;
			}
			reverse(outp);
		}
		printf("%s\n",outp);

		memset(inp,0,sizeof(inp));
		memset(outp,0,sizeof(outp));
	}
	return 0;
}
