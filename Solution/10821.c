#include<stdio.h>
void printBST(int from,int to,int H){
	int root=to-(1<<(H-1))+1;
	if(from==to) printf(" %d",from);
	else if(root<=from){
		printf(" %d",from);
		printBST(from+1,to,H-1);
	}else{
		printf(" %d",root);
		printBST(from,root-1,H-1);
		printBST(root+1,to,H-1);
	}
}
int main(){
	int cases,N,H;
	for(cases=1;scanf("%d%d",&N,&H),N|H;cases++){
		printf("Case %d:",cases);
		if((1<<H)-1<N){
			puts(" Impossible.");
			continue;
		}
		printBST(1,N,H);
		puts("");
	}
	return 0;
}
