#include<stdio.h>
#include<math.h>
int main()
{
	int cath,wcats,catsinhat,toth,totn,tot,i,j,temp;
	float d;
	while(1){
		scanf("%d%d",&cath,&wcats);
		if(cath+wcats==0) break;
		if(cath==1){
			printf("0 1\n");
			continue;
		}
		else if(wcats==1){
			printf("%.f %d\n",log10(cath)/log10(2),cath*2-1);
			continue;
		}
		else{
			for(i=1;i<32;i++){
				d=(float)1/i;
				catsinhat=pow(cath,d);
				catsinhat--;
				temp=pow(catsinhat,i);
				if(temp==wcats){
					totn=0;
					toth=cath;
					tot=cath;
					for(j=0;j<i;j++)
						totn+=pow(catsinhat,j);
					for(j=0;j<i;j++){
						toth/=(catsinhat+1);
						toth*=catsinhat;
						tot+=toth;
					}
					printf("%d %d\n",totn,tot);
					break;
				}
			}
		}
	}
	return 0;
}
