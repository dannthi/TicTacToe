#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Header.h"

int main() {
	int num_player;
	printf("1 or 2 players? ");
	scanf("%d", &num_player);
	do {
		if (num_player == 2) {
			int again = 0;
			do {
				int line_p1 = 0, row_p1 = 0, equal = 0, player, valid = 1, x;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						board[i][j] = ' ';
					}
				}

				while ((equal < 9)) {
					player = equal % 2 + 1;
					printf("\nTurn: %d\n", equal + 1);

					printf("Player %ds turn:\n", player);
					print_board();
					if (player == 1)
						x = 88;
					else if (player == 2)
						x = 79;
					
					get_move(x);

					equal += 1;

					if (check()) {
						equal = 10;
					}
					if (equal == 8) {
						printf("\nDraw");
					}
				}
				printf("\nContinue? Press 0\n");
				scanf("%d", &again);
			} while (again == 0);

			exit(0);
		}
		else if (num_player == 1) {
			int again = 0;
			do {
				int line_p1 = 0, row_p1 = 0, equal = 0, valid = 1, best_line, best_row;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						board[i][j] = ' ';
					}
				}

				while ((equal < 9)) {
					
					printf("\nTurn: %d\n", equal + 1);

					if ((equal % 2) == 0) {
						printf("Players turn:\n");

						print_board();
						get_move(88);
					}
					else if ((equal % 2) == 1) {
						do {
							best_line = rand() % 3;
							best_row = rand() % 3;

							if (board[best_line][best_row] != 32) {
								valid = 0;
							}
							else {
								valid = 1;
							}
							board[best_line][best_row] = 79;
						} while (valid == 0);
						valid = 1;
					}

					if (check()) {
						equal = 10;
						print_board();
					}
					if (equal == 8) {
						printf("\nDraw");
					}
					equal += 1;
				}

				printf("\nContinue? Press 0\n");
				scanf("%d", &again);
			} while (again == 0);
			exit(0);
		}
		else {
			printf("Invalid\nRetry...\n");
		}
	} while (true);
}
