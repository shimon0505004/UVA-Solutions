#include<stdio.h>
#define Up    0
#define Right 1
#define Down  2
#define Over  0
int rightest=0,maxn;
void move(int[],int[],int[],int,int,int,int);
int main()
{
	int L[5000]={0},H[5000]={0},R[5000]={0},i=0,k;
	while(scanf("%d%d%d",&L[i],&H[i],&R[i])!=EOF)
		i++;
	maxn=i;
	for(k=0;k<i;k++)
		rightest=(R[k]>rightest?R[k]:rightest);
	printf("%d",L[0]);
	move(L,H,R,Up,0,H[0],L[0]);
	printf("\n");
	return 0;
}
void move(int L[],int H[],int R[],int URD,int from,int to,int XorY)
{
	int i,flag=1,maxH=0,maxi=-1,maxR=0;
	switch(URD){
	case Right:
		for(i=0;L[i]<=to && flag!=Over && i<maxn;i++)
			if(L[i]>=from && H[i]>XorY){
				printf(" %d",L[i]);
				move(L,H,R,Up,XorY,H[i],L[i]);
				flag=Over;
			}
			else if(L[i]>=from && H[i]==XorY && R[i]>to){
				move(L,H,R,Right,L[i],R[i],XorY);
				flag=Over;
			}
		if(flag!=Over){
			printf(" %d",to);
			move(L,H,R,Down,XorY,0,to);
		}
		break;
	case Up:
		for(i=0;L[i]<=XorY && i<maxn;i++)
			if(L[i]==XorY){
				if(H[i]>maxH){
					maxH=H[i];
					maxi=i;
				}
			}								
		printf(" %d",H[maxi]);
		move(L,H,R,Right,L[maxi],R[maxi],H[maxi]);
		break;
	case Down:
		for(i=0;L[i]<=XorY && flag!=Over && i<maxn;i++)
			if(R[i]>XorY){
				if(H[i]>maxH){
					maxH=H[i];
					maxi=i;
					maxR=R[i];
				}
				else if(H[i]==maxH){
					if(R[i]>maxR){
						maxR=R[i];
						maxi=i;
					}
				}
			}
		if(maxi>=0){
			printf(" %d",H[maxi]);
			move(L,H,R,Right,XorY,R[maxi],H[maxi]);
			flag=Over;
		}
		if(flag!=Over){
			printf(" %d",to);
			if(XorY<rightest)
				move(L,H,R,Right,XorY,rightest,0);
		}
		break;
	}
	return;
}
