#include<stdio.h>
int main()
{
	int c,n,cases[1000],i,j,tot,passed;
	char grades[5000],a[6];
	float average;
	scanf("%d",&c);
	for(i=0;i<c;i++){
		getchar();
		j=0;
		tot=0;
		passed=0;
		while(1){
			a[j]=getchar();
			if(a[j]==' ' ||a[j]=='\n'){
				a[j]=0;
				break;
			}
			j++;
		}
		sscanf(a,"%d",&n);
		for(j=0;j<n;j++){
			scanf("%d",&cases[j]);
			tot+=cases[j];
		}
		average=(float)tot/n;
		for(j=0;j<n;j++)
			if(cases[j]>average)
				passed++;
		printf("%.3f%\n",(float)passed*100/n);
	}
	return 0;
}
