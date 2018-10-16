#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char a[30],b[30];
	int len1,len2,i,tot1,tot2;
	while(fgets(a,30,stdin)!=NULL&&fgets(b,30,stdin)!=NULL){
		tot1=tot2=0;
		len1=strlen(a),len2=strlen(b);
		for(i=0;i<len1;i++)
			if(isalpha(a[i]))
				tot1+=tolower(a[i])-'a'+1;
		for(i=0;i<len2;i++)
			if(isalpha(b[i]))
				tot2+=tolower(b[i])-'a'+1;
		tot1%=9;
		if(!tot1) tot1=9;
		tot2%=9;
		if(!tot2) tot2=9;
		if(tot1>tot2)
			printf("%.2lf %%\n",(double)tot2*100/tot1);
		else
			printf("%.2lf %%\n",(double)tot1*100/tot2);
	}
	return 0;
}
