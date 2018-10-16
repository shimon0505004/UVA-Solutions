#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int j,n1,n2,numerator,denominator,len,a,b,GCD,n=0;
	char num[15],temp[15];
	while(1){
		scanf("%d",&j);
		if(j<0) break;
		memset(num,0,sizeof(num));
		memset(temp,0,sizeof(temp));
		scanf("%s",num);
		sprintf(temp,"%s",num+2);
		len=strlen(temp);
		if(!atoi(temp)){
			printf("Case %d: 0/1\n",++n);
			continue;
		}
		if(!j){
			denominator=pow(10,len);
			numerator=atoi(temp);
		}
		else{
			n1=atoi(temp);
			temp[len-j]=0;
			n2=atoi(temp);
			numerator=n1-n2;
			denominator=pow(10,j)-1;
			denominator*=pow(10,len-j);
		}
		a=denominator;
		GCD=numerator;
		while(a%GCD){
			a%=GCD;
			b=a;
			a=GCD;
			GCD=b;
		}
		printf("Case %d: %d/%d\n",++n,numerator/GCD,denominator/GCD);
	}
	return 0;
}
