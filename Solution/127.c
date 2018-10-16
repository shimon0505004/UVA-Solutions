#include<stdio.h>
#include<string.h>
typedef struct num{
	int n;
	struct num* prev;
	struct num* next;
}chasing;
char stack[52][52][3];
char result[3];
int n_stack[52];
void push(char *k,int n)
{
	strcpy(stack[n][n_stack[n]++],k);
}
void pop(int n)
{
	strcpy(result,stack[n][--n_stack[n]]);
}
int is_empty(int n)
{
	return !n_stack[n];
}
int is_match(char *card1,char *card2)
{
	if(card1[0]==card2[0]||card1[1]==card2[1])
		return 1;
	else
		return 0;
}
int main()
{
	int i,count,prev,prev3,previous;
	char temp[3];
	chasing N[52];
	while(1){
		memset(n_stack,0,sizeof(n_stack));
		for(i=0;i<52;i++){
			N[i].n=i;
			if(i>0)
				N[i].prev=&(N[i-1]);
			else
				N[i].prev=NULL;
			if(i<52)
				N[i].next=&(N[i+1]);
			else
				N[i].next=NULL;
		}
		count=0;
		for(i=0;i<52;i++){
			scanf("%s",temp);
			if(*temp=='#') return 0;
			push(temp,i);
		}
		previous=i=1;
		while(i!=52){
			for(i=previous;i<52;i++){
				if(is_empty(i)) continue;
				prev=prev3=-1;
				if(N[i].prev!=NULL)
					prev=(N[i].prev->n);
				if(N[prev].prev!=NULL)
					if(N[prev].prev->prev!=NULL)
						prev3=(N[prev].prev->prev->n);
				if(prev3>=0)
					if(is_match(stack[i][n_stack[i]-1],stack[prev3][n_stack[prev3]-1])){
						pop(i);
						if(is_empty(i)){
							if(N[i].prev!=NULL)
								N[i].prev->next=N[i].next;
							if(N[i].next!=NULL)
								N[i].next->prev=N[i].prev;
						}
						push(result,prev3);
						previous=prev3;
						break;
					}
				if(prev>=0)
					if(is_match(stack[i][n_stack[i]-1],stack[prev][n_stack[prev]-1])){
						pop(i);
						if(is_empty(i)){
							if(N[i].prev!=NULL)
								N[i].prev->next=N[i].next;
							if(N[i].next!=NULL)
								N[i].next->prev=N[i].prev;
						}
						push(result,prev);
						previous=prev;
						break;
					}
			}
		}
		for(i=0;i<52;i++)
			if(!is_empty(i)) count++;
		printf("%d ",count);
		if(count==1)
			printf("pile");
		else
			printf("piles");
		printf(" remaining:");
		for(i=0;i<52;i++)
			if(!is_empty(i))
				printf(" %d",n_stack[i]);
		puts("");
	}
	return 0;
}
