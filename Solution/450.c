#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PROFILE{
	char Title[30];
	char FirstName[30],LastName[30];
	char HomeAddress[55];
	char *Department;
	char HomePhone[55],WorkPhone[35];
	char CampusBox[35];
};
int compar(const void *a,const void *b){
	struct PROFILE *p1=(struct PROFILE *)a,*p2=(struct PROFILE *)b;
	return strcmp(p1->LastName,p2->LastName);
}
void printFaculty(struct PROFILE *p){
	puts("----------------------------------------");
	printf("%s %s %s\n",p->Title,p->FirstName,p->LastName);
	printf("%s\n",p->HomeAddress);
	printf("Department: %s\n",p->Department);
	printf("Home Phone: %s\n",p->HomePhone);
	printf("Work Phone: %s\n",p->WorkPhone);
	printf("Campus Box: %s\n",p->CampusBox);
}
int main(){
	struct PROFILE p[5000];
	int deps,i,faculty=0;
	char department[12][65];
	char input[300];
	scanf("%d ",&deps);
	for(i=0;i<deps;i++){
		fgets(department[i],65,stdin);
		department[i][strlen(department[i])-1]=0;
		while(fgets(input,300,stdin)!=NULL&&*input!='\n'){
			sscanf(input,"%[^,]%*c%[^,]%*c%[^,]%*c%[^,]%*c%[^,]%*c%[^,]%*c%s",
				p[faculty].Title,p[faculty].FirstName,p[faculty].LastName,
				p[faculty].HomeAddress,p[faculty].HomePhone,p[faculty].WorkPhone,
				p[faculty].CampusBox);
			p[faculty].Department=department[i];
			faculty++;
		}
	}
	qsort(p,faculty,sizeof(struct PROFILE),compar);
	for(i=0;i<faculty;i++)
		printFaculty(&p[i]);
	return 0;
}
