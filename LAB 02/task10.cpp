//  Design a program that maintains library book records using dynamic arrays.
// => Each row represents a category (e.g., Fiction, Science, History).
// => Each category has a different number of books (use a jagged array).
// => Store book IDs dynamically and allow the user to search for a given book ID.
// => Print whether the book is available and in which category.
#include <iostream>
using namespace std;


int main() {
    int** books;              
    int n,* numberOfBOOK;                         
    string* categoryNames;     

    cout << "How many categories of books does the library have? ";
    cin >> n;

    books = new int*[n];
    numberOfBOOK = new int[n];
    categoryNames = new string[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of category " << i+1 << ": ";
        cin >> categoryNames[i];

        cout << "Enter number of books in " << categoryNames[i] << ": ";
        cin >> numberOfBOOK[i];

        books[i] = new int[numberOfBOOK[i]];
        for (int j = 0; j < numberOfBOOK[i]; j++) {
            
            cout << "Enter ID for book " << j+1 << " in " << categoryNames[i] << ": ";
            cin >> books[i][j];
        }
    }

    int searchID;
    cout << "\nEnter book ID to search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < numberOfBOOK[i]; j++) {
            if (books[i][j] == searchID) {
                cout << "Book ID " << searchID << " is available in category: " 
                     << categoryNames[i] << endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        cout << " Book ID " << searchID << " not found in library.\n";
    }
    for (int i = n; i >= 0; i++) {
        delete[] books[i];
    }
    delete[] books;
    delete[] numberOfBOOK;
    delete[] categoryNames;

    return 0;
}
