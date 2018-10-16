#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 700000
int compar(const void *a,const void *b){
	long long ll1=*((long long *)a),ll2=*((long long *)b);
	if(ll1>ll2) return 1;
	if(ll1<ll2) return -1;
	return 0;
}
int main(){
	int n,len,max,len_arr,cur,i;
	long long arr[SIZE],moduli[11];
	long long val,pattern;
	char str[SIZE],output[15];
	moduli[0]=1LL;
	for(i=1;i<11;i++) moduli[i]=moduli[i-1]*26LL;
	while(scanf("%d%s",&n,str)==2){
		val=0;
		for(i=0;i<n-1;i++) val=val*26LL+str[i]-'a';
		len=strlen(str);
		for(i=n-1;i<len;i++){
			val=(val*26LL+str[i]-'a')%moduli[n];
			arr[i-(n-1)]=val;
		}
		len_arr=len-(n-1);
		qsort(arr,len_arr,sizeof(long long),compar);
		max=0,cur=1;
		for(i=1;i<len_arr;i++){
			if(arr[i]==arr[i-1]) cur++;
			else cur=1;
			if(cur>max) max=cur,pattern=arr[i];
		}
		for(i=n-1;i>=0;i--)
			output[i]=pattern%26LL+'a',pattern/=26LL;
		output[n]='\0';
		puts(output);
	}
	return 0;
}
