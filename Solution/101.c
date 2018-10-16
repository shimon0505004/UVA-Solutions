#include<stdio.h>
#define Move_Onto 0
#define Move_Over 1
#define Pile_Onto 2
#define Pile_Over 3
void move_onto(int,int,int[],int[]);
void move_over(int,int,int[],int[]);
void pile_onto(int,int,int[],int[]);
void pile_over(int,int,int[],int[]);
int n_of_pile;
void (*funcs[4])(int,int,int[],int[])={move_onto,move_over,pile_onto,pile_over};
int main()
{
	char move[5]="move",pile[5]="pile",onto[5]="onto",over[5]="over",temp[15],action[5],method[5];
	int inpile[30]={0},inrank[30]={0},i,from,to,j,block[30][30]={0};
	while(scanf("%d",&n_of_pile)!=EOF){
		getchar();
		for(i=0;i<n_of_pile;i++){
			inpile[i]=i;
			inrank[i]=0;
		}
		while(1){
			fgets(temp,80,stdin);
			temp[strlen(temp)-1]=0;
			if(temp[0]=='q')
				break;
			sscanf(temp,"%s%d%s%d",action,&from,method,&to);
			if(inpile[from]==inpile[to])
				continue;
			if(strcmp(action,move)==0)
				if(strcmp(method,onto)==0)
					(*funcs[Move_Onto])(from,to,inpile,inrank);
				else
					(*funcs[Move_Over])(from,to,inpile,inrank);
			else
				if(strcmp(method,onto)==0)
					(*funcs[Pile_Onto])(from,to,inpile,inrank);
				else
					(*funcs[Pile_Over])(from,to,inpile,inrank);
		}
	
			
		for(i=0;i<n_of_pile;i++)
			for(j=0;j<n_of_pile;j++)
				block[i][j]=-1;
		for(i=0;i<n_of_pile;i++)
			block[inpile[i]][inrank[i]]=i;
		for(i=0;i<n_of_pile;i++){
			printf("%d:",i);
			for(j=0;j<n_of_pile;j++)
				if(block[i][j]>=0)
					printf(" %d",block[i][j]);
			printf("\n");

		}
	}
	return 0;
}
void move_onto(int from,int to,int inpile[],int inrank[])
{
	int i;
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[from]&&inrank[i]>inrank[from]){
			inpile[i]=i;
			inrank[i]=0;
		}
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[to]&&inrank[i]>inrank[to]){
			inpile[i]=i;
			inrank[i]=0;
		}
	inpile[from]=inpile[to];
	inrank[from]=inrank[to]+1;
	return;
}
void move_over(int from,int to,int inpile[],int inrank[])
{
	int i;
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[from]&&inrank[i]>inrank[from]){
			inpile[i]=i;
			inrank[i]=0;
		}
	inrank[from]=inrank[to];
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[to]&&inrank[i]>inrank[to]){
			inrank[from]++;
		}
	inrank[from]++;
	inpile[from]=inpile[to];
	return;
}
void pile_onto(int from,int to,int inpile[],int inrank[])
{
	int i;
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[to]&&inrank[i]>inrank[to]){
			inpile[i]=i;
			inrank[i]=0;
		}	
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[from]&&inrank[i]>inrank[from]){
			inpile[i]=inpile[to];
			inrank[i]=inrank[to]+1+inrank[i]-inrank[from];
		}
	inpile[from]=inpile[to];
	inrank[from]=inrank[to]+1;
	return;
}
void pile_over(int from,int to,int inpile[],int inrank[])
{
	int i,maxrank=0;
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[to]&&inrank[i]>=inrank[to])
			maxrank=(inrank[i]>maxrank?inrank[i]:maxrank);
	for(i=0;i<n_of_pile;i++)
		if(inpile[i]==inpile[from]&&inrank[i]>inrank[from]){
			inpile[i]=inpile[to];
			inrank[i]=maxrank+1+inrank[i]-inrank[from];
		}
	inpile[from]=inpile[to];
	inrank[from]=maxrank+1;
	return;
}

