#include <iostream>

using namespace std;
class Insertion_Sort
{
    private:
    int arr[6];
    int sizee=6;
    public:
void input()
{
    cout<<"Array size is 6."<<endl;
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<"Enter "<<i+1<<" number: ";
        cin>>arr[i];
    }
}
void display()
{
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
     }
}
void shift_right(int m,int n)
{
    int i;
    for(i=n;i>m;i--)
    {
        arr[i]=arr[i-1];
    }
}
void insert_(int no)
{
    int i=arr[no];
    int j;
    for(j=0;j<no;j++)
    {
        if(i<arr[j])
        {
            shift_right(j,no);
            arr[j]=i;
            return;
        }
    }
}
void insertionsort()
{
    int i;
    for(i=0;i<sizee;i++)
    {
        insert_(i);
    }
}
};
class Selection_Sort
{
 private:
    int arr[6];
    int sizee=6;
    public:
void input()
{
    cout<<"Array size is 6."<<endl;
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<"Enter "<<i+1<<" number: ";
        cin>>arr[i];
    }
}
void display()
{
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
     }
}
void shift_right(int m,int n)
{
    int i;
    for(i=n;i>m;i--)
    {
        arr[i]=arr[i-1];
    }
}
void moveMin(int no)
{
    int i=0,a,index;
    int mini=arr[no];
    for(i=no;i<sizee;i++)
    {
        if(arr[i]<mini)
        {
            mini=arr[i];
            index=i;
        }
    }
    shift_right(no,index);
    arr[no]=mini;
}
void selectionsort()
{
    int i;
    for(i=0;i<sizee;i++)
    {
        moveMin(i);
    }
}
};
class Merge_2_array
{
    private:
        int arr[10];
        int arr1[5];
        int arr2[5];
        int sizee=10;
        int sizee1=5;
        int sizee2=5;
    public:
      void input1()
        {
        cout<<"Sorted Array 1"<<endl;
        cout<<"Array 1 size is 5."<<endl;
        int i;
        for(i=0;i<sizee1;i++)
            {
                cout<<"Enter "<<i+1<<" number: ";
                cin>>arr1[i];
            }
        }
        void input2()
        {
            cout<<"________________"<<endl;
            cout<<"Sorted Array 2"<<endl;
            cout<<"Array 2 size is 5."<<endl;
            int i;
            for(i=0;i<sizee2;i++)
            {
                cout<<"Enter "<<i+1<<" number: ";
                cin>>arr2[i];
            }
        }
        void display()
        {
            int i;
            cout<<"Merged Sorted Array:"<<endl;
            for(i=0;i<sizee;i++)
            {
                cout<<arr[i]<<" ";
             }
        }
        void merge_()
        {
        int i=0,j=0,k=0;
          for(k=0;k<sizee;)
            {
            if(arr1[i]==arr2[j])
            {
            arr[k]=arr1[i];
            k++;
            arr[k]=arr2[j];
            i++; k++; j++;
            }
            else
            {
            if(arr1[i]<arr2[j])
                {
            arr[k]=arr1[i];
            i++;k++;
                }
            else
                {
                if(arr1[i]>arr2[j])
                {
                    arr[k]=arr2[j];
                    k++; j++;
                }

                }
            }
            if(i==sizee1)
            {
            for(j;j<sizee2;j++)
              {
                    arr[k]=arr2[j];
                    k++;
              }
            }
            if(j==sizee2)
            {
            for(i;i<sizee1;i++)
              {
                    arr[k]=arr1[i];
                    k++;
              }}}}
};
class Merge_Sort
{
private:
    int arr[10];
    int sizee=10;
public:
    void input()
    {
    cout<<"Array size is 10."<<endl;
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<"Enter "<<i+1<<" number: ";
        cin>>arr[i];
    }
    }
    void display()
    {
    int i;
    for(i=0;i<sizee;i++)
    {
        cout<<arr[i]<<" ";
     }
    }
    void merge_sort(int first, int last)
    {
    int mid;
    if (first < last)
        {
        mid=(first+last)/2;
        merge_sort(first,mid);
        merge_sort(mid+1,last);
        merge_(first,last,mid);
        }
    }
    void merge_(int first, int last, int mid)
    {
    int i, j, k, arr1[10];
    i = first; k = first; j = mid + 1;
    while (i <= mid && j <= last)
        {
        if (arr[i] < arr[j])
         {
            arr1[k] = arr[i];
            k++; i++;
        }
        else
        {
            arr1[k] = arr[j];
            k++; j++;
        }
    }
    while (i <= mid)
     {
        arr1[k] = arr[i];
        k++; i++;
    }
    while (j <= last)
     {
        arr1[k] = arr[j];
        k++; j++;
    }
    for (i = first; i < k; i++)
      {
        arr[i] = arr1[i];
      }
}
};
class Quick_sort
{
private:
    int arr[10];
    int sizee=10;
public:
    void input()
        {
        cout<<"Array size is 10."<<endl;
        int i;
        for(i=0;i<sizee;i++)
        {
            cout<<"Enter "<<i+1<<" number: ";
            cin>>arr[i];
        }}
    void display()
        {
        int i;
        for(i=0;i<sizee;i++)
        {
            cout<<arr[i]<<" ";
         }}
    void swap_(int *a, int *b)
        {
            int c = *a;
            *a = *b;
            *b = c;
        }
    int partiton(int first, int last)
    {
    int pivot = arr[last];
    int i = first-1;
    for (int j = first; j <= last- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap_(&arr[i], &arr[j]);

        }
    }
    swap_(&arr[i+1], &arr[last]);
    return (i + 1);
    }
    void quickSort( int first, int last)
    {
        if (first < last)
        {
            int pivot = partiton(first, last);
            quickSort(first, pivot - 1);
            quickSort(pivot + 1, last);
        }
    }
};
int main()
{
    char op;
    int i;
    do{
    cout<<"1. Insert."<<endl;
    cout<<"2. Move Min."<<endl;
    cout<<"3. Insertion sort."<<endl;
    cout<<"4. Selection sort."<<endl;
    cout<<"5. Merge two sorted arrays."<<endl;
    cout<<"6. Merge Sort."<<endl;
    cout<<"7. Quick Sort."<<endl;
    cin>>i;
    switch(i)
    {
    case 1:
        {
            Insertion_Sort A;
            A.input();
            A.display();
            cout<<endl;
            A.insert_(5);
            cout<<"Output:"<<endl;
            A.display();
            break;
        }
    case 2:
        {
            Selection_Sort B;
            B.input();
            B.display();
            cout<<endl;
            B.moveMin(0);
            cout<<"Output:"<<endl;
            B.display();
            break;
        }
    case 3:
        {
            Insertion_Sort C;
            C.input();
            C.display();
            cout<<endl;
            C.insertionsort();
            cout<<"Output:"<<endl;
            C.display();
            break;
        }
    case 4:
        {
            Selection_Sort D;
            D.input();
            D.display();
            cout<<endl;
            D.selectionsort();
            cout<<"Output:"<<endl;
            D.display();
            break;
        }
    case 5:
        {
            Merge_2_array E;
            E.input1();
            E.input2();
            E.merge_();
            E.display();
            break;
        }
    case 6:
        {
            Merge_Sort F;
            F.input();
            F.merge_sort(0,9);
            cout<<"Output:"<<endl;
            F.display();
            break;
        }
    case 7:
        {
            Quick_sort E;
            E.input();
            E.quickSort(0,9);
            cout<<"Output:"<<endl;
            E.display();
            break;
        }
    default:
        cout<<"Invalid Input."<<endl;
    }
    cout<<endl;
    cout<<"_____________________________"<<endl;
    cout<<"Do you want to continue?"<<endl;
    cout<<"Yes = Y"<<endl;
    cout<<"No = N"<<endl;
    cin>>op;
    }
    while(op =='Y' || op == 'y');
}

