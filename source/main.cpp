#include <iostream>
#include<fstream>
#include<cctype>

using namespace std;

//The main Shopping Class
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

//Menu Function for showing the menu
void shopping :: menu() 
{   
    m:
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
    cout<<endl<<endl;

    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t Please Login"<<endl<<endl;
            cout<<"\t\t\t Enter Email"<<endl;
            cin>>email;
            cout<<endl<<"\t\t\t Enter Password"<<endl;
            cin>>password;

            if(email=="admin@email.com" && password=="admin@123")
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

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout<<"\t\t Please Select from the Given Option"<<endl;
        }

    }

    goto m;
}

void shopping::administrator()
{   m:
    int choice;
    cout<<endl<<endl<<endl<<"\t\t\t Admin Menu"<<endl;
    cout<<"\t\t\t| 1) Add a product"<<endl;
    cout<<"\t\t\t| 2) Modify the product"<<endl;
    cout<<"\t\t\t| 3) Delete the the product"<<endl;
    cout<<"\t\t\t| 4) Back to the main menu"<<endl;

    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;

        case 3:
            rem_product();
            break;
        case 4:
            menu();
            break;
        
    }
    goto m;
}

void shopping::buyer()
{
    int choice;
    cout<<"\t\t\t Buyer"<<endl<<endl;
    cout<<"\t\t\t 1) Buyer"<<endl;
    cout<<"\t\t\t 2) Go Back"<<endl;
    
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();

        default:
            cout<<"invalid choice"<<endl;
    }

}

void shopping::add()
{
    m:
    fstream data;
    int c;
    int token;
    float p;
    float d;
    string n;

    cout<<endl<<endl<<endl<<"\t\t\t Add a new product";
    cout<<endl<<endl<<"\t Product code of your product: ";
    cin>>product_code;
    cout<<endl<<endl<<"Name of the product: ";
    cin>>product_name;
    cout<<endl<<endl<<"\tPrice of the product: ";
    cin>>price;
    cout<<endl<<endl<<"\t Discount on product: ";
    cin>>dis;

    data.open("database.txt",ios::app|ios::out);

    if (data.is_open())
    {
        data.open("database.txt, ios::app|ios::out");
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
        data.close();
    }

    else{
        data>>c>>n>>p>>d;

        while (!data.eof()) 
        {
            if(c == product_code)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }

    if(token == 1)
    {
        shopping::add();
    }

    else
    {
        data.open("database.txt, ios::app|ios::out");
        data<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    cout<<endl<<endl<<"\t Record Inserted!"<<endl;

}

void shopping::edit()
{
    fstream data, data1;
    int product_key;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<endl<<"\t\t\tModified the record";
    cout<<endl<<"\t\t\t Product Code :";

    cin>>product_key;

    data.open("database.txt", ios::in);

    if(!data)
    {
        cout<<endl<<endl<<"File Does not Exist"<<endl;
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);

        data>>product_code>>product_name>>price>>dis;
        while(!data.eof())
        {
            if(product_key==product_code)
            {
                cout<<endl<<"\t\t Product new code : ";
                cin>>c;
                cout<<endl<<"\t\t Name of the product: ";
                cin>>n;
                cout<<endl<<"\t\t Price: ";
                cin>>p;
                cout<<endl<<"\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;

                cout<<endl<<endl<<"\t\t Record editted"<<endl;
                token++;
            }

            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
            }

            data>>product_code>>product_name>>price>>dis;
        }
        data.close();
        data1.close();


        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<endl<<endl<<"Record not found";
        }
    }
}

void shopping::rem_product()
{
    fstream data,data1;
    int product_key;
    int token=0;
    cout<<endl<<endl<<"\tDelete Product";
    cout<<endl<<endl<<"\t Product Code: ";
    cin>>product_key;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>product_code>>product_name>>price>>dis;
        while(!data.eof())
        {
            if(product_code==product_key)
            {
                cout<<endl<<endl<<"\t Product Deleted Succesfully";
            }
            else
            {
                data1<<" "<<product_code<<" "<<product_name<<" "<<price<<" "<<dis<<endl;
            }
            data>>product_code>>product_name>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token==0)
        {
            cout<<endl<<endl<<"Record not found"; 
        }

    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<endl<<endl<<"_______________________________"<<endl;
    cout<<"Product-No \t\t Name \t\t Price"<<endl;
    cout<<endl<<endl<<"_______________________________"<<endl;
    data>>product_code>>product_name>>price>>dis;
    while(!data.eof())
    {
        cout<<product_code<<"\t\t"<<product_name<<price<<endl;
        data>>product_code>>product_name>>price>>dis;
    }
    data.close();
}

void shopping:: receipt()
{   m:
    fstream data;

    int arr_codes[100];
    int arr_quantity[100];
    char choice;
    int c=0;
    float amount = 0;
    float dis =0;
    float total=0;


    cout<<endl<<"\t\t\t\t Receipt"<<endl;
    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<endl<<endl<<"Empty Database";
    }
    else
    {
        data.close();
        list();
        cout<<endl<<"________________________________"<<endl;
        cout<<endl;
        cout<<"               Please Place the order"<<endl;
        cout<<endl;
        cout<<endl<<"________________________________"<<endl;

        do
        {
            cout<<endl<<"Enter Product Code : ";
            cin>>arr_codes[c];
            cout<<endl<<endl<<"Enter The product Quantity: ";
            cin>>arr_quantity[c];
            for(int i=0; i<c; i++)
            {
                if(arr_codes[c]==arr_codes[i])
                {
                    cout<<endl<<endl<<"Duplicate Product Code. Try Again";
                    goto m;
                }
            }
            c++;
            cout<<endl<<endl<<"Do you want to buy another product? Y/N";
            cin>>choice;
        }
        while(tolower(choice) == 'y');

        cout<<endl<<endl<<"\t\t\t____________________Recipt____________________"<<endl;
        cout<<endl<<"Product No.\t Product Quantity\t Price\t Amount\t Amount with Discount"<<endl;

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>product_code>>product_name>>price>>dis;
            while(!data.eof())
            {
                if(product_code==arr_codes[i])
                {
                    amount=price+arr_quantity[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<endl<<product_code<<"\t\t"<<product_name<<"\t\t"<<arr_quantity<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                }
                data>>product_code>>product_name>>price>>dis;
            }
        
        }
        data.close();
        

    }

    cout<<endl<<endl<<"_________________________________________________"<<endl;
    cout<<"Total Amount: "<<total;

}

int main()
{
    shopping s;
    s.menu();
}