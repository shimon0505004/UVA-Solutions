#include<stdio.h>
#include<stdlib.h>
struct LEG{
	int len,n;
};
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int compar2(const void *a,const void *b){
	struct LEG *l1=(struct LEG *)a,*l2=(struct LEG *)b;
	return l2->len-l1->len;
}
char outside(int cut[],int n_cut,int n){
	int i;
	qsort(cut,n_cut,sizeof(int),compar);
	for(i=0;i<n_cut;i++){
		int next=(i+1)%n_cut;
		if(((cut[next]+n-cut[i])%n)*2>=n) return 1;
	}
	return 0;
}
int main(){
	int n,i,total,n_cut,cut[105];
	struct LEG leg[105];
	char start=0;
	while(scanf("%d ",&n),n){
		for(i=0;i<n;i++) scanf("%d",&leg[i].len),leg[i].n=i;
		qsort(leg,n,sizeof(struct LEG),compar2);
		if(start) puts("");
		else start=1;
		total=0;
		for(n_cut=0;n_cut<3;n_cut++) cut[n_cut]=leg[n_cut].n,total+=leg[n_cut].len;
		while(outside(cut,n_cut,n)){
			cut[n_cut]=leg[n_cut].n,total+=leg[n_cut].len;
			n_cut++;
		}
		printf("%d\n",total-leg[n_cut-1].len*n_cut);
	}
	return 0;
}
