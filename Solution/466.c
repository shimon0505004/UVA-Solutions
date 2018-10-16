#include<stdio.h>
#include<string.h>
char preserved(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[i][j]!=orig[i][j])
				return 0;
	return 1;
}
char rotated_90(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[j][n-i-1]!=orig[i][j])
				return 0;
	return 1;
}
char rotated_180(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[n-i-1][n-j-1]!=orig[i][j])
				return 0;
	return 1;
}
char rotated_270(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[n-j-1][i]!=orig[i][j])
				return 0;
	return 1;
}
char vertical(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[n-i-1][j]!=orig[i][j])
				return 0;
	return 1;
}
char vertical_90(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[j][i]!=orig[i][j])
				return 0;
	return 1;
}
char vertical_180(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[i][n-j-1]!=orig[i][j])
				return 0;
	return 1;
}
char vertical_270(int n,char orig[][15],char tran[][15]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(tran[n-j-1][n-i-1]!=orig[i][j])
				return 0;
	return 1;
}
int main(){
	int n,cases,i;
	char orig[15][15],tran[15][15];
	for(cases=1;scanf("%d",&n)==1;cases++){
		for(i=0;i<n;i++) scanf("%s%s",orig[i],tran[i]);
		printf("Pattern %d was ",cases);
		if(preserved(n,orig,tran)) puts("preserved.");
		else if(rotated_90(n,orig,tran)) puts("rotated 90 degrees.");
		else if(rotated_180(n,orig,tran)) puts("rotated 180 degrees.");
		else if(rotated_270(n,orig,tran)) puts("rotated 270 degrees.");
		else if(vertical(n,orig,tran)) puts("reflected vertically.");
		else if(vertical_90(n,orig,tran)) puts("reflected vertically and rotated 90 degrees.");
		else if(vertical_180(n,orig,tran)) puts("reflected vertically and rotated 180 degrees.");
		else if(vertical_270(n,orig,tran)) puts("reflected vertically and rotated 270 degrees.");
		else puts("improperly transformed.");
	}
	return 0;
}
