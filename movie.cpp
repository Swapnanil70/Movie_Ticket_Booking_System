#include<vector>
#include<iostream>

using namespace std;

class Movie{
    private : 
    char seats[10][10];
    int available_seatCount;

    public:
        //Constructor to initialize the seat arrangement.
        Movie(){
            available_seatCount = 100;
            for (int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++){
                    seats[i][j] = 'A';
                }
            }
        }
        void updateSeats(){
            int count = 0;
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    if(seats[i][j] == 'A')
                        count++;
                }
            }
            available_seatCount = count;
        }
        bool checkSeatAvailibility(int r, int c){
            if(r > 10 || c > 10)
                return false;

            if(seats[r-1][c-1] == 'A')
                return true;

            else
                return false;
        }
        // Function to check Available Tickets.
        bool checkAvailibility(int n){
            if(n > available_seatCount)
                return false;

            else
                return true;
        }
        // Function to Book tickets.
        void bookTickets(vector<pair<int, int>> seatno){
            //book seats.
            for(int i = 0; i < seatno.size(); i++){
                
                int x = seatno[i].first - 1;
                int y = seatno[i].second - 1;

                seats[x][y] = 'B';
            }
            //Covid 19 precaution gap
            
            for(int i = 0; i < seatno.size(); i++){

                int x = seatno[i].first - 1;
                int y = seatno[i].second - 1;
                if(x == 0 && seats[x][y+1] != 'B'){
                    seats[x][y+1] = 'C';
                } 
                else if(seats[x][y+1] != 'B'){
                    seats[x][y+1] = 'C';
                }
                if(seats[x][y-1] != 'B'){
                    seats[x][y-1] = 'C';
                }
                else if(y == 9 && seats[x][y-1] != 'B'){
                    seats[x][y-1] = 'C';
                }
            }
            updateSeats();
        }
        // Function to display available seats.
        void display(){
            cout<<"A -------> Available Seat"<<endl;
            cout<<"B -------> Booked Seat"<<endl;
            cout<<"C -------> Covid-19 Precaution Seat Gap"<<endl;
            cout<<"Available seats :- "<<available_seatCount;
            cout<<endl;
            cout<<"  ";
            for(int i = 0; i < 10; i++)
                cout<<i+1<<" ";

            cout<<endl;

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){

                    if(j == 0)
                        cout<<i+1<<" ";

                    cout<<seats[i][j]<<" ";
                }
                cout<<endl;
            }
        }
};