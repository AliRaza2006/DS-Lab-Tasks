#include<iostream>
using namespace std;
int main()
{
    int arr1[3][3];
    int arr2[3][3];
    cout<<"Enter values for matrix 1: "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr1[i][j];
        }   
    }
    cout<<"Enter values for matrix 2: "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr2[i][j];
        }   
    }
    int arr3[3][3];
    cout<<"Sum of matrix 1 and matrix 2:"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
            cout<<arr3[i][j]<<" ";
        }   
        cout<<endl;
    }
}