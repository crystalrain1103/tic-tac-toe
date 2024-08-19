//Player1 use O(input 0) while Player2 use X(input 1)
//Copyright by Github@CrystalRain1103


#include <stdio.h>
//void test(int pic, int (*p)[pic]);
void intro(void);
void game(int pic, int x, int y, int (*p)[pic], int cnt);
void check(int cnt, int size, int pic, int (*p)[pic], int *pt);
void print(int pic, int (*p)[pic]);


int main(void){
    intro();
    int size;
    if(scanf("%d", &size) == 1 && size > 1){
        int pic = size + 1;
        int board[pic][pic];
        for(int a = 0; a < pic; a ++){
            for(int b = 0; b < pic; b ++){
                board[a][b] = -1;
            }
        }//initialise chessboard
        int x, y, cnt = 1, stop = 0;
        do{
            print(pic, board);
            //test(pic, board);
            if(cnt % 2){
                printf("P1:\n");
            }
            else {
                printf("P2:\n");
            }
            if(scanf("%d %d", &x, &y) == 2){
                if(x > 0 && x < pic && y > 0 && y < pic && board[x][y] == -1){   
                    game(pic, x, y, board, cnt);
                    check(cnt, size, pic, board, &stop);
                    cnt ++;
                    x = y = 0;
                }else{
                    printf("Invalid Input!\n");
                }
            }else break;
        }while(stop != 1);
        printf("Game Over!\nPress ENTER to quit.");
        getchar();getchar();
    }
}













void intro(void){
    printf(
        "RULE:\nP1 and P2 input a pair of (x,y) as the location IN TURN and P1 firstly inputs.\n"
        "input e.g.:\nP1:\nx y\n"
        "tips:'O' is for P1 while 'X' is for P2.\n"
        "ATTENTION:Any input that is not a POSITIVE NATURAL NUMBER is UNACCEPTABLE!\n"
        "please input the size:");
}


void print(int pic, int (*p)[pic]){
    char image[pic][pic];
    for(int a = 0; a < pic; a ++){
        for(int b = 0; b < pic; b ++){
            if(p[a][b] == -1) image[a][b] = '.';
            else if(p[a][b] == 0) image[a][b] = 'O';
            else if(p[a][b] == 1) image[a][b] = 'X';

            if(a == 0) image[a][b] = b + '0';
            else if(b == 0) image[a][b] = a + '0';
        }   
    }//write in chessboard
    for(int i = 0; i < pic; i ++){
        for(int j = 0; j < pic; j ++){
            if(i == 0 && j != 0) printf("y%c", image[i][j]);
            else if(j == 0 && i != 0) printf("x%c", image[i][j]);
            else printf("%c", image[i][j]);

            if(i == 0 && j != 0 && j < pic - 1) printf(" ");
            else if(j < pic - 1) printf("  ");
            else printf("\n");
        }
    }//print chessboard   
}


void game(int pic, int x, int y, int (*p)[pic], int cnt){
    if(cnt % 2) p[x][y] = 0;
    else p[x][y] = 1;
    //players' operation
}


void check(int cnt, int size, int pic, int (*p)[pic], int *pt){
    int numO1=0, numO2=0, numX1=0, numX2=0, numO3=0, numX3=0, numO4=0, numX4=0, win=-1;
    for(int i = 1; i < pic; i ++){
        for(int j = 1; j < pic; j ++){
            if(p[i][j] == 0) numO1 ++;
            else if(p[i][j] == 1) numX1 ++;//for every column,check every row

            if(p[j][i] == 0) numO2 ++;
            else if(p[j][i] == 1) numX2 ++;//for every row,check every column
        }//check straight line
        if(p[i][i] == 0) numO3 ++;
        else if(p[i][i] == 1) numX3 ++;

        if(p[i][pic-i] == 0) numO4 ++;
        else if(p[i][pic-i] == 1) numX4 ++;//check diagonal line

        if(numO1 == size || numO2 == size || numO3 == size || numO4 == size){
            win = 0;
            break;
        }else if(numX1 == size || numX2 == size || numX3 == size || numX4 == size){
            win = 1;
            break;
        }else{
            numO1 = numX1 = numO2 = numX2 = 0;
        }//judge if any player win
    }
    if(win == 0){
        printf("PLAYER1 WIN!\n");
        *pt = 1;
    }
    else if(win == 1){
        printf("PLAYER2 WIN!\n");
        *pt = 1;
    }
    else if(cnt == size * size){
        printf("DRAW!\n");
        *pt = 1;
    }
}


/*
void test(int pic, int (*p)[pic]){
    for(int i = 0; i < pic; i ++){
        for(int j = 0; j < pic; j ++){
            printf("(%d,%d)%d", i, j, p[i][j]);
            if(j < pic - 1) printf("  ");
            else printf("\n");
        }
    }  
}
*/