#include<stdio.h>
#include<stdlib.h>
int main(){
	int gainer,decliner;
	int nownum,nowden,nextnum,nextden;
	char start=0;
	while(scanf("%d%d",&gainer,&decliner)==2){
		if(start) puts("");
		else start=1;
		nownum=gainer/decliner,nowden=1;
		if((gainer%decliner)*2>=decliner) nownum++;
		printf("%d/%d\n",nownum,nowden);
		for(nextden=2;nownum*decliner!=nowden*gainer;nextden++){
			nextnum=nextden*gainer/decliner;
			if(((gainer*nextden)%decliner)*2>=decliner) nextnum++;
			if(abs(gainer*nowden-decliner*nownum)*nextden>abs(gainer*nextden-decliner*nextnum)*nowden)
				nownum=nextnum,nowden=nextden,printf("%d/%d\n",nownum,nowden);
		}
	}
	return 0;
}
