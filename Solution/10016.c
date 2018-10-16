#include<stdio.h>
#include<string.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b,*b=temp;
}
int main(){
	int M,N,T,C;
	int i,j,n_ring;
	int square[105][105];
	int output[105][105];
	int simulate[2][2];
	scanf("%d",&M);
	while(M--){
		scanf("%d",&N);
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				scanf("%d",&square[i][j]);
		memcpy(output,square,sizeof(square));
		n_ring=(N+1)/2;
		for(i=0;i<n_ring;i++){
			int side=N-i*2;
			simulate[0][0]=0,simulate[0][1]=1,simulate[1][0]=2,simulate[1][1]=3;
			scanf("%d",&T);
			while(T--){
				scanf("%d",&C);
				switch(C){
					case 1:
						swap(&simulate[0][0],&simulate[1][0]);
						swap(&simulate[0][1],&simulate[1][1]);
						break;
					case 2:
						swap(&simulate[0][0],&simulate[0][1]);
						swap(&simulate[1][0],&simulate[1][1]);
						break;
					case 3:
						swap(&simulate[0][1],&simulate[1][0]);
						break;
					case 4:
						swap(&simulate[0][0],&simulate[1][1]);
						break;
				}
			}
			if(side<=1) continue;
			if(simulate[0][0]==0){
				if(simulate[0][1]==1){
					for(j=0;j<side;j++)
						output[i][j+i]=square[i][j+i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[j+i][i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[j+i][i+side-1];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[i+side-1][j+i];
				}else if(simulate[0][1]==2){
					for(j=0;j<side;j++)
						output[i][j+i]=square[j+i][i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[i][j+i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[i+side-1][j+i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[j+i][i+side-1];
				}
			}else if(simulate[0][0]==1){
				if(simulate[0][1]==0){
					for(j=0;j<side;j++)
						output[i][j+i]=square[i][side-1-j+i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[j+i][i+side-1];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[j+i][i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[i+side-1][side-1-j+i];
				}else if(simulate[0][1]==3){
					for(j=0;j<side;j++)
						output[i][j+i]=square[j+i][i+side-1];
					for(j=0;j<side;j++)
						output[j+i][i]=square[i][side-1-j+i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[i+side-1][side-1-j+i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[j+i][i];
				}
			}else if(simulate[0][0]==2){
				if(simulate[0][1]==3){
					for(j=0;j<side;j++)
						output[i][j+i]=square[i+side-1][j+i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[side-1-j+i][i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[side-1-j+i][i+side-1];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[i][j+i];
				}else if(simulate[0][1]==0){
					for(j=0;j<side;j++)
						output[i][j+i]=square[side-1-j+i][i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[i+side-1][j+i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[i][j+i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[side-j-1+i][i+side-1];
				}
			}else if(simulate[0][0]==3){
				if(simulate[0][1]==1){
					for(j=0;j<side;j++)
						output[i][j+i]=square[side-1-j+i][i+side-1];
					for(j=0;j<side;j++)
						output[j+i][i]=square[i+side-1][side-1-j+i];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[i][side-1-j+i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[side-1-j+i][i];
				}else if(simulate[0][1]==2){
					for(j=0;j<side;j++)
						output[i][j+i]=square[i+side-1][side-1-j+i];
					for(j=0;j<side;j++)
						output[j+i][i]=square[side-1-j+i][i+side-1];
					for(j=0;j<side;j++)
						output[j+i][i+side-1]=square[side-1-j+i][i];
					for(j=0;j<side;j++)
						output[i+side-1][j+i]=square[i][side-1-j+i];
				}
			}
		}
		for(i=0;i<N;i++){
			printf("%d",output[i][0]);
			for(j=1;j<N;j++)
				printf(" %d",output[i][j]);
			puts("");
		}
	}
	return 0;
}
