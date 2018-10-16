#include<stdio.h>
int main(){
	int n;
	int i,j,k;
	signed char beat[105][105];
	char output[100000];
	while(scanf("%d",&n)==1){
		int count=0;
		char *ptr=output;
		for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%hhd",&beat[i][j]);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				if(j==i) continue;
				for(k=0;k<n;k++){
					if(k==j||k==i) continue;
					if(!beat[i][j]&&!beat[j][k]&&!beat[k][i]&&!beat[j][i]&&!beat[k][j]&&!beat[i][k]){
						if(i<j&&j<k){
							count++;
							ptr+=sprintf(ptr,"%d %d %d\n",i+1,j+1,k+1);
						}
					}else if(beat[i][j]&&beat[j][k]&&beat[k][i]){
						if((i>j&&j>k)||(i<j&&j<k))
							count++,ptr+=sprintf(ptr,"%d %d %d\n",i+1,j+1,k+1);
					}
				}
			}
		printf("%d\n",count);
		if(count) printf(output);
	}
	return 0;
}
