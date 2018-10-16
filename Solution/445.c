#include<stdio.h>
int main(){
	char c,prev=0;
	int num=0,i;
	while((c=getchar())!=EOF){
		if(c=='!'||c=='\n')
			printf("\n");
		else if(c>='0' && c<='9')
			num+=c-'0';
		else if(c=='b'){
			for(i=0;i<num;i++)
				printf(" ");
			num=0;
		}
		else{
			for(i=0;i<num;i++)
				printf("%c",c);
			num=0;
		}
		prev=c;
	}
	return 0;
}
