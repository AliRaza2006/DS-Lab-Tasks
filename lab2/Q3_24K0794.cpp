#include<iostream>
using namespace std;
int main()
{
	int patients;
	cout<<"Enter number of patients: ";
	cin>>patients;
	int* meds=new int[patients];
	cout<<"\nHow many medicines each patient have: "<<endl;
	for(int i=0;i<patients;i++)
	{
		cout<<"Patient "<<i+1<<": ";
		cin>>meds[i];
	}
	int** records=new int*[patients];
	for(int i=0;i<patients;i++)
	{
		records[i]=new int[meds[i]];
	}
	cout<<"\nEnter records: "<<endl;
	for(int i=0;i<patients;i++)
	{
		cout<<"Patient "<<i+1<<": ";
		for(int j=0;j<meds[i];j++)
		{
			cin>>records[i][j];
		}
	}
	cout<<"\nRecords: "<<endl;
	for(int i=0;i<patients;i++)
	{
		cout<<"Patient "<<i+1<<": ";
		for(int j=0;j<meds[i];j++)
		{
			cout<<records[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<patients;i++)
	{
		delete[] records[i];
	}
	delete[] records;
	delete[] meds;
}
