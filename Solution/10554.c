#include<stdio.h>
int main(){
	char unit,input[30],FatinPercent,*ptr;
	int len,CperG[5]={9,4,4,4,7},i;
	double nutri[5],total,percent,subtotal,Fat;
	for(;;){
		total=Fat=0.0;
		while(fgets(input,30,stdin),*input!='-'){
			subtotal=percent=0.0;
			FatinPercent=0;
			for(ptr=input,i=0;i<5;i++,ptr+=len){
				sscanf(ptr," %lf%c%n",&nutri[i],&unit,&len);
				if(unit=='C') subtotal+=nutri[i];
				else if(unit=='g') subtotal+=(nutri[i]*=CperG[i]);
				else{
					if(i==0) FatinPercent=1;
					percent+=nutri[i];
				}
			}
			subtotal*=100.0/(100.0-percent);
			if(FatinPercent) Fat+=subtotal*nutri[0]/100;
			else Fat+=nutri[0];
			total+=subtotal;
		}
		if(total<1e-6) break;
		printf("%.0lf%%\n",Fat/total*100);
	}
	return 0;
}
