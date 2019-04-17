#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIM 10

void generateShips(int, int);

bool computerBoard[DIM][DIM];
bool playerBoard[DIM][DIM];

int main()
{
    // cinque = 1, quattro = 2, tre = 3, due = 2;
    int i=0, j;
    for(i=0; i<DIM;i++){
        for(j=0;j<DIM;j++){
            computerBoard[i][j] = 0;
        }
    }










    generateShips(1, 5);
    generateShips(2, 4);
    generateShips(3, 3);
    generateShips(2, 2);

    printf("SALVE, BENVENUTO SU BATTAGLIA NAVALE: \n");
    //printf("");

    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(computerBoard[i][j] == 0){
                    printf("0 ");
            }
            else printf("1 ");
        }
        printf("\n\n");
    }

}


void generateShips(int numeroNavi, int dimensione){
    int k;
    for(k=0; k<numeroNavi; k++){
        int casuale = rand() % 2;
        if (casuale == 0){
            //orizzontale

            int colonnaT = rand() % dimensione;
            int rigaT = rand() % 10;
            int i;

            for(i=0;i<dimensione;i++){
                if(computerBoard[rigaT][colonnaT+i] == 1){
                    generateShips(numeroNavi, dimensione);
                }
            }

            for(i=0; i<dimensione;i++){
                computerBoard[rigaT][colonnaT + i] = 1;
            }
        }
        else {
            //verticale
            int colonnaT = rand() % 10;
            int rigaT = rand() % dimensione;
            printf("%d", rigaT);
            printf("%d", colonnaT);

            int i;

            for(i=0;i<dimensione;i++){
                if(computerBoard[rigaT + i][colonnaT] == 1){
                    generateShips(numeroNavi, dimensione);
                }
            }

            for(i=0; i<dimensione;i++){
                computerBoard[rigaT + i][colonnaT] = 1;
            }
        }
    }
}
