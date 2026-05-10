#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class Node
{
    private:
    string name;
    Node *next;
    public:
    Node ()
    {
        next=NULL;
    }
    Node (string n)
    {
        name=n;
    }
    void setData(string n)
    {
        name=n;
    }
    string getData()
    {
        return name;
    }
    void setNext(Node *n)
    {
        next=n;
    }
    Node* getNext()
    {
        return next;
    }
    void displayNode()
    {
        cout<<name<<endl;
    }

};
class LinkedList
{
    private:
    Node* head;
    public:
    LinkedList()
    {
       head=NULL;
    }
    void addAtStart(string x)
    {
        Node *t=new Node(x);
        t->setNext(head);
        head=t;
    }
    void displayList()
    {
       Node *temp;
       temp=head;
       while(temp!=NULL)
       {
           temp->displayNode();
           temp=temp->getNext();
       }
    }
    int number_of_nodes()
    {
      Node *temp;
       temp=head;
       int count=0;
       while(temp!=NULL)
       {
           count++;
           temp=temp->getNext();
       }
       return count;
    }
    int search(string x)
    {
    Node *temp;
     temp=head;
      int i=0;
      string a;
      while(temp!=NULL)
       {
           a=temp->getData();
           if(a==x)
            return i;
            i++;
           temp=temp->getNext();
       }
       return -1;

    }
    void addAtEnd(string x)
    {
        Node *t=new Node(x);
        Node *temp;
        temp=head;
        if(temp==NULL)
        {
            addAtStart(x);
        }
        else
        {
        while(temp->getNext() !=NULL)
        {
          temp=temp->getNext();
        }
        temp->setNext(t);
        }
     }
    void add_at_index(string x,int i)
    {
        Node *t=new Node(x);
        Node *temp=head;
        if(i<=0)
        {
            addAtStart(x);
        }
        else
        {
          if(i>number_of_nodes())
        {
            addAtEnd(x);
        }
        else
        {
            for(int j=0;j!=(i-1);j++)
            {
                temp=temp->getNext();
            }
            t->setNext(temp->getNext());
            temp->setNext(t);
        }
        }

    }
    void remove_first()
    {
        head=head->getNext();
    }
    void remove_end()
    {
        Node *temp=head;
        while((temp->getNext()->getNext()!=NULL))
        {
            temp=temp->getNext();
        }
        temp->setNext(NULL);
    }
    void remove_string(string x)
    {
        Node* temp=head;
        if (search(x)==-1)
        {
            cout<<"string not present"<<endl;
            return;
        }
        while(temp->getNext()!=NULL)
        {

            if(head->getData()==x)
            {
                head=head->getNext();
                return;
            }
            if (temp->getNext()->getData()==x)
            {
                temp->setNext(temp->getNext()->getNext());
                return;
            }
            temp=temp->getNext();
        }
    }
    void clearAll()
    {
        head=NULL;
    }
    string listpeek()
    {
        return head->getData();
    }
    void removeAt(int j)
    {
       Node* temp=head;
       if(j<0 || j==number_of_nodes())
       {
           cout<<"index out of range"<<endl;
           return;
       }
       if(j==0)
            {
                head=head->getNext();
                return;
            }
        for(int i=0;i<number_of_nodes();i++)
        {

            if (i==j-1)
            {
                temp->setNext(temp->getNext()->getNext());
                return;
            }
            temp=temp->getNext();
        }
    }
    void displayReverse(Node *temp)
    {
       if(temp==NULL)
       return;
       else
       {
           displayReverse(temp->getNext());
           cout<<temp->getData();
       }
    }
    void automater()
    {
        ifstream file;
        file.open("text.txt");
        string m,a;
        int i;
        while(!file.eof())
        {
            file>>m;
            if(m=="AAS")
            {
                file>>a;
                addAtStart(a);
            }
            if(m=="AAE")
            {
                file>>a;
                addAtEnd(a);
            }
            if(m=="ADD")
            {
                file>>a;
                file>>i;
                add_at_index(a,i);
            }
            if(m=="REM")
            {
                file>>a;
                remove_string(a);
            }
            if(m=="RAI")
            {
                file>>i;
                removeAt(i);
            }
            if(m=="RAS")
            {
                remove_first();
            }
            if (m=="RAE")
            {
                remove_end();
            }
            if (m=="DIS")
            {
                displayList();
            }
           if (m=="DIR")
            {
                displayReverse(head);
            }
        }
        file.close();

    }

};
class LStack
{
 private:
    LinkedList stack;
public:
    void push(string a)
    {
        stack.addAtStart(a);
    }
    void pop()
    {
      stack.remove_first();
    }
    void stackdisplay()
    {
        stack.displayList();
    }
    void clearlist()
    {
        stack.clearAll();
    }
    string top()
    {
        return stack.listpeek();
    }
};
class LQueue
{
private:
    LinkedList qu;
public:
    void enqueue(string a)
    {
        qu.addAtEnd(a);
    }
    void dequeue()
    {
      qu.remove_first();
    }
    void qdisplay()
    {
        qu.displayList();
    }
    void clearlist()
    {
        qu.clearAll();
    }
    string peek()
    {
        return qu.listpeek();
    }
};
class AStack
{
private:
    int arr[20];
    int tail=0;
public:
    void push(int x)
    {
      if(tail==20)
      {
          cout<<"it is full"<<endl;
      }
      else
      {
          arr[tail]=x;
          tail++;
      }
    }
    void pop()
    {
        if (tail==0 || tail<0)
            cout<<"nothing to pop"<<endl;
        else
            tail--;
    }
    int top()
    {
       return arr[tail-1];
    }
    bool isfull()
    {
      if (tail<=19)
            return true;
      else
        return false;
    }
    void clear_list()
    {
        tail=0;
    }
    void display_sarray()
    {
        int i=0;
        for(i;i<tail;i++)
        {
          cout<<arr[i]<<endl;
        }
    }

};
class AQueue
{
   private:
       int arr[20];
       int head=0;
       int tail=0;
   public:
    void enqueue(int x)
    {
        arr[tail]=x;
        tail++;
    }
    void dequeue()
    {
        if (head<tail)
         head++;
        else
        cout<<"nothing to pop"<<endl;

    }
    void clear_list()
    {
        head=0;
        tail=0;
    }
    int peek()
    {
        return arr[tail-1];
    }
    bool isfull()
    {
      if (tail<=19)
            return true;
      else
        return false;
    }
    void display_sarray()
    {
        int i=head;
        for(i;i<tail;i++)
        {
          cout<<arr[i]<<endl;
        }
    }

};
class CQueue
{
   private:
       int start=0;
       int endd=0;
       int arr[5];
   public:
       void enqueue(int x)
       {
           arr[endd]=x;
          if(endd==5 && start!=0)
          {
           endd=0;
          }
          else
          {
                endd++;
          }
       }
       void dequeue()
       {
           if (start==4)
            start=0;
            else
                start++;
       }
    int peek()
    {
        return arr[endd-1];
    }
    bool isfull()
    {
        if (start==0 && endd<=5)
            return true;
        else
            false;
    }
    void clear_list()
    {
        start=0;
        endd=0;
    }
     void display_list()
     {
         int i=0;
        for(i;i<5;i++)
        {
          cout<<arr[i]<<endl;
        }
     }


};
int main()
{
    CQueue c;
    c.enqueue(1);
    c.enqueue(2);
    c.enqueue(3);
    c.enqueue(4);
    c.enqueue(5);
    //c.enqueue(6);
    c.dequeue();
    c.dequeue();
    c.enqueue(19);
    //c.enqueue(19);
    c.display_list();
}




