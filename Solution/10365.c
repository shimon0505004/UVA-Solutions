#include<stdio.h>
#include<math.h>
int main()
{
	int cases,i,j,input,min,temp;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&input);
		min=2147483647;
		for(i=1;i*i*i<=input;i++){
			if(input%i) continue;
			for(j=1;j*j<=(input/i);j++){
				if((input/i)%j) continue;
				temp=2*(i*j+input/i+input/j);
				if(temp<min)
					min=temp;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
