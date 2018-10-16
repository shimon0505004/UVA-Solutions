#include<stdio.h>
#include<string.h>
int main(){
	char input[105];
	int count_N,count_U,count_L,i;
	char U[105],L[105];
	while(fgets(input,105,stdin),input[0]!='0'){
		count_N=count_U=count_L=0;
		for(i=0;input[i];i++)
			switch(input[i]){
				case 'p':case 'q':case 'r':case 's':case 't':
					L[count_L++]=input[i];
					break;
				case 'K':case 'A':case 'C':case 'E':
					U[count_U++]=input[i];
					break;
				case 'N':
					count_N++;
					break;
			}
		if(count_L==0) puts("no WFF possible");
		else{
			int size;
			for(i=0;i<count_N;i++) putchar('N');
			if(count_U<=count_L-1) size=count_U;
			else size=count_L-1;
			for(i=0;i<size;i++) putchar(U[i]),putchar(L[i]);
			putchar(L[size]);
			puts("");
		}
	}
	return 0;
}
