#include <iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
        int product_code;
        float price;
        float dis;
        string product_name;

    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem_product();
        void list();
        void receipt();

};

void shopping :: menu()
{
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t           Supermarket Main Menu          \n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t|    1) Administrator"<<endl;
    cout<<"\t\t\t\t|    2) Buyer"<<endl; 
    cout<<"\t\t\t\t|    3) Exit"<<endl<<endl;
    cout<<"\t\t\t\t|    Please Select"<<endl;

    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login"<<endl;
            cout<<"\t\t\t Enter Email"<<endl;
            cin>>email;
            cout<<endl<<"\t\t\t Enter Password"<<endl;
            cin>>password;

            if(email="admin@email.com" && password="admin@123")
            {
                administrator();
            }
            else
            {
                cout<<"Invalid email/password!!!"<<endl;
            }
        
        case 2:
        {
            buyer();
        }

        default:
        {
            cout<<"\t\t Please Select from the Given Option"<<endl;
        }

    }

}

