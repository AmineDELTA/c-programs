#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void PlayerMove();
void ComputerMove();
char CheckWinner();
void printWinner(char);

int main()
{
   char winner = ' ';

   // creates a seed based on curent time
   srand(time(0));

   resetBoard(board);
   // no need to use while (winner == ' ' && checkFreeSpaces() != 0) because we already have the break statements in both ifs
   for (;;)
   {
      printBoard(board);
      PlayerMove(board);
      winner = CheckWinner();
      if (winner != ' ' || checkFreeSpaces() == 0)
      {
         break;
      }

      ComputerMove(board);
      winner = CheckWinner();
      if (winner != ' ' || checkFreeSpaces() == 0)
      {
         break;
      }
   }
   printBoard(board);
   printWinner(winner);

   return 0;
}

void resetBoard()
{
   for (int i = 0; i < 3; i++)
   {

      for (int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}

void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}

int checkFreeSpaces()
{
   int freeSpaces = 9;
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (board[i][j] != ' ')
         {
            return 1;
         }
      }
   }
   return 0;
}

void PlayerMove()
{

   int x;
   int y;

   for (;;)
   {
      printf("Enter row #(1-3): ");
      scanf("%d", &x);
      x--;
      printf("Enter column #(1-3): ");
      scanf("%d", &y);
      y--;

      if (board[x][y] != ' ')
      {
         printf("Invalid move\n");
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   }
}

void ComputerMove()
{

   int x;
   int y;

   if (checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;

      } while (board[x][y] != ' ');
      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}

char CheckWinner()
{
   // check rows
   for (int i = 0; i < 3; i++)
   {
      if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }

   // chech columns
   for (int i = 0; i < 3; i++)
   {
      if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
      {
         return board[0][i];
      }
   }

   // check diagonols
   if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
   {
      return board[0][0];
   }

   if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
   {
      return board[0][2];
   }

   return ' ';
}

void printWinner(char winner)
{
   if (winner == PLAYER)
   {
      printf("\nYOU WIN!\n");
   }
   else if (winner == COMPUTER)
   {
      printf("\nYOU LOSE!\n");
   }
   else
   {
      printf("\nIT'S A TIE!\n");
   }
}
