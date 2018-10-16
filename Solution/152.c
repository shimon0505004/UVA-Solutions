#include<stdio.h>
#include<math.h>
struct POINT{
	int x,y,z;
};
int dis(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y,z=p1->z-p2->z;
	return (int)sqrt(x*x+y*y+z*z);
}
int main(){
	struct POINT p[5005];
	int i,count,j;
	int distance[5005],t;
	int bin[10]={0};
	for(count=0;scanf("%d%d%d",&p[count].x,&p[count].y,&p[count].z),p[count].x+p[count].y+p[count].z;count++)
		distance[count]=100000;
	for(i=0;i<count;i++){
		for(j=i+1;j<count;j++){
			t=dis(&(p[i]),&(p[j]));
			if(t<distance[i])
				distance[i]=t;
			if(t<distance[j])
				distance[j]=t;
		}
		bin[distance[i]]++;
	}
	for(i=0;i<10;i++)
		printf("%4d",bin[i]);
	puts("");
	return 0;
}
