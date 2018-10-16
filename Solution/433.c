#include<stdio.h>
#include<string.h>
int checksum(int d[]){
	int i,res=0;
	for(i=0;i<9;i++) res+=d[i]*(9-i);
	return res%11;
}
int main(){
	int cases,i,j,k;
	char OCR[10][9]={
		{0,1,0,1,0,1,1,1,1},{0,0,0,0,0,1,0,0,1},{0,1,0,0,1,1,1,1,0},
		{0,1,0,0,1,1,0,1,1},{0,0,0,1,1,1,0,0,1},{0,1,0,1,1,0,0,1,1},
		{0,1,0,1,1,0,1,1,1},{0,1,0,0,0,1,0,0,1},{0,1,0,1,1,1,1,1,1},
		{0,1,0,1,1,1,0,1,1}};
	char digit[9][10],input[30],curdig[9][10];
	int d[9],err;
	int inverse[10]={0,1,6,4,3,9,2,8,7,5};
	scanf("%d%*c",&cases);
	while(cases--){
		memset(digit,0,sizeof(digit));
		memset(curdig,0,sizeof(curdig));
		for(i=0;i<3;i++){
			fgets(input,30,stdin);
			for(j=0;j<27;j++)
				for(k=0;k<10;k++)
					if(input[j]!=' '&&OCR[k][i*3+j%3]==0)
						digit[j/3][k]=1,curdig[j/3][k]=k+1;
					else if(input[j]==' '&&OCR[k][i*3+j%3])
						curdig[j/3][k]=k+1;
		}
		err=-1;
		for(i=0;i<9;i++){
			int temp=0;
			for(j=0;j<10;j++)
				temp+=curdig[i][j];
			if(temp==55) err=i;
			else d[i]=54-temp;
		}
		if(err==-1){
			int c=checksum(d);
			if(c==0){
				for(i=0;i<9;i++) printf("%d",d[i]);
				puts("");
			}else{
				int possible=-1,change;
				for(i=0;i<9;i++){
					int t=(d[i]+inverse[9-i]*(11-c))%11;
					if(t!=10&&digit[i][t]==0){
						if(possible!=-1) break;
						change=t,possible=i;
					}
				}
				if(possible==-1) puts("failure");
				else if(i<9) puts("ambiguous");
				else{
					d[possible]=change;
					for(i=0;i<9;i++) printf("%d",d[i]);
					puts("");
				}
			}
		}else{
			int c;
			d[err]=0;
			c=11-checksum(d);
			d[err]=inverse[9-err]*c%11;
			if(d[err]==10||digit[err][d[err]]==1) puts("failure");
			else{
				for(i=0;i<9;i++) printf("%d",d[i]);
				puts("");
			}
		}
	}
	return 0;
}
