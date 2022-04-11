#include <stdio.h>
int main(void){

#define MATH_INDEX 0
#define PHYSICS_INDEX 1
#define NUMBER_OF_STUDNETS 5

//初期データ作成
int studentA[2] = {72,48};
int studentB[2] = {88,39};
int studentC[2] = {72,91};
int studentD[2] = {81,82};
int studentE[2] = {68,78};

int score_list[NUMBER_OF_STUDNETS][2] = {
    
    {studentA[MATH_INDEX],studentA[PHYSICS_INDEX]},
    {studentB[MATH_INDEX],studentB[PHYSICS_INDEX]},
    {studentC[MATH_INDEX],studentC[PHYSICS_INDEX]},
    {studentD[MATH_INDEX],studentD[PHYSICS_INDEX]},
    {studentE[MATH_INDEX],studentE[PHYSICS_INDEX]},
};

//数学の合計点、最高点、最低点数を格納する変数。
int sum_math_score = 0;
int math_max_score= 0;
int math_min_score = 100;

//物理の合計点、最高点、最低点数を格納する変数。
int sum_physics_score = 0;
int physics_max_score = 0;
int physics_min_score = 100;

//数学＋物理の最も高い合計点を格納する変数。
int best_score = 0;

for(int i = 0; i < NUMBER_OF_STUDNETS; i++) {
    sum_math_score += score_list[i][MATH_INDEX];
    sum_physics_score += score_list[i][PHYSICS_INDEX];
    
    if( best_score < (score_list[i][MATH_INDEX] + score_list[i][PHYSICS_INDEX]) ){
        best_score = (score_list[i][MATH_INDEX] + score_list[i][PHYSICS_INDEX]);
    }
    
	for(int j = 0; j < 2; j++) {
		if(j == MATH_INDEX) {
			if(score_list[i][j] > math_max_score){
			    math_max_score = score_list[i][j];
			}
			if(score_list[i][j] < math_min_score){
			    math_min_score = score_list[i][j];
			}
		}
		if(j == PHYSICS_INDEX){
		    if(score_list[i][j] > physics_max_score){
		        physics_max_score = score_list[i][j];
			}
		}
		if(score_list[i][j] < physics_min_score){
		    physics_min_score = score_list[i][j];
		}
	}
};

printf("数学の最高点は、%d点\n",math_max_score);
printf("数学の最低点は、%d点\n",math_min_score);
printf("数学の平均点は、%.1f点\n",(float)sum_math_score/NUMBER_OF_STUDNETS);

printf("物理の最高点は、%d点\n",physics_max_score);
printf("物理の最低点は、%d点\n",physics_min_score);
printf("物理の平均点は、%.1f点\n",(float)sum_physics_score/NUMBER_OF_STUDNETS);

printf("数学と物理の合計点が最も高い生徒の点数は、%d点\n",best_score);

}
