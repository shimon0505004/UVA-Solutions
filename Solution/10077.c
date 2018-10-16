#include<stdio.h>
struct FRAC{
	int den,num;
};
int main(){
	struct FRAC L,R,Q,M;
	while(scanf("%d%d",&Q.num,&Q.den),Q.num!=1||Q.den!=1){
		M.den=1,M.num=1;
		L.den=1,L.num=0,R.den=0,R.num=1;
		while(Q.den!=M.den||Q.num!=M.num){
			if(Q.den*M.num>Q.num*M.den){
				R=M,M.den+=L.den,M.num+=L.num;
				putchar('L');
			}else{
				L=M,M.den+=R.den,M.num+=R.num;
				putchar('R');
			}
		}
		puts("");
	}
	return 0;
}
