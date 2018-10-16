#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
void cal_dig(long long n,int arr[],int *dig){
	int count;
	for(count=0;n!=0;count++,n/=10) arr[count]=n%10;
	*dig=count;
}
int main(){
	long long a,b;
	int dig_a,dig_b;
	int b_d[10];
	long long ans_l[10];
	char result[25];
	int i,j,maxW,lineW,ansW,linecount;
	char *space="                    ";
	char *line="--------------------";
	while(scanf("%lld%lld",&a,&b)==2){
		cal_dig(a,b_d,&dig_a),cal_dig(b,b_d,&dig_b);
		lineW=MAX(dig_a,dig_b);
		lineW=MAX(lineW,1);
		if(a==0||b==0){
			printf("%*lld\n",lineW,a);
			printf("%*lld\n",lineW,b);
			printf("%.*s\n",lineW,line);
			printf("%*lld\n",lineW,0LL);
		}else{
			for(i=0;i<dig_b;i++) ans_l[i]=a*b_d[i];
			memset(result,0,sizeof(result));
			ansW=0;
			for(i=0;i<dig_b;i++){
				long long tmp=ans_l[i];
				for(j=0;tmp>0;j++,tmp/=10){
					result[i+j]+=tmp%10;
					ansW=MAX(ansW,i+j+1);
				}
			}
			for(i=0;i<ansW;i++){
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
			if(result[ansW]) ansW++;
			maxW=MAX(ansW,lineW);
			printf("%*lld\n",maxW,a);
			printf("%*lld\n",maxW,b);
			printf("%.*s%.*s\n",maxW-lineW,space,lineW,line);
			linecount=0;
			for(i=0;i<dig_b;i++)
				if(ans_l[i]>0) linecount++;
			if(linecount>1){
				for(i=0;i<dig_b;i++)
					if(ans_l[i]>0)
						printf("%*lld\n",maxW-i,ans_l[i]);
				printf("%.*s\n",maxW,line);
				for(i=maxW-1;i>=0;i--) printf("%d",result[i]);
				puts("");
			}else{
				for(i=maxW-1;i>=0;i--) printf("%d",result[i]);
				puts("");
			}
		}
		puts("");
	}
	return 0;
}
