#include<stdio.h>
double maxA;
int n;
char result[4];
typedef struct Point{
	int x;
	int y;
}P;
P p[20];
double area(P p1,P p2,P p3){
	return abs(((p3.y-p1.y)*(p2.x-p1.x)-(p2.y-p1.y)*(p3.x-p1.x)))/2.0;
}
char notin(int p1,int p2,int p3){
	int i;
	for(i=0;i<n;i++){
		if(i!=p1&&i!=p2&&i!=p3){
			if(area(p[i],p[p2],p[p3])+area(p[i],p[p1],p[p2])+area(p[i],p[p1],p[p3])==area(p[p1],p[p2],p[p3]))
				return 0;
		}
	}
	return 1;
}
void dfs(int depth,int pos,int output[]){
	int i;
	double t;
	if(depth==3){
		t=area(p[output[0]],p[output[1]],p[output[2]]);
		if(maxA<t){
			if(notin(output[0],output[1],output[2])){
				for(i=0;i<3;i++)
					result[i]=output[i]+'A';
				maxA=t;
			}
		}
		return;
	}
	for(i=pos;i<n-2+depth;i++){
		output[depth]=i;
		dfs(depth+1,i+1,output);
	}
}
int main()
{
	int output[4],i;
	char temp[2];
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%s%d%d",temp,&p[i].x,&p[i].y);
		maxA=0;
		memset(result,0,sizeof(result));
		dfs(0,0,output);
		puts(result);
	}
	return 0;
}
