#include<stdio.h>
#include<string.h>
#define D 0
#define I 1
#define C 2
char str1[25],str2[25];
int table[25][25];
char flag[25][25];
void printStep(int len1,int len2){
	if(len1==0&&len2==0) return;
	if(flag[len1][len2]==D){
		printStep(len1-1,len2);
		printf("D%c%.2d",str1[len1],len2+1);
	}else if(flag[len1][len2]==I){
		printStep(len1,len2-1);
		printf("I%c%.2d",str2[len2],len2);
	}else if(flag[len1][len2]==C){
		printStep(len1-1,len2-1);
		if(str1[len1]!=str2[len2]) printf("C%c%.2d",str2[len2],len2);
	}
}
int main(){
	int len1,len2;
	int i,j;
	while(scanf("%s%s",str1+1,str2+1)==2){
		memset(table,0,sizeof(table));
		len1=strlen(str1+1),len2=strlen(str2+1);
		for(i=1;i<=len1;i++) table[i][0]=i,flag[i][0]=D;
		for(i=1;i<=len2;i++) table[0][i]=i,flag[0][i]=I;
		for(i=1;i<=len1;i++)
			for(j=1;j<=len2;j++){
				int cost=str1[i]==str2[j]?0:1;
				table[i][j]=table[i-1][j-1]+cost,flag[i][j]=C;
				if(table[i][j]>table[i-1][j]+1)
					table[i][j]=table[i-1][j]+1,flag[i][j]=D;
				if(table[i][j]>table[i][j-1]+1)
					table[i][j]=table[i][j-1]+1,flag[i][j]=I;
			}
		printStep(len1,len2);
		puts("E");
	}
	return 0;
}
