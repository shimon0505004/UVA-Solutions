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
	char inputnums[45],outputnums[45]={0},*num="0123456789ABCDEF",test[2],minus[2];
	while(scanf("%d%d%s",&inputbase,&outputbase,inputnums)!=EOF){
		if(strcmp(inputnums,"0")==0) {
			printf("%s base %d = 0 base %d\n",inputnums,inputbase,outputbase);
			continue;
		}
		len=strlen(inputnums);
		if(inputnums[0]=='-'){
			sprintf(minus,"-");
			for(i=0;i<len-1;i++)
				inputnums[i]=inputnums[i+1];
			inputnums[len-1]=0;
			len--;
		}
		else
			sprintf(minus,"");
		exact=0;
		memset(outputnums,0,sizeof(outputnums));
		for(i=0;i<len;i++){
			sprintf(test,"%c",inputnums[i]);
			if(strcspn(num,test)>=inputbase){
				printf("%s%s is an illegal base %d number\n",minus,inputnums,inputbase);
				break;
			}
			exact+=strcspn(num,test)*pow(inputbase,len-1-i);
		}
		if(i==len){
			for(j=0;exact>0;j++){
				outputnums[j]=num[exact%outputbase];
				exact/=outputbase;
			}
			reverse(outputnums);
			printf("%s%s base %d = %s%s base %d\n",minus,inputnums,inputbase,minus,outputnums,outputbase);
		}	
	}
	return 0;
}

