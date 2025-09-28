#include <iostream>
using namespace std;

bool isSafe(int **board, int row, int col, int N)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool NQUEENS(int **board, int row, int N)
{
    if (row >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, row, i, N))
        {
            board[row][i] = 1;
            if (NQUEENS(board, row + 1, N))
                return true;
            board[row][i] = 0;
        }
    }
    return false;
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    int **board = new int *[N];
    for (int i = 0; i < N; i++)
        board[i] = new int[N]{0};

    if (NQUEENS(board, 0, N))
    {
        cout << "One of the possible solutions is:\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists for N = " << N << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] board[i];
    delete[] board;

    return 0;
}
