#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

class Contact
{
public:
    string name;
    string phone;
    string email;
    string address;
};

const string filename = "contacts.txt";

int totalContacts = 0;

//----------------------------------------------------------
void updateCount()
{
    ifstream fin(filename);
    Contact c;
    totalContacts = 0;

    while (getline(fin, c.name))
    {
        getline(fin, c.phone);
        getline(fin, c.email);
        getline(fin, c.address);
        totalContacts++;
    }
    fin.close();
}

//----------------------------------------------------------
void systemInfo()
{
    updateCount();

    time_t now = time(0);
    char *dt = ctime(&now);

    cout << "\n=============================================\n";
    cout << "              SYSTEM INFORMATION\n";
    cout << "=============================================\n";
    cout << "Total Contacts   : " << totalContacts << endl;
    cout << "File Name        : " << filename << endl;
    cout << "Storage Location : Current Project Folder\n";
    cout << "Last Update      : " << dt;
    cout << "=============================================\n";
}

//----------------------------------------------------------
void addContact()
{
    Contact c;

    cin.ignore();

    cout << "\nEnter Name    : ";
    getline(cin, c.name);

    cout << "Enter Phone   : ";
    getline(cin, c.phone);

    cout << "Enter Email   : ";
    getline(cin, c.email);

    cout << "Enter Address : ";
    getline(cin, c.address);

    ofstream fout(filename, ios::app);

    fout << c.name << endl;
    fout << c.phone << endl;
    fout << c.email << endl;
    fout << c.address << endl;

    fout.close();

    cout << "\nContact Added Successfully.\n";
}

//----------------------------------------------------------
void viewContacts()
{
    ifstream fin(filename);

    Contact c;

    if (!fin)
    {
        cout << "\nNo Contact File Found.\n";
        return;
    }

    cout << "\n==============================================================\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Name"
         << setw(18) << "Phone"
         << setw(25) << "Email"
         << setw(25) << "Address" << endl;
    cout << "==============================================================\n";

    int i = 1;

    while (getline(fin, c.name))
    {
        getline(fin, c.phone);
        getline(fin, c.email);
        getline(fin, c.address);

        cout << left
             << setw(5) << i++
             << setw(20) << c.name
             << setw(18) << c.phone
             << setw(25) << c.email
             << setw(25) << c.address
             << endl;
    }

    fin.close();

    if (i == 1)
        cout << "\nNo Contacts Available.\n";
}

//----------------------------------------------------------
void searchContact()
{
    ifstream fin(filename);

    Contact c;

    string key;

    cin.ignore();

    cout << "\n==============================\n";
    cout << "        SEARCH CONTACT\n";
    cout << "==============================\n";

    cout << "Search Name : ";
    getline(cin, key);

    bool found = false;

    while (getline(fin, c.name))
    {
        getline(fin, c.phone);
        getline(fin, c.email);
        getline(fin, c.address);

        if (c.name == key)
        {
            cout << "\nContact Found\n";
            cout << "-------------------------\n";
            cout << "Name    : " << c.name << endl;
            cout << "Phone   : " << c.phone << endl;
            cout << "Email   : " << c.email << endl;
            cout << "Address : " << c.address << endl;

            found = true;
            break;
        }
    }

    fin.close();

    if (!found)
        cout << "\nContact Not Found.\n";
}

//----------------------------------------------------------
void deleteContact()
{
    ifstream fin(filename);

    ofstream temp("temp.txt");

    Contact c;

    string key;

    cin.ignore();

    cout << "\nEnter Contact Name to Delete : ";
    getline(cin, key);

    bool found = false;

    while (getline(fin, c.name))
    {
        getline(fin, c.phone);
        getline(fin, c.email);
        getline(fin, c.address);

        if (c.name != key)
        {
            temp << c.name << endl;
            temp << c.phone << endl;
            temp << c.email << endl;
            temp << c.address << endl;
        }
        else
        {
            found = true;
        }
    }

    fin.close();
    temp.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (found)
        cout << "\nContact Deleted Successfully.\n";
    else
        cout << "\nContact Not Found.\n";
}

//----------------------------------------------------------
void saveContact()
{
    cout << "\nAll Contacts are Permanently Saved in File.\n";
}

//----------------------------------------------------------
int main()
{
    int choice;

    do
    {
        system("cls"); // Use "clear" for Linux

        cout << "\n==============================================\n";
        cout << "      CONTACT MANAGEMENT SYSTEM\n";
        cout << "==============================================\n";
        cout << "1. Add Contact\n";
        cout << "2. View All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Save Contact\n";
        cout << "6. System Information\n";
        cout << "7. Exit\n";
        cout << "==============================================\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            viewContacts();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            deleteContact();
            break;

        case 5:
            saveContact();
            break;

        case 6:
            systemInfo();
            break;

        case 7:
            cout << "\nThank You for Using Contact Management System.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

        if (choice != 7)
        {
            cout << "\nPress Enter to Continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 7);

    return 0;
}