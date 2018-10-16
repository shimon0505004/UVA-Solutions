#include<stdio.h>
#include<string.h>
int compar(char n1[],char n2[]){
	return strcmp(n1,n2);
}
void subtract(char n1[],char n2[]){
	int i;
	for(i=30;i>0;i--){
		n1[i]=n1[i]+10-n2[i]+'0';
		n1[i-1]+=(n1[i]-'0')/10-1;
		n1[i]=(n1[i]-'0')%10+'0';
	}
	n1[0]=n1[0]-n2[0]+'0';
}
int main(){
	char pow_2[101][32],Hanoi[32];
	int i,j,n;
	int peg[3],now,left,right;
	memset(pow_2,'0',sizeof(pow_2));
	for(i=0;i<=100;i++) pow_2[i][31]=0;
	pow_2[0][30]='1';
	for(i=1;i<=100;i++){
		for(j=30;j>0;j--){
			pow_2[i][j]+=(pow_2[i-1][j]-'0')*2;
			pow_2[i][j-1]+=(pow_2[i][j]-'0')/10;
			pow_2[i][j]=(pow_2[i][j]-'0')%10+'0';
		}
		pow_2[i][0]+=(pow_2[i-1][0]-'0')*2;
	}
	for(i=0;i<=100;i++) pow_2[i][30]--;
	while(scanf("%d%s",&n,Hanoi),n){
		int len=strlen(Hanoi);
		memmove(Hanoi+31-len,Hanoi,sizeof(char[len+1]));
		memset(Hanoi,'0',31-len);
		peg[0]=n,peg[1]=peg[2]=0;
		now=0,left=2,right=1;
		for(i=100;i>=0;i--){
			int comp=compar(Hanoi,pow_2[i]);
			if(comp>0){
				subtract(Hanoi,pow_2[i]);
				subtract(Hanoi,pow_2[1]);
				peg[now]-=i+1;
				if(i%2==0){
					peg[right]++;
					peg[left]+=i;
					now=left;
				}else{
					peg[left]++;
					peg[right]+=i;
					now=right;
				}
				left=(now+2)%3,right=(now+1)%3;
			}else if(comp==0){
				subtract(Hanoi,pow_2[i]);
				peg[now]-=i;
				if(i%2==0)
					peg[left]+=i;
				else
					peg[right]+=i;
			}
			if(compar(Hanoi,pow_2[0])==0) break;
		}
		printf("%d %d %d\n",peg[0],peg[1],peg[2]);
	}
	return 0;
}
