#include <iostream>
#include <vector>
using namespace std;

bool valid(vector<vector<int>>& board, int row, int col, int num){

    for (int i = 0; i < 9; i++){
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = startRow; i < startRow + 3; i++){
        for (int j = startCol; j < startCol + 3; j++){
            if (board[i][j] == num)
                return false;
        }
    }
    return true;     
}


void Sudoku(vector<vector<int>>& board, int row, int col){
    if (row == 8 && col == 8){
        board[row][col] = 0;
        cout << "Sudoku solved!" << endl;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    
    if (board[row][col] != 0){
        if (col == 8){
            Sudoku(board, row + 1, 0);
        } else {
            Sudoku(board, row, col + 1);
        }
        return;
    }
    for (int i = 1; i <= 9; i++) {
        if (valid(board, row, col, i)){
            board[row][col]=i;
            if (col == 8){
                Sudoku(board, row + 1, 0);
            } else {
                Sudoku(board, row, col + 1);
            }
        }
        board[row][col] = 0; // backtrack
    }
}



int main(){

    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    Sudoku(board, 0, 0);
    return 0;
}
