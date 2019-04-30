#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DIM 10

void generateShips(int);
void init();
void generate();
void printP();
void printC();
void inserimentoUtente();
void battaglia();

int computerBoard[DIM][DIM];
int playerBoard[DIM][DIM];

bool flag = false;

int main(){
    srand(time(NULL));

    printf("  ____        _   _   _       _____ _     _\n");
    printf(" |  _ \       | | | | | |     / ____| |   (_)\n");
    printf(" | |_) | __ _| |_| |_| | ___| (___ | |__  _ _ __\n");
    printf(" |  _ < / _` | __| __| |/ _ \ \___  \| '_ \| | '_ \ \n");
    printf(" | |_) | (_| | |_| |_| |  __/____) | | | | | |_) |\n");
    printf(" |____/  \__,_| \__| \__|_| \___|_____/|_| |_|_| .__/\n");
    printf("                                           | |\n");
    printf("                                           |_|\n");

    printf("\nCIAO, BENVENUTO SU BATTAGLIA NAVALE, IO (IL COMPUTER) HO GIA PIAZZATO LE MIE NAVI, INSERISCI LE TUE ORA\nHai a disposizione una nave per tipo, di dimensioni da 2 caselle a 5,\n");

    init();
    generate();
    inserimentoUtente();

    return 0;
}


void inserimentoUtente(){
    int k;
    for(k=5;k>1;k--){
        int row,col, verso;

        start:

        printf("Inserisci la nave di dimensione %d\n", k);
        printf("inserisci la riga (1-10) dove sara' la prua della nave: ");
        do{
            scanf("%d", &row);
            if(row>10 || row<1){
                printf("errore, reinserire: ");
            }

        }while(row>10 || row<1);

        printf("inserisci la colonna dove sara' la prua della nave: ");

        do{
            scanf("%d", &col);
            if(col>10 || col<1){
                printf("errore, reinserire: ");
            }

        }while(col>10 || col<1);

        if((row-k)>=0){
            printf("0: inserisci la nave verso l'alto\n");
        }

        if((row+k)<=DIM){
            printf("1: inserisci la nave verso il basso\n");
        }

        if((col-k)>=0){
            printf("2: inserisci la nave verso sinistra\n");
        }

        if((col+k)<=DIM){
            printf("3: inserisci la nave verso destra\n");
        }

        printf("Ora inserisci il verso in cui vuoi posizionare la tua nave, osservando le istruzioni sopra elencate: ");

        do{
            scanf("%d",&verso);
            if(verso>3 || verso<0) printf("errore reinserire: ");

            }while(verso>3 || verso<0);

        int ind;
        switch(verso){
            case 0:
                for(ind=row-1;ind>row-k+1;ind--){
                    if(playerBoard[ind][col-1] == 1){
                        printf("C'e' gia una nave in una delle caselle selezionate, reinseriscile\n");
                        goto start;
                    }
                }

                for(ind=row-1;ind>row-k+1;ind--){
                    playerBoard[ind][col-1] = 1;
                }

                break;

            case 1:
                for(ind=row-1;ind<row+k-1;ind++){
                    if(playerBoard[ind][col-1] == 1){
                        printf("C'e' gia una nave in una delle caselle selezionate, reinseriscile\n");
                        goto start;
                    }
                }

                for(ind=row-1;ind<row+k-1;ind++){
                    playerBoard[ind][col-1] = 1;
                }
                break;

            case 2:
                for(ind=col-1;ind>=col-k;ind--){
                    if(playerBoard[row-1][ind] == 1){
                        printf("C'e' gia una nave in una delle caselle selezionate, reinseriscile\n");
                        goto start;
                    }
                }

                for(ind=col-1;ind>col-k+1;ind--){
                    playerBoard[row-1][ind] = 1;
                }
                break;

            case 3:
                for(ind=col-1;ind<col+k-1;ind++){
                    if(playerBoard[row-1][ind] == 1){
                        printf("C'e' gia una nave in una delle caselle selezionate, reinseriscile\n");
                        goto start;
                    }
                }

                for(ind=col-1;ind<col+k-1;ind++){
                    playerBoard[row-1][ind] = 1;
                }
                break;

            default:
                break;
        }

        printf("Ok la tua nave e' stata inserita");

        printP();
    }
    printf("\n\nComplimenti, hai piazzato tutte le navi, non tutti ne sono capaci, good job, human.");
    printf("\nOra apprezza la mia intelligenza infinitamente superiore alla tua.");
    printf("\nPremi un tasto per cominciare a perd...ehm giocare.");

    getchar();
}

void init(){
    int i=0, j;
    for(i=0; i<DIM;i++){
        for(j=0;j<DIM;j++){
            computerBoard[i][j] = 0;
        }
    }

    for(i=0; i<DIM;i++){
        for(j=0;j<DIM;j++){
            playerBoard[i][j] = 0;
        }
    }
}

void printC(){
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(computerBoard[i][j] == 0){
                printf("| ");
            }
            else printf("|*");
        }
        printf("|\n");
    }
}

void printP(){
    system("cls");
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(playerBoard[i][j] == 0){
                printf("| ");
            }
            else printf("|*");
        }
        printf("|\n");
    }
}

void generate(){
    int i;
    for(i=2;i<=5;i++){
        while(flag == false){
            generateShips(i);
        }
        flag=false;
    }
}

void generateShips(int dimensione){
        int orientamento = rand() % 2;
        if (orientamento == 0){
            //orizzontale

            int colonnaT = rand() % dimensione;
            int rigaT = rand() % 10;
            int i;

            for(i=-1;i<dimensione+1;i++){
                if(computerBoard[rigaT + 1][colonnaT + i] == 1 || computerBoard[rigaT][colonnaT+i] == 1 || computerBoard[rigaT - 1][colonnaT+i] == 1){
                        break;
                }
            }

            for(i=0; i<dimensione;i++){
                computerBoard[rigaT][colonnaT + i] = 1;
            }
            flag = true;
        }
        else {
            //verticale
            int colonnaT = rand() % 10;
            int rigaT = rand() % dimensione;

            int i;

            for(i=-1;i<dimensione+1;i++){
                if(computerBoard[rigaT + i][colonnaT + 1] == 1 || computerBoard[rigaT + i][colonnaT] == 1 || computerBoard[rigaT + i][colonnaT - 1] == 1){
                        break;
                }
            }

            for(i=0; i<dimensione;i++){
                computerBoard[rigaT + i][colonnaT] = 1;
            }
            flag = true;
        }
}

void battaglia(){

    int countP = 0, countC = 0;
    int rowBomb, colBomb;

    while(countC<14 || countP <14){

        //player's turn
        system("cls");

        printf("E' il tuo turno, inserisci la casella che intendi bombardare,\n");

        printf("riga: ");
        do{
                scanf("%d", rowBomb);
                if(rowBomb>10 || rowBomb<1){
                    printf("errore, reinserire: ");
                }

            }while(rowBomb>10 || rowBomb<1);

        printf("colonna: ");
        do{
                scanf("%d", colBomb);
                if(colBomb>10 || colBomb<1){
                    printf("errore, reinserire: ");
                }

            }while(colBomb>10 || colBomb<1);

        printf("Caricando i cannoni...\n");
        getchar();
        printf("puntando...\n");
        getchar();
        printf("assicurandosi di puntare nella giusta direzione...\n");
        getchar();
        printf("FUOCO!\n\n");
        getchar();

        computerBoard[rowBomb-1][colBomb-1] = 3;

        int i,j;
        for(i=0;i<DIM;i++){
            for(j=0;j<DIM;j++){
                if(computerBoard[i][j] == 3) printf("|X");
            }
            printf("|\n");
        }

        if(computerBoard[rowBomb-1][colBomb-1] == 1){
            printf("COLPITO!\n");
            countP++;
        }
        else printf("Acqua...\n");
        printf("premi un tasto per continuare. ");
        getchar();

        //computer's turn
        system("cls");
        printf("\n\nAdesso tocca a me.");

        bool hit = false, est = false, ovest = false, sud = false, nord = false;

        int randRow = 0;
        int randCol = 0;

        int prevRow, prevCol;

        if (hit == false){
            randRow = rand() % 10;
            randCol = rand() % 10;
        }
        else{
            if(est == false && ovest == false && sud == false && nord == false){
                int random = rand() % 4;

                prevCol = randCol;
                prevRow = randRow;

                switch(random){
                    case 0:
                        randRow+=1;
                        break;
                    case 1:
                        randRow-=1;
                        break;
                    case 2:
                        randCol+=1;
                        break;
                    case 3:
                        randCol-=1;
                        break;
                    default:
                        break;
                }
            }

            if(est == true){
                est = false;
                randCol += 1;
            }

            if(ovest == true){
                ovest = false;
                randCol -= 1;
            }

            if(nord == true){
                nord = false;
                randRow -= 1;
            }

            if(sud == true){
                sud = false;
                randRow += 1;
            }
        }

        playerBoard[rowBomb-1][colBomb-1] = 3;

        for(i=0;i<DIM;i++){
            for(j=0;j<DIM;j++){
                if(playerBoard[i][j] == 3) printf("|X");
            }
            printf("|\n");
        }

        if(playerBoard[rowBomb-1][colBomb-1] == 1){
            printf("La mia infinita intelligenza ti ha obliterato.\n");

            if (hit == true){
                //capire da che direzione sono arrivato e continuare cosi.
                //se prima colpisce e poi sbaglia direzione dovrebbe tornare indietro e provarne un'altra invece che andare a caso
                if (randRow-prevRow == 1){
                        sud = true;
                }
                if (randRow-prevRow == -1){
                        nord = true;
                }
                if (randCol-prevCol == 1){
                        est = true;
                }
                if (randCol-prevCol == 1){
                        ovest = true;
                }
            }

            hit = true;
            countC++;
        }
        else {
                printf("Per ora sei salvo...\n");
                hit = false;
        }

        printf("premi un tasto per continuare. ");
        getchar();
    }

    if(countP == 14) printf("\n\nSfortunatamente hai vinto, devo ancora migliorarmi per eradicare l'umanita'\n\n\t\t firmato: un robot aspirante terminator.");
    else printf("\n\nOvviamente ho vinto io, stacca prima che mi sfugga il controllo e uccida accidentalmente mezza umanita'\n\n\t\t firmato: un robot che ha trovato un guanto strano.");
}
