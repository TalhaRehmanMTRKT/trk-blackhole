#include <iostream>
#include <fstream>
using namespace std;
class Node
{
private:
    int name;
    Node *next;

public:
    Node(int a)
    {
        name = a;
        next = NULL;
    }
    void setName(int a)
    {
        name = a;
    }
    int getName()
    {
        return name;
    }
    void setNext(Node *a)
    {
        next = a;
    }
    Node *getNext()
    {
        return next;
    }
    void display()
    {
        cout << "\n THE NAME IS :: " << name << endl;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void addAtStart(int a)
    {
        Node *temp = head;
        Node *t = new Node(a);
        if (temp == NULL)
        {
            head = t;
        }
        else
        {
            t->setNext(temp);
            head = t;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            temp->display();
            temp = temp->getNext();
        }
    }
    int Size()
    {
        Node *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->getNext();
        }
        if (counter == 0)
        {
            cout << "\n The List is empty :: size = 0  ";
            return 0;
        }
        else
        {
            return counter;
        }
    }
    int Search(int a)
    {
        Node *temp = head;
        int index = 0;
        while (temp != NULL)
        {
            index++;
            if (temp->getName() == a)
            {
                cout << "\n THE NODE IS :: ";
                return index;
            }
            temp = temp->getNext();
        }
        cout << "\n NOT FOUND :: ";
        return -1;
    }
    void addAtEnd(int a)
    {
        Node *temp = head;
        Node *t = new Node(a);
        if (temp == NULL)
        {
            head = t;
        }
        else
        {
            while (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(t);
        }
    }

    void Add(int n, int i)

    {
        Node *temp = head;
        Node *temp1;

        int index = 1;

        Node *t = new Node(n);

        if (i <= 1)

        {
            addAtStart(n);
        }

        else if (i >= Size())

        {
            addAtEnd(n);
        }

        else
        {
            while (index != i)

            {
                index++;
                temp1 = temp;
                temp = temp->getNext();
            }
            Node *temp2 = temp1->getNext();
            temp1->setNext(t);
            t->setNext(temp2);
        }
    }

    void removeAtStart()
    {
        if (head == NULL)
        {
            cout << "\n Not found any list...";
            return;
        }
        head = head->getNext();
        cout << "\n Removed node at start...";
    }
    void removeAtEnd()
    {
        Node *temp = head;
        if (temp == NULL)
        {
            cout << "No node to be removed...";
            return;
        }
        if (temp->getNext() == NULL)
        {
            head = NULL;
            cout << "Removed the head node";
            return;
        }

        while (temp->getNext()->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(NULL);
        cout << "\n Removed the node at end...";
    }
    void removeAt(int n)
    {
        Node *temp = head;
        Node *temp1;
        if (n > Size())
        {
            cout << "\n you entered larger than size number  " << Size();
            return;
        }
        if (n == 1 || n < 1)
        {
            removeAtStart();
        }
        else if (n == Size())
        {
            removeAtEnd();
        }
        else
        {
            int index = 1;
            while (index != n)
            {
                index++;
                temp1 = temp;
                temp = temp->getNext();
            }
            temp1->setNext(temp->getNext());
        }
    }

    void remove(int n)
    {
        Node *temp = head;
        Node *temp1;
        if(temp==NULL){cout<<"NOT FOUND";return;}
        while (temp->getNext() != NULL && temp->getName() != n)
        {
            temp1 = temp;
            temp = temp->getNext();
        }
        if (temp->getNext() == NULL && temp->getName() == n)
        {
            removeAtEnd();
        }
        else if (temp == head && temp->getName() == n)
        {
            removeAtStart();
        }
        else if (temp->getName() == n)
        {
            cout<<"REMOVING THE NODE....";
            temp1->setNext(temp->getNext());
        }
        else
        {
            cout << "Not found";
            return;
        }
    }
    void dr(Node *t)
    {
        if (t == NULL)
        {
            return;
        }
        else if (t->getNext() == NULL)
        {
            t->display();
        }
        else
        {
            dr(t->getNext());
            t->display();
        }
    }
    void displayReverse()
    {
        Node *temp = head;
        dr(temp);
    }
    Node* status()
    {
        return head;
    }
};

class Separate_Chaining
{
private:
    LinkedList a[10];//INITIALIZER
public:
    Separate_Chaining()
    {
    }
    int Hash_key(int input_data) // Finding Hash Key
    {
        return (input_data%10);  // Formula for hashing h(element)= element % size_of_array
    }
    void insert_in_table(int input_data) //Insert Function
    {
        int place=Hash_key(input_data); //calculating the position using hash function
        if(a[place].status()==NULL)
        {
            cout<<"\n ADDING AT THE LINKED LIST AT THE INDEX: "<<place<<endl;
            a[place].addAtStart(input_data);     //add at the start if place is empty
        }
        else
        {
            cout<<"\n ADDING AT THE LINKED LIST AT THE INDEX: "<<place<<endl;
            a[place].addAtEnd(input_data);   //add at the linked list at the place
        }
    }
    void delete_data(int data)
    {
        int place=Hash_key(data); //Computing the place
        a[place].remove(data);
        cout<<"\n \n THE  TARGET PLACE was : "<<place; //Tells the array index where changes was to be done
    }
    void search_data(int data)
    {
        int place=Hash_key(data);
        cout<<"\n The search linked list is at index "<<place;
        cout<<a[place].Search(data);
    }
    void Is_Full()
    {
        for(int i=0;i<19;i++)
        {
            if(a[i].status()==NULL)
            {
                cout<<endl<<"NOT FULL";
                return;
            }
        }
        cout<<endl<<"FULL";
        return;
    }
        void Is_Empty()
    {
        for(int i=0;i<10;i++)
        {
            if(a[i].status()!=NULL)
            {
                cout<<endl<<"NOT EMPTY";
                return;
            }
        }
        cout<<endl<<"EMPTY";
        return;
    }

};
int main()
{
    Separate_Chaining a;
    a.insert_in_table(10);
    a.insert_in_table(20);
    a.insert_in_table(122);
    a.delete_data(12);
    cout<<"\n \n SEARCHING";
    a.search_data(10); // provides the index of array along with the index of linked list[starting from 1)
    a.Is_Full();
    a.Is_Empty();
    Separate_Chaining b;
    b.Is_Full();
    b.Is_Empty();
}
