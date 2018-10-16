#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define SIZE 7100
struct ELEV{
	int X,Y;
};
int E,F;
int GCD(int a,int b){
	int temp;
	while(a%b!=0) temp=a,a=b,b=temp%b;
	return b;
}
int BigMod(int a,int p,int m){
	if(p==0) return 1;
	if(p%2==1){
		long long tmp=BigMod(a,p-1,m);
		tmp*=a,tmp%=m;
		return (int)tmp;
	}else{
		long long tmp=BigMod(a,p/2,m);
		tmp*=tmp,tmp%=m;
		return (int)tmp;
	}
}
int prime[909],n_prime=0;
void build_prime(){
	int i,j;
	char notprime[7100]={0};
	for(i=2;i<SIZE/2;i++){
		if(notprime[i]) continue;
		prime[n_prime++]=i;
		for(j=2;i*j<SIZE;j++)
			notprime[i*j]=1;
	}
	for(i=SIZE/2;i<SIZE;i++) if(!notprime[i]) prime[n_prime++]=i;
}
int phi(int n){
	int i,ret=n;
	for(i=0;prime[i]*prime[i]<=n;i++){
		if(n%prime[i]==0){
			ret/=prime[i],ret*=prime[i]-1;
			while(n%prime[i]==0) n/=prime[i];
		}
	}
	if(n>1) ret/=n,ret*=n-1;
	return ret;
}
char reachable(char map[][105],struct ELEV elev[],int A,int B){
	int i,j;
	for(i=0;i<E;i++){
		if(A<elev[i].Y||(A-elev[i].Y)%elev[i].X!=0) continue;
		for(j=0;j<E;j++)
			if(map[i][j]&&B>=elev[j].Y&&(B-elev[j].Y)%elev[j].X==0) return 1;
	}
	return 0;
}
char connect(struct ELEV *e1,struct ELEV *e2){
	int dx=GCD(e1->X,e2->X),dy=abs(e1->Y-e2->Y);
	long long x1,x2,y1,y2;
	long long co1,co2,t;
	if(dy%dx!=0) return 0;
	if(e1->Y<e2->Y) x1=e1->X,y1=e1->Y,x2=e2->X,y2=e2->Y;
	else x2=e1->X,y2=e1->Y,x1=e2->X,y1=e2->Y;
	if(x1==1) return 1;
	if(x2==1) co1=1,co2=x1-1;
	else{
		co1=(long long)BigMod(x1/dx,phi(x2/dx)-1,x2/dx);
		co2=(long long)x1*co1/x2;
	}
	co1*=dy/dx,co2*=dy/dx;
	t=MIN(co1/x2,co2/x1);
	co1-=x2*t;
	if(x1*co1+y1>=F) return 0;
	return 1;
}
int main(){
	int cases;
	int A,B,i,j,k;
	char map[105][105];
	struct ELEV elev[100];
	build_prime();
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&F,&E,&A,&B);
		memset(map,0,sizeof(map));
		for(i=0;i<E;i++) scanf("%d%d",&elev[i].X,&elev[i].Y);
		for(i=0;i<E;i++) for(j=0;j<i;j++) if(connect(&elev[i],&elev[j])) map[i][j]=map[j][i]=1;
		for(k=0;k<E;k++) for(i=0;i<E;i++) for(j=0;j<i;j++) if(map[i][k]&&map[k][j]) map[i][j]=map[j][i]=1;
		if(reachable(map,elev,A,B)) puts("It is possible to move the furniture.");
		else puts("The furniture cannot be moved.");
	}
	return 0;
}
