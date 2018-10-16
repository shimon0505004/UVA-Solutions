#include<stdio.h>
#include<math.h>
#include<string.h>
struct STUDENT{
	double score;
	int bonus,absence;
	int grade;
};
int main(){
	struct STUDENT s[32];
	int cases,T,S,i,j,score;
	double mean,sd,sum,sqr_sum;
	double average_grade;
	puts("MAKING THE GRADE OUTPUT");
	scanf("%d",&cases);
	while(cases--){
		sum=sqr_sum=0;
		memset(s,0,sizeof(s));
		scanf("%d%d",&S,&T);
		for(i=0;i<S;i++){
			int min=100;
			for(j=0;j<T;j++){
				scanf("%d",&score);
				if(score<min) min=score;
				s[i].score+=score;
			}
			if(T>2) s[i].score-=min,s[i].score/=(T-1);
			else s[i].score/=T;
			sum+=s[i].score;
			sqr_sum+=s[i].score*s[i].score;
			scanf("%d%d",&s[i].bonus,&s[i].absence);
		}
		mean=sum/S,sd=sqrt(sqr_sum/S-mean*mean);
		average_grade=0;
		for(i=0;i<S;i++){
			s[i].score+=(3*(s[i].bonus/2));
			if(s[i].score+1e-5>mean+sd) s[i].grade=4;
			else if(s[i].score+1e-5>mean) s[i].grade=3;
			else if(s[i].score+1e-5>mean-sd) s[i].grade=2;
			else s[i].grade=1;
			if(s[i].absence==0) s[i].grade++;
			else s[i].grade-=s[i].absence/4;
			if(s[i].grade>4) s[i].grade=4;
			else if(s[i].grade<0) s[i].grade=0;
			average_grade+=s[i].grade;
		}
		average_grade/=S;
		printf("%.1lf\n",average_grade);
	}
	puts("END OF OUTPUT");
	return 0;
}
