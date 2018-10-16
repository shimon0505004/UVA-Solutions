#include<stdio.h>
int main()
{
	char sentence[1025];
	unsigned int check;
	int CRC,len,i;
	int Result1,Result2;
	while(1){
		memset(sentence,0,sizeof(sentence));
		fgets(sentence,1024,stdin);
		if(*sentence=='#') break;
		len=strlen(sentence);
		sentence[len-1]=0;
		if(!*sentence){
			printf("00 00\n");
			continue;
		}
		CRC=0;
		for(i=0;i<len;i++){
			CRC+=sentence[i];
			CRC<<=8;
			CRC%=34943;
		}
		if(CRC) 
			CRC=34943-CRC;
		Result2=CRC%(1<<8);
		Result1=CRC>>8;
		printf("%.2X %.2X\n",Result1,Result2);
	}
	return 0;
}
