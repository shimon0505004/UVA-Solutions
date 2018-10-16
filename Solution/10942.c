#include<stdio.h>
int cal[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int nowy,nowm,nowd;
char isearlier(int y,int m,int d){
	if(y>nowy) return 0;
	if(y<nowy) return 1;
	if(m>nowm) return 0;
	if(m<nowm) return 1;
	if(d>nowd) return 0;
	if(d<nowd) return 1;
	return 1;
}
char year(int y){
	if(y==0) return 1;
	if(y%100==0) return 0;
	if(y%4==0) return 1;
	return 0;
}
char check(int y,int m,int d){
	char isleap=year(y);
	if(m>0&&m<13){
		if(d>0&&d<=cal[m]) return 1;
		else if(m==2&&isleap&&d==29) return 1;
	}
	return 0;
}
int main(){
	int cases;
	char isleap;
	int century,n1,n2,n3;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&century,&n1,&n2,&n3);
		century=((century+1)%4)*100;
		nowy=nowm=nowd=100;
		if(check(century+n1,n2,n3))
			nowy=n1,nowm=n2,nowd=n3;
		if(check(century+n1,n3,n2))
			if(isearlier(n1,n3,n2))
				nowy=n1,nowm=n3,nowd=n2;
		if(check(century+n2,n1,n3))
			if(isearlier(n2,n1,n3))
				nowy=n2,nowm=n1,nowd=n3;
		if(check(century+n2,n3,n1))
			if(isearlier(n2,n3,n1))
				nowy=n2,nowm=n3,nowd=n1;
		if(check(century+n3,n1,n2))
			if(isearlier(n3,n1,n2))
				nowy=n3,nowm=n1,nowd=n2;
		if(check(century+n3,n2,n1))
			if(isearlier(n3,n2,n1))
				nowy=n3,nowm=n2,nowd=n1;
		if(nowm==100) puts("-1");
		else printf("%.2d %.2d %.2d\n",nowy,nowm,nowd);
	}
	return 0;
}
