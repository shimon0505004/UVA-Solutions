#include<stdio.h>
#include<string.h>
#define maxdXY 260
#define maxR 510
int main()
{
	char X[maxdXY+1]={0},Y[maxdXY+1]={0};
	int result[maxR+1];
	char out[maxR+1];
	char temp[maxdXY+1]={0};
	int lenX,lenY,i,j,next;
	while(1){
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		memset(result,0,sizeof(result));
		next=0;
		if(scanf("%s",temp)==EOF) break;
		if(!atoi(temp))
			next=1;
		lenX=strlen(temp);
		strcpy(X+maxdXY-lenX,temp);
		if(scanf("%s",temp)==EOF) break;
		if(!atoi(temp))
			next=1;
		if(next){
			printf("0\n");
			continue;
		}
		lenY=strlen(temp);
		strcpy(Y+maxdXY-lenY,temp);
		for(i=maxdXY-lenX;i<maxdXY;i++)
			X[i]-='0';
		for(i=maxdXY-lenY;i<maxdXY;i++)
			Y[i]-='0';
		for(i=0;i<lenY;i++)
			for(j=0;j<lenX;j++)
				result[maxR-1-i-j]+=X[maxdXY-j-1]*Y[maxdXY-i-1];
		for(i=1;i<maxR;i++){
			result[maxR-1-i]+=result[maxR-i]/10;
			result[maxR-i]%=10;
		}
		for(i=0;i<maxR;i++)
			out[i]=result[i]+'0';
		printf("%s\n",out+strspn(out,"0"));
	}
	return 0;
}
