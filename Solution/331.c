#include<stdio.h>
struct seq{
	int s[5];
	int size;
};
int bubblesort(struct seq s){
	int i,j,temp,count=0;
	for(i=0;i<s.size-1;i++)
		for(j=0;j<(s.size-1-i);j++)
			if(s.s[j]>s.s[j+1])
				temp=s.s[j],s.s[j]=s.s[j+1],s.s[j+1]=temp,count++;
	return count;
}
int recursion(struct seq s,int count,int now){
	int temp,result,i;
	if(s.s[now]>s.s[now+1]){
		if(count==1) return 1;
		temp=s.s[now],s.s[now]=s.s[now+1],s.s[now+1]=temp;
		result=0;
		for(i=0;i<s.size-1;i++)
			result+=recursion(s,count-1,i);
		return result;
	}
	return 0;
}
int main()
{
	int i,count,cases=0,result;
	struct seq s;
	while(scanf("%d",&(s.size))==1&&s.size){
		for(i=0;i<s.size;i++)
			scanf("%d",&(s.s[i]));
		count=bubblesort(s);
		result=0;
		for(i=0;i<s.size-1;i++)
			result+=recursion(s,count,i);
		printf("There are %d swap maps for input data set %d.\n",result,++cases);
	}
	return 0;
}
