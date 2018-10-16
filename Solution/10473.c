#include<stdio.h>
#include<math.h>
int main()
{
	char num[15];
	int n;
	while(1){
		scanf("%s",num);
		if(atoi(num)<0) break;
		sscanf(num,"%i",&n);
		if(num[0]=='0')
			printf("%d\n",n);
		else
			printf("%#X\n",n);
	}
	return 0;
}
