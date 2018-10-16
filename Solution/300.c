#include<stdio.h>
#include<string.h>
char *Haab_month[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char *Tzolkin_month[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int name_to_month(char mon[]){
	int m;
	for(m=0;strcmp(Haab_month[m],mon)!=0;m++);
	return m;
}
int getHaab(){
	int d,m,y;
	char mon[10];
	scanf("%d%*c %s %d",&d,mon,&y);
	m=name_to_month(mon);
	return y*365+m*20+d;
}
void days_to_Tzolkin(int days,int *y,int *m,int *d){
	*y=days/260;
	days%=260;
	*m=days%20;
	*d=days%13+1;
}
int main(){
	int cases,days;
	int y,m,d;
	scanf("%d",&cases);
	printf("%d\n",cases);
	while(cases--){
		days=getHaab();
		days_to_Tzolkin(days,&y,&m,&d);
		printf("%d %s %d\n",d,Tzolkin_month[m],y);
	}
	return 0;
}
