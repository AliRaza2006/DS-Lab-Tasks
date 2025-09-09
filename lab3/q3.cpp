#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class node
{
    public:
    node* next;
    int seat;
    bool avlbl;
    node():next(nullptr),avlbl(false){}
    node(int num,bool state):seat(num),avlbl(state),next(nullptr){}
};
class linkedList
{
    public:
    node* head;
    node* curr;
    linkedList():head(nullptr),curr(nullptr){}
    void InsertAtEnd(int i)
    {
        if(!head)
        {
            head=new node(i,rand()%2==1?true:false);
            head->next=head;
            curr=head;
            return;
        }
        curr->next=new node(i,rand()%2==1?true:false);
        curr->next->next=head;
        curr=curr->next;
    }
    void printSeats()
    {
        if(!head)
        {
            cout<<"No seats!"<<endl;
        }
        node*temp=head;
        do
        {
            cout<<"Seat "<<temp->seat<<": "<<(temp->avlbl?"Available":"Not Available")<<endl;
            temp=temp->next;
        }
        while(temp!=head);
    }
};
int main()
{
    srand(time(0));
    int n;
    cout<<"How many seats: ";
    cin>>n;
    linkedList l;
    for(int i=0;i<n;i++)
    {
        l.InsertAtEnd(i+1);
    }
    int choice;
    while(1)
    {
        cout<<"\n1. Book a seat\n2. Add a seat\n3. Print Seats\n4. Exit\nChoice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                {
                    node* temp=l.head;
                    bool booked=false;
                    do
                    {
                        if(temp->avlbl)
                        {
                            cout<<"Seat "<<temp->seat<<" booked"<<endl;
                            temp->avlbl=false;
                            booked=true;
                            break;
                        }
                        temp=temp->next;
                    }while(temp!=l.head);
                    if(!booked)
                    cout<<"No seats Available!\n";
                    break;
                }
            case 2:
                l.InsertAtEnd(++n);
                l.curr->avlbl=true;
                break;
            case 3:
                l.printSeats();
                break;
            case 4:
                cout<<"Exiting...";
                return 0;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }
}