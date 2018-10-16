#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	int freq[52],i,max,counter,len;
	char input[1000],output[55];
	while(fgets(input,1000,stdin)!=NULL){
		len=strlen(input);
		memset(freq,0,sizeof(freq));
		for(i=0;i<len;i++)
			if(isupper(input[i]))
				freq[input[i]-'A']++;
			else if(islower(input[i]))
				freq[input[i]+26-'a']++;
		max=-1;
		for(i=0;i<52;i++){
			if(freq[i]>max)
				max=freq[i],output[0]=(i/26==0)?'A'+i:'a'+i-26,counter=1;
			else if(freq[i]==max)
				output[counter++]=(i/26==0)?'A'+i:'a'+i-26;
		}
		output[counter]=0;
		printf("%s %d\n",output,max);
	}
	return 0;
}
