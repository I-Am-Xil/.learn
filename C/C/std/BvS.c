#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char matrix[3][3] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	' ', ' ', ' '
};

int compX, compY, playerX, playerY;

int sub_tries()
{
	matrix[compX][compY] = ' ';
	compX = rand() % 3;
	compY = rand() % 3;

	if (matrix[compX][compY] == 'B')
	{
		return 1; /*Submarine won the fight*/
	}else{
		matrix[compX][compY] = 'S';
		return 0;
	}
}

int player_tries()
{
	matrix[playerX][playerY] = ' ';

	do{printf("enter new coordinates (X,Y)");
	scanf("%d%d", &playerX, &playerY);
	}while(playerX < 0 || playerX > 2 || playerY < 0 || playerY > 2 );

	if (matrix[playerX][playerY] == 'S')
	{
		return 1; /*Battleship won*/
	}else{
		matrix[playerX][playerY] = 'B';
		return 0;
	}

}

void display_board()
{
	printf("\n");
	printf(" %c | %c | %c\n", matrix[0][0], matrix[0][1], matrix[0][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", matrix[1][0], matrix[1][1], matrix[1][2]);
	printf("---|---|---\n");
	printf(" %c | %c | %c\n", matrix[2][0], matrix[2][1], matrix[2][2]);
}

int main()
{
	/*Time variable*/
	time_t t;
	/* Intializes random number generator */
	srand((unsigned) time(&t));


	compX = compY = playerX = playerY = 0;
	for (;;)
	{
		if (sub_tries())
		{
			printf("Submarine wins!\n");
			break;
		}
		if (player_tries())
		{
			printf("Battleship wins!\n");
			break;
		}
		display_board();
	}
	display_board();
}