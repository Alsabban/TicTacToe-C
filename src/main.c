#include <stdio.h>
#include "tictactoe.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char choice, winner;
	while (1) {
		printf("Player 1, Choose between X and O: ");
		scanf("%c", &choice);
		if (choice == 'x' || choice == 'X') {
			TICTACTOE_setPlayerOne('X');
			TICTACTOE_setPlayerTwo('O');
			break;
		} else if (choice == 'O' || choice == 'o') {
			TICTACTOE_setPlayerTwo('X');
			TICTACTOE_setPlayerOne('O');
			break;
		} else {
			printf("Wrong choice!! Try again...\n");
		}
	}

	while (1) {
		TICTACTOE_printBoard();
		while (!TICTACTOE_playerOnePlay())
			printf("Please enter a number on the board!\n");
		winner = TICTACTOE_checkWin();
		if (winner != 0) {
			break;
		}
		TICTACTOE_printBoard();
		while (!TICTACTOE_playerTwoPlay())
			printf("Please enter a number on the board!\n");
		winner = TICTACTOE_checkWin();
		if (winner != 0) {
			break;
		}
	}
	TICTACTOE_printBoard();
	if (winner != 3)
		printf("Player %d Wins!!\n", winner);
	else
		printf("Draw!!\n");
	system("pause");
	return 0;
}
