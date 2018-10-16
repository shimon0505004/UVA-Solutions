#include <stdio.h>
#include <string.h>
int num;
char pre[60],in[60];
void post(int start,int end)
{
	if(start<end)
	{
		int t;
		t=0;
		t=strchr(in,pre[num])-in;
		num++;
		post(start,t);
		post(t+1,end);
		printf("%c",in[t]);
	}
}
int main()
{
	int n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d%s%s",&a,&pre,&in);
		num=0;
		post(0,strlen(in));
		printf("\n");
	}
	return 0;
}
