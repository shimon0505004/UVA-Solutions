#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n,i,S,dig,j,init;
	char num[11];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",num);
		dig=strlen(num);
		S=atoi(num);
		init=S;
		while(1){
			dig=strlen(num);
			for(j=0,S=0;j<dig;j++)
				S+=pow(num[j]-'0',2);
			if(S==1){
				printf("Case #%d: %d is a Happy number.\n",i+1,init);
				break;
			}
			else if(S==4){
				printf("Case #%d: %d is an Unhappy number.\n",i+1,init);
				break;
			}
			sprintf(num,"%d",S);
		}
	}
	return 0;
}
