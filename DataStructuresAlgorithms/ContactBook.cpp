#include <iostream>


using namespace std;

int length( char *array );
int LinearSearch ( int *array, int size, int search_number);
void reverse_string ( char *array);




class CONTACT
{
private:
    int ID;
    string name;
    string email;
    long long int number;
public:
    CONTACT()
    {
        ID=0;
        number=0;
        name="";
        email="";
    }


    CONTACT(int id, string input_name, long long int num)
    {
        ID = id;
        number=num;
        name=input_name;
    }


    CONTACT(int id, string input_name, string input_email, long long int num)
    {

        ID = id;
        number=num;
        name=input_name;
        email=input_email;
    }
    void setID (int id)
    {
        ID=id;
    }
    int getID ()
    {
        return ID;
    }

    void setName (string NAME)
    {
        name=NAME;
    }

    string getName()
    {
        return name;
    }


    void setEmail ( string EMAIL )
    {
        email=EMAIL;
    }

    string getEmail()
    {
        return email;
    }

    void setNumber (long long int NUMBER )
    {
        number=NUMBER;
    }

    long long int getNumber()
    {
        return number;
    }

    void Display()
    {
        int i=0;

        cout<<"\nName : "<<name<<endl;
        cout<<"ID : "<<ID<<endl;
        cout<<"Email : "<<email<<endl;
        cout<<"Number : "<<number<<"\n"<<endl;
    }

};

class CONTACTS
{
private:
    CONTACT List[20];
    int lastID;
public:
    CONTACTS()
    {
        lastID=0;
    }

    void add ( int user_id, string user_name, string user_email, long long int user_number )
    {
        List[lastID].setID(user_id);
        List[lastID].setName(user_name);
        List[lastID].setEmail(user_email);
        List[lastID].setNumber(user_number);
        ++lastID;
    }
    void Search_By_Number (long long int search_number)
    {
        int i=0;
        while(i<=lastID)
        {
            if(List[i].getNumber()==search_number)
            {
                cout<<"Contact Found"<<endl;
                List[i].Display();
                return;
            }
            ++i;
        }
        cout<<"\t\n Contact Not Found !"<<endl;
    }
    void Search_By_Name( string search_name)
    {
        string z;
        for(int i=0; i<lastID; ++i)
        {

            z=List[i].getName();
            if(z==search_name)
            {
                cout<<"\nContact Found !\a"<<endl;
                List[i].Display();
                return;
            }
        }
        cout<<"\t\n Contact Not Found !"<<endl;

    }
    int Memory_Status ()
    {
        int memory_status =0,  i=0;
        while(i<lastID)
        {
            ++memory_status;
            ++i;
        }
        return memory_status;
    }

    void Display_All_Contacts ()
    {
        int i=0;
        while(i<lastID)
        {
            cout<<"Contact : "<<i+1<<endl;
            List[i].Display();
            ++i;
            cout<<endl;
        }
    }

    void Delete_Contact (long long int delete_no)
    {
        int i=0;
        while(i<lastID)
        {
            if( delete_no == List[i].getNumber() )
            {
                for(i; i<lastID; ++i)
                {
                    List[i].setName(List[i+1].getName());
                    List[i].setID(List[i+1].getID());
                    List[i].setEmail(List[i+1].getEmail());
                    List[i].setNumber(List[i+1].getNumber());
                }

                List[i].setName("");
                List[i].setID(0);
                List[i].setEmail("");
                List[i].setNumber(0);

                --lastID;

                break;
            }
            ++i;
        }
    }

};

int main()
{

    CONTACTS My_Contacts;

    char control = 'c';
    int select=0;

    while(control=='c' || control=='C')
    {
        cout<<"\nContacts List\n"
            <<"     1).  Add"<<endl
            <<"     2).  Search By Number"<<endl
            <<"     3).  Search By Name"<<endl
            <<"     4).  Delete Contact"<<endl
            <<"     5).  Memory Status"<<endl
            <<"     6).  Display All Contacts"<<endl
            <<"\nArray Searching\n"
            <<"     7).  Linear Search"<<endl

            <<"\n String \n"
            <<"     9).  Reverse String\n"
            <<"     10). Length of String\n";

        cout<<"\nEnter Task No.  To Execute : ";
        cin>>select;
        cout<<endl;

        switch(select)
        {
        case 1:
        {
            if(My_Contacts.Memory_Status()>=20)
            {
                cout<<"\nMemory Full !\a"<<endl;
                break;
            }
            int id;
            long long int number;
            string user_name, user_email;
            cout<<"_______________________________________________________________________________\n"<<endl;
            cout<<"Add Contact\n"<<endl;

            cout<<"Contact Name : ";
            cin.ignore();
            getline(cin,user_name);
            cout<<endl;
            cout<<"Contact Email : ";
            cin>>user_email;
            cout<<"Contact ID : ";
            cin>>id;
            cout<<"Contact Number : ";
            cin>>number;
            My_Contacts.add(id,user_name,user_email,number);
            cout<<"_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 2:
        {
            long long int number=0;

            cout<<"_______________________________________________________________________________\n"<<endl;
            cout<<"Search Number : ";
            cin>>number;
            My_Contacts.Search_By_Number(number);
            cout<<"\n_______________________________________________________________________________\n"<<endl;

            break;
        }
        case 3:
        {
            string n;

            cout<<"\n_______________________________________________________________________________\n"<<endl;
            cout<<"Search Name : ";
            cin.ignore();
            getline(cin,n);
            My_Contacts.Search_By_Name(n);
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 4:
        {
            long long int delete_no;
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            cout<<"Delete Contact\nEnter Number : ";
            cin>>delete_no;
            My_Contacts.Delete_Contact(delete_no);
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 5:
        {
            cout<<"\a\n_______________________________________________________________________________\n"<<endl;
            cout<<"\t\t\tContacts Stored : "<<My_Contacts.Memory_Status();
            cout<<"\a\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 6:
        {
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            My_Contacts.Display_All_Contacts();
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 7:
        {
            cout<<"\n\nLinear Search\n"<<endl;
            int size=7, search_no=0;
            int array[size]= {1,2,3,4,5,6,7};
            cout<<"Array Data"<<endl;
            for(int i=0; i<size; ++i)
            {
                cout<<array[i]<<" ";
            }
            cout<<"\nSearch Number : ";
            cin>>search_no;

            cout<<"Result Index : "<<LinearSearch(array,size,search_no);
            break;
        }
        case 9:
            {
                char str[25];
                cin>>str;
                reverse_string(str);
                cout<<"Array Data"<<endl;
                for(int i=0; i<25; ++i)
                {
                    cout<<str[i]<<" ";
                }
                break;
            }
        case 10:
            {
                char str[20];
                cout<<"Enter Your Name : ";
                cin>>str;
                cout<<"Length of Array : "<<length(str)<<endl;
                break;
            }
        default:
            cout<<" InCorrect Input "<<endl;
        }
        cout<<" Continue c  /  Stop s  ? : ";
        cin>>control;
    }
}

void reverse_string ( char *array)
{
    int i;
    char *begin_ptr, *end_ptr, ch;
    int len = length(array);
    begin_ptr = array;
    end_ptr = array;
    for (i = 0; i < len ; i++)
        end_ptr++;
    for (i = 0; i < len / 2; i++) {
        ch = *end_ptr;
        *end_ptr = *begin_ptr;
        *begin_ptr = ch;

        begin_ptr++;
        end_ptr--;
    }
}



int length( char *array )
{
    int length=0;
    while(*array !='\0')
    {
        ++length;
        ++array;
    }
    return length;
}

int LinearSearch ( int *array, int size, int search_number)
{
    int i=0;
    for(i=0; i%2!=0 && i<size; ++i)
    {
        if( array[i] == search_number )
        {
            return i;
        }
    }
    return -1;
}
