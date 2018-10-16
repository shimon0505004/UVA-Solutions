#include<stdio.h>
#include<string.h>
int find(char Gene[][35],char name[35],int *count){
	int i;
	for(i=1;i<*count;i++) if(strcmp(Gene[i],name)==0) return i;
	strcpy(Gene[*count],name);
	return (*count)++;
}
int main(){
	char Gene[305][35];
	char name1[35],name2[35];
	int map[305]={0};
	int p1,p2,count=1,i,t1,t2,c1,c2,degree;
	while(scanf("%s%s",name1,name2),strcmp(name1,"no.child")){
		p1=find(Gene,name1,&count);
		p2=find(Gene,name2,&count);
		map[p1]=p2;
	}
	while(scanf("%s%s",name1,name2)==2){
		p1=find(Gene,name1,&count);
		p2=find(Gene,name2,&count);
		for(t1=p1,c1=0;map[t1];t1=map[t1],c1++);
		for(t2=p2,c2=0;map[t2];t2=map[t2],c2++);
		if(t1!=t2){
			puts("no relation");
			continue;
		}else if(c1>c2){
			for(i=0,t1=p1;i<c1-c2;t1=map[t1],i++);
			if(t1==p2){
				degree=c1-c2;
				while(degree>2) printf("great "),degree--;
				if(degree==2) printf("grand ");
				printf("child\n");
				continue;
			}else{
				for(t2=p2,i=0;t2!=t1;i++,t1=map[t1],t2=map[t2]);
				printf("%d cousin removed %d\n",i-1,c1-c2);
			}
		}else if(c2>c1){
			for(i=0,t2=p2;i<c2-c1;t2=map[t2],i++);
			if(t2==p1){
				degree=c2-c1;
				while(degree>2) printf("great "),degree--;
				if(degree==2) printf("grand ");
				printf("parent\n");
				continue;
			}else{
				for(t1=p1,i=0;t2!=t1;i++,t1=map[t1],t2=map[t2]);
				printf("%d cousin removed %d\n",i-1,c2-c1);
			}
		}else{
			for(t1=p1,t2=p2,i=0;t1!=t2;i++,t1=map[t1],t2=map[t2]);
			i--;
			if(i) printf("%d cousin\n",i);
			else puts("sibling");
		}
	}
	return 0;
}
