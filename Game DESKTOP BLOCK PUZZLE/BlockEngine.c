#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "BlockEngine.h"

/*int grille[10][10];={
    //{0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,1,0,0,1,0,0},
    //{0,0,0,1,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    //{0,0,0,1,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    //{0,0,0,1,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    //{0,0,0,1,0,0,1,0,0,0},
    {0,0,0,0,1,0,0,1,0,0},
    {0,0,0,0,1,0,0,1,0,0}
};*/

//propsedBlock prpBlck[3];
extern
unsigned int SCORE=0;
possib* block_1x1_Poss=NULL;
possib* block_1x2_Poss=NULL;
possib* block_1x3_Poss=NULL;
possib* block_L_3_Poss=NULL;
possib* block_2x2_Poss=NULL;
possib* block_T_3_Poss=NULL;
possib* block_4x1_Poss=NULL;
possib* block_5x1_Poss=NULL;
possib* block_L_5_Poss=NULL;
possib* block_E_5_Poss=NULL;
possib* block_3x3_Poss=NULL;

void afficheGrille(){
    printf("--------------------\n");
        int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(grille[i][j]){
                printf("O|");
            }else{
                printf(".|");
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}

int canFit(const int blk){
    switch(blk){
        case block_1x1:
        return canFitBlock_1x1();
        break;
        case block_1x2:
        return canFitBlock_1x2();
        break;
        case block_1x3:
        return canFitBlock_1x3();
        break;
        case block_L_3:
        return canFitBlock_L_3();
        break;
        case block_2x2:
        return canFitBlock_2x2();
        break;
        case block_T_3:
        return canFitBlock_T_3();
        break;
        case block_4x1:
        return canFitBlock_4x1();
        break;
        case block_5x1:
        return canFitBlock_5x1();
        break;
        case block_L_5:
        return canFitBlock_L_5();
        break;
        case block_E_5:
        return canFitBlock_E_5();
        break;
        case block_3x3:
        return canFitBlock_3x3();
        break;
        default:
            return -1;
        break;
    }
}

int canFitBlock_1x1(){
    int res=0;
    resetPoss(&block_1x1_Poss);
      int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(grille[i][j]==0){
                addPoss(i,j,&block_1x1_Poss);
                res++;
            }
        }
    }
    return res;
}

int canFitBlock_1x2(){
    int res=0;
    resetPoss(&block_1x2_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(j<9){
                if(grille[i][j]==0 && grille[i][j+1]==0){
                    addPoss(i,j,&block_1x2_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_1x3(){
    int res=0;
    resetPoss(&block_1x3_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(j<8){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0){
                    addPoss(i,j,&block_1x3_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_L_3(){
    int res=0;
    resetPoss(&block_L_3_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<9 && j<9){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j+1]==0){
                    addPoss(i,j,&block_L_3_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_2x2(){
    int res=0;
    resetPoss(&block_2x2_Poss);
     int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<9 && j<9){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0){
                    addPoss(i,j,&block_2x2_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_T_3(){
    int res=0;
    resetPoss(&block_T_3_Poss);
     int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<8 && j<9){
                if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0 && grille[i+2][j]==0){
                    addPoss(i,j,&block_T_3_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_4x1(){
    int res=0;
    resetPoss(&block_4x1_Poss);
      int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<7){
                if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+2][j]==0 && grille[i+3][j]==0){
                    addPoss(i,j,&block_4x1_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_5x1(){
    int res=0;
    resetPoss(&block_5x1_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<6){
                if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+2][j]==0 && grille[i+3][j]==0 && grille[i+4][j]==0){
                    addPoss(i,j,&block_5x1_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_L_5(){
    int res=0;
    resetPoss(&block_L_5_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<8 && j<8){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0 && grille[i+1][j+2]==0 && grille[i+2][j+2]==0){
                    addPoss(i,j,&block_L_5_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_E_5(){
    int res=0;
    resetPoss(&block_E_5_Poss);
     int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<8 && j<9){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j+1]==0 && grille[i+2][j]==0 && grille[i+2][j+1]==0){
                    addPoss(i,j,&block_E_5_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_3x3(){
    int res=0;
    resetPoss(&block_3x3_Poss);
       int i=0;
  for(;i<=9;i++){
            int j=0;
        for(;j<=9;j++){
            if(i<8 && j<8){
                if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0 && grille[i+1][j+2]==0 && grille[i+2][j]==0 && grille[i+2][j+1]==0 && grille[i+2][j+2]==0){
                    addPoss(i,j,&block_3x3_Poss);
                    res++;
                }
            }
        }
    }
    return res;
}

int canFitBlock_1x1_XY(const int i,const int j){
    if(i<=9 && j<= 9){
        if(grille[i][j]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_1x2_XY(const int i,const int j){
    if(i<=9 && j<9){
        if(grille[i][j]==0 && grille[i][j+1]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_1x3_XY(const int i,const int j){
    if(i<=9 && j<8){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_L_3_XY(const int i,const int j){
    if(i<9 && j<9){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j+1]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_2x2_XY(const int i,const int j){
    if(i<9 && j<9){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_T_3_XY(const int i,const int j){
    if(i<8 && j<9){
        if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0 && grille[i+2][j]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_4x1_XY(const int i,const int j){
    if(i<7 && j<=9){
        if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+2][j]==0 && grille[i+3][j]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_5x1_XY(const int i,const int j){
    if(i<6 && j<=9){
        if(grille[i][j]==0 && grille[i+1][j]==0 && grille[i+2][j]==0 && grille[i+3][j]==0 && grille[i+4][j]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_L_5_XY(const int i,const int j){
    if(i<8 && j<8){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0 && grille[i+1][j+2]==0 && grille[i+2][j+2]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

int canFitBlock_E_5_XY(const int i,const int j){
    if(i<8 && j<9){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i+1][j+1]==0 && grille[i+2][j]==0 && grille[i+2][j+1]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

}

int canFitBlock_3x3_XY(const int i,const int j){
    if(i<8 && j<8){
        if(grille[i][j]==0 && grille[i][j+1]==0 && grille[i][j+2]==0 && grille[i+1][j]==0 && grille[i+1][j+1]==0 && grille[i+1][j+2]==0 && grille[i+2][j]==0 && grille[i+2][j+1]==0 && grille[i+2][j+2]==0){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

void addPoss(const int i,const int j,possib** L){
    if((*L)==NULL){
        (*L)=(possib *)malloc(sizeof(possib));
        (*L)->suiv=NULL;
        (*L)->i=i;
        (*L)->j=j;
    }else{
        possib* buff;
        buff=(*L);
        while(buff->suiv!=NULL) buff=buff->suiv;
        buff->suiv=(possib *)malloc(sizeof(possib));
        buff->suiv->suiv=NULL;
        buff->suiv->i=i;
        buff->suiv->j=j;
    }
}

void resetPoss(possib **L){
    if((*L)!=NULL){
        resetPoss(&((*L)->suiv));
        free((*L));
        (*L)=NULL;
    }
}

possib* blockToList(const int blk){
    switch(blk){
        case block_1x1:
            return block_1x1_Poss;
        break;
        case block_1x2:
            return block_2x2_Poss;
        break;
        case block_1x3:
            return block_1x3_Poss;
        break;
        case block_L_3:
            return block_L_3_Poss;
        break;
        case block_2x2:
            return block_2x2_Poss;
        break;
        case block_T_3:
            return block_T_3_Poss;
        break;
        case block_4x1:
            return block_4x1_Poss;
        break;
        case block_5x1:
            return block_5x1_Poss;
        break;
        case block_L_5:
            return block_L_5_Poss;
        break;
        case block_E_5:
            return block_E_5_Poss;
        break;
        case block_3x3:
            return block_3x3_Poss;
        break;
        default :
            return NULL;
        break;
    }
}

int insertBlock(const int i, const int j, const int choice_blk){
    if(!(choice_blk>=1 && choice_blk<=3)){
        printf("TYPE DE BLOCK INVALIDE\n");
        return -1;
    }
    int res;
    printf("%d",prpBlck[choice_blk-1].blockType);
    switch(prpBlck[choice_blk-1].blockType){
        case block_1x1:
            if(canFitBlock_1x1_XY(i,j)){
                grille[i][j]=1;
                res = 1;
                SCORE += 10;
            }else{
                res = -1;
            }
        break;
        case block_1x2:
            if(canFitBlock_1x2_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                res = 1;
                SCORE += 20;
            }else{
                res = -1;
            }
        break;
        case block_1x3:
            if(canFitBlock_1x3_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i][j+2]=1;
                res = 1;
                SCORE += 30;
            }else{
                res = -1;
            }
        break;
        case block_L_3:
            if(canFitBlock_L_3_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i+1][j+1]=1;
                res = 1;
                SCORE += 30;
            }else{
                res = -1;
            }
        break;
        case block_2x2:
            if(canFitBlock_2x2_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i+1][j]=1;
                grille[i+1][j+1]=1;
                res = 1;
                SCORE += 40;
            }else{
                res = -1;
            }
        break;
        case block_T_3:
            if(canFitBlock_T_3_XY(i,j)){
                grille[i][j]=1;
                grille[i+1][j]=1;
                grille[i+1][j+1]=1;
                grille[i+2][j]=1;
                res = 1;
                SCORE += 40;
            }else{
                res = -1;
            }
        break;
        case block_4x1:
            if(canFitBlock_4x1_XY(i,j)){
                    printf("fuck aye");
                grille[i][j]=1;
                grille[i+1][j]=1;
                grille[i+2][j]=1;
                grille[i+3][j]=1;
                res = 1;
                SCORE += 40;
            }else{
                res = -1;
            }
        break;
        case block_5x1:
            if(canFitBlock_5x1_XY(i,j)){
                grille[i][j]=1;
                grille[i+1][j]=1;
                grille[i+2][j]=1;
                grille[i+3][j]=1;
                grille[i+4][j]=1;
                res = 1;
                SCORE += 50;
            }else{
                res = -1;
            }
        break;
        case block_L_5:
            if(canFitBlock_L_5_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i][j+2]=1;
                grille[i+1][j+2]=1;
                grille[i+2][j+2]=1;
                res = 1;
                SCORE += 50;
            }else{
                res = -1;
            }
        break;
        case block_E_5:
            if(canFitBlock_E_5_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i+1][j+1]=1;
                grille[i+2][j]=1;
                grille[i+2][j+1]=1;
                SCORE += 50;
                res = 1;
            }else{
                res = -1;
            }
        break;
        case block_3x3:

            if(canFitBlock_3x3_XY(i,j)){
                grille[i][j]=1;
                grille[i][j+1]=1;
                grille[i][j+2]=1;
                grille[i+1][j]=1;
                grille[i+1][j+1]=1;
                grille[i+1][j+2]=1;
                grille[i+2][j]=1;
                grille[i+2][j+1]=1;
                grille[i+2][j+2]=1;
                SCORE += 90;
                res = 1;
            }else{
                res = -1;
            }
        break;
        default:
            printf("DEFAULT---------------------------\n)");
            return -1;
        break;
    }
    refreshGrille();
    if(res==1) updatePrpBlock(choice_blk);
    return res;
}

int refreshGrille(){
    int L=0;
    int L_a_supp[10]={0};
    int C_a_supp[10]={0};
    int i=0;
    int j=0;
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            if(grille[i][j]==1){
                L++;
            }
        }
        if(L==10){
            L_a_supp[i]=1;
        }
        L=0;
    }
    L=0;
    for(j=0;j<=9;j++){
        for(i=0;i<=9;i++){
            if(grille[i][j]==1){
                L++;
            }
        }
        if(L==10){
            C_a_supp[j]=1;
        }
        L=0;
    }
    int score=0;
    int mul=1;
    for(i=0;i<=9;i++){
        if(L_a_supp[i]==1){
            for(j=0;j<=9;j++){
                grille[i][j]=0;
            }
            score=score+(mul*100);
            mul++;
            if(mul==6) mul=1;
        }
    }
    if(mul==6) mul=1;
    for(j=0;j<=9;j++){
        if(C_a_supp[j]==1){
            for(i=0;i<=9;i++){
                grille[i][j]=0;
            }
            score=score+(mul*100);
            mul++;
            if(mul==6) mul=1;
        }
    }
    SCORE+=score;
    return score;
}

int init_game(){
    SCORE = 0;
    int i =0;
    for(i=0;i<=9;i++){
        int j=0;
        for(;j<=9;j++){
            grille[i][j]=0;
        }
    }
    updatePrpBlock(1);
    updatePrpBlock(2);
    updatePrpBlock(3);
}

void updatePrpBlock(const int in_choice){
    int tab_blk_res[8]={0};
    int exist=0;
    int in_blk=1;
    int i=0;
    for(;i<=7;i++){
        int j=0;
        for(;j<=2;j++){
            if(in_blk==prpBlck[j].blockType){
                exist=1;
            }
        }
        if(!exist){
            tab_blk_res[i]=in_blk;
        }else i--;
        in_blk++;
        exist=0;
    }
    int nv_blk=tab_blk_res[(rand()%8)];
    if(in_choice>=1 && in_choice<=3){
        prpBlck[in_choice-1].blockType=nv_blk;
    }
     i=0;
    for(;i<=2;i++){
        if(canFit(prpBlck[i].blockType)){
            prpBlck[i].isBlocked=0;
        }else{
            prpBlck[i].isBlocked=1;
        }
    }
}
///////////////////////TESTING FUNCTIONS

void fillGrille(){
    int i=0;
    for(;i<=9;i++){
        int j=0;
        for(;j<=9;j++){
            grille[i][j]=(rand() % 2);
        }
    }
}

void printList(possib* L){
    if(L==NULL){
        printf("LISTE VIDE\n");
        return;
    }
    possib* buff;
    buff=L;
    int i=0;
    while(buff!=NULL){
        i++;
        printf("%d:(%d,%d)|",i,buff->i,buff->j);
        buff=buff->suiv;
    }
    printf("\n");
}

void printPrpBlck(){
    int i=0;
    for(;i<=2;i++){
        printf("[%d,%d]|",prpBlck[i].blockType,prpBlck[i].isBlocked);
    }
    printf("\n");
}

void printStat(){
    afficheGrille();
    printPrpBlck();
    printf("SCORE : %d\n",SCORE);
    printf("---------------\n");
}

int choose(){
    char rep[3];
    int choice=0;
    int i=0,j=0;
    while(canFit(prpBlck[0].blockType) || canFit(prpBlck[1].blockType) || canFit(prpBlck[2].blockType)){
        //printStat();
        printf("Quel Bloc : ");fgets(rep,3,stdin);
        choice = atoi(rep);
        printf("OU -> X : ");fgets(rep,3,stdin);i=atoi(rep);
        printf("OU -> Y : ");fgets(rep,3,stdin);j=atoi(rep);
        insertBlock(i,j,choice);
    }
}

void saveGame(){
    FILE *savedGame;
    savedGame = fopen("savedGame.txt","w+");
    fprintf(savedGame,"%d\n",SCORE);
    int i,j;
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            fprintf(savedGame,"%d\t",grille[i][j]);
        }
        fprintf(savedGame,"\n");
    }
    for(i=0;i<=2;i++){
        fprintf(savedGame,"%d\t",prpBlck[i].blockType);
    }
    fclose(savedGame);
}

int loadGame(){
    FILE* loadedGame;
    loadedGame=NULL;
    loadedGame = fopen("savedGame.txt","r");
    if(loadedGame==NULL){
        return 0; // FICHIER NON EXISTANT
    }
    fscanf(loadedGame,"%d\n",&SCORE);
    int i,j;
    for(i=0;i<=9;i++){
        for(j=0;j<=9;j++){
            fscanf(loadedGame,"%d\t",&grille[i][j]);
        }
        fscanf(loadedGame,"\n");
    }
    for(i=0;i<=2;i++){
        fscanf(loadedGame,"%d\t",&prpBlck[i].blockType);
        if(canFit(prpBlck[i].blockType)){
            prpBlck[i].isBlocked=0;
        }else{
            prpBlck[i].isBlocked=1;
        }
    }
    fclose(loadedGame);
    return 1;
}

int updateBestScore(const char *name,const int score){
    FILE *bestScoreF;
    bestScoreF=NULL;
    bestScoreF = fopen("BestScore.txt","r");
    int po=0;
    for(po=0;po<=4;po++){
        strcmp(bestScore[po].name,"");
        bestScore[po].score = 0;
        bestScore[po].day= 0;
        bestScore[po].month=0;
        bestScore[po].year = 0;
    }
    if(bestScoreF==NULL){
        //Ficher de best score n'existe pas... on le cree
        bestScoreF = fopen("BestScore.txt","w");
    }else{
        fclose(bestScoreF);
        bestScoreF = fopen("BestScore.txt","a+");
    }
    rewind(bestScoreF);
    int i=0;
    char ligne[100];
    while(fgets(ligne,100,bestScoreF)){
        sscanf(ligne,"%s\t%d\t%d/%d/%d",bestScore[i].name,&(bestScore[i].score),&(bestScore[i].day),&(bestScore[i].month),&(bestScore[i].year));
        i++;
    }
    if(i>0){//fichier non vide
        int j=0;
        while(j<=4 && score<=bestScore[j].score){
            j++;
        }
        if(j<=4){
            int in;
            for(in=4;in>=j;in--){
                bestScore[in].score=bestScore[in-1].score;
                strcpy(bestScore[in].name,bestScore[in-1].name);
                bestScore[in].day=bestScore[in-1].day;
                bestScore[in].month=bestScore[in-1].month;
                bestScore[in].year=bestScore[in-1].year;
            }
        }
        bestScore[j].score=score;
        strcpy(bestScore[j].name,name);
        time_t now = time(0);
        struct tm tmNow=*(localtime(&now));
        bestScore[j].day=tmNow.tm_mday;
        bestScore[j].month=tmNow.tm_mon+1;
        bestScore[j].year=tmNow.tm_year+1900;
    }else if(i==0){//fichier vide
        bestScore[0].score=score;
        strcpy(bestScore[0].name,name);
        time_t now = time(0);
        struct tm tmNow=*(localtime(&now));
        bestScore[0].day=tmNow.tm_mday;
        bestScore[0].month=tmNow.tm_mon+1;
        bestScore[0].year=tmNow.tm_year+1900;
    }
    fclose(bestScoreF);
    bestScoreF=fopen("BestScore.txt","w+");
    i=0;
    while(i<=4 && strcmp(bestScore[i].name,"\0")!=0){
        fprintf(bestScoreF,"%s\t%d\t%d/%d/%d\n",bestScore[i].name,bestScore[i].score,bestScore[i].day,bestScore[i].month,bestScore[i].year);
        i++;
    }
    fclose(bestScoreF);
    return 1;
}
