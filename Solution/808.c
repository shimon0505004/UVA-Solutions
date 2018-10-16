#include<stdio.h>
#include<math.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int cal_dis(int s_x,int s_y,int e_x,int e_y){
	int temp;
	if(s_y>e_y){
		temp=s_y,s_y=e_y,e_y=temp;
		temp=s_x,s_x=e_x,e_x=temp;
	}
	if(s_x<=e_x) return MAX(e_x-s_x,e_y-s_y);
	return (s_x-e_x)+(e_y-s_y);
}
void cal_pos(int n,int *x,int *y){
	int k=(int)((sqrt(12*n-3)-3)/6);
	int d=n-(3*k*k+3*k+1),min;
	*x=k,*y=0;
	if(d>0) (*y)--,d--;
	if(d>0) min=MIN(d,k),*x-=min,*y-=min,d-=min;
	if(d>0) min=MIN(d,k+1),*x-=min,d-=min;
	if(d>0) min=MIN(d,k+1),*y+=min,d-=min;
	if(d>0) min=MIN(d,k+1),*x+=min,*y+=min,d-=min;
	if(d>0) min=MIN(d,k+1),*x+=min,d-=min;
	if(d>0) *y-=d;
}
int main(){
	int a,b,s_x,s_y,e_x,e_y;
	while(scanf("%d%d",&a,&b),a|b){
		cal_pos(a,&s_x,&s_y),cal_pos(b,&e_x,&e_y);
		printf("The distance between cells %d and %d is %d.\n",a,b,cal_dis(s_x,s_y,e_x,e_y));
	}
	return 0;
}
