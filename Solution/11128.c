#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int compar(const void *a,const void *b){
	return *((int *)b)-*((int *)a);
}
double t_sqrt[100];
double max=0;
char all_zero(int ans[7]){
	int i;
	for(i=0;i<7;i++) if(ans[i]!=0) return 0;
	return 1;
}
char cal(int a[7],int ans[7]){
	double sum[7],f[7];
	int i;
	sum[6]=t_sqrt[a[6]];
	for(i=5;i>=0;i--) sum[i]=sum[i+1]+t_sqrt[a[i]];
	f[0]=0;
	for(ans[0]=-9;ans[0]<10;ans[0]++){
		f[0]=t_sqrt[a[0]]*ans[0];
		if(fabs(f[0])-9*sum[1]+1e-8>1e-4) continue;
		for(ans[1]=-9;ans[1]<10;ans[1]++){
			f[1]=f[0]+t_sqrt[a[1]]*ans[1];
			if(fabs(f[1])-9*sum[2]+1e-8>1e-4) continue;
			for(ans[2]=-9;ans[2]<10;ans[2]++){
				f[2]=f[1]+t_sqrt[a[2]]*ans[2];
				if(fabs(f[2])-9*sum[3]+1e-8>1e-4) continue;
				for(ans[3]=-9;ans[3]<10;ans[3]++){
					f[3]=f[2]+t_sqrt[a[3]]*ans[3];
					if(fabs(f[3])-9*sum[4]+1e-8>1e-4) continue;
					for(ans[4]=-9;ans[4]<10;ans[4]++){
						f[4]=f[3]+t_sqrt[a[4]]*ans[4];
						if(fabs(f[4])-9*sum[5]+1e-8>1e-4) continue;
						for(ans[5]=-9;ans[5]<10;ans[5]++){
							f[5]=f[4]+t_sqrt[a[5]]*ans[5];
							if(fabs(f[5])-9*sum[6]+1e-8>1e-4) continue;
							for(ans[6]=-9;ans[6]<10;ans[6]++){
								f[6]=f[5]+t_sqrt[a[6]]*ans[6];
								if(all_zero(ans)) continue;
								if(fabs(f[6])<1e-4) return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
int find(int a[7],int s){
	int i;
	for(i=0;i<7;i++)
		if(a[i]==s){
			a[i]=-1;
			return i;
		}
	return -1;
}
int main(){
	int a[7],orig[7];
	int ans[7],T,cases,i;
	for(i=0;i<100;i++) t_sqrt[i]=sqrt(i);
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		orig[0]=1;
		for(i=1;i<7;i++) scanf("%d",&orig[i]);
		memcpy(a,orig,sizeof(int[7]));
		qsort(a,7,sizeof(int),compar);
		printf("Case %d:",cases);
		if(cal(a,ans)){
			for(i=0;i<7;i++){
				int t=find(a,orig[i]);
				printf(" %d",ans[t]);
			}
			puts("");
		}else puts(" No Solution.");
	}
	return 0;
}
