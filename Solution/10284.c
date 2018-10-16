#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char chessboard[12][12];
	char isfight[12][12],fight;
	int i,j,len,count,count2;
	char input[100],*tokenPtr;
	while(1){
		if(scanf("%s",input)!=1) break;
		memset(chessboard,'-',sizeof(chessboard));
		memset(isfight,'-',sizeof(isfight));
		for(tokenPtr=strtok(input,"/"),count=2;tokenPtr!=NULL;tokenPtr=strtok(NULL,"/"),count++){
			len=strlen(tokenPtr);
			for(i=0,j=2;i<len;i++)
				if(isalpha(tokenPtr[i])){
					chessboard[count][j]=tokenPtr[i];
					isfight[count][j++]='#';
				}
				else
					j+=tokenPtr[i]-'0';
		}
#ifdef DEBUG
		for(i=0;i<=11;i++)
			printf("%.12s\n",chessboard[i]);
		printf("\n");
#endif
		for(i=2;i<10;i++)
			for(j=2;j<10;j++){
				fight=chessboard[i][j];
				if(!isalpha(fight)) continue;
				switch(tolower(fight)){
					case 'p':
						if(islower(fight)){
							isfight[i+1][j-1]='#';
							isfight[i+1][j+1]='#';
						}
						else{
							isfight[i-1][j-1]='#';
							isfight[i-1][j+1]='#';
						}
						break;
					case 'q':
					case 'r':
						for(count=i-1;count>=0;count--){
							if(isalpha(chessboard[count][j])) break;
							isfight[count][j]='#';
						}
						for(count=i+1;count<12;count++){
							if(isalpha(chessboard[count][j])) break;
							isfight[count][j]='#';
						}
						for(count=j-1;count>=0;count--){
							if(isalpha(chessboard[i][count])) break;
							isfight[i][count]='#';
						}
						for(count=j+1;count<12;count++){
							if(isalpha(chessboard[i][count])) break;
							isfight[i][count]='#';
						}
					case 'b':
						if(tolower(fight)=='r') break;
						for(count=1;i-count>=0&&j-count>=0;count++){
							if(isalpha(chessboard[i-count][j-count])) break;
							isfight[i-count][j-count]='#';
						}
						for(count=1;i+count<12&&j-count>=0;count++){
							if(isalpha(chessboard[i+count][j-count])) break;
							isfight[i+count][j-count]='#';
						}
						for(count=1;i-count>=0&&j+count<12;count++){
							if(isalpha(chessboard[i-count][j+count])) break;
							isfight[i-count][j+count]='#';
						}
						for(count=1;i+count<12&&j+count<12;count++){
							if(isalpha(chessboard[i+count][j+count])) break;
							isfight[i+count][j+count]='#';
						}
						break;
					case 'k':
						for(count=-1;count<2;count++)
							for(count2=-1;count2<2;count2++)
								isfight[i+count][j+count2]='#';
						break;
					case 'n':
						isfight[i+2][j+1]='#';
						isfight[i+2][j-1]='#';
						isfight[i+1][j+2]='#';
						isfight[i+1][j-2]='#';
						isfight[i-2][j+1]='#';
						isfight[i-2][j-1]='#';
						isfight[i-1][j+2]='#';
						isfight[i-1][j-2]='#';
						break;
				}
			}
#ifdef DEBUG
		for(i=0;i<=11;i++)
			printf("%.12s\n",isfight[i]);
		printf("\n");
#endif
		for(i=2,count=0;i<10;i++)
			for(j=2;j<10;j++)
				if(isfight[i][j]!='#') count++;
		printf("%d\n",count);
	}
	return 0;
}
