#include<stdio.h>
#include<string.h>
char name[65][25];
int n_name=0;
int GCD(int a,int b){
	int temp;
	while(a%b!=0) temp=a,a=b,b=temp%b;
	return b;
}
int find_name(char fname[]){
	int i;
	for(i=0;i<n_name;i++) if(strcmp(name[i],fname)==0) return i;
	strcpy(name[n_name],fname);
	return n_name++;
}
int main(){
	char instr;
	char name1[25],name2[25];
	char relation[65][65]={{0}};
	int rate[65][65][2];
	int n1,n2,p1,p2;
	int i,j,k;
	while(scanf(" %c",&instr),instr!='.'){
		if(instr=='!'){
			int gcd;
			scanf("%d%s %*c%d%s",&p1,name1,&p2,name2);
			gcd=GCD(p1,p2);
			n1=find_name(name1),n2=find_name(name2);
			relation[n1][n2]=relation[n2][n1]=1;
			rate[n1][n2][0]=p1/gcd,rate[n1][n2][1]=p2/gcd;
			rate[n2][n1][0]=p2/gcd,rate[n2][n1][1]=p1/gcd;
		}else if(instr=='?'){
			scanf("%s %*c%s",name1,name2);
			n1=find_name(name1),n2=find_name(name2);
			for(k=0;k<n_name;k++)
				for(i=0;i<n_name;i++)
					for(j=0;j<i;j++){
						if(relation[i][k]&&relation[k][j]){
							int gcd1=GCD(rate[i][k][1],rate[k][j][0]);
							int a=rate[i][k][0]*(rate[k][j][0]/gcd1);
							int b=rate[k][j][1]*(rate[i][k][1]/gcd1);
							int gcd2=GCD(a,b);
							relation[i][j]=relation[j][i]=1;
							rate[i][j][0]=a/gcd2,rate[i][j][1]=b/gcd2;
							rate[j][i][0]=b/gcd2,rate[j][i][1]=a/gcd2;
						}
					}
			if(relation[n1][n2]) printf("%d %s = %d %s\n",rate[n1][n2][0],name1,rate[n1][n2][1],name2);
			else printf("? %s = ? %s\n",name1,name2);
		}
	}
	return 0;
}
