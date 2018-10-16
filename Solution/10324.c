#include<stdio.h>
int main()
{
	int ZO[1000005];
	char charZO[1000005];
	char a,previous;
	int q,start,end,i,cases=0,temp;
	int len;
	while(1){
		memset(ZO,0,sizeof(ZO));
		if(fgets(charZO,1000005,stdin)==NULL) break;
		len=strlen(charZO)-1;
		ZO[0]=charZO[0]-'0';
		for(i=1;i<len;i++)
			ZO[i]=ZO[i-1]+charZO[i]-'0';
		scanf("%d",&q);
		printf("Case %d:\n",++cases);
		while(q--){
			scanf("%d%d",&start,&end);
			if(start>end){
				temp=start;
				start=end;
				end=temp;
			}
			if(charZO[start]=='1')
				if((ZO[end]-ZO[start])==(end-start))
					printf("Yes\n");
				else
					printf("No\n");
			else
				if(!(ZO[end]-ZO[start]))
					printf("Yes\n");
				else
					printf("No\n");
		}
		if(getchar()==EOF) break;
	}
	return 0;
}
