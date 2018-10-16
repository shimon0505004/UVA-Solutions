#include<stdio.h>
#include<stdlib.h>
int main(){
	int M,i,j,k,l;
	char **map;
	int allmax,min;
	while(scanf("%d",&M)==1){
		map=(char **)malloc(sizeof(char *[M]));
		for(i=0;i<M;i++) map[i]=(char *)malloc(sizeof(char[M])+1);
		for(i=0;i<M;i++) scanf("%s",map[i]);
		allmax=0;
		for(i=0;i<M;i++){
			for(j=0;j<M;j++){
				if(map[i][j]=='1'){
					min=M<<1;
					for(k=0;k<M;k++){
						for(l=0;l<M;l++){
							if(min<allmax) break;
							if(abs(i-k)+abs(j-l)>min) continue;
							if(map[k][l]=='3') min=abs(i-k)+abs(j-l);
						}
						if(l<M) break;
					}
					if(allmax<min) allmax=min;
				}
			}
		}
		printf("%d\n",allmax);
	}
	return 0;
}

