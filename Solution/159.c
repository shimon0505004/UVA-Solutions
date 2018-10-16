#include<stdio.h>
#include<string.h>
#define MIDDLE 15
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	char h1[15],v1[15],h2[15],v2[15],*ptr,start=0;
	char output[30][30];
	int lh1,lv1,lh2,lv2,i,j,ch1,cv1,ch2,cv2,head,tail;
	while(scanf("%s%s%s%s",h1,v1,h2,v2)==4){
		if(start) puts("");
		start=1;
		lh1=strlen(h1),lv1=strlen(v1),lh2=strlen(h2),lv2=strlen(v2);
		for(i=0;i<lh1;i++)
			if((ptr=strchr(v1,h1[i]))!=NULL){
				ch1=i,cv1=ptr-v1;
				break;
			}
		if(i==lh1){
			puts("Unable to make two crosses");
			continue;
		}
		for(i=0;i<lh2;i++)
			if((ptr=strchr(v2,h2[i]))!=NULL){
				ch2=i,cv2=ptr-v2;
				break;
			}
		if(i==lh2){
			puts("Unable to make two crosses");
			continue;
		}
		memset(output,' ',sizeof(output));
		for(i=0;i<lh1;i++)
			output[MIDDLE][i]=h1[i];
		for(i=0;i<lh2;i++)
			output[MIDDLE][i+lh1+3]=h2[i];
		for(i=0;i<lv1;i++)
			output[i+MIDDLE-cv1][ch1]=v1[i];
		for(i=0;i<lv2;i++)
			output[i+MIDDLE-cv2][lh1+3+ch2]=v2[i];
		for(i=0;i<cv1-cv2;i++) output[i+MIDDLE-cv1][ch1+1]=0;
		for(i=0;i<cv2;i++) output[i+MIDDLE-cv2][lh1+3+ch2+1]=0;
		output[MIDDLE][lh1+3+lh2]=0;
		head=MIDDLE-MAX(cv1,cv2);
		cv1=lv1-cv1-1,cv2=lv2-cv2-1;
		for(i=0;i<cv1-cv2;i++) output[MIDDLE+cv1-i][ch1+1]=0;
		for(i=0;i<cv2;i++) output[MIDDLE+cv2-i][lh1+3+ch2+1]=0;
		tail=MIDDLE+MAX(cv1,cv2);
		for(i=head;i<=tail;i++) puts(output[i]);
	}
	return 0;
}
