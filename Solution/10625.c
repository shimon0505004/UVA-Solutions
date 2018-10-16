#include<stdio.h>
#include<string.h>
struct RULE{
	char src;
	char dest[105];
	int len;
};
int main(){
	int cases;
	int i,j,k,R,Q,n;
	struct RULE r[10];
	char orig[105],c;
	unsigned long long cnt0[128],cnt1[128];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&R);
		for(i=0;i<R;i++)
			scanf(" %c%*c%*c%s",&(r[i].src),r[i].dest),r[i].len=strlen(r[i].dest);
		scanf("%d",&Q);
		while(Q--){
			int len;
			scanf("%s %c%d",orig,&c,&n);
			len=strlen(orig);
			memset(cnt0,0,sizeof(cnt0));
			for(i=0;i<len;i++) cnt0[(int)orig[i]]++;
			for(i=1;i<=n;i++){
				if(i&1){
					memcpy(cnt1,cnt0,sizeof(cnt1));
					for(j=0;j<R;j++){
						for(k=0;k<r[j].len;k++)
							cnt1[(int)r[j].dest[k]]+=cnt0[(int)r[j].src];
						cnt1[(int)r[j].src]-=cnt0[(int)r[j].src];
					}
				}else{
					memcpy(cnt0,cnt1,sizeof(cnt0));
					for(j=0;j<R;j++){
						for(k=0;k<r[j].len;k++)
							cnt0[(int)r[j].dest[k]]+=cnt1[(int)r[j].src];
						cnt0[(int)r[j].src]-=cnt1[(int)r[j].src];
					}
				}

			}
			if(n&1) printf("%llu\n",cnt1[(int)c]);
			else printf("%llu\n",cnt0[(int)c]);
		}
	}
	return 0;
}
