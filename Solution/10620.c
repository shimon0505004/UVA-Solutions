#include<stdio.h>
char white(int x,int y,int S){
	if(x%S==0||y%S==0) return 0;
	if((x/S)%2+(y/S)%2==1) return 1;
	return 0;
}
int main(){
	int S,x,y,dx,dy,i;
	while(scanf("%d%d%d%d%d",&S,&x,&y,&dx,&dy),S){
		for(i=0;i<1100;i++){
			if(white(x+i*dx,y+i*dy,S)){
				printf("After %d jumps the flea lands at (%d, %d).\n",i,x+i*dx,y+i*dy);
				break;
			}
		}
		if(i==1100) puts("The flea cannot escape from black squares.");
	}
	return 0;
}
