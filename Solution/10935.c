#include<stdio.h>
#define MAX_SIZE 55
int queue[MAX_SIZE];
int tail,head;
int isempty(){
	return tail==head;
}
void enqueue(int n){
	queue[tail++]=n;
	tail%=MAX_SIZE;
}
int dequeue(){
	int result=queue[head++];
	head%=MAX_SIZE;
	return result;
}
int main(){
	int n,i,temp;
	while(scanf("%d",&n),n){
		if(n==1){
			puts("Discarded cards:");
			puts("Remaining card: 1");
			continue;
		}
		tail=head=0;
		for(i=1;i<=n;i++) enqueue(i);
		dequeue();
		printf("Discarded cards: 1");
		for(;;){
			enqueue(dequeue());
			temp=dequeue();
			if(isempty()){
				printf("\nRemaining card: %d\n",temp);
				break;
			}
			printf(", %d",temp);
		}
	}
	return 0;
}
