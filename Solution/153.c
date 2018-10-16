#include<stdio.h>
#include<string.h>
int C[35][35]={0};
int compar(const void *a,const void *b){
	return *((char *)a)-*((char *)b);
}
int comb(int count[]){
	int total=0,i,result=1;
	for(i=0;i<26;i++)
		total+=count[i];
	for(i=0;i<26;i++){
		if(count[i]){
			result*=C[total][count[i]];
			total-=count[i];
		}
	}
	return result;
}
int cal(char input[],int len,int count[]){
	int i,result=0;
	if(len==1) return 1;
	for(i=0;i<*input-'a';i++){
		if(count[i]){
			count[i]--;
			result+=comb(count);
			count[i]++;
		}
	}
	count[*input-'a']--;
	return result+cal(input+1,len-1,count);
}
int main(){
	int i,j;
	char input[35];
	int count[26],len;
	C[0][0]=1;
	for(i=1;i<31;i++){
		C[i][0]=1;
		for(j=i;j>0;j--)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	while(scanf("%s",input),*input!='#'){
		memset(count,0,sizeof(count));
		len=strlen(input);
		for(i=0;i<len;i++)
			count[input[i]-'a']++;
		printf("%10d\n",cal(input,strlen(input),count));
	}
	return 0;
}
