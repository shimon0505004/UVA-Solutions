#include<stdio.h>
#include<string.h>
int main(){
	int T,M,N,Q,i,S,a,b,X,Y;
	char map[105][105],c;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&M,&N,&Q);
		printf("%d %d %d\n",M,N,Q);
		memset(map,0,sizeof(map));
		for(i=1;i<=M;i++)
			scanf("%s",map[i]+1);
		for(i=0;i<Q;i++){
			scanf("%d%d",&X,&Y);
			c=map[++X][++Y];
			for(S=1;;S++){
				b=Y-S;
				for(a=X-S;a<X+S;a++)
					if(map[a][b]!=c) break;
				if(a<X+S) break;
				a=X+S;
				for(b=Y-S;b<Y+S;b++)
					if(map[a][b]!=c) break;
				if(b<Y+S) break;
				b=Y+S;
				for(a=X+S;a>X-S;a--)
					if(map[a][b]!=c) break;
				if(a>X-S) break;
				a=X-S;
				for(b=Y+S;b>Y-S;b--)
					if(map[a][b]!=c) break;
				if(b>Y-S) break;
			}
			printf("%d\n",2*S-1);
		}
	}
	return 0;
}
