#include<stdio.h>
void bubblesort(char*string)
{
	int i,j,len;
	char temp;
	len=strlen(string);
	for(i=0;i<len-1;i++)
		for(j=0;j<len-i-1;j++)
			if(string[j]>string[j+1]){
				temp=string[j];
				string[j]=string[j+1];
				string[j+1]=temp;
			}
	return;
}
void reverse(char num[])
{
	char hold;
	int i,len=strlen(num);
	for(i=0;i<len/2;i++){
		hold=num[i];
		num[i]=num[len-1-i];
		num[len-1-i]=hold;
	}
}
int main()
{
	int n1,n2,diff,previous[100],n,exit,i;
	char inpn[11];
	while(1){
		scanf("%s",inpn);
		if(atoi(inpn)==0) break;
		printf("Original number was %s\n",inpn);
		for(i=0;i<100;i++)
			previous[i]=-1;
		n=0;
		exit=1;
		while(exit){
			bubblesort(inpn);
			n2=atoi(inpn);
			reverse(inpn);
			n1=atoi(inpn);
			diff=n1-n2;
			printf("%d - %d = %d\n",n1,n2,diff);
			n++;
			for(i=0;i<100;i++)
				if(diff==previous[i]){
					printf("Chain length %d\n",n);
					exit=0;
				}
			previous[n]=diff;
			sprintf(inpn,"%d",diff);
		}
		printf("\n");
	}
	return 0;
}
