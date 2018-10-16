#include<stdio.h>
#include<string.h>
void subtract(char n1[],char n2[]){
	int len1=strlen(n1),len2=strlen(n2),i,j;
	for(i=0;i<len2;i++){
		if(n1[i]>=n2[i])
			n1[i]-=n2[i]-'0';
		else{
			j=i+1;
			while(n1[j]=='0') n1[j]='9',j++;
			n1[j]--;
			n1[i]=n1[i]+10-n2[i]+'0';
		}	
	}
	i=len1-1;
	while(n1[i]=='0') n1[i]=0,i--;
}
void print(char s[]){
	int i;
	for(i=strlen(s)-1;i>=0;i--)
		putchar(s[i]);
	puts("");
}
int main(){
	char cable[2005][1005]={0};
	int i,j,len,N;
	strcpy(cable[0],"1");
	strcpy(cable[1],"1");
	strcpy(cable[2],"3");
	for(i=3;i<2005;i++){
		len=strlen(cable[i-1]);
		cable[i][0]=(cable[i-1][0]-'0')*3;
		for(j=1;j<len;j++){
			cable[i][j]=(cable[i-1][j]-'0')*3+cable[i][j-1]/10;
			cable[i][j-1]=cable[i][j-1]%10+'0';
		}
		cable[i][len]+=cable[i][len-1]/10;
		cable[i][len-1]=cable[i][len-1]%10+'0';
		if(cable[i][len]>0){
			cable[i][len]+='0';
			cable[i][len+1]=0;
		}
		subtract(cable[i],cable[i-2]);
	}
	while(scanf("%d",&N),N)
		print(cable[N]);
	return 0;
}
