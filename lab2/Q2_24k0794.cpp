#include<iostream>
using namespace std;
int main()
{
    int n=20;
    int* quantity=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Quantity of item "<<i<<": ";
        cin>>quantity[i];
    }
    cout<<"\nChoose from the following: "<<endl;
    cout<<"1. Add an item\n";
    cout<<"2. Sell an item\n";
    cout<<"3. Display stock list\n";
    cout<<"Press another key to exit\n";
    while(1)
    {
        int option;
        cout<<"\nOption: ";
        cin>>option;
        cout<<endl;
        switch(option)
        {
            case 1:
            {
                int*arr=new int[++n];
                for(int i=0;i<n-1;i++)
                {
                    arr[i]=quantity[i];
                }
                delete[] quantity;
                cout<<"Enter the quantity of item that is to be added: ";
                cin>>arr[n-1];
                quantity=arr;
                cout<<"Item added succesfully"<<endl;
                break;
            }
            case 2:
            {
                if(n==0)
                {
                    cout<<"The list is empty!"<<endl;
                }
                else
                {
                    int ind;
                    cout<<"Enter the index(0 based) of item to be removed: ";
                    cin>>ind;
                    if(ind>=n || ind<0)
                    {
                        cout<<"Invalid item!";
                        break;
                    }
                    int qty;
                    cout<<"How many peices do you want to purchase: ";
                    cin>>qty;
                    if(quantity[ind]-qty<=0)
                    {
                        if((quantity[ind]-qty==0))
                        cout<<"Item # "<<ind<<" sold(out of stock)"<<endl;
                        else if (quantity[ind] - qty < 0) 
                        {
                            cout << "Only " << quantity[ind] << " pieces sold instead of "<<qty<<"(out of stock)"<< endl;
                        }
                        for(int i=ind;i<n-1;i++)
                        {
                            quantity[i]=quantity[i+1];
                        }
                        n--;
                        int* arr=new int[n];
                        for(int i=0;i<n;i++)
                        {
                            arr[i]=quantity[i];
                        }
                        delete[] quantity;
                        quantity=arr;
                    }
                    else if(quantity[ind]-qty>0)
                    {
                        quantity[ind]-=qty;
                    }
                }
                break;
            }
            case 3:
            {
                if(n==0)
                {
                    cout<<"The list is empty!"<<endl;
                }
                else
                {
                    for(int i=0;i<n;i++)
                    {
                        cout<<"Item "<<i<<": "<<quantity[i]<<" pcs"<<endl;
                    }
                }
                break;
            }
            default:
            {
                cout<<"Thank you for using our program";
                delete[] quantity;   
                return 0;
            }
        }
    }
}