#include<stdio.h>
#include<string.h>
#define MAX 10000
int findindex(int n,int p[],int *size){
	int i;
	for(i=0;i<(*size);i++)
		if(n==p[i]) return i;
	p[*size]=n;
	(*size)++;
	return *size-1;
}
int findroot(int n,int parent[]){
	char travel[MAX]={0};
	if(parent[n]<0) return n;
	while(parent[n]>=0){
		if(travel[n]) return -1;
		travel[n]=1;
		n=parent[n];
	}
	return n;
}
int main(){
	int a,b,root,finish,cases,count,i,j,k,p[MAX],parent[MAX];
	char pointed[MAX];
	for(cases=1;;cases++){
		scanf("%d%d",&a,&b);
		if(a<0) break;
		if(!a&&!b){
			printf("Case %d is a tree.\n",cases);
			continue;
		}
		memset(pointed,0,sizeof(pointed));
		memset(p,0,sizeof(p));
		for(i=0;i<MAX;i++)
			parent[i]=-1;
		finish=count=0;
		printf("Case %d is ",cases);
		if(a==b){
			printf("not "),finish=1;
			finish=1;
		}
		p[0]=a;
		p[1]=b;
		pointed[1]=1;
		parent[1]=0;
		count=2;
		while(scanf("%d%d",&a,&b),a+b){
			if(!finish){
				int tmpa,tmpb;
				if(a==b){
					printf("not "),finish=1;
					continue;
				}
				tmpa=findindex(a,p,&count);
				tmpb=findindex(b,p,&count);
				if(pointed[tmpb]){
					printf("not "),finish=1;
					continue;
				}
				parent[tmpb]=tmpa;
				pointed[tmpb]=1;
			}
		}
		if(!finish){
			root=-1;
			for(i=0;i<count&&!finish;i++){
				if(root<0){
					root=findroot(i,parent);
					if(root<0){
						printf("not "),finish=1;
						break;
					}
				}else{
					if(root!=findroot(i,parent)){
						printf("not "),finish=1;
						break;
					}
				}
			}
		}
		puts("a tree.");
	}
	return 0;
}
