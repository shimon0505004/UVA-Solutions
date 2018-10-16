#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ITEM{
	char name[15];
	double buyat,sellat;
	int onhand;
};
int find_item(struct ITEM item[],int n_item,char name[]){
	int i;
	for(i=0;i<n_item;i++) if(strcmp(name,item[i].name)==0) return i;
	return -1;
}
int compar(const void *a,const void *b){
	struct ITEM *i1=(struct ITEM *)a,*i2=(struct ITEM *)b;
	return strcmp(i1->name,i2->name);
}
int main(){
	struct ITEM item[105];
	int n_item=0;
	char instr[10],name[15];
	double profit=0,totvalue;
	int index,i;
	int quantity;
	while(scanf("%s",instr),*instr!='*'){
		switch(*instr){
			case 'n':
				scanf("%s%lf%lf",item[n_item].name,&item[n_item].buyat,&item[n_item].sellat);
				item[n_item].onhand=0;
				n_item++;
				break;
			case 'd':
				scanf("%s",name);
				index=find_item(item,n_item,name);
				profit-=item[index].buyat*item[index].onhand;
				item[index]=item[--n_item];
				break;
			case 'b':
				scanf("%s%d",name,&quantity);
				index=find_item(item,n_item,name);
				item[index].onhand+=quantity;
				break;
			case 's':
				scanf("%s%d",name,&quantity);
				index=find_item(item,n_item,name);
				profit+=(item[index].sellat-item[index].buyat)*quantity;
				item[index].onhand-=quantity;
				break;
			case 'r':
				printf("%34s\n","INVENTORY REPORT");
				printf("%-14s%-12s%-13s%-15s%s\n","Item Name","Buy At","Sell At","On Hand","Value");
				printf("%-14s%-12s%-13s%-15s%s\n","---------","------","-------","-------","-----");
				qsort(item,n_item,sizeof(struct ITEM),compar);
				totvalue=0;
				for(i=0;i<n_item;i++){
					double value;
					value=item[i].buyat*item[i].onhand;
					printf("%-10s%10.2lf%13.2lf%13d%13.2lf\n",item[i].name,item[i].buyat,item[i].sellat,item[i].onhand,value);
					totvalue+=value;
				}
				puts("------------------------");
				printf("Total value of inventory%35.2lf\n",totvalue);
				printf("Profit since last report%35.2lf\n",profit);
				profit=0;
				puts("");
				break;
		}
	}
	return 0;
}
