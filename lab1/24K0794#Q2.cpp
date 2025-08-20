#include<iostream>
using namespace std;
/*Create a MovieTicket class to manage bookings. The class should store the movie name (use
DMA) and the seat number. Implement the Rule of Three by writing a destructor, a copy
constructor, and a copy assignment operator to ensure deep copying of data. In your program,
create one ticket, make a copy of it, and also assign it to another ticket object. Then change the
movie name in one of the copies and confirm that the original booking remains unaffected.*/
class MovieTicket
{
    private:
    string* movieName;
    int seatNumber;
    public:
    MovieTicket(string mn,int sn):seatNumber(sn){
        movieName=new string(mn);
    }
    MovieTicket()
    {
        movieName=new string("Movie");
        seatNumber=1;
    }
    MovieTicket(const MovieTicket& m)
    {
        seatNumber=m.seatNumber;
        movieName=new string(*m.movieName);
    }
    MovieTicket& operator=(const MovieTicket&m)
    {
        if(this!=&m)
        {
            delete movieName;
            seatNumber=m.seatNumber;
            movieName=new string(*m.movieName);
        }
        return *this;
    }
    int getSeatNumber()const{return seatNumber;}
    string getMovieName()const{return *movieName;}
    void setSeatNumber(int num){seatNumber=num;}
    void setMovieName(string name){*movieName=name;}
    ~MovieTicket()
    {
        delete movieName;
    }
};
void displayall(const MovieTicket& t1,const MovieTicket& t2,const MovieTicket& t3)
{
    cout<<"Ticket 1: "<<endl;
    cout<<"Movie Name: "<<t1.getMovieName()<<endl;
    cout<<"Seat number: "<<t1.getSeatNumber()<<endl<<endl;

    cout<<"Ticket 2: "<<endl;
    cout<<"Movie Name: "<<t2.getMovieName()<<endl;
    cout<<"Seat number: "<<t2.getSeatNumber()<<endl<<endl;

    cout<<"Ticket 3: "<<endl;
    cout<<"Movie Name: "<<t3.getMovieName()<<endl;
    cout<<"Seat number: "<<t3.getSeatNumber()<<endl<<endl;
}
int main()
{
    MovieTicket t1("Demon Slayer: Kimetsu no Yaiba Infinity Castle",14);
    MovieTicket t2(t1);//copy constructor
    MovieTicket t3;
    t3=t1;//copy assignment operator
    cout<<"Tickets before changing movies name: "<<endl;
    displayall(t1,t2,t3);
    t2.setMovieName("Attack on Titan the Movie: The Last Attack");
    t3.setMovieName("Interstellar");
    cout<<"Tickets after changing movies name: "<<endl;
    displayall(t1,t2,t3);
}