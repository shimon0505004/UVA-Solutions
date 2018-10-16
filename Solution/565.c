#include<stdio.h>
int pow_2[17]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,
	16384,32768,65536};
void printPizza(int n){
	int i;
	char flag=1;
	printf("Toppings:");
	for(i=0;i<16;i++){
		if(pow_2[i]&n){
			if(flag) putchar(' ');
			flag=0;
			putchar(i+'A');
		}
	}
	puts("");
}
int main(){
	char input[35];
	int specified[12],XOR[12],fri;
	int i,j;
	while(!feof(stdin)){
		for(fri=0;fgets(input,35,stdin),input[0]!='.';fri++){
			char *ptr;
			specified[fri]=0;
			XOR[fri]=0;
			for(ptr=input;*ptr!=';';ptr+=2){
				int which=*(ptr+1)-'A';
				char PorM=*ptr;
				if(PorM=='-') XOR[fri]|=pow_2[which];
				specified[fri]|=pow_2[which];
			}
		}
		for(i=0;i<pow_2[16];i++){
			for(j=0;j<fri;j++)
				if(((i&specified[j])^XOR[j])==0) break;
			if(j==fri){
				printPizza(i);
				break;
			}
		}
		if(i==pow_2[16]) puts("No pizza can satisfy these requests.");
		scanf(" ");
	}
	return 0;
}
