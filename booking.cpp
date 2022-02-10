#include<iostream>
#include<vector>
#include "movie.cpp"

using namespace std;



int main(){
    system("cls");
    Movie m1;
    Movie m2;
    
    while(true){
        REENTER:
        cout<<"--------------------------------Welcome to Online Movie Ticket Booking-------------------------------"<<endl;
        cout<<"(1)  Book Ticket   "<<endl;
        cout<<"(2)  Check Availability   "<<endl;
        cout<<"(3)  Exit"<<endl;
        cout<<"-------Enter Your Choice---------"<<endl;

        int ch; cin>>ch;
        switch (ch)
        {
        case 1:
        {
            MOVIECHOICE:
            cout<<"-------------------The Movies Running are :------------------------"<<endl;
            cout<<"(1) Avengers : Endgame"<<endl;
            cout<<"(2) Spiderman : No Way Home"<<endl;
            cout<<"------------Enter Your Choice-----------"<<endl;
            
            int mvch; cin>>mvch;
            // Movie 1
            if(mvch == 1){
                m1.display();
                cout<<endl;

                vector<pair<int, int>> seatno;

                cout<<"Enter Number of Tickets for Movie 1 :- ";
                int n; cin>>n;

                bool available = m1.checkAvailibility(n);

                if(available){
                    RESELECT1:
                    cout<<"Enter Seat Coordinates :- (row, column) "<<endl;
                    for(int i = 0; i < n; i++){
                        int r,c;
                        cin>>r>>c;
                        if(m1.checkSeatAvailibility(r,c))
                            seatno.push_back({r,c});

                        else{
                            cout<<"Seat Not Available..... Please Reselect"<<endl;
                            goto RESELECT1;
                        }
                    }
                    m1.bookTickets(seatno);
                    cout<<"Tickets Booked Successfully for Movie 1. "<<endl;
                    goto REENTER;
                }
                else{
                    cout<<"Sorry Movie is HOUSEFULL"<<endl;
                    break;
                }
            }
            // Movie 2
            if(mvch == 2){
                m2.display();
                cout<<endl;

                vector<pair<int, int>> seatno;

                cout<<"Enter Number of Tickets for Movie 2 :- ";
                int n; cin>>n;

                bool available = m1.checkAvailibility(n);

                if(available){
                    RESELECT2:
                    cout<<"Enter Seat Coordinates :- (row, column) "<<endl;
                    for(int i = 0; i < n; i++){
                        int r,c;
                        cin>>r>>c;
                        if(m2.checkSeatAvailibility(r,c))
                            seatno.push_back({r,c});

                        else{
                            cout<<"Seat Not Available..... Please Reselect"<<endl;
                            goto RESELECT2;
                        }
                    }
                    m2.bookTickets(seatno);
                    cout<<"Tickets Booked Successfully for Movie 1. "<<endl;
                    goto REENTER;
                }
                else{
                    cout<<"Sorry Movie is HOUSEFULL"<<endl;
                    break;
                }
            }
            else{
                cout<<"Invalid Choice........."<<endl;
                goto MOVIECHOICE;
            }
            break;
        }
        case 2:
        {
            DISPLAYM:
            cout<<"-------------------The Movies Running are :------------------------"<<endl;
            cout<<"(1) Avengers : Endgame"<<endl;
            cout<<"(2) Spiderman : No Way Home"<<endl;
            cout<<"------------Enter Your Choice-----------"<<endl;
            
            int mvch; cin>>mvch;
            if(mvch == 1){
                m1.display();
                goto REENTER;
            }

            if(mvch == 2){
                m2.display();
                goto REENTER;
            }
            else{
                cout<<"Invalid Choice..... Renter Movie"<<endl;
                goto DISPLAYM;
            }
            break;
        }
        case 3:
        {
            goto EXIT;
            break;
        }
        default:
            cout<<"Invalid Choice.......Please re enter"<<endl;
            goto REENTER;
        }
    }
    EXIT:

    return 0;
}
