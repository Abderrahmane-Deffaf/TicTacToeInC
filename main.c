#include <stdio.h>
#include <stdlib.h>
const char choice1 = 'x';
const char choice2 = 'o' ;
int player = 1 ; // we intialize the player to 1 to begain with the first player

char matrice[11][11] = {{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{' ','1',' ','|',' ','2',' ','|',' ','3',' '}
,{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
{' ','4',' ','|',' ','5',' ','|',' ','6',' '},{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},{'_','_','_','_','_','_','_','_','_','_','_'},{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '},
{' ','7',' ','|',' ','8',' ','|',' ','9',' '},{' ',' ',' ','|',' ',' ',' ','|',' ',' ',' '}} ; // we fill the matrix with its required values
void display() ; // to display the content of the matrix
int checkvalidc (char  c , int b  ) ;
int checkwin ()  ; // to check if there is a win
int boardfull() ; // to check if the board are filled to test if we can add a new values
void clearboard( int x ) ; // to reset the board to its required values to play a second round
int main()
{
    char x  ; // it will be the value entered by the players from 1 to 9
    int y = 0  ; // to check if the player wanna to play a second round or not
   // here we have our main loop
    do {
                clearboard(y) ;
   int player = 1 ;
     // here we have the loop to enter the values under some conditions
     while (boardfull()) {
    system("cls");
         display() ;
        // here we have the loop if the user enter a false values
        do {
                system("cls");
        display() ;
            printf("player %d enter a valid number please ", player) ;
            scanf("%c",&x) ;
        } while(checkvalidc(x, player) == 0 ) ;
        if (checkwin() == 1 ) {
            break ;
        }
        player = player % 2 + 1 ;
     }
     system("cls");
     display() ;
     if (checkwin()== 1 ) {
             printf("\n \t\t player %d win !! \n" , player) ;
     } else if (!boardfull()) {
     printf("\n\t\t it's draw \n ") ;
     }
       printf("do you wanna to play again ? enter --1-- if --yes-- or enter --0-- if --no-- ") ;
     scanf ("%d",&y);
  } while (y == 1 ) ;
    return 0;
}
void display() {
        printf("\n\n\t\t tic tac toe \n\n") ;
        printf("\n\n\t player 1 (x) , player 2 (o) \n\n") ;

  for (int i=0 ; i<11 ; i++) {
                  printf("\t\t");
    for (int j = 0 ; j< 11 ; j++) {
        printf("%c",matrice[i][j]) ;
    }
    printf("\n");
  }
}
int checkvalidc (char c , int b   ) {
    char x ;
if (c == matrice[1][1] || c == matrice[1][5] || c == matrice[1][9] || c == matrice[5][1] || c == matrice[5][5] || c == matrice[5][9] || c == matrice[9][1] || c == matrice[9][5]
    || c == matrice[9][9] ) {
        if (b == 1 ) {
                        x = choice1 ;

        }
        else {
                        x = choice2 ;

        }
        if (c == matrice[1][1]) {
            matrice[1][1] = x ;
                return 1 ;

        } else if ( c == matrice[1][5]) {
           matrice[1][5] = x ;
               return 1 ;

        } else if ( c == matrice[1][9]) {
          matrice[1][9] = x ;
              return 1 ;

        } else if ( c == matrice[5][1]) {
        matrice[5][1] = x ;
            return 1 ;

        } else if (c == matrice[5][5]) {
          matrice[5][5] = x ;
              return 1 ;

        } else if (c == matrice[5][9]) {
        matrice[5][9] = x ;
            return 1 ;

        } else if (c == matrice[9][1]) {
        matrice[9][1] = x ;
            return 1 ;

        } else if ( c == matrice[9][5] ) {
        matrice[9][5] = x ;
            return 1 ;

        } else if (c == matrice[9][9]) {
        matrice[9][9] = x ;
            return 1 ;

        }
    }

        else {
               return 0  ;

        }
}
int checkwin ()  {
    if ((matrice[1][1] == matrice[5][1]) && (matrice[5][1] == matrice[9][1]) ) {
        matrice[0][1] = '|' ;
        matrice[2][1] = '|' ;
        matrice[4][1] = '|' ;
        matrice[6][1] = '|' ;
        matrice[8][1] = '|' ;
        matrice[10][1] = '|' ;
    return 1 ;
    } else if ((matrice[1][5] == matrice[5][5] )&& (matrice[5][5] == matrice[9][5]) ){
     matrice[0][5] = '|' ;
        matrice[2][5] = '|' ;
        matrice[4][5] = '|' ;
        matrice[6][5] = '|' ;
        matrice[8][5] = '|' ;
        matrice[10][5] = '|' ;
    return 1 ;
    } else if ((matrice[1][9] == matrice[5][9]) && (matrice[5][9] == matrice[9][9])) {
     matrice[0][9] = '|' ;
        matrice[2][9] = '|' ;
        matrice[4][9] = '|' ;
        matrice[6][9] = '|' ;
        matrice[8][9] = '|' ;
        matrice[10][9] = '|' ;
    return 1 ;
    } else if ((matrice[1][1] == matrice[1][5]) && (matrice[1][5] == matrice[1][9])) {
     matrice[1][0] = '-' ;
        matrice[1][2] = '-' ;
        matrice[1][4] ='-' ;
        matrice[1][6] = '-' ;
        matrice[1][8] = '-' ;
        matrice[1][10] = '-' ;
    return 1 ;
    } else if ((matrice[5][1] == matrice[5][5]) && (matrice[5][5] == matrice[5][9])) {
        matrice[5][0] = '-' ;
        matrice[5][2] = '-' ;
        matrice[5][4] ='-' ;
        matrice[5][6] = '-' ;
        matrice[5][8] = '-' ;
        matrice[5][10] = '-' ;
    return 1 ;
    } else if ((matrice[9][1] == matrice[9][5] )&&  (matrice[9][5] == matrice[9][9])) {
     matrice[9][0] = '-' ;
        matrice[9][2] = '-' ;
        matrice[9][4] ='-' ;
        matrice[9][6] = '-' ;
        matrice[9][8] = '-' ;
        matrice[9][10] = '-' ;
    return 1 ;
    } else if ((matrice[1][1] == matrice[5][5] )&& (matrice[5][5] == matrice[9][9])) {
        matrice[0][0] = '\\' ;
        matrice[2][2] =  '\\' ;
        matrice[4][4] = '\\' ;
        matrice[6][6] = '\\' ;
        matrice[8][8] = '\\' ;
        matrice[10][10] =  '\\' ;
    return 1 ;
    } else if ((matrice[1][9] == matrice[5][5] )&&( matrice[5][5] == matrice[9][1])) {
        matrice[0][10] = '/' ;
        matrice[2][8] =  '/' ;
        matrice[4][6] = '/' ;
        matrice[6][4] ='/' ;
        matrice[8][2] = '/' ;
        matrice[10][0] =  '/' ;
    return 1 ;
    }
    else {
        return 0 ;
    }
}
int boardfull() {
   if ('1' == matrice[1][1] || '2' == matrice[1][5] || '3' == matrice[1][9] || '4' == matrice[5][1] || '5' == matrice[5][5] || '6' == matrice[5][9] || '7' == matrice[9][1] || '8' == matrice[9][5]
    || '9' == matrice[9][9] ) {
    return 1 ;
    } else {
    return 0;
    }
}
void clearboard( int x ) {
  int i,j ;
  if (x) {
    for(i=0; i<11 ; i++) {
        for (j=0 ; j<11 ; j++) {
            matrice[i][j] = ' ' ;
        }
    }
    for (i=0 ; i<11 ; i++) {
        matrice[3][i] = '_';
    }
    for (i=0 ; i<11 ; i++) {
        matrice[7][i] = '_' ;
    }
    for (i=0 ; i<3 ; i++) {
        matrice[i][3] = '|' ;
    }
    for (i=0 ; i<3 ; i++) {
        matrice[i][7] = '|' ;
    }
    for (i=4 ; i<7 ; i++) {
        matrice[i][3] = '|' ;
    }
    for (i=4 ; i<7 ; i++) {
        matrice[i][7] = '|' ;
    }
    for (i=8 ; i<11 ; i++) {
        matrice[i][3] = '|' ;
    }
    for (i=8 ; i<11 ; i++) {
        matrice[i][7] = '|' ;
    }
    matrice [1][1] = '1' ;
    matrice [1][5] = '2' ;
    matrice [1][9] = '3' ;
     matrice [5][1] = '4' ;
    matrice [5][5] = '5' ;
    matrice [5][9] = '6' ;
     matrice [9][1] = '7' ;
    matrice [9][5] = '8' ;
    matrice [9][9] = '9' ;
  }
}









