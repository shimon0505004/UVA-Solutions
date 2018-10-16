#include<stdio.h>
#include<string.h>
int main()
{
	int width,i,j,k,len;
	char num[10];
	int n[10][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
	while(1){
		memset(num,0,sizeof(num));
		scanf("%d%s",&width,num);
		if(!(width+atoi(num))) break;
		len=strlen(num);
		for(i=0;i<len;i++){
			if(i) printf(" ");
			printf(" ");
			for(j=0;j<width;j++)
				printf("%s",n[num[i]-'0'][0]?"-":" ");
			printf(" ");
		}
		printf("\n");
		for(k=0;k<width;k++){
			for(i=0;i<len;i++){
				if(i) printf(" ");
				printf("%s",n[num[i]-'0'][1]?"|":" ");
				for(j=0;j<width;j++)
					printf(" ");
				printf("%s",n[num[i]-'0'][2]?"|":" ");
			}
			printf("\n");
		}
		for(i=0;i<len;i++){
			if(i) printf(" ");
			printf(" ");
			for(j=0;j<width;j++)
				printf("%s",n[num[i]-'0'][3]?"-":" ");
			printf(" ");
		}
		printf("\n");
		for(k=0;k<width;k++){
			for(i=0;i<len;i++){
				if(i) printf(" ");
				printf("%s",n[num[i]-'0'][4]?"|":" ");
				for(j=0;j<width;j++)
					printf(" ");
				printf("%s",n[num[i]-'0'][5]?"|":" ");
			}
			printf("\n");
		}
		for(i=0;i<len;i++){
			if(i) printf(" ");
			printf(" ");
			for(j=0;j<width;j++)
				printf("%s",n[num[i]-'0'][6]?"-":" ");
			printf(" ");
		}
		printf("\n\n");
	}
	return 0;
}
