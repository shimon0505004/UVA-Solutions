#include<stdio.h>
#include<math.h>
int main()
{
	int a,i,j,n=1,pos,p,m,k,hostage[30],ansm[15];
	for(k=1;k<14;k++){
		n=2*k;
		m=k;
		i=0;
		while(i<k){
			m++;
			if(m%(2*k)==1) m+=k;
			for(i=0;i<n;i++)
				hostage[i]=i+1;
			pos=0;
			for(i=0;i<k;i++){
				p=m%(n-i);
				pos=(pos+p+n-i-1)%(n-i);
				if(pos<k) break;
				for(j=pos;j<n-i;j++)
					hostage[j]=hostage[j+1];
			}
		}
		ansm[k]=m;
	}
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		printf("%d\n",ansm[n]);
	}
	return 0;
}
