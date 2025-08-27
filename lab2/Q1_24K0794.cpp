#include<iostream>
using namespace std;
int main()
{
    int days=7;
    int reading=3;
    double** arr=new double*[days];
    for(int i=0;i<days;i++)
    {
        arr[i]=new double[3];
    }
    for(int i=0;i<days;i++)
    {
        cout<<"Enter Temperatures for day "<<i+1<<": ";
        for(int j=0;j<reading;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<days;i++)
    {
        cout<<"Temperatures for day "<<i+1<<": ";
        for(int j=0;j<reading;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    double min=arr[0][0];
    double max=arr[0][0];
	for(int i=1;i<days;i++)
    {
    	for(int j=0;j<reading;j++)
    	{
			if(arr[i][j]<min)
			{
				min=arr[i][j];
			}
			if(arr[i][j]>max)
			{
				max=arr[i][j];
			}
		}	
	}
	cout<<"Max: "<<max<<endl;
	cout<<"Min: "<<min<<endl;
	for(int i=0;i<days;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
