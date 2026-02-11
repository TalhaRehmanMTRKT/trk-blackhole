#include <iostream>
#include <fstream>
using namespace std;
class Node
{
  private:
	string name;
	Node *next;

  public:
	Node(string a)
	{
		name = a;
		next = NULL;
	}
	void setName(string a)
	{
		name = a;
	}
	string getName()
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
	void addAtStart(string a)
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
	int Search(string a)
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
	void addAtEnd(string a)
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

	void Add(string n, int i)

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

	void remove(string n)
	{
		Node *temp = head;
		Node *temp1;
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
	void automator(string a)
	{
		fstream file;
		file.open(a);
		while (!file.eof())
		{
			string t;
			file >> t;
			if (t == "endl")
			{
				cout << endl
					 << endl;
			}
			if (t == "AAS")
			{
				string x;
				file >> x;
				addAtStart(x);
			}
			if (t == "AAE")
			{
				string x;
				file >> x;
				addAtEnd(x);
			}
			if (t == "ADD")
			{
				string x;
				int y;
				file >> x >> y;
				Add(x, y);
			}
			if (t == "REM")
			{
				string x;
				file >> x;
				remove(x);
			}
			if (t == "RAT")
			{
				int x;
				file >> x;
				removeAt(x);
			}
			if (t == "RAS")
			{
				removeAtStart();
			}
			if (t == "RAE")
			{
				removeAtEnd();
			}
			if (t == "DIS")
			{
				display();
			}
			if (t == "DIR")
			{
				displayReverse();
			}
		}
	}
};
int main()
{
	LinkedList a;
	//a.display();cout<<"\n __________________________________________________________";a.addAtEnd("TA");	a.addAtEnd("Ahn");	a.addAtEnd("han");	a.display();	cout<<"\n ___________________________________________________________";	cout << "The size of list is ="<<a.Size();cout << endl << endl;	cout<<"\n ___________________________________________________________";#cout << a.Search("han");cout<<"\n___________________________________________________________";a.display();#cout<<"\n ___________________________________________________________";#a.Add("kaa", 2);#a.display();	cout<<"\n ___________________________________________________________";a.removeAt(5);a.display();	cout<<"\n ___________________________________________________________";	a.remove("han");	a.display();
	a.automator("input.txt");
}
