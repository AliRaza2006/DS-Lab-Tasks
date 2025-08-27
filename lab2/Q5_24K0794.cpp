#include<iostream>
using namespace std;
int main()
{
    int total=0;
    int n;
    cout<<"Enter number of transactions: ";
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Transaction "<<i+1<<": ";
        cin>>arr[i];
        total+=arr[i];
    }
    cout<<"Total balance: "<<total;
    delete[] arr;
}