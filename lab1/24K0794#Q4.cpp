#include<iostream>
using namespace std;
/*Q4. A weather station wants to store temperatures for a week. Write a C++ program that
dynamically allocates an array of 7 double values using a pointer. Ask the user to input daily
temperatures, then display them along with the average temperature. Finally, free the memory.*/ 
int main()
{
    double* temp=new double[7];
    double sum=0;
    cout<<"Enter Temperatures: "<<endl;
    for(int i=0;i<7;i++)
    {
        cout<<"Day "<<i+1<<": ";
        cin>>*(temp+i);
        sum+=*(temp+i);
    }
    cout<<"Average temperature: "<<sum/7;
    delete[] temp;
}