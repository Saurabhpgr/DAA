#include <iostream>
using namespace std;

#define N 4

int solutionCount = 0;

void printBoard(int board[N][N]) {

    cout << "\nSolution " << solutionCount << ":\n";

    for(int i = 0; i < N; i++) {

        for(int j = 0; j < N; j++) {

            if(board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}

bool isSafe(int board[N][N], int row, int col) {

    // Check upper column
    for(int i = 0; i < row; i++) {

        if(board[i][col])
            return false;
    }

    // Check upper-left diagonal
    for(int i = row, j = col;
        i >= 0 && j >= 0;
        i--, j--) {

        if(board[i][j])
            return false;
    }

    // Check upper-right diagonal
    for(int i = row, j = col;
        i >= 0 && j < N;
        i--, j++) {

        if(board[i][j])
            return false;
    }

    return true;
}

void solveNQueens(int board[N][N], int row) {

    // If all queens are placed
    if(row == N) {

        solutionCount++;

        printBoard(board);

        return;
    }

    // Try every column
    for(int col = 0; col < N; col++) {

        if(isSafe(board, row, col)) {

            // Place queen
            board[row][col] = 1;

            // Recur for next row
            solveNQueens(board, row + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {

    int board[N][N] = {0};

    solveNQueens(board, 0);

    cout << "\nTotal Solutions = "
         << solutionCount << endl;

    return 0;
}