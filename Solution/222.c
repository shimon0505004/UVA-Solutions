#include<stdio.h>
#include<math.h>
#define EPS (1e-5)
#define SIZE 1000
#define MIN(a,b) ((a)<(b)?(a):(b))
int queue[SIZE],head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int res=queue[tail++];
	tail%=SIZE;
	return res;
}
char is_empty(){
	return head==tail;
}
struct GAS_STA{
	double dis,ppg;
};
int main(){
	double dis;
	double cap,mpg,cost[55];
	int n_gas,i;
	struct GAS_STA gas[55];
	int cases;
	for(cases=1;scanf("%lf",&dis),dis>-EPS;cases++){
		scanf("%lf%lf%lf%d",&cap,&mpg,&cost[0],&n_gas);
		n_gas++;
		for(i=1;i<=n_gas;i++) cost[i]=1e10;
		gas[0].dis=0,gas[i].ppg=0;
		for(i=1;i<n_gas;i++) scanf("%lf%lf",&gas[i].dis,&gas[i].ppg);
		gas[n_gas].dis=dis;
		initial();
		enqueue(0);
		while(!is_empty()){
			int cur=dequeue();
			double c;
			for(i=cur+1;i<n_gas;i++){
				double usage=(gas[i].dis-gas[cur].dis)/mpg;
				if(usage>cap) break;
				if(usage*2<cap){
					if((gas[i+1].dis-gas[cur].dis)*mpg>cap){
						c=cost[cur]+floor(usage*gas[i].ppg+0.5)/100+2;
						if(cost[i]>c){
							cost[i]=c;
							enqueue(i);
						}
					}
				}else{
					c=cost[cur]+floor(usage*gas[i].ppg+0.5)/100+2;
					if(cost[i]>c){
						cost[i]=c;
						enqueue(i);
					}
				}
			}
		}
		for(i=n_gas-1;i>=0;i--){
			double usage=(gas[n_gas].dis-gas[i].dis)/mpg;
			if(usage>cap) break;
			cost[n_gas]=MIN(cost[i],cost[n_gas]);
		}
		printf("Data Set #%d\n",cases);
		printf("minimum cost = $%.2lf\n",cost[n_gas]);
	}
	return 0;
}
