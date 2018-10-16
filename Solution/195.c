#include<stdio.h>
#include<string.h>
#include<ctype.h>
void bubblesort(char*string)
{
	int i,j,len;
	char temp;
	len=strlen(string);
	for(i=0;i<len-1;i++)
		for(j=0;j<len-i-1;j++)
			if(tolower(string[j])>=tolower(string[j+1])){
				if((string[j]==string[j+1])||(string[j+1]-string[j]=='a'-'A'))
						continue;
				temp=string[j];
				string[j]=string[j+1];
				string[j+1]=temp;
			}
	return;
}
int main()
{
	char rank[1000],temp;
	int len,mark,n;
	int i,j,k;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		memset(rank,0,sizeof(rank));
		scanf("%s",rank);
		bubblesort(rank);
		len=strlen(rank);
		mark=0;
		printf("%s\n",rank);
		while(1){
			for(i=len-1;i>0;i--)
				if(tolower(rank[i])>=tolower(rank[i-1])){
					if((rank[i]==rank[i-1])||(rank[i-1]-rank[i])==('a'-'A')) 
						continue;
					for(j=len-1;j>=i;j--){
						if(tolower(rank[j])>=tolower(rank[i-1])){
							if((rank[j]==rank[i-1])||((rank[i-1]-rank[j])==('a'-'A')))
									continue;
							temp=rank[j];
							rank[j]=rank[i-1];
							rank[i-1]=temp;
							break;
						}
					}
					mark=i;
					break;
				}
			if(!i) break;
			bubblesort(rank+mark);
			printf("%s\n",rank);
		}
	}
	return 0;
}

