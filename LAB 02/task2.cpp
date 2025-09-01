// Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
// => Rows represent benches, columns represent seats on each bench.
// => Initialize the array with 0 (empty).
// => Let the user fill seats (1 for occupied).
// => Print the final seating chart in matrix form.

#include <iostream>
using namespace std;
int main()
{
    int **chart,row, col;
    cout << "Enter no of rows: ";
    cin >> row;
    cout << "Enter no of columns: ";
    cin >> col;

    chart = new int*[row];
    for (int i=0; i<row; i++)
        chart[i] = new int[col];

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++)
            chart[i][j] = 0;
    }

    char choice;
    cout << "Do you want to fill seats? ";
    cin >> choice;
    if (choice == 'y') {
        cout << "How many seats do you want to fill? ";
        int size;
        cin >> size;
        if (size > (row*col)) {
                cout << "Boundary error";
                return 0;
            }
        cout << "Enter the positions: " << endl;
        for (int i=0;i<size ; i++) {
            cout << i+1 << ". ";
            int pos, r, c;
            cin >> pos;
            if (pos>(row*col)) {
                cout << "Boundary error";
                return 0;
            }
            else {
               pos--;             
               r = pos / col;  
               c = pos % col;     

            }
        }
    }

    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++) {
            cout << chart[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=row-1; i>=0; i--)
    {
        delete[] chart[i];
    }
    delete[] chart;
}
