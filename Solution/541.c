#include<stdio.h>
#define Corrupt 1
int main()
{
	int i,j,n,matrix[101][101],countevenR,countevenC,tot,flagR,flagC;
	int msg;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		countevenR=countevenC=0;
		msg=0;
		for(i=0;i<n;i++){
			tot=0;
			for(j=0;j<n;j++){
				scanf("%d",&matrix[i][j]);
				tot+=matrix[i][j];
			}
			if(tot%2){
				countevenR++;
				flagR=i;
				if(countevenR>1){
					msg=Corrupt;
				}
			}
		}
		for(i=0;i<n;i++){
			tot=0;
			for(j=0;j<n;j++)
				tot+=matrix[j][i];
			if(tot%2){
				countevenC++;
				flagC=i;
				if(countevenC>1){
					msg=Corrupt;
					break;
				}
			}
		}
		if(msg==Corrupt)
			printf("Corrupt\n");	
		else if(countevenC+countevenR==0)
			printf("OK\n");
		else
			printf("Change bit (%d,%d)\n",flagR+1,flagC+1);
	}
	return 0;
}
