#include<stdio.h>
#include<string.h>
struct MAP{
	int B,D,L[15],U[15],C[15];
	char name[15];
};
int main(){
	int N,Q,i,j,d,Cd,n,q[15],phyadd;
	char qname[15];
	struct MAP m[100];
	scanf("%d%d",&N,&Q);
	for(i=0;i<N;i++){
		scanf("%s%d%d%d",m[i].name,&m[i].B,&Cd,&m[i].D);
		for(j=1;j<=m[i].D;j++)
			scanf("%d%d",&m[i].L[j],&m[i].U[j]);
		m[i].C[m[i].D]=Cd;
		for(d=m[i].D-1;d>0;d--){
			m[i].C[d]=m[i].C[d+1]*(m[i].U[d+1]-m[i].L[d+1]+1);
		}
		for(m[i].C[0]=m[i].B,j=1;j<=m[i].D;j++)
			m[i].C[0]-=m[i].C[j]*m[i].L[j];
	}
	while(Q--){
		scanf("%s",qname);
		for(n=0;strcmp(m[n].name,qname);n++);
		for(i=1;i<=m[n].D;i++) scanf("%d",&q[i]);
		printf("%s[%d",qname,q[1]);
		for(i=2;i<=m[n].D;i++) printf(", %d",q[i]);
		printf("] = ");
		phyadd=m[n].C[0];
		for(i=1;i<=m[n].D;i++) phyadd+=m[n].C[i]*q[i];
		printf("%d\n",phyadd);
	}
	return 0;
}
