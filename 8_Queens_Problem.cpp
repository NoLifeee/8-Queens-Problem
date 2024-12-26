#include <iostream>
#include <vector>
using namespace std;

#define N 8 // Chess table size (N x N)

int nrSol; // for displaying at the end of the program how many solution exist

int isValid(int row, int col, vector<int> &queens)
{
    for (int i = 0; i < row; i++)
    {
        int prevCol = queens[i];
        if (prevCol == col) // checking column
            return 0;
        if (i - prevCol == row - col) // checking negative diagonal
            return 0;
        if (i + prevCol == row + col) // checking positive diagonal
            return 0;
    }
    return 1;
}

void printBoard(vector<int> &queens)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (queens[i] == j)
                cout << "1 "; // queen position
            else
                cout << "0 "; // empty position
        }
        cout << endl;
    }
    cout << endl;
}

void solve(int row, vector<int> &queens)
{
    if (row == N) // if all the queens have been succesfully placed we print the solution
    {
        printBoard(queens);
        nrSol++;
        return;
    }

    for (int col = 0; col < N; ++col)
    {
        if (isValid(row, col, queens)) // checking if the position is valid
        {
            queens[row] = col;      // placing queen
            solve(row + 1, queens); // going to next row
            queens[row] = -1;       // backtracking
        }
    }
}

int main()
{
    vector<int> queens(N, 0); // positions with the value 0 are marked as empty
    solve(0, queens);
    cout << "There are " << nrSol << " solutions";
    return 0;
}
