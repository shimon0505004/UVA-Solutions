#include<stdio.h>
#include<string.h>
#include<math.h>
void reverse(char *string)
{
	int i,len=strlen(string);
	char temp;
	for(i=0;i<len/2;i++){
		temp=string[i];
		string[i]=string[len-i-1];
		string[len-i-1]=temp;
	}
}
int main()
{
	int i,j,inputbase,outputbase,len;
	long long int exact;
	char inputnums[45],outputnums[45]={0},*num="0123456789ABCDEF",test[2];
	while(scanf("%s%d%d",inputnums,&inputbase,&outputbase)==3){
		len=strlen(inputnums);
		exact=0;
		memset(outputnums,0,sizeof(outputnums));
		for(i=0;i<len;i++){
			sprintf(test,"%c",inputnums[i]);
			exact+=strcspn(num,test)*pow(inputbase,len-1-i);
		}
		if(!exact){
			printf("%7s\n","0");
			continue;
		}
		for(j=0;exact>0;j++){
			outputnums[j]=num[exact%outputbase];
			exact/=outputbase;
		}
		reverse(outputnums);
		if(strlen(outputnums)>7)
			printf("%7s\n","ERROR");
		else
			printf("%7s\n",outputnums);
	}
	return 0;
}

