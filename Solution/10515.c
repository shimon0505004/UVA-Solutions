#include<stdio.h>
#include<math.h>
int main()
{
	int m,n,p,lenm,lenn;
	char inpm[105]={0},inpn[105]={0};
	while(1){
		scanf("%s%s",inpm,inpn);
		lenm=strlen(inpm);
		lenn=strlen(inpn);
		m=inpm[lenm-1]-'0';
		n=inpn[lenn-1]-'0';
		if(m+n==0&&lenm+lenn==2) break;
		if(lenn>1)
			n+=(inpn[lenn-2]-'0')*10;
		if(m==0 && n!=0)
			printf("0\n");
		else if(n==0 && lenn==1)
			printf("1\n");
		else if(n%4==0){
			p=pow(m,4);
			printf("%d\n",p%10);
		}
		else{
			n%=4;
			p=pow(m,n);
			printf("%d\n",p%10);
		}
	}
	return 0;
}
