#include<stdio.h>
int swap;
int tempN[1005];
void mergesort(int *seq,int members){
	int temp,half,i,a,b,*s1,*s2;
	if(members==1) return;
	if(members==2){
		if(seq[1]<seq[0]) temp=seq[0],seq[0]=seq[1],seq[1]=temp,swap++;
		return;
	}
	half=members/2;
	mergesort(seq,half);
	mergesort(seq+half,members-half);
	s1=seq,s2=seq+half;
	for(i=a=b=0;i<members;i++){
		if(a==half){
			memmove(tempN+i,s2+b,(members-half-b)*sizeof(int));
			break;
		}else if(b==members-half){
			memmove(tempN+i,s1+a,(half-a)*sizeof(int));
			break;
		}
		if(s1[a]<=s2[b]){
			tempN[i]=s1[a];
			a++;
		}else{
			tempN[i]=s2[b];
			b++;
			swap+=half-a;
		}
	}
	memmove(seq,tempN,members*sizeof(int));
}
int main()
{
	int n,i,j,N[1005];
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%d",&N[i]);
		swap=0;
		mergesort(N,n);
		printf("Minimum exchange operations : %d\n",swap);
	}
	return 0;
}
