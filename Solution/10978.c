#include<stdio.h>
#include<string.h>
struct CARD{
	struct CARD *prev,*next;
	char card[3];
	int temp;
};
int main(){
	struct CARD c[52],*now,temp;
	int i,j,len,n;
	char card[3],count[25];
	while(scanf("%d",&n),n){
		if(n==1){
			scanf("%s%s",card,count);
			puts(card);
			continue;
		}
		for(i=0;i<n;i++) c[i].temp=i;
		c[0].prev=&(c[n-1]),c[0].next=&(c[1]);
		for(i=1;i<n-1;i++)
			c[i].prev=&(c[i-1]),c[i].next=&(c[i+1]);
		c[n-1].prev=&(c[n-2]),c[n-1].next=&(c[0]);
		temp.next=c,temp.prev=&(c[n-1]);
		now=&temp;
		for(i=0;i<n;i++){
			scanf("%s%s",card,count);
			len=strlen(count);
			len%=(n-i);
			if(len==0) now=now->prev;
			while(len--) now=now->next;
			strcpy(now->card,card);
			now->prev->next=now->next,now->next->prev=now->prev;
		}
		printf("%s",c[0].card);
		for(i=1;i<n;i++) printf(" %s",c[i].card);
		puts("");
	}
	return 0;
}
