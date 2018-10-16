#include<stdio.h>
#include<string.h>
int main(){
	int roads,i,j,k,s1,s2;
	int map[35][35],cases=0,count;
	while(scanf("%d",&roads)==1){
		memset(map,0,sizeof(map));
		count=0;
		for(i=0;i<roads;i++){
			scanf("%d%d",&s1,&s2);
			map[s1][s2]=1;
			if(s1>count) count=s1;
			if(s2>count) count=s2;
		}
		count++;
		for(k=0;k<count;k++)
			for(i=0;i<count;i++)
				for(j=0;j<count;j++)
					if(map[i][j]&&map[j][i]) map[i][j]=map[j][i]=-1;
					else if(map[i][k]&&map[k][j])
						if(map[i][k]==-1||map[k][j]==-1)
							map[i][j]=-1;
						else map[i][j]+=map[i][k]*map[k][j];
		printf("matrix for city %d\n",cases++);
		for(i=0;i<count;i++){
			printf("%d",map[i][0]);
			for(j=1;j<count;j++)
				printf(" %d",map[i][j]);
			puts("");
		}
	}
	return 0;
}
