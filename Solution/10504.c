#include<stdio.h>
char fit(int n,int size){
	if(n>=0&&n<size) return 1;
	return 0;
}
char match(int i,int j,int k,int l,char square[][105],int size,char c){
	if(!fit(i+l,size)||!fit(j-k,size)||!fit(i+l+k,size)||!fit(j-k+l,size)||!fit(i+k,size)||!fit(j+l,size)) return 0;
	if(square[i+l][j-k]==c&&square[i+l+k][j-k+l]==c&&square[i+k][j+l]==c) return 1;
	return 0;
}
int main(){
	int size,n_query;
	int i,j,k,l,count;
	char square[105][105],start=0;
	while(scanf("%d",&size),size){
		if(start) puts("");
		else start=1;
		scanf("%d",&n_query);
		for(i=0;i<size;i++) scanf("%s",square[i]);
		while(n_query--){
			char c;
			count=0;
			scanf(" %c",&c);
			for(i=0;i<size;i++)
				for(j=0;j<size;j++)
					if(square[i][j]==c)
						for(k=0;k<=j;k++)
							for(l=1;l<size-i;l++)
								if(match(i,j,k,l,square,size,c))
									count++;
			printf("%c %d\n",c,count);
		}
	}
	return 0;
}
