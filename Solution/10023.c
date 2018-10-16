#include<stdio.h>
#include<string.h>
#define MAXD 1003
struct BigNum{
	char n[MAXD];
	int d;
};
void assign(struct BigNum *dest,struct BigNum *src){
	memcpy(dest,src,sizeof(struct BigNum));
}
void initial(struct BigNum *n){
	memset(n->n,0,sizeof(n->n));
	n->d=0;
}
int compar(struct BigNum *n1,struct BigNum *n2){
	int i;
	if(n1->d>n2->d) return 1;
	if(n1->d<n2->d) return -1;
	for(i=n1->d;i>=0;i--){
		if(n1->n[i]>n2->n[i]) return 1;
		else if(n1->n[i]<n2->n[i]) return -1;
	}
	return 0;
}
void add(struct BigNum *dest,struct BigNum *src){
	int i,d_max=dest->d>src->d?dest->d:src->d;
	struct BigNum tmp;
	assign(&tmp,dest);
	for(i=0;i<d_max;i++){
		tmp.n[i]+=src->n[i];
		if(tmp.n[i]>=10){
			tmp.n[i+1]++;
			tmp.n[i]-=10;
		}
	}
	assign(dest,&tmp);
	dest->d=d_max;
	if(dest->n[d_max]>0) dest->d++;
}
void subtract(struct BigNum *dest,struct BigNum *src){
	int i;
	for(i=1;i<=dest->d;i++){
		dest->n[i-1]=dest->n[i-1]+10-src->n[i-1];
		if(dest->n[i-1]>=10) dest->n[i-1]-=10;
		else dest->n[i]--;
	}
	for(i=dest->d-1;i>=0&&dest->n[i]==0;i--);
	dest->d=i+1;
}
void printBigNum(struct BigNum *bignum){
	int i;
	for(i=bignum->d-1>0?bignum->d-1:0;i>=0;i--) printf("%d",bignum->n[i]);
	puts("");
}
void multiply_by_ten(struct BigNum *bn){
	memmove((bn->n)+1,bn->n,sizeof(char[MAXD-1]));
	bn->n[0]=0;
	if(bn->d>0) bn->d++;
}
void multiply_by_twenty(struct BigNum *bn){
	struct BigNum tmp;
	assign(&tmp,bn);
	add(bn,&tmp);
	multiply_by_ten(bn);
}
void multiply_by_hundred(struct BigNum *bn){
	memmove((bn->n)+2,bn->n,sizeof(char[MAXD-2]));
	bn->n[0]=bn->n[1]=0;
	if(bn->d>0) bn->d+=2;
}
void add_int(struct BigNum *bn,int n){
	int i;
	bn->n[0]+=n;
	for(i=1;i<=bn->d&&bn->n[i-1]>10;i++)
		bn->n[i]++,bn->n[i-1]-=10;
	if(bn->n[bn->d]>0) bn->d++;
}
int main(){
	int cases,start,count;
	char input[MAXD];
	struct BigNum odd,answer,remain;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",input+1);
		input[0]='0';
		if(strlen(input)%2==0) start=0;
		else start=1;
		initial(&remain),initial(&answer);
		for(;input[start];start+=2){
			assign(&odd,&answer);
			multiply_by_twenty(&odd);
			add_int(&odd,1);
			multiply_by_hundred(&remain);
			remain.n[0]=input[start+1]-'0';
			remain.n[1]=input[start]-'0';
			if(remain.d<2){
				if(remain.n[1]) remain.d=2;
				else if(remain.n[0]) remain.d=1;
			}
			count=0;
			for(count=0;compar(&remain,&odd)>=0;count++){
				subtract(&remain,&odd);
				add_int(&odd,2);
			}
			multiply_by_ten(&answer);
			add_int(&answer,count);
		}
		printBigNum(&answer);
		if(cases) puts("");
	}
	return 0;
}
