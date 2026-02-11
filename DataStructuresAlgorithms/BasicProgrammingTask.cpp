
#include<iostream>
using namespace std;
void capital_or_small(char a);
void num_to_word (int x);
void a1(int x);
int a2(int x);
int a3(int x);
int a4(int x);
int a5(int x);
int a6(int x, int y,int counter);
int a7(int x, int first=0,int second=1);
int a8(int x, int first=0,int second=1);
void task1_Capital_small_letter();
void task2_num_to_words();
void task3_sum_the_Numbers();
void task4_PrintChar();
void task5_shapeA();
void task6_shapeB();
void task7_shapeC();
void task8_shapeD();
void task9_shapeE();
void task10_shapeF();
void task11_Permutation();
void task12_Factorial_A();
void task14_Factorial_recursive2();
void task13_Factorial_recursive1();
void task15_GCD_loop();
void task16_GCD_recursion();
void task17_fibonacciA();
void task18_fibonacciB();
void task19_fibonacciA_Recursion();
void task20_fibonacciB_Recursion();
int main()
{
    task1_Capital_small_letter();
    task2_num_to_words();
    task3_sum_the_Numbers();
    task4_PrintChar();
    task5_shapeA();
    task6_shapeB();
    task7_shapeC();
    task8_shapeD();
    task9_shapeE();
    task10_shapeF();
    //task11_Permutation();
    task12_Factorial_A();
    task13_Factorial_recursive1();
    task14_Factorial_recursive2();
    task15_GCD_loop();
    task16_GCD_recursion();
    task17_fibonacciA();
    task18_fibonacciB();
    task19_fibonacciA_Recursion();
    task20_fibonacciB_Recursion();

}
void task1_Capital_small_letter()
{
    cout<<"::::::::"<<"4.1  CAPITAL OR SMALL"<<"::::::::"<<endl<<endl;
    cout<<"Enter the Character  "<<endl<<endl;
    char x;
    cin>>x;
    capital_or_small(x);
}
void capital_or_small(char a)
{
    int y;
    y=a;
    if(y>=65 && y<=91)
    {
        cout<<endl<<" CAPITAL LETTER "<<endl<<endl;
    }
    else if(y>=97 && y<=122)
    {
        cout<<endl<<"SMALL LETTER "<<endl<<endl;
    }
    else
    {
        cout<<endl<<" NON "<<endl<<endl;
    }
}
void task2_num_to_words()
{
    cout<<"::::::::"<<"4.2  Number To Words "<<"::::::::"<<endl<<endl;
    cout<<endl<<" Enter the 6 digit number "<<endl;
    int x;
    cin>>x;
    num_to_word(x);
}
void num_to_word (int x)
{
    if(x/1000000>=1)
    {
        cout<<"You HAVE ENTERED GREATER THAN 6 DIGIT"<<endl;
        return;
    }
    int a,b,c,d,e,f;
    a=x%10;
    b=(x%100)/10;
    c=(x%1000)/100;
    d=(x%10000)/1000;
    e=(x%100000)/10000;
    f=(x%1000000)/100000;
    a1(f);
    a1(e);
    a1(d);
    a1(c);
    a1(b);
    a1(a);
    cout<<endl;
}
void a1(int x)
{
    switch(x)
    {
    case 0:
    {
        cout<<"Zero ";
        break;
    }
    case 1:
    {
        cout<<"One ";
        break;
    }
    case 2:
    {
        cout<<"Two ";
        break;
    }
    case 3:
    {
        cout<<"Three ";
        break;
    }
    case 4:
    {
        cout<<"Four ";
        break;
    }
    case 5:
    {
        cout<<"Five ";
        break;
    }
    case 6:
    {
        cout<<"Six ";
        break;
    }
    case 7:
    {
        cout<<"Seven ";
        break;
    }
    case 8:
    {
        cout<<"Eight ";
        break;
    }
    case 9:
    {
        cout<<"Nine ";
        break;
    }
    default:
    {
        return;
    }
    }
}
void task3_sum_the_Numbers()
{
    cout<<endl<<":::::::"<<" TASK 4.3 Sum The Numbers "<<":::::::::"<<endl;
    cout<<endl<<a2(500)<<endl<<endl;
}
int a2(int x)
{
    if(x==3000)
    {
        return 0;
    }
    else if(x%5==0 && x%3==0)
    {
        return a2(x+1);
    }
    else if(x%3==0 || x%5==0)
    {
        return x+a2(x+1);
    }
    else
    {
        return a2(x+1);
    }
}

void task4_PrintChar()
{
    cout<<endl<<endl<<"::::::"<<" TASK 4.4 a) Print Char  "<<"::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=1; i<=x; i++)
    {
        cout<<y;
    }
    cout<<endl<<endl;
}
void task5_shapeA()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 b) SHAPE A "<<"::::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=1; i<=x; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void task6_shapeB()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 c) SHAPE B "<<"::::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=x; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl<<endl;

}
void task7_shapeC()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 d) SHAPE C "<<"::::::::"<<endl<<endl;

    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=x; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<y;
        }
        cout<<endl;
        for(int f=i; f<=x; f++)
        {
            cout<<" ";
        }
    }
    cout<<endl<<endl;
}
void task8_shapeD()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 e) SHAPE D "<<"::::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=x; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<y;
        }
        for(int f=i; f<x; f++)
        {
            cout<<" ";
        }
        for(int f=i; f<x; f++)
        {
            cout<<" ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void task9_shapeE()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 f) SHAPE E "<<"::::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;
    for(int i=x; i>=1; i--)
    {
        for(int j=i; j<=x; j++)
        {
            cout<<y;
        }
        for(int f=1; f<i; f++)
        {
            cout<<" ";
        }
        for(int f=1; f<i; f++)
        {
            cout<<" ";
        }
        for(int k=i; k<=x; k++)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void task10_shapeF()
{
    cout<<endl<<endl<<":::::::"<<" TASK 4.4 g) SHAPE F "<<"::::::::"<<endl<<endl;
    int x;
    char y;
    cout<<endl<<" Enter the Number of times you want to print [HEIGHT] "<<endl;
    cin>>x;
    cout<<endl<<" Enter the character you want to print "<<endl;
    cin>>y;
    cout<<endl<<endl;

    for(int i=x; i>=1; i--)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<y;
        }
        for(int f=i; f<x; f++)
        {
            cout<<" ";
        }
        for(int f=i; f<x; f++)
        {
            cout<<" ";
        }
        for(int k=1; k<=i; k++)
        {
            cout<<y;
        }
        cout<<endl;
    }


    for(int i=x; i>=1; i--)
    {
        for(int j=i; j<=x; j++)
        {
            cout<<y;
        }
        for(int f=1; f<i; f++)
        {
            cout<<" ";
        }
        for(int f=1; f<i; f++)
        {
            cout<<" ";
        }
        for(int k=i; k<=x; k++)
        {
            cout<<y;
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void task11_Permutation()
{

}
void task12_Factorial_A()
{
    cout<<endl<<"::::::::::"<<" TASK 4.6 a) Factorial A "<<":::::::::"<<endl<<endl;
    int x;
    cout<<" Enter the NUmber to find FActorial "<<endl;
    cin>>x;
    cout<<endl<<endl;
    cout<<a3(x);
    cout<<endl<<endl;
    cout<<endl<<endl;
}
int a3(int x)
{
    if(x==1 || x==0)
    {
        return 1;
    }
    else
    {
        return x*a3(x-1);
    }
}
void task14_Factorial_recursive2()
{
    cout<<endl<<"::::::::::"<<" TASK 4.6 d) REcursive Factorial B "<<":::::::::"<<endl<<endl;
    int x;
    cout<<" Enter the NUmber to find FActorial  "<<endl;
    cin>>x;
    cout<<endl<<endl;
    cout<<a4(x);
    cout<<endl<<endl;

}
int a4(int x)
{
    if(x==1 || x==0)
    {
        cout<<x<<"=";
        return 1;
    }
    else
    {
        cout<<x<<"*";
        return x*a4(x-1);
    }
}
void task13_Factorial_recursive1()
{
    cout<<endl<<"::::::::::"<<" TASK 4.6 b) REcursive Factorial A "<<":::::::::"<<endl<<endl;
    int x;
    cout<<" Enter the NUmber to find FActorial  "<<endl;
    cin>>x;
    cout<<endl<<endl;
    cout<<"="<<a5(x);
    cout<<endl<<endl;

}
int a5(int x)
{
    int z;
    if(x==1 || x==0)
    {
        cout<<x<<"*";
        return 1;
    }
    else
    {
        z=x*a5(x-1);
        cout<<x<<"*";
    }
    return z;
}
void task15_GCD_loop()
{
    cout<<endl<<endl;
    cout<<endl<<"::::::::"<<" TASK 4.7 a) GCD using loops "<<"::::::::";
    cout<<endl<<"ENTER THE FIRST NUMBER "<<endl;
    int x;
    cin>>x;
    cout<<endl<<"ENTER THE SECOND NUMBER "<<endl;
    int y;
    cin>>y;
    int counter=1;
    int gcd;
    while(counter<=y && counter<=x)
    {
        if(x%counter==0 && y%counter==0)
        {
            gcd=counter;
        }
        counter=counter+1;
    }
    cout<<endl<<endl<<"  Gcd is =  "<<gcd;
    cout<<endl<<endl;
}

void task16_GCD_recursion()
{
    cout<<endl<<endl;
    cout<<endl<<"::::::::"<<" TASK 4.7 a) GCD using Recursion "<<"::::::::";
    cout<<endl<<"ENTER THE FIRST NUMBER "<<endl;
    int x;
    cin>>x;
    cout<<endl<<"ENTER THE SECOND NUMBER "<<endl;
    int y;
    cin>>y;
    cout<<endl;
    cout<<" GCD IS == "<<a6(x,y,x);
}
int a6(int x, int y,int z)
{
    if(z>y)
    {
        z=y;
        return a6(x,y,z);
    }
    else if(z==1)
    {
        return z;
    }
    else if(x%z==0 && y%z==0)
    {
        return z;
    }
    else
    {
        return a6(x,y,z-1);
    }
}
void task17_fibonacciA()
{
    cout<<endl<<endl<<":::::::"<<" get the Fibonacci num A "<<":::::::"<<endl<<endl;
    cout<<endl<<" Enter the number (the nth fibonacci) "<<endl<<endl;
    int x;
    cin>>x;
    cout<<endl<<endl;
    int j=0,k=1;
    int f;
    for(int i=1; i<x; i++)
    {
        f=j+k;
        j=k;
        k=f;
    }
    cout<<endl<<endl<<j;
}
void task18_fibonacciB()
{
    cout<<endl<<endl<<":::::::"<<" get the Fibonacci num B "<<":::::::"<<endl<<endl;
    cout<<endl<<" Enter the number (the nth fibonacci) "<<endl<<endl;
    int x;
    cin>>x;
    int j=0,k=1;
    int f;
    for(int i=1; i<x; i++)
    {
        cout<<j<<", ";
        f=j+k;
        j=k;
        k=f;
    }
    cout<<j;
}
void task19_fibonacciA_Recursion()
{
    cout<<endl<<endl<<":::::::"<<" get the Fibonacci num A recursion "<<":::::::"<<endl<<endl;
    cout<<endl<<" Enter the number (the nth fibonacci) "<<endl<<endl;
    int x;
    cin>>x;
    cout<<endl<<endl;
    cout<<endl<<a7(x,0,1);
    cout<<endl<<endl;
}
int a7(int x, int first,int second)
{
    if(x==1)
    {
        return first;
    }
    else
    {
        return a7(x-1,second,first+second);
    }
}
void task20_fibonacciB_Recursion()
{
    cout<<endl<<endl<<":::::::"<<" get the Fibonacci num B recursion "<<":::::::"<<endl<<endl;
    cout<<endl<<" Enter the number (the nth fibonacci) "<<endl<<endl;
    int x;
    cin>>x;
    cout<<endl<<endl;
    cout<<a8(x,0,1);
    cout<<endl<<endl<<endl;
}
int a8(int x, int first,int second)
{

    if(x==1)
    {
        return first;
    }
    else
    {
        cout<<first<<" , ";
        a8(x-1,second,first+second);
    }
}

