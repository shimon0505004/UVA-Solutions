#include<stdio.h>
#include<math.h>
#define log10_2 log10(2)
#define log10_3 log10(3)
#define log10_5 log10(5)
#define Nums 7420
int main()
{
	struct num{
		float logvalue;
		short int P2;
		short int P3;
		short int P5;
	};
	struct num temp;
	int i,j,k,n=0;
	struct num Num[Nums];
	for(i=0;i<Nums;i++)
		Num[i].logvalue=1<<16;
	for(i=0;i<30;i++)
		for(j=0;j<19;j++)
			for(k=0;k<13;k++){
				Num[n].logvalue=i*log10_2+j*log10_3+k*log10_5;
				Num[n].P2=i;
				Num[n].P3=j;
				Num[n].P5=k;
				n++;
			}
	for(i=0;i<Nums-1;i++)
		for(j=0;j<Nums-1;j++)
			if(Num[j].logvalue>Num[j+1].logvalue){
				temp=Num[j];
				Num[j]=Num[j+1];
				Num[j+1]=temp;
			}
	printf("The 1500'th ugly number is %.0f.\n",pow(2,Num[1499].P2)*pow(3,Num[1499].P3)*pow(5,Num[1499].P5));
	return 0;
}
