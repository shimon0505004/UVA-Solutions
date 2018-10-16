#include<stdio.h>
#include<string.h>
int main()
{
	int n,k,C,i,f,l,t,start=0;
	int map[26][26]={0};
	int RPS[101][2];
	char frps[10],lrps[10];
	map['r'-'a']['p'-'a']=-1;
	map['r'-'a']['s'-'a']=1;
	map['p'-'a']['r'-'a']=1;
	map['p'-'a']['s'-'a']=-1;
	map['s'-'a']['r'-'a']=-1;
	map['s'-'a']['p'-'a']=1;
	while(scanf("%d%d",&n,&k),n){
		if(start) puts("");
		start=1;
		C=k*n*(n-1)/2;
		memset(RPS,0,sizeof(RPS));
		for(i=1;i<=C;i++){
			scanf("%d%s%d%s",&f,frps,&l,lrps);
			t=map[*frps-'a'][*lrps-'a'];
			if(t>0){
				RPS[f][0]++;
				RPS[l][1]++;
			}else if(t<0){
				RPS[f][1]++;
				RPS[l][0]++;
			}
		}
		for(i=1;i<=n;i++)
			if((t=RPS[i][0]+RPS[i][1])==0)
				puts("-");
			else
				printf("%.3lf\n",(double)RPS[i][0]/t);
	}
	return 0;
}
