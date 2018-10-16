#include<stdio.h>
int main(){
	char c,a,b;
	char mark;
	char skip=0,skip2;
	for(;;){
		if(!skip) if((c=getchar())==EOF) break;
		skip=0;
		if(c!='\\') putchar(c);
		else{
			if((mark=getchar())==EOF) break;
			if(mark=='s'){
				while(b=getchar())
					if(b<'0'||b>'9') break;
				if(b=='.'){
					while(b=getchar())
						if(b<'0'||b>'9') break;
					c=b;
					skip=1;
				}else{
					c=b;
					skip=1;
				}
			}else if(mark=='*'){
				skip2=0;
				for(;;){
					if(!skip2) if((a=getchar())==EOF) return 0;
					while(a!='\\'){
						putchar(a);
						if((a=getchar())==EOF) return 0;
					}
					if((mark=getchar())==EOF) return 0;
					if(mark=='*') break;
					putchar('\\'),a=mark,skip2=1;
				}
			}else if(mark=='\\')
				putchar('\\');
			else if(mark!='b'&&mark!='i')
				putchar(mark);
		}
	}
	return 0;
}
