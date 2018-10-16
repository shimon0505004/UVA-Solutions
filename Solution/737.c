#include<stdio.h>
struct CUBE{
	int xl,xu,yl,yu,zl,zu;
};
int main(){
	int N,i,s,volume;
	struct CUBE cube[1005],answer;
	while(scanf("%d",&N),N){
		answer.xl=answer.yl=answer.zl=-2147483647;
		answer.xu=answer.yu=answer.zu=2147483647;
		for(i=0;i<N;i++){
			scanf("%d%d%d%d",&cube[i].xl,&cube[i].yl,&cube[i].zl,&s);
			cube[i].xu=cube[i].xl+s;
			cube[i].yu=cube[i].yl+s;
			cube[i].zu=cube[i].zl+s;
			if(cube[i].xu<answer.xu) answer.xu=cube[i].xu;
			if(cube[i].yu<answer.yu) answer.yu=cube[i].yu;
			if(cube[i].zu<answer.zu) answer.zu=cube[i].zu;
			if(cube[i].xl>answer.xl) answer.xl=cube[i].xl;
			if(cube[i].yl>answer.yl) answer.yl=cube[i].yl;
			if(cube[i].zl>answer.zl) answer.zl=cube[i].zl;
		}
		if(answer.xl>answer.xu||answer.yl>answer.yu||answer.zl>answer.zu) volume=0;
		else volume=(answer.xu-answer.xl)*(answer.yu-answer.yl)*(answer.zu-answer.zl);
		printf("%d\n",volume);
	}
	return 0;
}
