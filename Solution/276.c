#include<stdio.h>
#include<string.h>
const char *Egyptian[5]={"|||||||||","nnnnnnnnn","999999999","888888888","rrrrrrrrr"};
int translate(char *s){
	int len=strlen(s);
	switch(s[0]){
		case '|': return len;
		case 'n': return len*10;
		case '9': return len*100;
		case '8': return len*1000;
		case 'r': return len*10000;
	}
	return -1;
}
void printEgyptian(int n,char *output){
	int i;
	char *ptr=output;
	if(n==0){
		*output=0;
		return;
	}
	for(i=0;i<5;i++){
		if(n%10) ptr+=sprintf(ptr,"%.*s ",n%10,Egyptian[i]);
		n/=10;
	}
}
int main(){
	char A[60],B[60],output[60],*ptr,trans[15];
	int len;
	int n_A,n_B,t;
	for(;;){
		fgets(A,60,stdin);
		if(*A=='\n') break;
		fgets(B,60,stdin);
		for(n_A=0,ptr=A;sscanf(ptr,"%s%n",trans,&len)==1;ptr+=len)
			n_A+=translate(trans);
		for(n_B=0,ptr=B;sscanf(ptr,"%s%n",trans,&len)==1;ptr+=len)
			n_B+=translate(trans);
		for(t=1;t<=n_B;t<<=1){
			printEgyptian(t,output);
			if(t&n_B) strcat(output,"*");
			printf("%-34s",output);
			printEgyptian((t*n_A)%100000,output);
			puts(output);
		}
		printEgyptian((n_A*n_B)%100000,output);
		printf("The solution is: %s\n",output);
	}
	return 0;
}
