#include<stdio.h>
#include<ctype.h>
char variable[128];
char *skip_WFF(char input[]){
	if(*input=='N') return skip_WFF(input+1);
	if(islower(*input)) return input+1;
	input++;
	input=skip_WFF(input);
	input=skip_WFF(input);
	return input;
}
char get_WFF(char input[]){
	char w,x,operator;
	if(*input=='N') return !get_WFF(input+1);
	if(islower(*input)) return variable[*input];
	operator=*input++;
	w=get_WFF(input);
	input=skip_WFF(input);
	x=get_WFF(input);
	switch(operator){
		case 'K': return w&x;
		case 'A': return w|x;
		case 'C': return !(w==1&&x==0);
		case 'E': return w==x;
	}
	return 127;
}
char is_tautology(char input[]){
	int i;
	for(i=0;i<32;i++){
		variable['p']=(i&1)?1:0,variable['q']=(i&2)?1:0,variable['r']=(i&4)?1:0;
		variable['s']=(i&8)?1:0,variable['t']=(i&16)?1:0;
		if(get_WFF(input)==0) return 0;
	}
	return 1;
}
int main(){
	char input[105];
	while(fgets(input,105,stdin),input[0]!='0'){
		if(is_tautology(input)) puts("tautology");
		else puts("not");
	}
	return 0;
}
