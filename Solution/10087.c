#include<stdio.h>
#include<string.h>
void fill(int square[][100],int now_x,int now_y,int now,char type){
	if(type=='L'){
		square[now_x*2][now_y*2+1]=now++;
		square[now_x*2+1][now_y*2]=now++;
		square[now_x*2+1][now_y*2+1]=now++;
		square[now_x*2][now_y*2]=now++;
	}else if(type=='U'){
		square[now_x*2][now_y*2]=now++;
		square[now_x*2+1][now_y*2]=now++;
		square[now_x*2+1][now_y*2+1]=now++;
		square[now_x*2][now_y*2+1]=now++;
	}else if(type=='X'){
		square[now_x*2][now_y*2]=now++;
		square[now_x*2+1][now_y*2+1]=now++;
		square[now_x*2+1][now_y*2]=now++;
		square[now_x*2][now_y*2+1]=now++;
	}
}
char LUX(int x,int y,int l){
	if(x<l) return 'L';
	if(x==l){
		if(y!=l) return 'L';
		return 'U';
	}
	if(x==l+1){
		if(y!=l) return 'U';
		return 'L';
	}
	return 'X';
}
int main(){
	int square[100][100];
	char used[100][100];
	int L,S,now_x,now_y,sum,L_sqr,now;
	int i,j;
	while(scanf("%d%d",&L,&S)==2){
		if(L==2){
			puts("You can't be like Shahjahan!\n");
			continue;
		}
		sum=(L*L*L+L)/2;
		L_sqr=L*L;
		now=1+(S-sum)/L;
		if((S-sum)%L!=0){
			puts("You can't be like Shahjahan!\n");
			continue;
		}
		if(L%2==1){
			memset(used,0,sizeof(used));
			now_x=0,now_y=L/2;
			for(i=0;i<L_sqr;i++,now++){
				if(used[now_x][now_y]) now_x=(now_x+2)%L,now_y=(now_y+L-1)%L;
				square[now_x][now_y]=now;
				used[now_x][now_y]=1;
				now_x=(now_x+L-1)%L,now_y=(now_y+1)%L;
			}
		}else if(L%4==0){
			int l=L/4;
			for(i=0;i<l;i++){
				for(j=0;j<l;j++,now++) square[i][j]=now;
				for(j=l;j<L-l;j++,now++) square[L-1-i][L-1-j]=now;
				for(j=L-l;j<L;j++,now++) square[i][j]=now;
			}
			for(i=l;i<L-l;i++){
				for(j=0;j<l;j++,now++) square[L-1-i][L-1-j]=now;
				for(j=l;j<L-l;j++,now++) square[i][j]=now;
				for(j=L-l;j<L;j++,now++) square[L-1-i][L-1-j]=now;
			}
			for(i=L-l;i<L;i++){
				for(j=0;j<l;j++,now++) square[i][j]=now;
				for(j=l;j<L-l;j++,now++) square[L-1-i][L-1-j]=now;
				for(j=L-l;j<L;j++,now++) square[i][j]=now;
			}
		}else{
			int l=L/4,s_LUX=2*l+1,s_LUX_sqr=s_LUX*s_LUX;
			memset(used,0,sizeof(used));
			now_x=0,now_y=s_LUX/2;
			for(i=0;i<s_LUX_sqr;i++,now+=4){
				if(used[now_x][now_y]) now_x=(now_x+2)%s_LUX,now_y=(now_y+s_LUX-1)%s_LUX;
				fill(square,now_x,now_y,now,LUX(now_x,now_y,l));
				used[now_x][now_y]=1;
				now_x=(now_x+s_LUX-1)%s_LUX,now_y=(now_y+1)%s_LUX;
			}
		}
		for(i=0;i<L;i++,puts("")){
			printf("%10d",square[i][0]);
			for(j=1;j<L;j++)
				printf(" %10d",square[i][j]);
		}
		puts("");
	}
	return 0;
}
