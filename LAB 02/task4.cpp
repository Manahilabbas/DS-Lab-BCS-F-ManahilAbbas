//  Create a dynamic program that manages monthly expenses for a family.
// => Use a 1D dynamic array to store expenses for n months.
// => Add a feature to resize the array if the user wants to track more months later.
// => Compute and display the total and average expenses.
#include<iostream>
using namespace std;
float* resizearr(int newsize,int oldsize,float* array){
    float *arr;
    if(newsize<=oldsize){return array;}
    else{
        arr =new float[newsize];
        for (int i=0;i<oldsize;i++){
         arr[i]=array[i];
        }
        delete[] array;
    return arr;}
}
 int main(){
    float * expenses;
    int nMonths;
    cout<<"enter the numbers of months you want to manage expences "<<endl;
    cin>>nMonths;
    expenses=new float[nMonths];
    float avg=0;
    float total;
    for(int i=0;i<nMonths;i++){
        cout<<"enter the total expences for month"<<i+1<<endl;
        cin>>expenses[i];
        total+=expenses[i];
    }
    avg=total/nMonths;
    cout<<"the total and average expenses: "<<avg<<endl;
     char choice;
    cout << "\nDo you want to track more months? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int newMonths;
        cout << "Enter the new total number of months: ";
        cin >> newMonths;

        expenses = resizearr(newMonths, nMonths, expenses);

        for (int i = nMonths; i < newMonths; i++) {
            cout << "Enter the total expenses for month " << i + 1 << ": ";
            cin >> expenses[i];
            total += expenses[i];
        }
       avg=total/nMonths;
        nMonths = newMonths;
        cout<<"the total and average expenses: "<<avg<<endl;
     char choice;
    delete[]expenses;
    
    
    return 0;
 }}