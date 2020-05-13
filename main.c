#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 10

void drawBoard( char *board, int arrSize );
void markBoard( int move , char *board, int arrSize, char playerLetter, int playerID );
int checkForWin( char *board, int arrSize );

int main(void)
{

    int move = 0;
    int playerID = 1;
    int iResultOfGame = 0;
    char playerLetter = ' ';
    char board[BOARD_SIZE] = {'0','1','2','3','4','5','6','7','8','9'};  // initialize board to dummy values, element 0 is unused

    while(1){

    drawBoard( board , BOARD_SIZE);
    printf("Player %d move , enter a number: ", playerID);
    if(playerID == 1)
    {
        playerLetter = 'X';
    }
    else
    {
        playerLetter = 'O';
    }
    scanf("%d",&move);
    getchar();
    markBoard( move, board, BOARD_SIZE, playerLetter, playerID );
    iResultOfGame =  checkForWin( board, BOARD_SIZE );
    if(iResultOfGame == 0){
        printf("It is a draw! Game over!\n");
        break;
    }
    else if(iResultOfGame == 1){
        printf("Player %d won.  Congratulations1\n",playerID);
        break;
    }
    playerID = ( playerID % 2) + 1;  // Next player's turn
    printf("Enter any key to continue.");
    getchar();
    printf("\033[2J\033[;H");
    }

    return 0;
}

void drawBoard( char * board, int arrSize ){
    printf("\n\tTic Tac Toe\n\nPlayer 1 (X) - Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
}

void markBoard( int move , char* board, int arrSize, char playerLetter, int playerID ){

    _Bool invalidMove = 1;
    while(invalidMove)
    {
        if( move > 9 || move < 1 )
            printf("Invalid move.");
        else if( board[move] == 'X' || board[move] == 'O')
            printf("Invalid move.");
        else
        {
            invalidMove = 0;
        }
        if (invalidMove)
        {
            printf("\nPlayer %d move , enter a number: ", playerID);
            scanf("%d",&move);
        }
    }
    board[move] = playerLetter;
}


int checkForWin( char *board, int arrSize ){
    int winOrDraw = 2; // 0 if draw, 1 if win

    // check for a win
    if( board[1] == board[2] && board[2] == board[3] )  // if there are matching entries in each row
        winOrDraw = 1;
    else if( board[4] == board[5] && board[5] == board[6] )
        winOrDraw = 1;
    else if( board[7] == board[8] && board[8] == board[9] )
        winOrDraw = 1;
    else if( board[1] == board[4] && board[4] == board[7] ) // if there are matching entries in each column
        winOrDraw = 1;
    else if( board[2] == board[5] && board[5] == board[8] )
        winOrDraw = 1;
    else if( board[3] == board[6] && board[6] == board[9] )
        winOrDraw = 1;
    else if( board[1] == board[5] && board[5] == board[9] )  // if the diagonals have matching entries
        winOrDraw = 1;
    else if( board[7] == board[5] && board[5] == board[3] )
        winOrDraw = 1;
    // loop checks for draw
    if(winOrDraw != 1)
    {
        int iNumOfPlayerEntries = 0;
        for( int i = 1; i < arrSize; i++ ){
            if( board[i] == 'X' || board[i] == 'O' )
                    iNumOfPlayerEntries++;
        }
        if(iNumOfPlayerEntries == 9)
            winOrDraw = 0;
    }

    return winOrDraw;
}

