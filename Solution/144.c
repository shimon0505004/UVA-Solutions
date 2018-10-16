#include<stdio.h>
#include<string.h>
int main(){
	int N,k,i;
	char full[30];
	int receive[30],now,next,out[30],count;
	while(scanf("%d%d",&N,&k),N|k){
		memset(full,0,sizeof(full));
		memset(receive,0,sizeof(receive));
		count=1,now=0,next=1;
		for(i=1;count<=N;i%=N,i++){
			if(now==0) now=next,next%=k,next++;
			if(full[i]) continue;
			receive[i]+=now;
			if(receive[i]>=40){
				now=receive[i]-40,full[i]=1;
				out[count++]=i;
			}else now=0;
		}
		printf("%3d",out[1]);
		for(i=2;i<=N;i++) printf("%3d",out[i]);
		puts("");
	}
	return 0;
}
