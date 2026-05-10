#include <iostream>
#include<string.h>
using namespace std; string p1;string p2; const int rows=3;const int columns=3;int turn=9;
void data();void start();void display_screen_input(int array[rows][columns],char array2[rows][columns]);void player_turn(int array[rows][columns],char array2[rows][columns],int player);
void display_screen_output(int array[rows][columns],char array2[rows][columns]);bool win_status=false;
void win_check(int array[rows][columns],char array2[rows][columns]);
int main()
{
    int a[rows][columns];char b[rows][columns];
    start();
    data();display_screen_input(a,b);
    int p=1;player_turn(a,b,p);
}
void data()
{
    cout<<endl<<"ENTER THE NAME OF PLAYER 1 : ";cin>>p1;
    cout<<endl<<"ENTER THE NAME OF PLAYER 2 : ";cin>>p2;
    cout<<endl<<endl;
}
void start()
{
    cout<<"********  *   *****  *********     *      *****   *********   *****   ******"<<endl;
    cout<<"   |      *   |          |        * *     |           |       |   |   |      "<<endl;
    cout<<"   |      *   |          |       *****    |           |       |   |   ******"<<endl;
    cout<<"   |      *   |          |      *     *   |           |       |   |   |     "<<endl;
    cout<<"   |      *   *****      |     *       *  *****       |       *****   ******"<<endl;cout<<endl;
    cout<<"            BY   MUHAMMAD TALHA REHMAN KHAN TAREEN @ NamalInstituteMianwali        "<<endl<<endl;
}
void display_screen_input(int array[rows][columns],char array2[rows][columns])
{
      cout<<"DISPLAY SCREEN: "<<endl<<endl;
              for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){cout<<" ";array2[i][j]=' ';cout<<array2[i][j];cout<<" "<<'|';}if(i!=2){cout<<endl<<"_________________"<<endl<<endl;}}


      cout<<endl<<endl<<"CHOICE MATRIX: "<<endl;
        for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){cout<<" ";array[i][j]=i*columns+j+2;cout<<array[i][j];cout<<" ";}cout<<endl<<"___________"<<endl<<endl;}

}
void display_screen_output(int array[rows][columns],char array2[rows][columns])
{
      cout<<"DISPLAY SCREEN: "<<endl<<endl;
              for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){cout<<" ";cout<<array2[i][j];cout<<" "<<'|';}if(i!=2){cout<<endl<<"_________________"<<endl<<endl;}}


      cout<<endl<<endl<<"CHOICE MATRIX: "<<endl;
        for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){cout<<" ";cout<<array[i][j];cout<<" ";}cout<<endl<<"___________"<<endl<<endl;}

}
void player_turn(int array[rows][columns],char array2[rows][columns],int player)
{
    cout<<endl<<" NOW ITS THE TURN of player--"<<player<<endl;
    int c1;bool flag=false;
    display_screen_output(array,array2);
    cout<<endl<<":: CHOSE THE PLACE FROM CHOICE MATRIX (2-10):: ";cin>>c1;
    if(c1<=0 || c1==1 || c1>10 ){cout<<endl<<"YOU ENTERED WRONG CHOSE from 2-10"<<endl;player_turn(array,array2,player);}
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {

            if(array[i][j]==c1)
            {
                if(player==1)
                {
                    array2[i][j]=251;flag=true;array[i][j]=1;
                }
                if(player==2){array2[i][j]='X';flag=true;array[i][j]=0;}
            }
        }

    }win_check(array,array2);if(win_status==true){ cout<<endl;display_screen_output(array,array2);cout<<endl<<" CONGRATULATION PLAYER "<<player<<" ";if(player==1){cout<<p1;}else{cout<<p2;}cout<<" WIN THE MATCH"<<endl<<endl;return;}
if(flag==true){turn--;}else{cout<<endl<<"YOU ENTERED WRONG PLACE try again "<<endl;player_turn(array,array2,player);}
if(turn==0){display_screen_output(array,array2);cout<<endl<<"MATCH TIED::";return;}
if(player==1){player_turn(array,array2,2);}
if(player==2){player_turn(array,array2,1);}
}
void win_check(int array[rows][columns],char array2[rows][columns])
{ bool flag=true;
    for(int i=0;i<rows;i++)
    {  flag=true;
        for(int j=0;j<columns;j++)
        {
            if(array[i][j]!=1){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

    }
        for(int i=0;i<rows;i++)
    {  flag=true;
        for(int j=0;j<columns;j++)
        {
            if(array[i][j]!=0){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

    }
for(int i=0;i<columns;i++)
    {  flag=true;
        for(int j=0;j<rows;j++)
        {
            if(array[j][i]!=1){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

    }
        for(int i=0;i<columns;i++)
    {  flag=true;
        for(int j=0;j<rows;j++)
        {
            if(array[j][i]!=0){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

    }

for(int i=0, j=0;i<columns;i++,j++)
    {  flag=true;
            if(array[j][i]!=1){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}


        for(int i=0,j=0;i<columns;i++,j++)
     {  flag=true;
            if(array[j][i]!=0){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

for(int i=2, j=2;i>=0;i--,j--)
    {  flag=true;
            if(array[j][i]!=1){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}


        for(int i=2,j=2;i>=0;i--,j--)
     {  flag=true;
            if(array[j][i]!=0){flag=false;break;}
        }
       if(flag==true){win_status=true;return;}

}
