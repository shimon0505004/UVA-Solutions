#include<stdio.h>
#include<math.h>
int main(){
	int year,index;
	int factstone[23]={0,2,3,5,8,12,20,34,57,98,170,300,536,966,1754,3210,5910,10944,20366,38064,71421,134480,254016};
	while(scanf("%d",&year),year){
		index=(year-1940)/10;
		printf("%d\n",factstone[index]);
	}
	return 0;
}
