/*
 *
 *	 File Name: tictactoe.h
 *
 *	 Description: Header file for Tic-Tac-Toe game functions & variables
 *
 *	 Author: Youssef Alsabban
 *
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_


void TICTACTOE_printBoard(void);

char TICTACTOE_playerOnePlay(void);

char TICTACTOE_playerTwoPlay(void);

void TICTACTOE_setPlayerOne(char playerChar);

void TICTACTOE_setPlayerTwo(char playerChar);

char TICTACTOE_checkWin(void);



#endif /* TICTACTOE_H_ */
