#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
void printBoard(int arr[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (col % 3 == 0 && col != 0) cout << "| ";

            if (arr[row][col] == 0) {
                cout << "\033[32m" << ". " << "\033[0m ";
            }
            else {
                // Display initial numbers in green
                cout << "\033[32m" << arr[row][col] << "\033[0m ";
            }
        }
        cout << endl;

        if ((row + 1) % 3 == 0 && row != 8) {
            cout << "---------------------" << endl;
        }
    }
}

void clearScreen() {
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

bool checker(int arr[][9], int row,int col,int num) {
    for(int i=0; i<9;++i) {
        if( num == arr[row][i] ){
            return false;
        }
    }

    for(int i=0;i<9;++i) {
        if(num==arr[i][col]){
            return false;
        }
    }

    int rowStart = row - (row %9 );
    int colStart = col - (col % 9);

    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(num == arr[rowStart+i][colStart+j]){
                return false;
            }
        }
    }

    return true;
}

bool solverRecursion(int arr[][9], int row, int col) {
    if(row == 8 && col == 9) return false;

    if(col == 9) {
        row++;
        col = 0;
    }

    if(arr[row][col] != 0) return solverRecursion(arr, row, col+1);

    for(int i=0;i<=9;++i) {
        if(checker(arr,row,col,i)) {
            arr[row][col] = i;

            // Clear the screen and print the board after backtracking
            clearScreen();
            printBoard(arr);

            if(solverRecursion(arr, row, col+1)) {
                return true;
            }
            arr[row][col] = 0;

            // Clear the screen and print the board after backtracking
            clearScreen();
            printBoard(arr);
        }
    }

    return false;
}

int main() {
    time_t start, end;
    time(&start);

    int arr[9][9] = {
        {0, 0, 0, 1, 0, 2, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 8, 0, 0, 0, 9, 0, 0},
        {4, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {2, 0, 0, 0, 8, 0, 0, 0, 1},
        {0, 0, 9, 0, 0, 0, 8, 0, 5},
        {0, 7, 0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 3, 0, 4, 0, 0, 0}
    };


}