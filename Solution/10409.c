#include<stdio.h>
void roll(int *fb[],int *rl[],char dir)
{
	int temp,i;
	switch(dir){
		case 'n':
			temp=*fb[3];
			for(i=3;i>0;i--)
				*fb[i]=*fb[(i+3)%4];
			*fb[0]=temp;
			break;
		case 'e':
			temp=*rl[3];
			for(i=3;i>0;i--)
				*rl[i]=*rl[(i+3)%4];
			*rl[0]=temp;
			break;
		case 'w':
			temp=*rl[0];
			for(i=0;i<3;i++)
				*rl[i]=*rl[(i+1)%4];
			*rl[3]=temp;
			break;
		case 's':
			temp=*fb[0];
			for(i=0;i<3;i++)
				*fb[i]=*fb[(i+1)%4];
			*fb[3]=temp;
			break;
	}
}
int main()
{
	int rolltimes,i;
	char temp[10];
	int *fb[4],*rl[4],UP,DOWN,NORTH,EAST,WEST,SOUTH;
	fb[0]=&UP,fb[1]=&NORTH,fb[2]=&DOWN,fb[3]=&SOUTH;
	rl[0]=&UP,rl[1]=&EAST,rl[2]=&DOWN,rl[3]=&WEST;
	while(1){
		scanf("%d",&rolltimes);
		if(!rolltimes) break;
		UP=1,NORTH=2,WEST=3,DOWN=6,SOUTH=5,EAST=4;
		for(i=0;i<rolltimes;i++){
			scanf("%s",temp);
			roll(fb,rl,*temp);
		}
		printf("%d\n",*fb[0]);
	}
	return 0;
}
