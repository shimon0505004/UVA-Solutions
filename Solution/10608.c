#include<stdio.h>
int parent[30005];
int size[30005];
int find_root(int n){
	if(parent[n]!=n) parent[n]=find_root(parent[n]);
	return parent[n];
}
void link(int a,int b){
	parent[b]=a;
	size[a]+=size[b];
}
int main(){
	int cases;
	int n,m,f1,f2;
	int max;
	int i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) parent[i]=i,size[i]=1;
		while(m--){
			int p1,p2;
			scanf("%d%d",&f1,&f2);
			p1=find_root(f1),p2=find_root(f2);
			if(p1!=p2) link(p1,p2);
		}
		max=0;
		for(i=1;i<=n;i++) if(parent[i]==i&&size[i]>max) max=size[i];
		printf("%d\n",max);
	}
	return 0;
}
