#include <iostream>

using namespace std;
class Heap
{
private:
    int arr[15];
    int length=0;
public:
    int getLength()
    {
        return length;
    }
    int getLeft(int i)
    {
        return ((2*i)+1);
    }
    int getRight(int i)
    {
        return ((2*i)+2);
    }
    int getParent(int i)
    {
        return ((i-1)/2);
    }
    int GetTop()
    {
        return arr[0];
    }
    bool IsHeap()
    {
    int  i;
    int  len = length/2;
    for (i=0; i <= len ; i++ )
    {
        if ((!(getLeft(i) > length)) ||(!(getRight(i) > length)) )

        { cout<<"center "<<arr[i]<<endl;
        cout<<"left "<<arr[getLeft(i)]<<endl;
          cout<<"right "<<arr[getRight(i)]<<endl;

            if (arr[i] < arr[getLeft(i)] || arr[i] < arr[getRight(i)])
                return false;
        }
    }
    return true;
    }
    void Swap(int i, int j)
    {
        int a = arr[i];
        arr[i]=arr[j];
        arr[j]=a;
        return ;
    }
    int Max(int i, int j)
    {
        if(arr[i]<arr[j])
            return j;
        else
            return i;
    }
    void heapifyup()
    {
         int i=length;
         while(i!=0)
         {  int j=getParent(i);
            if(arr[i]>arr[j])
            {
                Swap(i,j);
            }
            i=j;
         }
    }
    void heapifydown()
    {
        int i=0,z;
        while(!IsHeap())
        {  if(i==length || i==length-1)
            {
                return;
            }
            z=Max(getLeft(i),getRight(i));
            if(arr[i]<arr[z])
            {
                Swap(i,z);
                i=z;
            }
        }
    }
    void add(int no)
    { if(length<15)
        {arr[length]=no;
        if (!(IsHeap()))
        {
            heapifyup();
        }
        length++;}
        else
            cout<<"Array is full."<<endl;
    }
    void deletee()
    {
        cout<<"Element "<<arr[0]<<" has been deleted."<<endl;
        arr[0]=arr[length-1];
        length--;
        if (!IsHeap())
            heapifydown();
    }
    void display()
    {
        for (int i=0;i<length;i++)
        {
            cout<<i<<". "<<arr[i]<<endl;
        }
    }

};
int main()
{

    Heap c;
   c.add(95);
    c.add(80);
    c.add(70);
    c.add(88);
    c.add(64);
    c.add(43);
    c.add(98);
    c.add(27);
    c.add(33);
    c.add(78);
    c.display();
    c.deletee();
    c.display();
    c.deletee();
    c.display();
    c.add(89);
    c.display();

    Heap A;
    char a;
    do
    {
        int i;
        cout<<endl;
        cout<< "1. Add a number in Heap."<<endl;
        cout<< "2. Delete"<<endl;
        cout<< "3. Is Heap."<<endl;
        cout<< "4. Get Top."<<endl;
        cout<< "5. Display."<<endl;
        cout<<endl;
        cin >> i;
        switch(i)
        {
        case 1:
            {
                int no;
                cout << "Enter a Number to add."<<endl;
                cin >> no;
                A.add(no);
                break;
            }
        case 2:
            {
                A.deletee();
                break;
            }
        case 3:
            {
                if(!(A.IsHeap()))
                    cout << "Is not a heap."<<endl;
                else
                    cout<<"Is Heap"<<endl;
                break;
            }
        case 4:
            {
               cout<<A.GetTop();
                break;
            }
        case 5:
            {
                A.display();
                break;
            }
        default:
            cout << "Wrong Input."<<endl;
        }
        cout<<endl;
        cout<<"Do you want to run again?"<<endl;
        cout<<" Yes = Y "<<endl;
        cout<<" No = N "<<endl;
        cin >> a;
    }
    while (a == 'y' || a == 'Y');
}
