#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n=0,i,n_step,n_dir;
	char treasure[205],*tPtr,temp[20]={0},dir[3]={0};
	long double x,y,step,distance;
	while(1){
		memset(treasure,0,sizeof(treasure));
		scanf("%s",treasure);
		tPtr=treasure;
		if(*tPtr=='E') break;
		n++;
		x=y=0.0;
		while(*tPtr!='.'){
			memset(dir,0,sizeof(dir));
			memset(temp,0,sizeof(temp));
			n_step=strcspn(tPtr,"NEWS");
			strncpy(temp,tPtr,n_step);
			step=(double)atoi(temp);
			tPtr+=n_step;
			n_dir=strcspn(tPtr,",.");
			strncpy(dir,tPtr,n_dir);
			if(strlen(dir)==2) 
				step/=sqrt(2);
			if(strchr(dir,'N')!=NULL)
				y+=step;
			if(strchr(dir,'E')!=NULL)
				x+=step;
			if(strchr(dir,'W')!=NULL)
				x-=step;
			if(strchr(dir,'S')!=NULL)
				y-=step;
			tPtr+=n_dir;
			if(*tPtr==',')
				tPtr++;
		}
		printf("Map #%d\n",n);
		printf("The treasure is located at (%.3Lf,%.3Lf).\n",x,y);
		distance=sqrt(pow(x,2)+pow(y,2));
		printf("The distance to the treasure is %.3Lf.\n",distance);
		printf("\n");
	}
	return 0;
}
