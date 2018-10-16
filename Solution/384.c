#include<stdio.h>
char *get_slump(char slurpy[]){
	if(*slurpy!='D'&&*slurpy!='E') return NULL;
	if(*(slurpy+1)!='F') return NULL;
	while(*++slurpy=='F');
	if(*slurpy=='G') return slurpy+1;
	if((slurpy=get_slump(slurpy))!=NULL) return slurpy;
	return NULL;
}
char *get_slimp(char slurpy[]){
	if(*slurpy++!='A') return NULL;
	if(*slurpy=='H') return slurpy+1;
	if(*slurpy=='B'){
		slurpy=get_slimp(slurpy+1);
		if(slurpy==NULL) return NULL;
		if(*slurpy=='C') return slurpy+1;
		return NULL;
	}else{
		slurpy=get_slump(slurpy);
		if(*slurpy=='C') return slurpy+1;
		return NULL;
	}
}
char is_slurpy(char slurpy[]){
	if((slurpy=get_slimp(slurpy))==NULL) return 0;
	slurpy=get_slump(slurpy);
	if(slurpy==NULL) return 0;
	if(*slurpy=='\0') return 1;
	return 0;
}
int main(){
	int N;
	char slurpy[70];
	puts("SLURPYS OUTPUT");
	scanf("%d",&N);
	while(N--){
		scanf("%s",slurpy);
		if(is_slurpy(slurpy)) puts("YES");
		else puts("NO");
	}
	puts("END OF OUTPUT");
	return 0;
}
