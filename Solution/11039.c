#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int cases,n;
	int blue[500005],red[500005];
	int n_b,n_r,floors,nowsize;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		n_b=n_r=0;
		while(n--){
			int temp;
			scanf("%d",&temp);
			if(temp>0) blue[n_b++]=temp;
			else red[n_r++]=-temp;
		}
		qsort(blue,n_b,sizeof(int),compar);
		qsort(red,n_r,sizeof(int),compar);
		if(n_b==0||n_r==0){
			if(n_b+n_r>0) puts("1");
			else puts("0");
			continue;
		}
		if(blue[n_b-1]>red[n_r-1]) nowsize=blue[n_b-1],floors=1,n_b--;
		else nowsize=1000000,floors=0;
		for(;;){
			for(n_r--;n_r>=0;n_r--)
				if(red[n_r]<nowsize){
					nowsize=red[n_r];
					floors++;
					break;
				}
			if(n_r<0) break;
			for(n_b--;n_b>=0;n_b--)
				if(blue[n_b]<nowsize){
					nowsize=blue[n_b];
					floors++;
					break;
				}
			if(n_b<0) break;
		}
		printf("%d\n",floors);
	}
	return 0;
}
