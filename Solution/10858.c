#include<stdio.h>
int ans[30];
int printFac(char **buf,int n,int now,int depth){
	int i,count=1;
	for(i=now;i*i<=n;i++){
		if(n%i==0){
			ans[depth]=i;
			count+=printFac(buf,n/i,i,depth+1);
		}
	}
	for(i=0;i<depth;i++)
		*buf+=sprintf(*buf,"%d ",ans[i]);
	*buf+=sprintf(*buf,"%d\n",n);
	return count;
}
int main(){
	int i,n,count;
	char buf[30000],*ptr;
	while(scanf("%d",&n),n){
		count=0;
		ptr=buf,*ptr='\0';
		for(i=2;i*i<=n;i++){
			if(n%i==0){
				ans[0]=i;
				count+=printFac(&ptr,n/i,i,1);
			}
		}
		printf("%d\n",count);
		printf(buf);
	}
	return 0;
}
