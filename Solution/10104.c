#include<stdio.h>
int main()
{
	int A,B,D,t[2],s[2],temp[2];
	while(scanf("%d%d",&A,&B)==2){
		s[0]=0,s[1]=1;
		t[0]=1,t[1]=A/B*(-1);
		if(!(A%B)){
			printf("0 1 %d\n",B);
			continue;
		}
		while(A%B){
			D=A%B;
			A=B,B=D;
			if(!(A%B)) break;
			temp[0]=t[0],temp[1]=t[1];
			t[0]=s[0]-t[0]*(A/B);
			t[1]=s[1]-t[1]*(A/B);
			s[0]=temp[0],s[1]=temp[1];
		}
		printf("%d %d %d\n",t[0],t[1],D);
	}
	return 0;
}
