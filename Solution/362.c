#include<stdio.h>
#include<math.h>
int main(){
	int bytes,now,i,trans,count,cases,buf;
	for(cases=1;scanf("%d",&bytes),bytes;cases++){
		printf("Output for data set %d, %d bytes:\n",cases,bytes);
		buf=now=0;
		for(count=1;;count++){
			scanf("%d",&trans);
			now+=trans,buf+=trans;
			if(count%5==0){
				if(buf==0)
					puts("   Time remaining: stalled");
				else
					printf("   Time remaining: %.0lf seconds\n",ceil((double)(bytes-now)/buf*5));
				buf=0;
			}
			if(now==bytes) break;
		}
		printf("Total time: %d seconds\n",count);
		puts("");
	}
	return 0;
}
