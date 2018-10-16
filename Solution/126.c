#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct ITEM{
	int xdeg,ydeg,coef;
};
char *getItem(char *ptr,struct ITEM *item){
	char isNeg=0,xory;
	int deg;
	item->xdeg=item->ydeg=item->coef=0;
	if(*ptr=='-') isNeg=1;
	else if(*ptr!='+') ptr--;
	while(isdigit(*++ptr)) item->coef=item->coef*10+*ptr-'0';
	if(item->coef==0) item->coef=1;
	if(isNeg) item->coef*=-1;
	xory=*ptr;
	if(xory!='x'&&xory!='y') return ptr;
	deg=0;
	while(isdigit(*++ptr)) deg=deg*10+*ptr-'0';
	if(xory=='x'){
		if(deg) item->xdeg=deg;
		else item->xdeg=1;
	}else if(xory=='y'){
		if(deg) item->ydeg=deg;
		else item->ydeg=1;
	}
	xory=*ptr;
	if(xory!='x'&&xory!='y') return ptr;
	deg=0;
	while(isdigit(*++ptr)) deg=deg*10+*ptr-'0';
	if(xory=='x'){
		if(deg) item->xdeg=deg;
		else item->xdeg=1;
	}else if(xory=='y'){
		if(deg) item->ydeg=deg;
		else item->ydeg=1;
	}
	return ptr;
}
int main(){
	char line[100],*ptr,start;
	char expo[100],base[100],*expoPtr,*basePtr;
	int coef[205][205];
	int acount,bcount,i,j,len;
	struct ITEM aitem[10005],bitem[10005];
	while(fgets(line,100,stdin),*line!='#'){
		memset(coef,0,sizeof(coef));
		for(acount=0,ptr=line;*ptr!='\n';acount++)
			ptr=getItem(ptr,&aitem[acount]);
		fgets(line,100,stdin);
		for(bcount=0,ptr=line;*ptr!='\n';bcount++)
			ptr=getItem(ptr,&bitem[bcount]);
		for(i=0;i<acount;i++)
			for(j=0;j<bcount;j++)
				coef[aitem[i].xdeg+bitem[j].xdeg][aitem[i].ydeg+bitem[j].ydeg]+=aitem[i].coef*bitem[j].coef;
		expoPtr=expo,basePtr=base;
		memset(expo,' ',sizeof(expo));
		memset(base,' ',sizeof(base));
		start=0;
		for(i=204;i>=0;i--)
			for(j=0;j<205;j++)
				if(coef[i][j]){
					if(start){
						basePtr++,expoPtr++;
						if(coef[i][j]<0) *basePtr='-';
						else *basePtr='+';
						basePtr+=2,expoPtr+=2;
					}else if(coef[i][j]<0) *basePtr++='-',expoPtr++;
					start=1;
					if((i==0&&j==0)||abs(coef[i][j])>1){
						len=sprintf(basePtr,"%d",abs(coef[i][j]));
						basePtr+=len,expoPtr+=len,*basePtr=' ';
					}
					if(i) *basePtr++='x',expoPtr++;
					if(i>1){
						len=sprintf(expoPtr,"%d",i);
						basePtr+=len,expoPtr+=len,*expoPtr=' ';
					}
					if(j) *basePtr++='y',expoPtr++;
					if(j>1){
						len=sprintf(expoPtr,"%d",j);
						basePtr+=len,expoPtr+=len,*expoPtr=' ';
					}
				}
		len=expoPtr-expo;
		if(basePtr-base>len) len=basePtr-base;
		base[len]=expo[len]=0;
		puts(expo),puts(base);
	}
	return 0;
}
