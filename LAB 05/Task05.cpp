#include <iostream>
using namespace std;
bool issafe(int board[9][9], int row, int col, int num)
{
    // chacking in row and col
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == num || board[row][i] == num)
        {
            return false;
        }
    }
    int startrow = (row / 3) * 3;
    int startcol = (col / 3) * 3;

    // checking in 3*3 matrix
    for (int i = startrow; i < startrow + 3; i++)
    {
        for (int j = startcol; j < startcol + 3; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool solvesudoku(int board[9][9], int row, int col)
{
    if (row == 9)
    {
        return true;
    }
    if (col == 9)
    {
        return solvesudoku(board, row + 1, 0);
    }
    if (board[row][col] != 0)
    {
        return solvesudoku(board, row, col + 1);
    }
    for (int num = 1; num <= 9; num++)
    {
        if (issafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solvesudoku(board, row, col + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    cout << "soling correct sudoku" << endl;
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solvesudoku(board, 0, 0))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists" << endl;
    }
    cout << "Testing wrong sudoku\n";
    int wrong[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 5, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if (solvesudoku(wrong, 0, 0))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << wrong[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}
