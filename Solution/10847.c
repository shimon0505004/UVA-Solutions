#include<stdio.h>
#include<ctype.h>
char is_formula(char line[]){
	int i;
	int n_alpha=0,n_equal=0;
	if(line[0]=='-') return 0;
	for(i=0;line[i];i++){
		if(isalpha(line[i])) n_alpha++;
		else if(line[i]=='=') n_equal++;
		if(n_equal>=n_alpha) return 0;
	}
	if(n_alpha!=n_equal+1) return 0;
	return 1;
}
char is_tautology(char line[]){
	int variable[128]={0};
	char i;
	char *ptr;
	if(!is_formula(line)) return -1;
	for(ptr=line;*ptr;ptr++)
		variable[(int)*ptr]++;
	for(i='a';i<='z';i++)
		if(variable[(int)i]%2!=0)
			return 1;
	for(i='A';i<='Z';i++)
		if(variable[(int)i]%2!=0)
			return 1;
	if(variable[(int)'-']%2!=0) return 1;
	return 0;
}
int main(){
	int cases;
	char line[205];
	scanf("%d",&cases);
	while(cases--){
		char res;
		scanf("%s",line);
		res=is_tautology(line);
		if(res==0) puts("tautology");
		else if(res==1) puts("formula");
		else puts("incorrect");
	}
	return 0;
}
