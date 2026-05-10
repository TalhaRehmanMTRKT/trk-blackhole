#include <iostream>
using namespace std;
class Node
{
private:
    int key;
    Node* left;
    Node* right;
    int height;
public:
    Node(int value)
    {
        key=value;
        left=NULL;
        right=NULL;
    }

    void setHeight(int h)
    {
        height=h;
    }
    int getHeight()
    {
        return height;
    }
    void setLeft(Node* temp)
    {
        left=temp;
    }
    void setRight(Node* temp)
    {
        right=temp;
    }
    Node* getLeft()
    {
        return left;
    }
    Node* getRight()
    {
        return right;
    }
    void setKey(int value)
    {
        key=value;
    }
    int getKey()
    {
        return key;
    }
};

class AVL
{
private:
    Node* root;
public:
    AVL()
    {
        root=NULL;
    }


    int max(int a, int b)
    {
        return a>b?a:b;
    }

    int getHeight(Node* node)
    {

        if(node==NULL)
        {

            return -1;
        }
        else
            return node->getHeight();
    }

    int getBalanceFactor(Node* node)
    {

        int bf=getHeight(node->getRight()) - getHeight(node->getLeft());
        return bf;
    }

    Node* LEFT_LEFT_case(Node* current)
    {
        cout<<"RIGHT ROTATION \n";
        cout<<"Rotating "<<current->getKey()<<endl;
        Node* n2=current->getLeft();
        current->setLeft(n2->getRight());
        n2->setRight(current);

        int height=max(getHeight(current->getRight()), getHeight(current->getLeft()))+1;
        current->setHeight(height);

        height=max(getHeight(n2->getRight()), getHeight(n2->getLeft()))+1;

        n2->setHeight(height);
        cout<<"Returning "<<n2->getKey()<<" as new parent\n";
        return n2;

    }
    Node* RIGHT_RIGHT_case(Node* current)
    {
        cout<<"LEFT ROTAION"<<endl;
        cout<<"Rotating "<<current->getKey()<<endl;
        Node* n2=current->getRight();
        current->setRight(n2->getLeft());
        n2->setLeft(current);

        int height=max(getHeight(current->getRight()), getHeight(current->getLeft()))+1;
        current->setHeight(height);

        height=max(getHeight(n2->getRight()), getHeight(n2->getLeft()))+1;
        n2->setHeight(height);
        cout<<"Returning "<<n2->getKey()<<" as new parent\n";
        return n2;
    }
    Node* RIGHT_LEFT_case(Node* current)
    {
        Node* n2=current->getRight();
        current->setRight(LEFT_LEFT_case(n2));
        Node* a;
        a=RIGHT_RIGHT_case(current);
        cout<<a->getKey();
        return a;
    }
    Node* LEFT_RIGHT_case(Node* current)
    {
        Node* n2=current->getLeft();
        current->setLeft(RIGHT_RIGHT_case(n2));
        Node* a;
        a=LEFT_LEFT_case(current);
        cout<<a->getKey();
        return a;
    }

    void add(int value)
    {
        Node* newNode=new Node(value);
        root=addR(root,newNode);
    }
    Node* addR(Node* start,Node* newNode)
    {
        if(start==NULL)
        {
            start=newNode;
        }
        else if(start->getKey() < newNode->getKey())
        {

            start->setRight(addR(start->getRight(),newNode));
            int bf=getBalanceFactor(start);
            if(bf==2 || bf==-2)
            {

                if(newNode->getKey() > start->getRight()->getKey())
                {
                    cout<<"Right Right case "<<endl;
                    start= RIGHT_RIGHT_case(start);

                }
                else
                {
                    cout<<"Right Left case"<<endl;
                    start= RIGHT_LEFT_case(start);
                }
            }
        }
        else if(start->getKey() > newNode->getKey())
        {
            start->setLeft(addR(start->getLeft(),newNode));
            int bf=getBalanceFactor(start);

            if(bf==2 || bf==-2)
            {

                if(newNode->getKey() < start->getLeft()->getKey())
                {
                    cout<<"Left Left CASE "<<endl;
                    start= LEFT_LEFT_case(start);

                }
                else
                {
                    cout<<"Left Right CASE "<<endl;
                    start= LEFT_RIGHT_case(start);
                }
            }
        }
        int height=max(getHeight(start->getRight()), getHeight(start->getLeft()))+1;
        start->setHeight(height);
        return start;
    }
    void remove(int x)
	{
		Node *temp = root;
		Node *temp1;
		Node *temp2;
		Node *temp3;
		if (root == NULL)
		{
			cout << "\n NO TREE ";
			return;
		}
		while (temp != NULL)
		{
			if (x < temp->getKey())
			{
				if (temp->getLeft() == NULL)
				{
					cout << "\n Not found :: ";
					return;
				}
				else
				{
					temp1 = temp;
					temp = temp->getLeft();
				}
			}
			else if (x > temp->getKey())
			{
				if (temp->getRight() == NULL)
				{
					cout << "\n NOT FOUND :: ";
					return;
				}
				else
				{
					temp1 = temp;
					temp = temp->getRight();
				}
			}
			else
			{
				if (temp->getLeft() != NULL)
				{
					if (temp->getRight() == NULL)
					{
						if (temp1->getLeft() == temp)
						{
							temp1->setLeft(temp->getLeft());return;
						}
						else
						{
							temp1->setRight(temp->getLeft());return;
						}
					}
					temp3 = temp->getLeft();
					if (temp3->getRight() != NULL)
					{
						while (temp3->getRight() != NULL)
						{
							temp2 = temp3;
							temp3 = temp3->getRight();
						}
						temp->setKey(temp3->getKey());
						temp2->setRight(temp3->getLeft());
						return;
					}
					else
					{
						temp3->setRight(temp->getRight());cout<<"1";
						if(temp==root){root=temp3;return;}
						temp1->setRight(temp3);
						return;
					}
				}
				else if (temp->getRight() != NULL)
				{
					if (temp1->getLeft() == temp)
					{
						temp1->setLeft(temp->getRight());
					}
					else
					{
						temp1->setRight(temp->getRight());
					}
				}
				else
				{
					if (temp == root)
					{
						root = NULL;
						return;
					}
					else if (temp == temp1->getLeft())
					{
						temp1->setLeft(NULL);
						return;
					}
					else
					{
						temp1->setRight(NULL);
						return;
					}
				}
			}
		}cout<<"\n Not Found";
	}

    void display()
    {
        displayR(root);
    }
    void displayR(Node* start)
    {
        if(start!=NULL)
        {
            displayR(start->getLeft());
            cout<<start->getKey()<<"  ";
            displayR(start->getRight());
        }
    }
    void display2()
    {
        Node *temp = root;
        cout << endl
             << "\n   Pre order display \n ";
        preorder(temp);
    }
    void preorder(Node *rt)
    {
        if (rt == NULL)
        {
            return;
        }
        else
        {
            cout << "    ";
            Search(rt->getKey());
            cout << endl;
            preorder(rt->getLeft());
            preorder(rt->getRight());
            return;
        }
    }
    void Search(int x)
    {
        Node *temp = root;
        Node *temp1 = temp;
        if (temp == NULL)
        {
            cout << "\n THE TREE IS EMPTY  HAHA :-)";
            return;
        }
        while (temp != NULL)
        {
            if (x < temp->getKey())
            {
                temp1 = temp;
                if (temp->getLeft() == NULL)
                {
                    cout << "\n"
                         << x << " NOT FOUND ::  ";
                    return;
                }
                else
                {
                    temp = temp->getLeft();
                }
            }
            else if (x > temp->getKey())
            {
                temp1 = temp;
                if (temp->getRight() == NULL)
                {
                    cout << "\n"
                         << x << " NOT FOUND ::  ";
                    return;
                }
                else
                {
                    temp = temp->getRight();
                }
            }
            else
            {
                if (temp == root)
                {
                    cout << " I AM THE PARENT OF ALL IN TREE :: " << root->getKey();
                    return;
                }
                else if (temp1->getRight() == temp)
                {
                    cout << "\n"
                         << x << " is RIGHT CHILD OF :: " << temp1->getKey();
                    return;
                }
                else
                {
                    cout << "\n"
                         << x << "  is LEFT CHILD OF :: " << temp1->getKey();
                    return;
                }
            }
        }
    }


};
int main()
{

    AVL bst;
    bst.add(12);
    bst.add(8);
    bst.add(13);
    bst.add(4);
    bst.add(9);
    bst.add(10);
    cout<<"\n";
    bst.display2();
    bst.remove(8);
    bst.display2();
        return 1;
}

