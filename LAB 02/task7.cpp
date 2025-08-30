// A company has multiple departments, each department has a different number of employees.
// => Use a jagged array where each row corresponds to a department and columns store employee
// salaries.
// Calculate:
// -> The highest salary in each department.
// -> The department with the overall maximum average salary. 
#include<iostream>
using namespace std;
 int main(){
    int nD,*Ne,**salaries,*high;
    float* avg;
    cout<<"input number of departments"<<endl;
    cin>>nD;
    Ne=new int[nD];
    high=new int[nD];
    salaries=new int*[nD];
    avg=new float[nD];
    for(int i=0;i<nD;i++){
        avg[i]=0;
        cout<<"enter the number of employies in department "<<i+1<<endl;
        cin>>Ne[i];
        salaries[i]=new int[Ne[i]];
        for(int j=0;j<Ne[i];j++){
        cout<<"enter the salary of employe"<<j+1<<endl;
        cin>>salaries[i][j];
        avg[i]+=salaries[i][j];
    }
    avg[i]/=Ne[i];
    }
    for(int i=0;i<nD;i++){
        high[i]=0;
        for(int j=0;j<Ne[i];j++){
         if(salaries[i][j]>high[i]){high[i]=salaries[i][j];}
        }
    }
    for(int i=0;i<nD;i++){
        cout<<"higest salary in department "<<i+1<<" is: "<<high[i]<<endl;
        cout<<"average salary in department "<<i+1<<" is: "<<avg[i]<<endl;
    }
    delete[]Ne;
    delete[]high;
    delete[] avg;
    for(int i=0;i<nD;i++){
        delete[]salaries[i];
    }
    delete[]salaries;
    

    return 0;
 }