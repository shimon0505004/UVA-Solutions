#include<stdio.h>
#include<string.h>
int powfour[6]={1,4,16,64,256,1024};
char *count(char Quad[],int depth,char out[]){
	int i;
	if(*Quad=='f'){
		for(i=0;i<powfour[depth];i++)
			out[i]=1;
		return Quad;
	}
	if(*Quad=='p'){
		for(i=0;i<4;i++)
			Quad=count(++Quad,depth-1,out+i*powfour[depth-1]);
		return Quad;
	}
	return Quad;
}
int main(){
	char Quad1[1400],Quad2[1400];
	char out1[1025],out2[1025];
	int cases,a,b,i,result,pixels;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s%s",Quad1,Quad2);
		memset(out1,0,sizeof(out1));
		memset(out2,0,sizeof(out2));
		count(Quad1,5,out1),count(Quad2,5,out2);
		pixels=0;
		for(i=0;i<1024;i++)
			if(out1[i]|out2[i]) pixels++;
		printf("There are %d black pixels.\n",pixels);
	}
	return 0;
}
