#include<stdio.h>
int main()
{
	char chargingstep;
	char telnum[10];
	int starth,startm,endh,endm,startmins,endmins;
	int passmidnight;
	int daymin,eveningmin,nightmin;
	double rate[3][5]={{0.10,0.25,0.53,0.87,1.44},{0.06,0.15,0.33,0.47,0.80},{0.02,0.05,0.13,0.17,0.30}};
	double cost;
	while(1){
		scanf(" %c",&chargingstep);
		if(chargingstep=='#') break;
		scanf("%s%d%d%d%d",telnum,&starth,&startm,&endh,&endm);
		passmidnight=daymin=eveningmin=nightmin=0;
		startmins=starth*60+startm;
		endmins=endh*60+endm;
		if(startmins>=endmins)
			passmidnight=1;
		if(passmidnight){
			if((startmins)*(startmins-8*60)<0||(startmins==0)){
				nightmin=8*60-startmins;
				startmins=8*60;
			}
			if((startmins-8*60)*(startmins-18*60)<0||(startmins==8*60)){
				daymin=18*60-startmins;
				startmins=18*60;
			}
			if((startmins-18*60)*(startmins-22*60)<0||(startmins==18*60)){
				eveningmin=22*60-startmins;
				startmins=22*60;
			}
			nightmin+=24*60-startmins;
			if((endmins-24*60)*(endmins-22*60)<0||(endmins==24*60)){
				nightmin+=endmins-22*60;
				endmins=22*60;
			}
			if((endmins-22*60)*(endmins-18*60)<0||(endmins==22*60)){
				eveningmin+=endmins-18*60;
				endmins=18*60;
			}
			if((endmins-18*60)*(endmins-8*60)<0||(endmins==18*60)){
				daymin+=endmins-8*60;
				endmins=8*60;
			}
			nightmin+=endmins;
		}
		else{
			if((endmins-8*60)*(startmins-8*60)<0||(endmins==8*60)){
				nightmin=8*60-startmins;
				startmins=8*60;
			}
			if((endmins-18*60)*(startmins-18*60)<0||endmins==18*60){
				daymin+=18*60-startmins;
				startmins=18*60;
			}
			if((endmins-22*60)*(startmins-22*60)<0||endmins==22*60){
				eveningmin+=22*60-startmins;
				startmins=22*60;
			}
			if(endmins<8*60&&startmins<8*60)
				nightmin+=endmins-startmins;
			else if((endmins-8*60)*(endmins-18*60)<0){
				if((startmins-8*60)*(startmins-18*60)<0||startmins==8*60)
					daymin=endmins-startmins;
			}
			else if((endmins-18*60)*(endmins-22*60)<0){
				if((startmins-18*60)*(startmins-22*60)<0||startmins==18*60)
					eveningmin+=endmins-startmins;
			}
			else if((endmins-24*60)*(endmins-22*60)<0)
				if((startmins-22*60)*(startmins-24*60)<0||startmins==22*60)
					nightmin+=endmins-startmins;
		}
		cost=(double)daymin*rate[0][chargingstep-'A'];
		cost+=(double)eveningmin*rate[1][chargingstep-'A'];
		cost+=(double)nightmin*rate[2][chargingstep-'A'];
		printf("%10s%6d%6d%6d%3c%8.2lf\n",telnum,daymin,eveningmin,nightmin,chargingstep,cost);

	}
	return 0;
}
