#include <iostream>
using namespace std;
class Node
{
  private:
	int Data;
	Node *Left;
	Node *Right;

  public:
	Node(int x)
	{
		Data = x;
		Left = NULL;
		Right = NULL;
	}
	Node *getLeft()
	{
		return Left;
	}
	Node *getRight()
	{
		return Right;
	}
	int getData()
	{
		return Data;
	}
	void setLeft(Node *n)
	{
		Left = n;
	}
	void setRight(Node *n)
	{
		Right = n;
	}
	void setData(int x)
	{
		Data = x;
	}
	void display()
	{
		cout << "\n THE NODE DATA IS :: " << Data;
	}
};
class BST
{
  private:
	Node *root;

  public:
	BST()
	{
		root = NULL;
	}
	void addNode(int x)
	{
		Node *temp = root;
		Node *t = new Node(x);
		if (temp == NULL)
		{
			root = t;
			cout << "\n I BECOME ROOT HAHA :-)";
			return;
		}
		while (temp != NULL)
		{
			while (x <= temp->getData())
			{
				if (temp->getLeft() == NULL)
				{
					temp->setLeft(t);
					cout << "\n i have been added to Left   of " << temp->getData();
					return;
				}
				else
				{
					temp = temp->getLeft();
					break;
				}
			}
			while (x > temp->getData())
			{
				if (temp->getRight() == NULL)
				{
					temp->setRight(t);
					cout << "\n i have been added to RIGHT   of " << temp->getData();
					return;
				}
				else
				{
					temp = temp->getRight();
					break;
				}
			}
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
			if (x < temp->getData())
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
			else if (x > temp->getData())
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
					cout << " I AM THE PARENT OF ALL IN TREE :: " << root->getData();
					return;
				}
				else if (temp1->getRight() == temp)
				{
					cout << "\n"
						 << x << " is RIGHT CHILD OF :: " << temp1->getData();
					return;
				}
				else
				{
					cout << "\n"
						 << x << "  is LEFT CHILD OF :: " << temp1->getData();
					return;
				}
			}
		}
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
			Search(rt->getData());
			cout << endl;
			preorder(rt->getLeft());
			preorder(rt->getRight());
			return;
		}
	}
	void inorder(Node *rt)
	{
		if (rt == NULL)
		{
			return;
		}
		else
		{
			inorder(rt->getLeft());
			cout << "    ";
			Search(rt->getData());
			cout << endl;
			inorder(rt->getRight());
			return;
		}
	}
	void postorder(Node *rt)
	{
		if (rt == NULL)
		{
			return;
		}
		else
		{
			postorder(rt->getLeft());
			postorder(rt->getRight());
			cout << "    ";
			Search(rt->getData());
			cout << endl;
			return;
		}
	}
	void display()
	{
		Node *temp = root;
		cout << endl
			 << "\n   Pre order display \n ";
		preorder(temp);
		cout << endl
			 << "\n   In order display \n ";
		inorder(temp);
		cout << endl
			 << "\n   post order display \n  ";
		postorder(temp);
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
			if (x < temp->getData())
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
			else if (x > temp->getData())
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
						temp->setData(temp3->getData());
						temp2->setRight(temp3->getLeft());
						return;
					}
					else
					{
						temp3->setRight(temp->getRight());
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
};

int main()
{
	BST a;
	a.addNode(500);
	a.addNode(600);
	a.addNode(700);

	a.addNode(400);
	a.addNode(550);
	a.addNode(450);
	a.addNode(449);
	a.addNode(452);
	a.addNode(451);
	a.addNode(549);
	cout << endl
		 << endl;
	cout << "   search \n   \n";
	a.Search(500);
	a.Search(42342);
	a.Search(600);
	a.Search(700);
	a.Search(400);
	a.Search(550);
	a.Search(450);
	a.Search(452);
	a.Search(451);
	a.Search(549);
	cout << endl
		 << endl;
	a.display();
	cout << endl;
	a.remove(449);
	cout << "hi";
	a.display();
}
