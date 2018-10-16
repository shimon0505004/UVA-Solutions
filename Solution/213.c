#include<stdio.h>
#include<string.h>
#include<ctype.h>
int getBin(int len){
	int i,result=0;
	char d;
	for(i=0;i<len;i++){
		result<<=1;
		while(isspace(d=getchar()));
		if(d=='1') result++;
	}
	return result;
}
int main(){
	char header[250],map[250];
	int twopow[8]={1,2,4,8,16,32,64,128};
	int i,j,count,len,d;
	while(scanf(" "),fgets(header,250,stdin)!=NULL){
		memset(map,0,sizeof(map));
		count=0;
		for(i=1;i<=7;i++)
			for(j=0;j<twopow[i]-1;j++)
				map[twopow[i]+j]=header[count++];
		while((len=getBin(3))!=0)
			while((d=getBin(len))!=twopow[len]-1)
				putchar(map[twopow[len]+d]);
		puts("");
	}
	return 0;
}
