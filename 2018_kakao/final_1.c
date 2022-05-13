#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRST_RATE 1.0000000000
#define SECONDE_RATE 0.7500000000
#define THIRD_RATE 0.5000000000
#define FORTH_RATE 0.3333333333
#define FIFTH_RATE 0.2500000000
#define ZERO_RATE 0.0000000000
typedef struct team
{
	char name[10];
	double total_point;
	double rate;
}TEAM;

int compare(const void *a, const void *b){
	TEAM *x = (TEAM *)a;
	TEAM *y = (TEAM *)b;
	return x->total_point > y->total_point ? 0 : 1;
}

int main()
{
	TEAM team[4];
	TEAM buff[4];

	scanf("%s %s %s %s", team[0].name, team[1].name, team[2].name, team[3].name );
	memcpy(buff[0].name, team[0].name, 10);
	memcpy(buff[1].name, team[1].name, 10);
	memcpy(buff[2].name, team[2].name, 10);
	memcpy(buff[3].name, team[3].name, 10);

	for(int i =0; i<6; i++){
		char team1[10], team2[10];
		double win, draw, lose;
		scanf("%s %s %lf %lf %lf", team1, team2, &win, &draw, &lose);
		if (!strcmp(team[0].name, team1)){
			team[0].total_point += win*3 + draw * 1; // + lose * 0
				
		}	
		if (!strcmp(team[1].name, team1)){
			team[1].total_point += win*3 + draw * 1; // + lose * 0
		}	
		if (!strcmp(team[2].name, team1)){
			team[2].total_point += win*3 + draw * 1; // + lose * 0
		}	
		if (!strcmp(team[3].name, team1)){
			team[3].total_point += win*3 + draw * 1; // + lose * 0
		}
		if (!strcmp(team[0].name, team2)){
			team[0].total_point += draw * 1 + lose * 3; // + win * 0
		}
		if (!strcmp(team[1].name, team2)){
			team[1].total_point += draw * 1 + lose * 3; // + win * 0
		}		
		if (!strcmp(team[2].name, team2)){
			team[2].total_point += draw * 1 + lose * 3; // + win * 0
		}	
		if (!strcmp(team[3].name, team2)){
			team[3].total_point += draw * 1 + lose * 3; // + win * 0
		}
	}
		
	//for (int i =0; i<4; i++)
	//{
	//	printf ("%s %lf\n", team[i].name, team[i].total_point);
	//}
	qsort(team, 4, sizeof(TEAM), compare);
	
	if (team[0].total_point == team[1].total_point){
		if (team[1].total_point == team[2].total_point){
			if (team[2].total_point == team[3].total_point){
				team[0].rate = FIFTH_RATE;
				team[1].rate = FIFTH_RATE;
				team[2].rate = FIFTH_RATE;
				team[3].rate = FIFTH_RATE;
			}
			else {
				team[0].rate = SECONDE_RATE;
				team[1].rate = SECONDE_RATE;
				team[2].rate = SECONDE_RATE;
				team[3].rate = ZERO_RATE;
			}
		}
		else {
			team[0].rate = FIRST_RATE;
			team[1].rate = FIRST_RATE;
			team[2].rate = ZERO_RATE;
			team[3].rate = ZERO_RATE;
		}
	}
	else {
		if (team[1].total_point == team[2].total_point){
			if (team[2].total_point == team[3].total_point){
				team[0].rate = FIRST_RATE;
				team[1].rate = SECONDE_RATE;
				team[2].rate = SECONDE_RATE;
				team[3].rate = SECONDE_RATE;
			}
			else{
				team[0].rate = FIRST_RATE;
				team[1].rate = THIRD_RATE;
				team[2].rate = THIRD_RATE;
				team[3].rate = ZERO_RATE;
			}
		}
		else {
			team[0].rate = FIRST_RATE;
			team[1].rate = FIRST_RATE;
			team[2].rate = ZERO_RATE;
			team[3].rate = ZERO_RATE;
		}
	}

	for (int i =0; i<4; i++)
	{
		for (int j = 0; j < 4; j++){
			if (!strcmp(buff[i].name, team[j].name)) {
				printf ("%s %lf\n", team[j].name, team[j].rate);
			}
		}
	}



	return 0;
}
