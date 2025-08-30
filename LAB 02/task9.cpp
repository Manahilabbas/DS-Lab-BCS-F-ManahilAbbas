//  Implement a program to represent a sparse matrix using a dynamic 2D array.
// => Input matrix elements.
// => Display the matrix in normal form.
// => Display the matrix in compressed form (row, column, value).
#include<iostream>
using namespace std;
 int main(){
    int m,n,**Matrix;
    cout <<"enter te no of Rows:"<<endl;
    cin>>m;
    cout<<"Enter the number of columns:"<<endl;
    cin>>n;
    Matrix=new int *[m];
    for (int i=0;i<m;i++){
        Matrix[i]=new int [n];
    }
    cout<<"Enter the elements of matrix"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter element for row "<<i+1<<" column"<<j+1<<endl;
            cin>>Matrix[i][j];
        }
    }
    cout<<"normal form:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            cout<<Matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"compressed form (row, column, value):"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(Matrix[i][j]!=0)
            cout<<i+1<< " "<<j+1<<" "<<Matrix[i][j]<<endl;
        }
      
    }
   for(int i=0;i<m;i++){ delete[] Matrix[i]; }

    
    delete[]Matrix;
    return 0;
 }