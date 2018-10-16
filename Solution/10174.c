#include<stdio.h>
int main()
{
	char input[50];
	int a,b,NorP,range;
	int flag;
	while(fgets(input,50,stdin)!=NULL){
		flag=sscanf(input,"%d%d",&a,&b);
		if(flag==1){
			if(!a)
				puts("0 0");
			else{
				NorP=(a>0?1:-1);
				if(a<0) a*=-1;
				switch(a%4){
					case 0:
						printf("%d %d\n",a/4+NorP,a/4-NorP);
						break;
					case 1:
					case 3:
						printf("%d %d\n",(a+NorP)/2,(a-NorP)/2);
						break;
					case 2:
						puts("Bachelor Number.");
						break;
				}
			}
		}
		else{
			range=b-a+1;
			switch(range%4){
				case 0:
					printf("%d\n",range/4);
					break;
				case 1:
					if(b%4==2)
						printf("%d\n",(range+3)/4);
					else
						printf("%d\n",(range-1)/4);
					break;
				case 2:
					switch(b%4){
						case 0:
						case 1:
							printf("%d\n",(range-2)/4);
							break;
						case 2:
						case 3:
							printf("%d\n",(range+2)/4);
							break;
					}
					break;
				case 3:
					if(b%4==1)
						printf("%d\n",(range-3)/4);
					else
						printf("%d\n",(range+1)/4);
					break;
			}
		}
	}
	return 0;
}
