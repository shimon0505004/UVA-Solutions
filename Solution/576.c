#include<stdio.h>
#include<string.h>
int main()
{
	char haiku[3][300],input[300],*haikuPtr,*tokenPtr;
	int n,i,len,syllables[3],correct[3]={5,7,5};
	while(fgets(input,300,stdin)!=NULL){
		input[strlen(input)-1]=0;
		if(!strcmp(input,"e/o/i")) break;
		tokenPtr=strtok(input,"/");
		n=0;
		memset(haiku,0,sizeof(haiku));
		while(tokenPtr!=NULL){
			sprintf(haiku[n++],"%s",tokenPtr);
			tokenPtr=strtok(NULL,"/");
		}
		n=0;
		memset(syllables,0,sizeof(syllables));
		for(i=0;i<3;i++){
			for(haikuPtr=haiku[i];*haikuPtr!=0;haikuPtr+=len){
				len=strcspn(haikuPtr,"aeiouy");
				haikuPtr+=len;
				len=strspn(haikuPtr,"aeiouy");
				if(!len) break;
				syllables[n]++;
			}
			n++;
		}
		for(i=0;i<3;i++){
			if(syllables[i]!=correct[i]){
				printf("%d\n",i+1);
				break;
			}
		}
		if(i==3) printf("Y\n");
	}
	return 0;
}
