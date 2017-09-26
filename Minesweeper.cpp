#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define maxMine 99
#define maxSide 25
#define MOVE 526

int side, mine;
bool Valid(int width, int height);
bool Mine(int width, int height, char Board[]);
void playerMove(int *x, int *y);
void viewBoard(char playerboard[]);
int adjacentCells(int width, int height, int MINE[][2], char currentBoard[][maxSide]);
bool playUntil(char playerBoard[][maxSide], char currentBoard[][maxSide], int MINE[][2], int width, int height, int *moves);
void mineLocation(int MINE[][2], char currentBoard[]);
void Initialize(char currentBoard[][maxSide], char playerBoard[][maxSide]);
void newMines(int width, int height, char Board[][maxSide]);
void playMinesweeper();
void chooseDifficultyLevel();


int main(){

	chooseDifficultyLevel();
	playMinesweeper();
	return (0);

}

bool Valid(int width, int height){

    return (width >= 0) && (width < side) && (height >= 0) && (height < side);
}

bool Mine(int width, int height, char Board[][maxSide]){

	if(Board[width][height] == '*'){
		return true;
	}
	else{
		return false;
	}
}

void playerMove(int *x, int *y){

	cout << "Choose your move player (x,y): ";
	cin >> *x >> *y;
}

void viewBoard(char Board[][maxSide]){

	cout << "\n\n\t\t\t    ";

	for(int i = 0; i < side; i++){
		cout << "%d " << i;
	}

	cout << "\n\n";

	for(int i = 0; i < side; i++){
		cout << "\t\t\t    " << i;

		for(int j = 0; j < side; j++){
			cout << "%c " << Board[i][j];
		}
		cout << " %d" << i;
		cout << "\n";
	}
	return;
}

int adjacentCells(int width, int height, int MINE[][2], char currentBoard[][maxSide]){

	int count = 0;

	//North cell
	if(Valid(width - 1, height) == true){
		if(Mine(width - 1, height, currentBoard) == true){
			count++;
		}
	}

	//South cell
	if(Valid(width + 1, height) == true){
		if(Mine(width + 1, height, currentBoard) == true){
			count++;
		}
	}

	//East cell
	if(Valid(width, height + 1) == true){
		if(Mine(width, height + 1, currentBoard) == true){
			count++;
		}
	}

	//West cell
	if(Valid(width, height - 1) == true){
		if(Mine(width, height - 1, currentBoard) == true){
			count++;
		}
	}

	//NorthEast cell
	if(Valid(width - 1, height + 1) == true){
		if(Mine(width - 1, height + 1, currentBoard) == true){
			count++;
		}
	}

	//NorthWest cell
	if(Valid(width - 1, height - 1) == true){
		if(Mine(width - 1, height - 1, currentBoard) == true){
			count++;
		}
	}

	//SouthEast cell
	if(Valid(width + 1, height + 1) == true){
		if(Mine(width + 1, height + 1, currentBoard) == true){
			count++;
		}
	}

	//SouthWest cell
	if(Valid(width + 1, height - 1) == true){
		if(Mine(width + 1, height - 1, currentBoard) == true){
			count++;
		}
	}
	return count;
}

bool playUntil(char playerBoard[][maxSide], char currentBoard[][maxSide], int MINE[][2], int width, int height, int *moves){

	if(playerBoard[width][height] != '-'){
		return false;
	}

	int i;

	if(currentBoard[width][height]== '*'){
		playerBoard[width][height] = '*';

		for(i = 0; i < mine; i++){
			playerBoard[MINE[i][0]][MINE[i][1]] = '*';

		}
		cout << playerBoard;
		cout << "Oh no, you lost! Better Luck next time!";
		return true;
	}
	else{
		int count = adjacentCells(width, height, MINE, currentBoard);
		*moves--;
		playerBoard[width][height] = count + '0';


		if(!count){

			if(Valid(width - 1, height) == true){
				if(Mine(width - 1, height, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width - 1, height, moves);
					}
			}

			if(Valid(width + 1, height) == true){
				if(Mine(width + 1, height, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width + 1, height, moves);
				}
			}

			if(Valid(width, height + 1) == true){
				if(Mine(width, height + 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width, height + 1, moves);
				}
			}

			if(Valid(width, height - 1) == true){
				if(Mine(width, height - 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width, height - 1, moves);
				}
			}

			if(Valid(width - 1, height + 1) == true){
				if(Mine(width - 1, height + 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width - 1, height + 1, moves);
				}
			}

			if(Valid(width - 1, height - 1) == true){
				if(Mine(width - 1, height - 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width - 1, height - 1, moves);
				}
			}

			if(Valid(width + 1, height + 1) == true){
				if(Mine(width + 1, height + 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width + 1, height + 1, moves);
				}
			}

			if(Valid(width + 1, height - 1) == true){
				if(Mine(width + 1, height - 1, playerBoard) == false){
					playUntil(playerBoard, currentBoard, MINE, width + 1, height - 1, moves);
				}
			}
			return false;
		}
	}
	return 0;
}

void mineLocation(int MINE[][2], char currentBoard[]){
	bool mark[maxSide * maxSide];
	memset(mark,false,sizeof(mark));

	for(int i = 0; i < mine;){

		int random = rand() % (side * side);
		int x = random / side;
		int y = random % side;

		if(mark[random == false]){
			MINE[i][0] = x;
			MINE[i][1] = y;

			currentBoard[MINE[i][0]][MINE[i][1]] = '*';
			mark[random] = true;
			i++;
		}
	}
}

void Initialize(char currentBoard[][maxSide], char playerBoard[][maxSide]){

	srand(time(NULL));

	int i,j;

	for(i = 0; i < side; i++){
		for(j = 0; j < side; j++){

			playerBoard[i][j] = '-';
		}
		return;
	}
}

void newMines(int width, int height, char Board[][maxSide]){

	for(int i = 0; i < side; i++){
		for(int j = 0; j < side; j++){
			if(Board[i][j] != '*'){

				Board[i][j] = '*';
				Board[width][height] = '-';
				return;
		}
	}
}
}

void playMinesweeper(){

	bool LOSE = false;
	char currentBoard[maxSide][maxSide];
	char playerBoard[maxSide][maxSide];
	int moves = (side * side) - mine;
	int x, y;
	int MINE[maxMine][2];

	Initialize(currentBoard, playerBoard);
	mineLocation(MINE, currentBoard);

	while(LOSE == false){

		viewBoard(playerBoard);
		cout << playerBoard;
		playerMove(&x, &y);

		if(moves == 0){
			if(Mine(x,y,currentBoard) == true){
				newMines(x,y,currentBoard);
			}
		}
		moves++;
		LOSE = playUntil(playerBoard, currentBoard, MINE, x, y, &moves);

		if((LOSE == false) && (moves == 0)){

			cout << "Congratulations! You won!" << endl;
			LOSE == true;
		}
	}
}

void Difficulty(){

	int mode;
	cout << "Choose a difficulty mode. 0 for easy, 1 for normal, 2 for hard: ";
	cin >> mode;

	if(mode == 0){

		side = 9;
		mine = 10;
	}
	else if(mode == 1){
		side = 16;
		mine = 40;
	}
	else{
		if(mode == 2){
			side = 24;
			mine = 99;
		}
	}
	return;
}
