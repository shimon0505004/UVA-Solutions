#include<stdio.h>
struct TSP{
	int value;
	int next;
};
int main(){
	int n,m,i,j,min,next,mini,now,temp;
	struct TSP t[15][105];
	while(scanf("%d%d",&m,&n)==2){
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&t[i][j].value);
		for(i=n-2;i>=0;i--)
			for(j=0;j<m;j++){
				min=t[j][i+1].value,next=j;
				if(min>(temp=t[(j+m-1)%m][i+1].value))
					min=temp,next=(j+m-1)%m;
				else if(min==(temp=t[(j+m-1)%m][i+1].value)&&next>((j+m-1)%m))
					min=temp,next=(j+m-1)%m;
				if(min>(temp=t[(j+1)%m][i+1].value))
					min=temp,next=(j+1)%m;
				else if(min==(temp=t[(j+1)%m][i+1].value)&&next>((j+1)%m))
					min=temp,next=(j+1)%m;
				t[j][i].value+=min;
				t[j][i].next=next;
			}
		min=t[0][0].value,mini=0;
		for(i=1;i<m;i++)
			if(min>t[i][0].value)
				min=t[i][0].value,mini=i;
		printf("%d",mini+1);
		now=mini;
		for(i=0;i<n-1;i++){
			printf(" %d",t[now][i].next+1);
			now=t[now][i].next;
		}
		printf("\n%d\n",t[mini][0]);
	}
	return 0;
}
