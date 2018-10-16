#include<stdio.h>
struct MOBILE{
	char unbal;
	int w;
};
struct MOBILE getMobile(){
	struct MOBILE m,wl,wr;
	int dr,dl;
	scanf("%d%d%d%d",&wl.w,&dl,&wr.w,&dr);
	wl.unbal=wr.unbal=m.unbal=0;
	if(wl.w==0) wl=getMobile();
	if(wr.w==0) wr=getMobile();
	if(wl.unbal||wr.unbal) m.unbal=1;
	if(wl.w*dl!=wr.w*dr) m.unbal=1;
	m.w=wl.w+wr.w;
	return m;
}
int main(){
	int cases;
	scanf("%d",&cases);
	while(cases--){
		if(getMobile().unbal) puts("NO");
		else puts("YES");
		if(cases) puts("");
	}
	return 0;
}
