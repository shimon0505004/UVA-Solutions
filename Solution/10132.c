#include<stdio.h>
#include<string.h>
char file[260][2][260];
int n_file[260];
char answer[260];
int sum_len;
char is_answer(){
	int i,j;
	for(i=1;i<=sum_len;i++)
		for(j=0;j<n_file[i];j++)
			if(strncmp(file[i][j],answer,i)!=0&&strncmp(file[i][j],answer+sum_len-i,i)!=0) return 0;
	return 1;
}
int main(){
	int cases,len,maxcomb,maxlen;
	char input[260];
	int n,start=0;
	scanf("%d ",&cases);
	while(cases--){
		if(start) puts("");
		start=1;
		memset(n_file,0,sizeof(n_file));
		memset(file,0,sizeof(file));
		sum_len=maxcomb=0;
		for(n=0;fgets(input,260,stdin)!=NULL&&*input!='\n';n++){
			input[strlen(input)-1]=0;
			len=strlen(input);
			sum_len+=len;
			if(n_file[len]==2) continue;
			else if(n_file[len]==1&&strcmp(file[len][0],input)!=0)
				strcpy(file[len][n_file[len]++],input);
			else if(n_file[len]==0)
				strcpy(file[len][n_file[len]++],input);
			if(n_file[len]>maxcomb) maxcomb=n_file[len],maxlen=len;
		}
		sum_len/=n/2;
		strcpy(answer,file[maxlen][0]);
		strcat(answer,file[sum_len-maxlen][0]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[sum_len-maxlen][0]);
		strcat(answer,file[maxlen][0]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[maxlen][1]);
		strcat(answer,file[sum_len-maxlen][0]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[sum_len-maxlen][0]);
		strcat(answer,file[maxlen][1]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[maxlen][0]);
		strcat(answer,file[sum_len-maxlen][1]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[sum_len-maxlen][1]);
		strcat(answer,file[maxlen][0]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[maxlen][1]);
		strcat(answer,file[sum_len-maxlen][1]);
		if(is_answer()){
			puts(answer);
			continue;
		}
		strcpy(answer,file[sum_len-maxlen][1]);
		strcat(answer,file[maxlen][1]);
		if(is_answer()){
			puts(answer);
			continue;
		}
	}
	return 0;
}
