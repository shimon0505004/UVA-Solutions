#include<stdio.h>
#include<math.h>
#define EPS (1e-8)
#define pi 3.14159265358979323846
struct POINT{
	double x,y;
};
double cross_product(struct POINT *v1,struct POINT *v2){
	return v1->x*v2->y-v1->y*v2->x;
}
double inner_product(struct POINT *v1,struct POINT *v2){
	return v1->x*v2->x+v1->y*v2->y;
}
char equal(struct POINT *p1,struct POINT *p2){
	return fabs(p1->x-p2->x)+fabs(p1->y-p2->y)<EPS;
}
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
double cal_angle(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	double sin_theta,cos_theta,theta;
	struct POINT v1,v2;
	double len1=dis(p0,p1),len2=dis(p0,p2);
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	sin_theta=cross_product(&v1,&v2)/(len1*len2);
	cos_theta=inner_product(&v1,&v2)/(len1*len2);
	theta=atan2(sin_theta,cos_theta)/pi*180;
	if(theta<0) theta+=360;
	return theta;
}
void cal_ref(struct POINT *ref,struct POINT *pa,struct POINT *pa_,struct POINT *pb,struct POINT *pb_){
	double A=pa->y-pa_->y,A_=pa_->x-pa->x,B=pb->y-pb_->y,B_=pb_->x-pb->x;
	double C=(pb->x+pb_->x)/2-(pa->x+pa_->x)/2,C_=(pb->y+pb_->y)/2-(pa->y+pa_->y)/2;
	double t;
	if(fabs(B*A_-B_*A)>EPS){
		t=(B*C_-B_*C)/(B*A_-B_*A);
		ref->x=(pa->x+pa_->x)/2+A*t,ref->y=(pa->y+pa_->y)/2+A_*t;
	}else{
		A=pb->x-pa->x,A_=pb->y-pa->y,B=pb_->x-pa_->x,B_=pb_->y-pa_->y;
		C=pa_->x-pa->x,C_=pa_->y-pa->y;
		if(fabs(B*A_-B_*A)>EPS){
			t=(B*C_-B_*C)/(B*A_-B_*A);
			ref->x=pa->x+A*t,ref->y=pa->y+A_*t;
		}else ref->x=(pa->x+pa_->x)/2,ref->y=(pa->y+pa_->y)/2;
	}
}
int main(){
	struct POINT pa,pa_,pb,pb_;
	struct POINT orig,tran;
	for(;;){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&pa.x,&pa.y,&pa_.x,&pa_.y,&pb.x,&pb.y,&pb_.x,&pb_.y);
		if(fabs(pa.x)+fabs(pa.y)+fabs(pa_.x)+fabs(pa_.y)+fabs(pb.x)+fabs(pb.y)+fabs(pb_.x)+fabs(pb_.y)<EPS) break;
		orig.x=pb.x-pa.x,orig.y=pb.y-pa.y;
		tran.x=pb_.x-pa_.x,tran.y=pb_.y-pa_.y;
		if(equal(&pa,&pa_)&&equal(&pb,&pb_)) puts("No move.");
		else if(equal(&orig,&tran)) printf("Translation by vector <%.1lf,%.1lf>.\n",pa_.x-pa.x,pa_.y-pa.y);
		else{
			struct POINT ref;
			double angle;
			cal_ref(&ref,&pa,&pa_,&pb,&pb_);
			if(equal(&pa,&pa_)) angle=cal_angle(&ref,&pb,&pb_);
			else angle=cal_angle(&ref,&pa,&pa_);
			printf("Rotation around (%.1lf,%.1lf) by %.1lf degrees counterclockwise.\n",ref.x,ref.y,angle);
		}
	}
	return 0;
}
