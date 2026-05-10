#include <iostream>

using namespace std;

class HashNode   //making class of hash node with get and set functions
{
private:
    int data;
public:
    HashNode()
    {
        data = -1;
    }
    void setData(int d)
    {
        data = d;
    }
    int getData()
    {
        return data;
    }

};
class LinearProbing  //linear probing class
{
private:
    HashNode arr[10];  //declaring the array of size 10
    int load=0; //load will tell us when the array is full
public:
    int hashindex(int key)
    {
        return key%10;   // using the hash function  h(x)= number % size
    }
    bool isFull()
    {
        if (load == 10)  // if the load is 10 this means the array is full
        {
            return true; // all the entries are filled so it will return true for isFull function
        }
        return false;
    }
    void add(int key) //making function of adding a number in hash table
    {
        int index = hashindex(key); // using hash function to specify the index of number
        int i=0;
        int value;
        value=index;
        //collision
        while( arr[value].getData() != -1)// if the place is not empty then it will move one by one through the array to find empty place
        {
            if(isFull()==1) // if the array full it will stop..because no place is empty
            {
                cout<<"Array is full."<<endl;
                return;
            }
            else
            {
                value=((index + i)%10);  // the value is updated on every iteration until it finds the empty one and then at the next if statement the number(key) will be updated at that point
                i++;
            }
        }
        if(arr[value].getData() == -1) // if this particular array index is empty then it will update it
        {
            load++; // increment in load to specify that one index is filled
            arr[value].setData(key); // setting the value of this particular index data equals to the key(input number)
        }// the value variable will specify the updating index
    }
    void deletee(int key)
    {
        int index = hashindex(key);// getting the index from hashfunction
        int i=0;
        int value;
        value=index;
        //collision
        while(arr[value].getData() != key || i==9) //if the index data and the provided key do not match then it will go through this loop ...checking all the index one by one stating from the hash index
        {
            value=((index + i)%10);
            i++;
        } // when the key and index data matches the while loop breaks ..if not then loop will break when all the index are checked i.e at i==10
        if(arr[value].getData() == key) //if the key and index data matches then this is executed
        {
            arr[value].setData(-1); // the data is updated to -1 to specify it is empty
            load--; // the decrement in load specify that the new space is empty and another room for data is avalable
            cout<<"The data  "<<key<<" is deleted."<<endl;
            return;
        }
        cout<<"The data  "<<key<<" is not present in the array."<<endl; // if not found the key then this will send the message that the data is not found to delete
        return;
    }
    void search_(int key) // searching the key in array using linear probing
    {
        int index = hashindex(key); // getting the index from hash function
        int i=0,z=0;
        int value=index;
        //collision
        while(arr[value].getData()!=key)// this loop is to iterate through the whole array to find the key if it is not found in first go.
        {
            z++;
            if(z>10)
            {
                cout<<"The data  "<<key<<" is not found."<<endl;
                return;
            }
            value=((index + i)%10);
        }
        if(arr[value].getData()== key) // if data is found this is executed
        {
            cout<<"The data  "<<key<<" is found."<<" at index "<<value<<endl; // provide the index of the found key
            return ;
        }

        cout<<"The data  "<<key<<" is not found."<<endl; // else this will send message that the data not found
        return;
    }

    bool isEmpty() // this will specify that either the list is empty or not
    {
        if( load==0 )
        {
            return true;
        }
        return false;
    }
    void Display() // using for loop to display the data of the array
    {
        for (int i=0; i<10 ; i++)
        {
            if(arr[i].getData() != -1)
                cout << i << ".  " << arr[i].getData()<< endl;
        }
    }
};
class QuadraticProbing
{
private:
    HashNode arr[13]; // declaring array of size 13
    int load=0; // same functionality as in linear probing
public:
    int hashindex(int key)
    {
        return key%13;  // using the hash function  h(x)= number % size
    }
    bool isFull() // tells whether the array is full or not
    {
        if (load == 12)
        {
            return true;
        }
        return false;
    }
    void add(int key)  // add function using quadratic probing
    {
        int index = hashindex(key); // getting the index from hash function
        int i=0;
        int value=index;
        //collision
        while( arr[value].getData() != -1) // the loop will be executed when the array index is already occupied (the index found using first hash function)
        {
            if(isFull()==1) // if the array is full then it will send message and we do not need to do all the process
            {
                cout<<"Array is full."<<endl;
                return;
            }
            value =((index+(i*i))%13); // as we have collision so using second hash function to add the key... h2(x) = (h(x) + (i)^2 )%13
            i++;

        }
        if(arr[value].getData() == -1) // when the empty place found this will update the data as well as the load value
        {
            load++;
            arr[value].setData(key);
        }
    }
    void deletee(int key) // delete using quadratic probing
    {
        int index = hashindex(key);// getting the index from hash function
        int i=0;
        int value=index;
        //collision
        while(arr[value].getData() != key || i==12)// if not found in first go then will iterate using second hash function through the array
        {
            value =((index+(i*i))%13); //using the second hash function
            i++;
        } // while loop end when the key is found or the maximum i is reached
        if(arr[value].getData() == key) // if key and index data are same then this will delete the data
        {
            arr[value].setData(-1);
            load--;// the decrement in load specify that the new space is empty and another room for data is avalable
            cout<<"The data  "<<key<<" is deleted."<<endl;
            return;
        }
        cout<<"The data  "<<key<<" is not present in the array."<<endl;
        return;
    }
    void search_(int key)// searching the key in array using quadratic probing
    {
        int index = hashindex(key);  // getting the index from hash function
        int i=0,z=0;
        int value=index;
        //collision
        while(arr[value].getData()!=key) //if the index data and the provided key do not match then it will go through this loop ...checking all the index one by one using second hash function
        {
            z++;
            if(z>13)
            {
                cout<<"The data  "<<key<<" is not found."<<endl;
                return;
            }
            value =((index+(i*i))%13); // using second hash function
            i++;
        }
        if(arr[value].getData()== key) // if found it will return the index and display the message
        {
            cout<<"The data  "<<key<<" is found."<<" at index "<<value<<endl;
            return ;
        }
        //else not found message is displayed
        cout<<"The data  "<<key<<" is not found."<<endl;
        return;
    }

    bool isEmpty() // tells whether the array is empty or not
    {
        if( load==0 )
        {
            return true;
        }
        return false;
    }
    void Display() //displaying the array simply using for loop
    {
        for (int i=0; i<13 ; i++)
        {
            if(arr[i].getData() != -1)
                cout << i << ".  " << arr[i].getData()<< endl;
        }
    }
};
class DoubleProbing
{
private:
    HashNode arr[13];// declaring array of size 13
    int load=0;
public:
    int hashindex(int key)
    {
        return key%13;// using first hash function as h(x)= key % size
    }
    bool isFull() // tells whether the array is empty or not
    {
        if (load == 12)
        {
            return true;
        }
        return false;
    }
    void add(int key)
    {
        int index = hashindex(key); // getting index from first hash function
        int i=0;
        int value=index;
        while( arr[value].getData() != -1) // if found collision then this loop execued
        {
             if(isFull()==1)
            {
                cout<<"Array is full."<<endl;
                return;
            }
            value =((index+(i*(11-(key%11))))%13); //using second hash function as h2(x) = ( h(x) + i*(prime number - h(prime number)) ) % size
            i++;
        }
        if(arr[value].getData() == -1) // when found an empty place the value of data is updated
        {
            load++;
            arr[value].setData(key);
        }
    }
    void deletee(int key) // delete using double hasing
    {
        int index = hashindex(key);
        int i=0;
        int value=index;
        //collision
        while(arr[value].getData() != key )
        {
            value =((index+(i*(11-(key%11))))%13); // using second hash function to iterate through the array
            i++;
        }
        if(arr[value].getData() == key) // if key found then delete using this statement.. the value of index is given from the while loop above if collision exist
        {
            arr[value].setData(-1);
            load--;
            cout<<"The data  "<<key<<" is deleted."<<endl;
            return;
        }
        //else the message of not found is displayed
        cout<<"The data  "<<key<<" is not present in the array."<<endl;
        return;
    }
    void search_(int key)
    {
        int index = hashindex(key);// first hash function to get the index (first try)
        int i=0,z=0;
        int value=index;
        // collision
        while(arr[value].getData()!=key)  // if not found on first go then this will be executed to iterate in array using second hash function for double hashing
        {
            z++;
            if(z>13) // if all index are checked then it will return not found message
            {
                cout<<"The data  "<<key<<" is not found."<<endl;
                return;
            }
            value =((index+(i*(11-(key%11))))%13); // using second hash function to iterate through the array
            i++;
        }
        if(arr[value].getData()== key)
        {
            cout<<"The data  "<<key<<" is found."<<endl;
            return ;
        }

        cout<<"The data  "<<key<<" is not found."<<endl;
        return;
    }

    bool isEmpty() // tells whether the array is empty or not
    {
        if( load==0 )
        {
            return true;
        }
        return false;
    }
    void Display()
    {
        for (int i=0; i<13 ; i++)
        {
            if(arr[i].getData() != -1)
                cout << i << ".  " << arr[i].getData()<< endl;
        }
    }
};
int main()
{   // designing user interface using switch statements
    char op;
    do
    {
        int a;
        cout << "1. Linear Probing"<<endl;
        cout << "2. Quadratic Probing"<<endl;
        cout << "3. Double Hashing"<<endl;
        cin >> a;
        switch(a)
        {
        case 1:
        {
            char o;
            LinearProbing A;
            do
            {
                int a;
                cout << "\n-------------------\n";
                cout<< "1. Insert a Number."<<endl;
                cout<< "2. Delete a Number."<<endl;
                cout<< "3. Search a Number."<<endl;
                cout<< "4. Is Full."<<endl;
                cout<< "5. Is Empty."<<endl;
                cout<< "6. Display."<<endl;
                cin >>a;
                switch(a)
                {
                case 1:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    A.add(Key);
                    break;
                }
                case 2:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    A.deletee(Key);
                    break;
                }
                case 3:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    A.search_(Key);
                    break;
                }
                case 4:
                {
                    if(A.isFull()==1)
                    {
                        cout << "Array is Full."<<endl;
                    }
                    else
                    {
                        cout << "Array is not Full."<<endl;
                    }
                    break;
                }
                case 5:
                {
                    if(A.isEmpty()==1)
                    {
                        cout << "Array is empty."<<endl;
                    }
                    else
                    {
                        cout << "Array is not empty."<<endl;
                    }
                    break;
                }
                case 6:
                {
                    A.Display();
                    break;
                }
                default:
                {
                    cout << "Wrong Input."<<endl;
                }
                }
                cout << "\n------------------\n";
                cout<< "do you want to run Again?"<<endl;
                cout<<" Yes = Y"<<endl;
                cout<<" No = N"<<endl;
                cin>> o;
            }
            while(o=='y'|| o == 'Y');
            break;

        }
        case 2:
        {
            char o;
            QuadraticProbing B;
            do
            {
                int a;
                cout << "\n-------------------\n";
                cout<< "1. Insert a Number."<<endl;
                cout<< "2. Delete a Number."<<endl;
                cout<< "3. Search a Number."<<endl;
                cout<< "4. Is Full."<<endl;
                cout<< "5. Is Empty."<<endl;
                cout<< "6. Display."<<endl;
                cin >>a;
                switch(a)
                {
                case 1:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    B.add(Key);
                    break;
                }
                case 2:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    B.deletee(Key);
                    break;
                }
                case 3:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    B.search_(Key);
                    break;
                }
                case 4:
                {
                    if(B.isFull()==1)
                    {
                        cout << "Array is Full."<<endl;
                    }
                    else
                    {
                        cout << "Array is not Full."<<endl;
                    }
                    break;
                }
                case 5:
                {
                    if(B.isEmpty()==1)
                    {
                        cout << "Array is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Array is not Empty."<<endl;
                    }
                    break;
                }
                case 6:
                {
                    B.Display();
                    break;
                }
                default:
                {
                    cout << "Wrong Input."<<endl;
                }
                }
                cout << "\n------------------\n";
                cout<< "do you want to run Again?"<<endl;
                cout<<" Yes = Y"<<endl;
                cout<<" No = N"<<endl;
                cin>> o;
            }
            while(o=='y'|| o == 'Y');
            break;
        }
        case 3:
        {
            char o;
            DoubleProbing C;
            do
            {
                int a;
                cout << "\n-------------------\n";
                cout<< "1. Insert a Number."<<endl;
                cout<< "2. Delete a Number."<<endl;
                cout<< "3. Search a Number."<<endl;
                cout<< "4. Is Full."<<endl;
                cout<< "5. Is Empty."<<endl;
                cout<< "6. Display."<<endl;
                cin >>a;
                switch(a)
                {
                case 1:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    C.add(Key);
                    break;
                }
                case 2:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    C.deletee(Key);
                    break;
                }
                case 3:
                {
                    int Key;
                    cout << "Enter a number."<<endl;
                    cin >> Key;
                    C.search_(Key);
                    break;
                }
                case 4:
                {
                    if(C.isFull()==1)
                    {
                        cout << "Array is Full."<<endl;
                    }
                    else
                    {
                        cout << "Array is not Full."<<endl;
                    }
                    break;
                }
                case 5:
                {
                    if(C.isEmpty()==1)
                    {
                        cout << "Array is Empty."<<endl;
                    }
                    else
                    {
                        cout << "Array is not Empty."<<endl;
                    }
                    break;
                }
                case 6:
                {
                    C.Display();
                    break;
                }
                default:
                {
                    cout << "Wrong Input."<<endl;
                }
                }
                cout << "\n------------------\n"<<endl;
                cout<< "do you want to run Again?"<<endl;
                cout<<" Yes = Y"<<endl;
                cout<<" No = N"<<endl;
                cin>> o;
            }
            while(o=='y'|| o == 'Y');
            break;
        }
        }
        cout << "\n------------------\n";
        cout<< "do you want to run Again (using different hashing)?"<<endl;
        cout<<" Yes = Y"<<endl;
        cout<<" No = N"<<endl;
        cin>>op;
    }
    while(op=='y'|| op == 'Y');
}
