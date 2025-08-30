#include <iostream>
using namespace std;

int main() {
    int **M1, **M2, **R;
    int r1, r2, c1, c2;

    cout << "Enter the no of rows for Matrix 1: ";
    cin >> r1;
    cout << "Enter the no of columns for Matrix 1: ";
    cin >> c1;

    cout << "Enter the no of rows for Matrix 2: ";
    cin >> r2;
    cout << "Enter the no of columns for Matrix 2: ";
    cin >> c2;


    M1 = new int*[r1];
    for (int i = 0; i < r1; i++) M1[i] = new int[c1];

    M2 = new int*[r2];
    for (int i = 0; i < r2; i++) M2[i] = new int[c2];

    cout << "\nEnter the elements for Matrix 1:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "M1[" << i+1 << "][" << j+1 << "]: ";
            cin >> M1[i][j];
        }
    }

   
    cout << "\nEnter the elements for Matrix 2:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "M2[" << i+1 << "][" << j+1 << "]: ";
            cin >> M2[i][j];
        }
    }

    cout << "\nOperation you want to perform between two matrices:\n"
         << "1. Addition\n2. Subtraction\nChoice: ";
    int choice;
    cin >> choice;

    
    if (r1 != r2 || c1 != c2) {
        cout << "\nMatrices cannot be added or subtracted because dimensions do not match." << endl;

        
        for (int i = 0; i < r1; i++) delete[] M1[i];
        for (int i = 0; i < r2; i++) delete[] M2[i];
        delete[] M1;
        delete[] M2;
        return 0;
    }

  
    R = new int*[r1];
    for (int i = 0; i < r1; i++) R[i] = new int[c1];

   
    switch (choice) {
        case 1: 
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    R[i][j] = M1[i][j] + M2[i][j];
            break;

        case 2: 
            for (int i = 0; i < r1; i++)
                for (int j = 0; j < c1; j++)
                    R[i][j] = M1[i][j] - M2[i][j];
            break;

        default:
            cout << "Invalid choice!" << endl;
            
            for (int i = 0; i < r1; i++) delete[] M1[i];
            for (int i = 0; i < r2; i++) delete[] M2[i];
            delete[] M1;
            delete[] M2;
            return 0;
    }

    
    cout << "\nResult Matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << R[i][j] << " ";
        }
        cout << endl;
    }

  
    for (int i = 0; i < r1; i++) {
        delete[] M1[i];
        delete[] M2[i];
        delete[] R[i];
    }
    delete[] M1;
    delete[] M2;
    delete[] R;

    return 0;
}
