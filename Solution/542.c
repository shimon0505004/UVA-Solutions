#include<stdio.h>
#define TEAMS 16
int main(){
	int i,j,k,l;
	char name[TEAMS][15];
	double against_prob[TEAMS][TEAMS];
	double win_prob[5][TEAMS];
	for(i=0;i<TEAMS;i++) scanf("%s",name[i]);
	for(i=0;i<TEAMS;i++)
		for(j=0;j<TEAMS;j++)
			scanf("%lf",&against_prob[i][j]);
	for(i=0;i<TEAMS;i++) win_prob[0][i]=1.0;
	for(i=0;i<4;i++){
		int g=2<<i,h_g=g>>1;
		for(j=0;j<TEAMS;j+=g){
			for(k=j;k<j+h_g;k++){
				double tmp_prob=0;
				for(l=j+h_g;l<j+g;l++)
					tmp_prob+=win_prob[i][l]*against_prob[k][l]/100;
				win_prob[i+1][k]=win_prob[i][k]*tmp_prob;
			}
			for(k=j+h_g;k<j+g;k++){
				double tmp_prob=0;
				for(l=j;l<j+h_g;l++)
					tmp_prob+=win_prob[i][l]*against_prob[k][l]/100;
				win_prob[i+1][k]=win_prob[i][k]*tmp_prob;
			}
		}
	}
	for(i=0;i<TEAMS;i++)
		printf("%-10s p=%.2lf%%\n",name[i],win_prob[4][i]*100);
	return 0;
}
