#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Room
{
    int roomNo;
    string type;
    bool booked;
    string customerName;
    string phone;
    int days;
    float pricePerDay;
};

Room rooms[10];

void initializeRooms()
{
    for(int i=0;i<10;i++)
    {
        rooms[i].roomNo = 101 + i;
        rooms[i].booked = false;

        if(i<4)
        {
            rooms[i].type="Single";
            rooms[i].pricePerDay=1000;
        }
        else if(i<7)
        {
            rooms[i].type="Double";
            rooms[i].pricePerDay=1800;
        }
        else
        {
            rooms[i].type="Deluxe";
            rooms[i].pricePerDay=3000;
        }
    }
}

void viewRooms()
{
    cout<<"\n================ AVAILABLE ROOMS ================\n";
    cout<<left<<setw(15)<<"Room No"
        <<setw(20)<<"Room Type"
        <<setw(15)<<"Status"<<endl;

    cout<<"-------------------------------------------------\n";

    for(int i=0;i<10;i++)
    {
        cout<<left<<setw(15)<<rooms[i].roomNo
            <<setw(20)<<rooms[i].type
            <<setw(15)<<(rooms[i].booked?"Booked":"Available")
            <<endl;
    }
}

void bookRoom()
{
    int room;

    viewRooms();

    cout<<"\nEnter Room Number: ";
    cin>>room;

    for(int i=0;i<10;i++)
    {
        if(rooms[i].roomNo==room)
        {
            if(rooms[i].booked)
            {
                cout<<"\nRoom Already Booked.\n";
                return;
            }

            cin.ignore();

            cout<<"Enter Customer Name : ";
            getline(cin,rooms[i].customerName);

            cout<<"Enter Phone Number : ";
            getline(cin,rooms[i].phone);

            cout<<"Enter Number of Days : ";
            cin>>rooms[i].days;

            rooms[i].booked=true;

            cout<<"\nRoom Booked Successfully.\n";
            return;
        }
    }

    cout<<"\nInvalid Room Number.\n";
}

void customerDetails()
{
    bool found=false;

    cout<<"\n================ CUSTOMER DETAILS ================\n";

    cout<<left
        <<setw(10)<<"Room"
        <<setw(20)<<"Name"
        <<setw(18)<<"Phone"
        <<setw(10)<<"Days"
        <<setw(15)<<"Room Type"<<endl;

    cout<<"---------------------------------------------------------------\n";

    for(int i=0;i<10;i++)
    {
        if(rooms[i].booked)
        {
            found=true;

            cout<<left
                <<setw(10)<<rooms[i].roomNo
                <<setw(20)<<rooms[i].customerName
                <<setw(18)<<rooms[i].phone
                <<setw(10)<<rooms[i].days
                <<setw(15)<<rooms[i].type
                <<endl;
        }
    }

    if(!found)
        cout<<"\nNo Customer Records Found.\n";
}

void generateBill()
{
    int room;

    cout<<"\nEnter Room Number: ";
    cin>>room;

    for(int i=0;i<10;i++)
    {
        if(rooms[i].roomNo==room)
        {
            if(!rooms[i].booked)
            {
                cout<<"\nRoom is Not Booked.\n";
                return;
            }

            float total=rooms[i].days*rooms[i].pricePerDay;
            float gst=total*0.18;
            float finalBill=total+gst;

            cout<<"\n============== BILL SUMMARY ==============\n";

            cout<<"Customer Name : "<<rooms[i].customerName<<endl;
            cout<<"Phone Number  : "<<rooms[i].phone<<endl;
            cout<<"Room Number   : "<<rooms[i].roomNo<<endl;
            cout<<"Room Type     : "<<rooms[i].type<<endl;
            cout<<"Days Stayed   : "<<rooms[i].days<<endl;
            cout<<"Rate/Day      : Rs. "<<rooms[i].pricePerDay<<endl;
            cout<<"------------------------------------------\n";
            cout<<"Room Charge   : Rs. "<<total<<endl;
            cout<<"GST (18%)     : Rs. "<<gst<<endl;
            cout<<"------------------------------------------\n";
            cout<<"Total Bill    : Rs. "<<finalBill<<endl;
            cout<<"==========================================\n";

            return;
        }
    }

    cout<<"\nInvalid Room Number.\n";
}

int main()
{
    initializeRooms();

    int choice;

    do
    {
        cout<<"\n=========================================\n";
        cout<<"      HOTEL MANAGEMENT SYSTEM\n";
        cout<<"=========================================\n";
        cout<<"1. Book Room\n";
        cout<<"2. View Available Rooms\n";
        cout<<"3. Customer Details\n";
        cout<<"4. Generate Bill\n";
        cout<<"5. Exit\n";
        cout<<"=========================================\n";
        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                bookRoom();
                break;

            case 2:
                viewRooms();
                break;

            case 3:
                customerDetails();
                break;

            case 4:
                generateBill();
                break;

            case 5:
                cout<<"\nThank You for Using Hotel Management System.\n";
                break;

            default:
                cout<<"\nInvalid Choice.\n";
        }

    }while(choice!=5);

    return 0;
}