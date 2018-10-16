#include<stdio.h>
#include<string.h>
void assign(char dest[],char src[]){
	memcpy(dest,src,sizeof(char[105]));
}
void add(char dest[],char src[]){
	int i;
	for(i=0;i<105;i++) dest[i]+=src[i];
	for(i=1;i<105;i++) dest[i]+=dest[i-1]/10,dest[i-1]%=10;
}
void swap(char dest[],char src[]){
	char tmp[105];
	memcpy(tmp,dest,sizeof(char[105]));
	memcpy(dest,src,sizeof(char[105]));
	memcpy(src,tmp,sizeof(char[105]));
}
void printBigNum(char N[]){
	int i;
	for(i=105-1;i>0&&N[i]==0;i--);
	for(;i>=0;i--) printf("%d",N[i]);
	puts("");
}
int main(){
	char X[10005];
	char Z[105];
	int N,lenX,lenZ,i,j;
	char table[10005][105];
	char temp[105];
	scanf("%d",&N);
	while(N--){
		scanf("%s%s",X+1,Z+1);
		lenX=strlen(X+1),lenZ=strlen(Z+1);
		memset(table,0,sizeof(table));
		for(i=0;i<=lenX;i++) table[i][0]=1;
		for(i=1;i<=lenZ;i++){
			memset(temp,0,sizeof(temp));
			swap(table[i-1],temp);
			for(j=i;j<=lenX;j++){
				if(Z[i]==X[j]){
					add(temp,table[j-1]);
					swap(temp,table[j]);
				}else{
					swap(temp,table[j]);
					assign(table[j],table[j-1]);
				}
			}
		}
		printBigNum(table[lenX]);
	}
	return 0;
}
