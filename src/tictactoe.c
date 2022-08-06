/*
 *
 *	 File Name: tictactoe.c
 *
 *	 Description: Source file for Tic-Tac-Toe game functions & variables
 *
 *	 Author: Youssef Alsabban
 *
 */
#include "tictactoe.h"
#include <stdio.h>

static volatile char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
static volatile char playerOneChar;
static volatile char playerTwoChar;

void TICTACTOE_printBoard(void) {
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", board[0], board[1], board[2]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", board[3], board[4], board[5]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
	printf("     |     |     \n\n");
}

char TICTACTOE_playerOnePlay(void) {
	char position, i, played = 0;
	printf("Player 1: ");
	scanf(" %c", &position);
	for (i = 0; i < 9; i++) {
		if (board[i] == position) {
			board[i] = playerOneChar;
			played = 1;
		}
	}
	return played;
}

char TICTACTOE_playerTwoPlay(void) {
	char position, i, played = 0;
	printf("Player 2: ");
	scanf(" %c", &position);
	for (i = 0; i < 9; i++) {
		if (board[i] == position) {
			board[i] = playerTwoChar;
			played = 1;
		}
	}
	return played;
}

void TICTACTOE_setPlayerOne(char playerChar) {
	playerOneChar = playerChar;
}

void TICTACTOE_setPlayerTwo(char playerChar) {
	playerTwoChar = playerChar;
}

char TICTACTOE_checkWin(void) {
	char i, winner = 0;

	//check horizontal
	for (i = 0; i < 7; i += 3) {
		if (board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
			if (board[i] == playerOneChar) {
				winner = 1;
			} else {
				winner = 2;
			}
			break;
		}
	}

	//check vertical
	for (i = 0; i < 3; i++) {
		if (board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
			if (board[i] == playerOneChar) {
				winner = 1;
			} else {
				winner = 2;
			}
			break;
		}
	}

	//check both diagonals
	for (i = 0; i < 3; i += 2) {
		if (board[i] == board[i + 4] && board[i + 4] == board[i + 8]) {
			if (board[i] == playerOneChar) {
				winner = 1;
			} else {
				winner = 2;
			}
			break;
		}
	}

	for (i = 2; i < 3; i += 2) {
		if (board[i] == board[i + 2] && board[i + 2] == board[i + 4]) {
			if (board[i] == playerOneChar) {
				winner = 1;
			} else {
				winner = 2;
			}
			break;
		}
	}

	//Check for draw
	if (winner == 0) {
		for (i = 0; i < 9; i++) {
			if (board[i] != 'X' && board[i] != 'O')
				break;
		}
		if (i == 9) {
			winner = 3;
		}
	}
	return winner;
}
