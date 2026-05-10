
from numpy import*
print("-----------TALHA REHMAN,,,,,,,,,,,,,,,,,.......")
print(".............-------THIS IS THE HUMAN VS HUMAN VERSION--------.................")
print("see the below number matrices to mark the above locations")
A=array([[' A ' ,' B ',' C '],[' D ',' E ',' F '],[' G ',' H ',' I ']])
B=array([[1,2,3],[4,5,6],[7,8,9]])
print(A)
print('__________________________')
print(B)

print('------------------------------------------------')
p1=input("enter the NAME OF PLAYER ONE:",)
p2=input("enter the NAME of player two:",)
print('--------------------------------------------')
count=10
chances=0
for d in range(1000):
    if count==0:
        break
    
    
    print(A)
    print('__________________________')
    print(B)
    #player one turn
    print('============================================================================================')
    print(".............its the player  one turn........::",p1)
    if chances==9:
        print("DRAW")
        break
    x=int(input("eneter the location:",))
    
    for j in range(len(A)):
           for i in range(3):
               if x==B[j][i]:
                    A[j][i]=' X '

                    B[j][i]=0
                    chances=chances+1
                    break
               else:
                continue

    for k in range(3):
        if A[k][0]==A[k][1]==A[k][2]==' X ' or A[0][k]==A[1][k]==A[2][k]==' X 'or A[0][0]==A[1][1]==A[2][2]==' X 'or A[0][2]==A[1][1]==A[2][0]==' X ' :
            print('++++++++++++++++++++++++++++++')
            print('congratulation')
            print("P1 win")
            count=0
            break
        else:
            continue
    #player 2 turn
    if count==0:
        break  
    print('=================================================================================')
   
    print(A)
    print('__________________________')
    print(B)
    print(".............its the player  two turn........::",p2)
    if chances==9:
        print("DRAW")
        break
    y=int(input("eneter the location:",))
    
    for j in range(len(A)):
        for i in range(3):
            if y==B[j][i]:
                A[j][i]=' O '
                B[j][i]=1
                
                chances=chances+1
                break
            else:
                continue

    for k in range(3):
        if A[k][0]==A[k][1]==A[k][2]==' 0 ' or A[0][k]==A[1][k]==A[2][k]==' O ' or A[0][0]==A[1][1]==A[2][2]==' O 'or A[0][2]==A[1][1]==A[2][0]==' O ' :
            print('++++++++++++++++++++++++++++++')
            print("CONGRATULATIONS")
            print('_______________________________________________')
            print("P2 win")
            count=0
            break


        else:
            continue
