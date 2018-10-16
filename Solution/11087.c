#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long long congruent[505]={0},ans;
int seq[100005];
char flag[20000005]={0},*flagVec=flag+10000000;
int mod(int n,int k){
	n%=k;
	if(n<0) n+=k;
	return n;
}
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
void cal_pair(int modulus,int n_seq){
	int i;
	ans=0;
	for(i=0;i<n_seq;i++){
		if(flagVec[seq[i]]==2&&mod(seq[i]*2,modulus)==0) ans++;
		flagVec[seq[i]]=0;
	}
	for(i=1;i<=(modulus-1)/2;i++)
		ans+=congruent[i]*congruent[modulus-i];
	if(modulus%2==0) ans+=congruent[modulus/2]*(congruent[modulus/2]-1)/2;
	ans+=congruent[0]*(congruent[0]-1)/2;
}
int main(){
	int T,cases,n,k,tmp,n_seq;
	int i;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		printf("Case %d: ",cases);
		scanf("%d%d ",&n,&k);
		memset(congruent,0,sizeof(congruent));
		n_seq=0;
		for(i=0;i<n;i++){
			scanf("%d",&tmp);
			if(flagVec[tmp]) flagVec[tmp]=2;
			else flagVec[tmp]=1,seq[n_seq++]=tmp,congruent[mod(tmp,k)]++;
		}
		cal_pair(k,n_seq);
		printf("%lld\n",ans);
	}
	return 0;
}
