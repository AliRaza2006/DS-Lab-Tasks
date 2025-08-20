#include<iostream>
using namespace std;
/*Q3. Create a C++ classInventory that stores a list of item prices using DMA. The size of the
inventory will be provided during object creation. Implement a deep copy constructor so that if
one inventory object is copied to another, changes in one will not affect the other. In your
program, create one inventory with some prices, copy it to another inventory, update a price in
the copied version, and display both to verify they are separate.*/
class Inventory
{
    private:
    int size;
    double* price;
    public:
    Inventory(int s,double* p)
    {
        size=s;
        price=new double[size];
        for(int i=0;i<size;i++)
        {
            price[i]=p[i];
        }
    }
    Inventory(const Inventory& inv)
    {
        size=inv.size;
        price=new double[inv.size];
        for(int i=0;i<inv.size;i++)
        {
            price[i]=inv.price[i];
        }
    }
    Inventory& operator=(const Inventory& inv)
    {
        if(this!=&inv)
        {
            delete[] price;
            size=inv.size;
            price=new double[inv.size];
            for(int i=0;i<inv.size;i++)
            {
                price[i]=inv.price[i];
            }
        }
        return *this;
    }
    void display() const
    {
        cout<<"Size: "<<size<<endl;
        cout<<"Prices: ";
        for(int i=0;i<size;i++)
        {
            if(i==size-1)
            {
                cout<<price[i]<<endl;
            }
            else
            {
                cout<<price[i]<<", ";
            }
        }
    }
    void setPriceAtIndex(int index,double updatedPrice)
    {
        if(index<0 || index>=size)
        {
            cout<<"Out of bounds access!"<<endl;
            return;
        }
        price[index]=updatedPrice;
    }
    ~Inventory()
    {
        delete[] price;
    }
};
void displayTwoInventories(const Inventory& inv,const Inventory& inv2)
{
    cout<<"Inventory 1: "<<endl;
    inv.display();
    cout<<endl;
    cout<<"Inventory 2: "<<endl;
    inv2.display();
    cout<<endl;
}
int main()
{
    double prices[]={12.5,10.5,5.2,5.0,6.125};
    Inventory inv(sizeof(prices)/sizeof(prices[0]),prices);
    cout<<"Inventories before any change: "<<endl;
    Inventory inv2(inv);
    displayTwoInventories(inv,inv2);
    inv2.setPriceAtIndex(0,370);
    inv2.setPriceAtIndex(1,290);
    cout<<"Inventories after changes: "<<endl;
    displayTwoInventories(inv,inv2);
}