#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

int board[3][3];

void print_board() {
	
	printf("\n_____________\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("| %c ", board[i][j]);
		}
		printf("|\n_____________\n");
	}
}

int check() {
	for (int i = 0; i < 3; i++) {
		if ((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]) && (board[1][i] == board[2][i])) {
			if (board[1][i] == 88) {
				printf("Player 1 wins!");
				return 1;
			}
			else if (board[1][i] == 79) {
				printf("Player 2 wins!");
				return 1;
			}
			else {
				return 0;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]) && (board[i][1] == board[i][2])) {
			if (board[i][1] == 88) {
				printf("Player 1 wins!");
				return 1;
			}
			else if (board[i][1] == 79) {
				printf("Player 2 wins!");
				return 1;
			}
			else {
				return 0;
			}
		}
	}

	if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]) && (board[1][1] == board[2][2])) {
		if (board[1][1] == 88) {
			printf("Player 1 wins!");
			return 1;
		}
		else if (board[1][1] == 79) {
			printf("Player 2 wins!");
			return 1;
		}
		else {
			return 0;
		}
	}

	else if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0]) && (board[1][1] == board[2][0])) {
		if (board[1][1] == 88) {
			printf("Player 1 wins!");
			return 1;
		}
		else if (board[1][1] == 79) {
			printf("Player 2 wins!");
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
}

void get_move(int x) {
	int line_p1 = 0, row_p1 = 0, valid = 1;
	do
	{
		printf("Line: ");
		scanf("%d", &line_p1);
		if (line_p1 > 3) {
			printf("Invalid\nRetry..\n");
			valid = 0;
		}
		else {
			valid = 1;
		}
		line_p1 = line_p1 - 1;
		printf("Row: ");
		scanf("%d", &row_p1);
		if (row_p1 > 3) {
			printf("Invalid\nRetry..\n");
			valid = 0;
		}
		else {
			valid = 1;
		}
		row_p1 = row_p1 - 1;
		if (board[line_p1][row_p1] != 32) {
			printf("Invalid\nRetry..\n");
			valid = 0;
		}
		else {
			valid = 1;
		}
		board[line_p1][row_p1] = x;
	} while (valid == 0);
	valid = 1;
}
