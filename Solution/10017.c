#include<stdio.h>
struct STACK{
	int nums;
	int honai[255];
};
struct STACK h[3];
int pop(int index){
	return h[index].honai[--h[index].nums];
}
void push(int index,int n){
	h[index].honai[h[index].nums++]=n;
}
void print(){
	int i;
	printf("A=>");
	if(h[0].nums) printf("  ");
	for(i=0;i<h[0].nums;i++)
		printf(" %d",h[0].honai[i]);
	puts("");
	printf("B=>");
	if(h[1].nums) printf("  ");
	for(i=0;i<h[1].nums;i++)
		printf(" %d",h[1].honai[i]);
	puts("");
	printf("C=>");
	if(h[2].nums) printf("  ");
	for(i=0;i<h[2].nums;i++)
		printf(" %d",h[2].honai[i]);
	puts("\n");

}
void HONAI(int *depth,int n,int from,int to,int aux){
	if(*depth==0) return;
	if(n==1){
		push(to,pop(from));
		(*depth)--;
		print();
		return;
	}
	HONAI(depth,n-1,from,aux,to);
	HONAI(depth,1,from,to,aux);
	HONAI(depth,n-1,aux,to,from);
}
int main(){
	int n,m,cases=0,i;
	while(scanf("%d%d",&n,&m),n+m){
		printf("Problem #%d\n\n",++cases);
		for(i=0;i<n;i++)
			h[0].honai[i]=n-i;
		h[0].nums=n,h[1].nums=h[2].nums=0;
		print();
		HONAI(&m,n,0,2,1);
	}
	return 0;
}
