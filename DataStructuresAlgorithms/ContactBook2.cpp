#include <iostream>
#include <fstream>
using namespace std;

int Words ( string file_name);
int Lines ( string file_name);
int FindinFile ( string file_name, string search);
void appendToFile ( string file_name, string input_data);

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
            cout<<"\t\tContact : "<<i+1<<endl;
            List[i].Display();
            ++i;
            cout<<endl;
        }
    }

    void Export ( string file_name )
    {
        int i=0;
        string data;
        long long int number;
        ofstream write;
        write.open(file_name.c_str());
        while(i<lastID)
        {
            data=List[i].getName();
            write<<data<<endl;

            data=List[i].getEmail();
            write<<data<<endl;

            number=List[i].getID();
            write<<number<<endl;

            number=List[i].getNumber();
            write<<number<<endl;
            ++i;
        }
        write.close();
    }

    void Import ( string file_name )
    {
        int i=0;
        string name, email;
        long long int number;
        int id;
        ifstream read;
        read.open(file_name.c_str());

        while(!read.eof())
        {
            read>>name;
            List[lastID].setName(name);

            read>>email;
            List[lastID].setEmail(email);

            read>>id;
            List[lastID].setID(id);

            read>>number;
            List[lastID].setNumber(number);

            ++lastID;
        }
        read.close();
    }


    void Automator ( string file_name)
    {
        ifstream read;
        read.open(file_name.c_str());
        string identifier;
        int selector;
        while(!read.eof())
        {
            read>>identifier;
            if(identifier=="A")
                selector=1;
            if(identifier=="R")
                selector=2;
            if(identifier=="S")
                selector=3;
            if(identifier=="D")
                selector=4;

            switch(selector)
            {
            case 1:
            {
                cout<<"Identifier : A"<<endl;
                string name, email;
                long long int number;

                read>>name;
                List[lastID].setName(name);

                read>>number;
                List[lastID].setNumber(number);

                read>>email;
                List[lastID].setEmail(email);

                ++lastID;
                break;
            }
            case 2:
            {
                cout<<"Identifier : R"<<endl;
                long long int del_number;
                read>>del_number;
                Delete_Contact(del_number);
                break;
            }
            case 3:
            {
                cout<<"Identifier : S"<<endl;
                long long int search_number;
                read>>search_number;
                Search(search_number);
                break;
            }
            case 4:
            {
                cout<<"Identifier : D"<<endl;
                Display_All_Contacts();
                break;
            }
            default:
                cout<<"Identifier Mistake"<<endl;
            }
        }
        read.close();
    }

    void Search ( long long int search_no)
    {
        int i=0;
        while(i<lastID)
        {
            if (search_no == List[i].getNumber())
            {
                cout<<"\n\t\tContact Found ! "<<endl;
                List[i].Display();
                return;
            }
            ++i;
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
    cout<<"TALHA REHMAN .....ALL RIGHTs RESERVED ......Copyright(c)";
    CONTACTS My_Contacts;

    char control = 'c';
    int select=0;

    while(control=='c' || control=='C')
    {
        cout<<"\nBasic file operations\n"
            <<"     1).  Words"<<endl
            <<"     2).  Lines"<<endl
            <<"     3).  Find in File"<<endl
            <<"     4).  Append To File"<<endl

            <<"\nSaving Contacts to File\n"
            <<"     5).  Export"<<endl
            <<"     6).  Import"<<endl

            <<"\nProgram Automation \n"
            <<"     7).  Automator\n\n"
            <<"\nContacts \n"
            <<"     8).  Display All Contacts\n"
            <<"     9).  Add Contact\n"
            <<"    10).  Memory Status\n";



        cout<<"\nExecute : ";
        cin>>select;
        cout<<endl;

        switch(select)
        {
        case 1:
        {
            cout<<"_______________________________________________________________________________\n"<<endl;
            string file_name;
            cout<<"Enter File_Name : ";
            cin.ignore();
            getline(cin,file_name);
            cout<<"\a\n\tWords : "<<Words(file_name)<<endl;
            cout<<"_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 2:
        {
            cout<<"_______________________________________________________________________________\n"<<endl;
            string file_name;
            cout<<"Enter File_Name : ";
            cin.ignore();
            getline(cin,file_name);
            cout<<"\a\n\tLines : "<<Lines(file_name)<<endl;
            cout<<"_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 3:
        {
            cout<<"_______________________________________________________________________________\n"<<endl;
            string file_name , searchh;
            cout<<"Find : ";
            cin>>searchh;

            cout<<"Enter File_Name : ";
            cin>>file_name;

            cout<<searchh<<" Found : "<<FindinFile(file_name,searchh)<<" Times "<<endl;
            cout<<"_________________________________________________________________\n"<<endl;
            break;
        }
        case 4:
        {
            cout<<"__________________________________________________________________\n"<<endl;
            string file_name, data;
            cout<<"Write : ";
            cin>>data;
            cout<<"Enter File_Name : ";
            cin>>file_name;
            appendToFile(file_name,data);
            cout<<"________________________________________________________________\n"<<endl;
            break;
        }
        case 5:
        {
            cout<<"\n___________________________________________________________________\n"<<endl;
            cout<<"Export Contacts\n"<<endl;
            string file_name="";
            cout<<"Enter  File_Name : ";
            cin.ignore();
            getline(cin,file_name);
            My_Contacts.Export(file_name);
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;


        }
        case 6:
        {
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            cout<<"Import Contacts\n"<<endl;
            string file_name="";
            cout<<"Enter  File_Name : ";
            cin.ignore();
            getline(cin,file_name);
            My_Contacts.Import(file_name);
            break;
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 7:
        {
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            cout<<"Automator\n"<<endl;
            string file_name;
            cout<<"Enter File_Name : ";
            cin.ignore();
            getline(cin,file_name);
            My_Contacts.Automator(file_name);
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 8:
        {
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            My_Contacts.Display_All_Contacts();
            cout<<"\n_______________________________________________________________________________\n"<<endl;
            break;
        }
        case 9:
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
        case 10:
        {
            cout<<"\a\n_______________________________________________________________________________\n"<<endl;
            cout<<"\t\t\tContacts Stored : "<<My_Contacts.Memory_Status();
            cout<<"\a\n_______________________________________________________________________________\n"<<endl;
            break;
        }

        default:
            cout<<" InCorrect Input "<<endl;
        }
        cout<<" Continue c  /  Stop s  ? : ";
        cin>>control;
    }
}

int Words ( string file_name)
{
    string word="";
    int count=0;
    ifstream read;
    read.open(file_name.c_str());
    while(!read.eof())
    {
        read>>word;
        ++count;
    }
    read.close();
    return count;
}
int Lines ( string file_name)
{
    string line="";
    int count=0;
    ifstream read;
    read.open(file_name.c_str());
    while(!read.eof())
    {
        getline(read,line);
        ++count;
    }
    read.close();
    return count;
}
int FindinFile ( string file_name, string search)
{
    string word="";
    int count=0;
    ifstream read;
    read.open(file_name.c_str());
    while(!read.eof())
    {
        read>>word;
        if(word==search)
            ++count;
    }
    read.close();
    return count;

}

void appendToFile ( string file_name, string input_data)
{

    ofstream write;
    write.open(file_name.c_str(), ios::app);
    write<<endl<<input_data;
    write.close();
}
