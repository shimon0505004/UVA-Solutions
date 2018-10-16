#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int c[100];
	int x[100],n,i,j,nx;
	int result;
	char *tokenPtr,inputc[100],inputx[100];
	while(1){
		memset(inputc,0,sizeof(inputc));
		if(fgets(inputc,100,stdin)==NULL) break;
		tokenPtr=strtok(inputc," ");
		n=0;
		memset(c,0,sizeof(c));
		while(tokenPtr!=NULL){
			sscanf(tokenPtr,"%d",&c[n++]);
			tokenPtr=strtok(NULL," ");
		}
		memset(inputx,0,sizeof(inputx));
		fgets(inputx,100,stdin);
		tokenPtr=strtok(inputx," ");
		nx=0;
		memset(x,0,sizeof(x));
		while(tokenPtr!=NULL){
			sscanf(tokenPtr,"%d",&x[nx++]);
			tokenPtr=strtok(NULL," ");
		}
		for(i=0;i<nx;i++){
			result=0;
			for(j=0;j<n-1;j++)
				result+=pow(x[i],n-1-j)*c[j];
			result+=c[n-1];
			if(i) printf(" ");
			printf("%d",result);
		}
		printf("\n");
	}
	return 0;
}


