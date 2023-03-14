#include <iostream>
#include "NodeClass.h"//User Defined Library
using namespace std;

class Dlinkedlist
{
private:
	DNode *head; //Head declare the starting point of the list
	DNode *tail; //Tail declare the ending point of the list
public:
	Dlinkedlist() //This is a constructor
	{
		head = 0;
		tail = 0;
	}
	
	void addToHead(double element);
	void addToTail(double element);
	void addAfter(double existing, double element);
	void addBefore(double existing, double element);
	void deletefromHead();
	void deletefromTail();
	void deleteSpecific(double element); //this function is used to delete specific value from the list
	void traverselist();//Display Function


};
void Dlinkedlist::addToHead(double element) //a function for adding value at the start of list
{
	DNode *newNode = new DNode(element); //creates a new node to enter data in the list
	if (head == 0 && tail == 0)			 //condition shows list is empty
	{
		head = tail = newNode; //new Node is added at the head
	}
	else
	{
		newNode->next = head; //shift the address of head to new node's next part
		head = newNode;		  //make head as a new Node
	}
}
void Dlinkedlist::addToTail(double element) //a function for adding value at the end of the list
{
	DNode *newNode = new DNode(element);
	if (head == 0 && tail == 0)
	{
		tail = newNode;
	}
	else
	{
		tail->next = newNode; //add null in the next part of null to make new node as the tail
		tail = newNode;
	}
}
void Dlinkedlist::addAfter(double existing, double element) //this function add value after an existing value and the existing is provided by the user
{
	if (tail->data == existing) //Check if value of tail equals to existing (call the function of addToTail) so that we don't need to search the whole list for existing which saves our time
	{
		addToTail(element);
	}
	else
	{
		DNode *current = head;							  //Make head as the current node and start searching the existing value which is provided by the user
		while (current != 0 && current->data != existing) //this condition is true till the user do not find an existing value or the current is not equal to 0
		{
			current = current->next; //Till the above condition is true so the reference of current is shifting forward in the list
		}
		if (current == 0) //means existing not present in our list
		{
			cout << "Existing not present in the list";
		}
		else
		{
			DNode *newNode = new DNode(element);
			newNode->next = current->next; //when the existing value is found store the address  of current or present node in the new node's next part
			current->next = newNode;
		}
	}
}
void Dlinkedlist::addBefore(double existing, double element) //this function add value before an existing value and the existing is provided by the user
{
	if (head->data == existing)
	{
		addToHead(element);
	}
	else
	{
		DNode *current = head;
		while (current != 0 && current->data != existing)
		{
			current = current->next;
		}
		if (current == 0)
		{
			cout << "Existing not present in the list";
		}
		else
		{
			DNode *newNode = new DNode(element);
			newNode->next = current->next;
			current->next = newNode;
		}
	}
}
void Dlinkedlist::deletefromHead() //Delete from head delete data from the head ( from the start of the list)
{
	if (head == 0 && tail == 0)
	{
		cout << "List is empty";
	}
	else
	{
		DNode *current = head;
		head = current->next; //this shift's the address of head to the next node from the head
		delete current;		  //delete the current node which is the head of the list
	}
}
void Dlinkedlist::deletefromTail() //Delete from tail delete data from the tail ( from the end of the list)
{
	if (head == 0 && tail == 0)
	{
		cout << "List is empty." << endl;
	}
	else
	{
		DNode *current = tail;
		current->next = tail; //store null in next part of current this makes the current as the tail of list
		delete current;
	}
}

void Dlinkedlist::traverselist() //this function is used to display values from the list
{
	if (head == 0 && tail == 0)
	{
		cout << "List is empty." << endl;
	}
	else
	{int num=0;
		DNode *currentNode = head; //start from the head
		while (currentNode != 0)
		{
			cout << currentNode->data << "\t";
			currentNode = currentNode->next; //shift the reference of current node to next node of current and display values from head to tail
			num++; //increments number of nodes until nodes does not points to null
		}
	}
}

int main()
{
	cout << "**Doubly Linked List**" << endl;
	Dlinkedlist list;
	int choice;
	do
	{
		cout << "\n\t.....Menu......" << endl;
		cout << "\nPress 1: Add to Head" << endl;
		cout << "Press 2: Add to Tail" << endl;
		cout << "Press 3: Add After" << endl;
		cout << "Press 4: Add Before" << endl;
		cout << "Press 5: Delete from Head" << endl;
		cout << "Press 6: Delete from Tail" << endl;
		cout << "Press 7: Traverse the List" << endl;
		cout << "Press 8: Exit" << endl;
		cout << "\nEnter choice of user: ";
		cin >> choice;
		if (choice == 1)
		{
			int Element;
			cout << "Enter element = ";
			cin >> Element;
			list.addToHead(Element);
		}
		else if (choice == 2)
		{
			int element;
			cout << "Enter element = ";
			cin >> element;
			list.addToTail(element);
		}
		else if (choice == 3)
		{

			int Element;
			cout << "Enter element = ";
			cin >> Element;
			int Existing;
			cout << "Enter existing to add value after existing. = " << endl;
			cin >> Existing;
			list.addAfter(Existing, Element);
		}

		else if (choice == 4)
		{

			int Element;
			cout << "Enter element = ";
			cin >> Element;
			int Existing;
			cout << "Enter existing to add value after existing. = " << endl;
			cin >> Existing;
			list.addBefore(Existing, Element);
		}
		else if (choice == 7)
		{
			list.traverselist();
		}
		
		else if (choice == 5)
		{
			list.deletefromHead();
		}
		else if (choice == 6)

		{
			list.deletefromTail();
		}

		else if (choice == 8)

		{
			cout<<"Thank You for Using The Program"<<endl;
		}

		else if (choice == 9)
		{
			cout << "Invalid choice. Enter again" << endl;
		}
	} while (choice != 8);
	return 0;
}
