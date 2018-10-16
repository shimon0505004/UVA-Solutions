#include<stdio.h>
#include<string.h>
int p[50005];
int find_set(int s){
	if(s!=p[s])
		p[s]=find_set(p[s]);
	return p[s];
}
void link(int s1,int s2){
	p[s2]=s1;
}
int main(){
	int n,m,i;
	int s1,s2,religions,cases;
	for(cases=1;scanf("%d%d",&n,&m),n||m;cases++){
		memset(p,0,sizeof(p));
		for(i=0;i<n;i++) p[i]=i;
		while(m--){
			scanf("%d%d",&s1,&s2);
			link(find_set(s1),find_set(s2));
		}
		religions=0;
		for(i=0;i<n;i++)
			if(p[i]==i) religions++;
		printf("Case %d: %d\n",cases,religions);
	}
	return 0;
}
