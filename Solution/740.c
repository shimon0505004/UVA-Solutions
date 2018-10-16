#include<stdio.h>
#include<string.h>
#define DNSHIFT 0
#define UPSHIFT 1
int main(){
	char input[85];
	char shift[2][34],status;
	int bit,i,len;
	fgets(shift[0],34,stdin);
	fgets(shift[1],34,stdin);
	while(fgets(input,85,stdin)!=NULL){
		len=strlen(input);
		bit=0;
		status=DNSHIFT;
		for(i=0;i<len;i++){
			bit<<=1,bit+=input[i]-'0';
			if(i%5==4){
				if(bit==27) status=DNSHIFT;
				else if(bit==31) status=UPSHIFT;
				else putchar(shift[status][bit]);
				bit=0;
			}
		}
		puts("");
	}
	return 0;
}
