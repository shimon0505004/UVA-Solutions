#include<stdio.h>
#include<math.h>
int main(){
	double distance;
	int cases,x1,y1,x2,y2,m;
	char input[30];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d ",&x1,&y1);
		distance=0;
		while(fgets(input,30,stdin)!=NULL&&*input!='\n'){
			sscanf(input,"%d%d%d%d",&x1,&y1,&x2,&y2);
			distance+=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		}
		m=(int)(distance*0.006+0.5);
		printf("%d:%.2d\n",m/60,m%60);
		if(cases) puts("");
	}
	return 0;
}
