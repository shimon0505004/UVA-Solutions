#include<stdio.h>
#include<string.h>
int main(){
	int n,i,j,a,k,map[205],loop,temp,onemap[205];
	char input[205],c,mapped[205];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%d",&map[i]),map[i]--;
		while(scanf("%d",&k),k){
			memset(input,' ',n*sizeof(char));
			scanf("%*c%[^\n]",input);
			input[strlen(input)]=' ';
			input[n]=0;
			for(i=0;i<n;i++){
				onemap[0]=i;
				for(temp=i,loop=1;(temp=map[temp])!=i;loop++)
					onemap[loop]=temp;
				mapped[onemap[k%loop]]=input[i];
			}
			mapped[n]=0;
			puts(mapped);
		}
		puts("");
	}
	return 0;
}
