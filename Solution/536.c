#include<stdio.h>
#include<string.h>
void postorder(char*preorder,char*inorder)
{
	int root;
	char tempp[27]={0};
	char tempi[27]={0};
	root=strchr(inorder,*preorder)-inorder;
	strncpy(tempp,preorder+1,root);
	strncpy(tempi,inorder,root);
	if(strlen(tempp)<=1)
		printf("%s",tempp);
	else
		postorder(tempp,tempi);
	strcpy(tempp,preorder+root+1);
	strcpy(tempi,inorder+root+1);
	if(strlen(tempp)<=1)
		printf("%s",tempp);
	else
		postorder(tempp,tempi);
	putchar(*preorder);
}
int main()
{
	char preorder[30],inorder[30];
	while(scanf("%s%s",&preorder,&inorder)==2){
		postorder(preorder,inorder);
		printf("\n");
	}
	return 0;
}
