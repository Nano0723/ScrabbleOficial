#include <iostream>
#include <time.h>





char jugador1[7];
char jugador2[7];
char jugador3[7];
char jugador4[7];


//funcion que asigna las letras de forma aleatoria
void opa(char letter[]){

    int i = 0;
    //genera i cantidad de fichas
    while (i<7) {

        int num = 1 + rand() % (30 - 1);


        if (num == 1) letter[i]= 'A';
        if (num == 2) letter[i]= 'B';
        if (num == 3) letter[i]= 'C';
        if (num == 4) letter[i]= 'D';
        if (num == 5) letter[i]= 'E';
        if (num == 6) letter[i]= 'F';
        if (num == 7) letter[i]= 'G';
        if (num == 8) letter[i]= 'H';
        if (num == 9) letter[i]= 'I';
        if (num == 10) letter[i]= 'J';
        if (num == 11) letter[i]= 'K';
        if (num == 12) letter[i]= 'L';
        if (num == 13) letter[i]= 'M';
        if (num == 14) letter[i]= 'N';
        if (num == 15) letter[i]= '0';
        if (num == 16) letter[i]= 'O';
        if (num == 17) letter[i]= 'P';
        if (num == 18) letter[i]= 'Q';
        if (num == 19) letter[i]= 'R';
        if (num == 20) letter[i]= 'S';
        if (num == 21) letter[i]= 'T';
        if (num == 22) letter[i]= 'U';
        if (num == 23) letter[i]= 'V';
        if (num == 24) letter[i]= 'W';
        if (num == 25) letter[i]= 'X';
        if (num == 26) letter[i]= 'Y';
        if (num == 27) letter[i]= 'Z';
        if (num == 28) letter[i]= '2';
        if (num == 29) letter[i]= '4';
        if (num == 30) letter[i]= '6';

        i++;



    }
}

int main() {
    srand(time(NULL));
    int i = 0;

    opa(jugador1);
    opa(jugador2);
    opa(jugador3);
    opa(jugador4);


    while (i<7){
        printf("%c,", jugador1[i]);
        i++;
    }
    printf("\n");

    i = 0;

    while (i<7){
        printf("%c,", jugador2[i]);
        i++;
    }
    printf("\n");



    return 0;
}