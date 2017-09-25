#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define maxMine = 99;
#define maxSide = 25;
#define MOVE 526;

int side, mine;
bool Valid(int width, int height);
bool Mine(int width, int height, int board[]);
void makeMove(int *x, int *y);
void printBoard(char playerboard[]);
void chooseDifficultyLevel();
void playMinesweeper ();


int main(){

	return (0);

}

bool Valid(int width, int height){

    return (width >= 0) && (width < side) && (height >= 0) && (height < side);
}

bool Mine(int width, int height, char Board[][]){

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

void viewBoard(char Board[]){

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

int adjacentCells(int width, int height, int Mine[], char currentBoard[]){

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


