#include<stdio.h>
#include<string.h>
int main(){
	char code[10][100];
	int n_code,i,j,cases;
	for(cases=1;fgets(code[0],100,stdin)!=NULL;cases++){
		for(n_code=1;fgets(code[n_code],100,stdin),*code[n_code]!='9';n_code++);
		for(i=0;i<n_code;i++){
			for(j=0;j<i;j++){
				int len1=strlen(code[i]),len2=strlen(code[j]),len=len1;
				if(len>len2) len=len2;
				if(strncmp(code[i],code[j],len-1)==0) break;
			}
			if(j<i) break;
		}
		printf("Set %d is ",cases);
		if(i<n_code) printf("not ");
		puts("immediately decodable");
	}
	return 0;
}
