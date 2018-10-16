#include<stdio.h>
#include<math.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef struct POINT{
	int X,Y;
}Point;
typedef Point Vector;
typedef struct LINE{
	Point P1,P2;
	Vector V;
}Line;
int CrossProduct(Vector *v1,Vector *v2){
	return v1->X*v2->Y-v1->Y*v2->X;
}
Vector toVec(Point *P1,Point *P2){
	Vector v;
	v.X=P2->X-P1->X,v.Y=P2->Y-P1->Y;
	return v;
}
double Dis(Point *P1,Point *P2){
	double x=P1->X-P2->X,y=P1->Y-P2->Y;
	return sqrt(x*x+y*y);
}
double Length(Vector *v){
	return sqrt(v->X*v->X+v->Y*v->Y);
}
double Point_Line_Dis(Point *P,Line *L){
	Vector V1,V2;
	V1=toVec(P,&(L->P1));
	V2=toVec(P,&(L->P2));
	return (double)CrossProduct(&V1,&V2)/Length(&(L->V));
}
int InnerProduct(Vector *v1,Vector *v2){
	return v1->X*v2->X+v1->Y*v2->Y;
}
char isAcute(Point *p0,Point *p1,Point *p2){
	Vector V1,V2;
	V1=toVec(p1,p2),V2=toVec(p1,p0);
	if(InnerProduct(&V1,&V2)<0) return 0;
	V1=toVec(p2,p1),V2=toVec(p2,p0);
	if(InnerProduct(&V1,&V2)<0) return 0;
	return 1;
}
int main(){
	char MSG[2][5];
	Line L1,L2,temp;
	for(;;){
		scanf("%d%d%d%d%s",&L1.P1.X,&L1.P1.Y,&L1.P2.X,&L1.P2.Y,MSG[0]);
		scanf("%d%d%d%d%s",&L2.P1.X,&L2.P1.Y,&L2.P2.X,&L2.P2.Y,MSG[1]);
		if(MSG[0][0]=='E') break;
		L1.V=toVec(&(L1.P1),&(L1.P2));
		L2.V=toVec(&(L2.P1),&(L2.P2));
		if(MSG[0][1]==0&&MSG[1][1]==0){
			if(CrossProduct(&(L1.V),&(L2.V))) puts("0.00000");
			else printf("%.5lf\n",fabs(Point_Line_Dis(&(L1.P1),&(L2))));
		}else if(MSG[0][1]=='S'&&MSG[1][1]=='S'){
			double L1P1_L2,L1P2_L2,L2P1_L1,L2P2_L1,MinDis,D;
			L1P1_L2=Point_Line_Dis(&(L1.P1),&(L2));
			L1P2_L2=Point_Line_Dis(&(L1.P2),&(L2));
			L2P1_L1=Point_Line_Dis(&(L2.P1),&(L1));
			L2P2_L1=Point_Line_Dis(&(L2.P2),&(L1));
			if(L1P1_L2*L1P2_L2<0&&L2P1_L1*L2P2_L1<0) puts("0.00000");
			else{
				MinDis=Dis(&(L1.P1),&(L2.P1));
				if(MinDis>(D=Dis(&(L1.P1),&(L2.P2)))) MinDis=D;
				if(MinDis>(D=Dis(&(L1.P2),&(L2.P1)))) MinDis=D;
				if(MinDis>(D=Dis(&(L1.P2),&(L2.P2)))) MinDis=D;
				if(MinDis>(D=fabs(L1P1_L2))&&isAcute(&(L1.P1),&(L2.P1),&(L2.P2))) MinDis=D;
				if(MinDis>(D=fabs(L1P2_L2))&&isAcute(&(L1.P2),&(L2.P1),&(L2.P2))) MinDis=D;
				if(MinDis>(D=fabs(L2P1_L1))&&isAcute(&(L2.P1),&(L1.P1),&(L1.P2))) MinDis=D;
				if(MinDis>(D=fabs(L2P2_L1))&&isAcute(&(L2.P2),&(L1.P1),&(L1.P2))) MinDis=D;
				printf("%.5lf\n",MinDis);
			}
		}else{
			double D1,D2;
			if(MSG[1][1]=='S') temp=L1,L1=L2,L2=temp;
			D1=Point_Line_Dis(&(L1.P1),&(L2));
			D2=Point_Line_Dis(&(L1.P2),&(L2));
			if(D1*D2<0) puts("0.00000");
			else printf("%.5lf\n",MIN(fabs(D1),fabs(D2)));
		}
	}
	return 0;
}
