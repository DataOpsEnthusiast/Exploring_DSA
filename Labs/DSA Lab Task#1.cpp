#include<iostream>
using namespace std;
class Node  //Class for node
{
	public:
		string Name;
		int Roll;
		int Contact;
		Node* next;    //node of NEXT is created
		Node(string n, int c=0 ,int r = 0, Node* x = 0)
		{
			Name = n;
			Contact = c;
			Roll = r;
			next = x;
		}
};
class Record   //class created for student record 
{
	public:
		Node* head; // Node created for head that represents starting of the list
		Node* tail; // Node created for tail that represents ending of the list
	
		Record(void) { // constructor
			head = 0;
			tail = 0;
		}
		~Record(void); //destructor
		bool isEmpty() {   //checks whether the list is empty or not
			if(head == 0)
			{
				return true;   //returns true if list is empty
			}
			else
			{
				return false;  //returns false if list is not empty
			}
		}	
		void addToHead(string name,int roll,int contact); // Adds record to head of list (first node)
		void addToTail(string name,int roll,int contact); // Adds record to tail of list (last node)
		void addAfter(double existing,string name,int roll,int contact); // Adds record after specific record
		void addSorted(string name,int roll,int contact);
		int findNode(double existing); // search a record in the list
		void deleteNode(double existing); // deletes a record with specific value(roll no)
		void deletefromHead(); // deletes record from a head node
		void deletefromTail(); // deletes record from a tail node	
		void traverseList(void);  //display the whole list of records 	
		void Display(string name,int roll,int contact);
};

void Record::addToHead(string name,int roll,int contact)  //calling function to add record in head
{
	Node *newNode = new Node(name,roll,contact); // node created for name,roll and contact
	if(head == 0 && tail == 0)  //checks if list is empty or not
	{
		head = tail = newNode;  //if list is empty new node will be created
	}
	else
	{
		newNode->next = head;   //else new node will be pointed as head
		head = newNode;
	}
}

void Record::addToTail(string name,int roll,int contact)  //calling funtion to add record to tail of the list
{
	Node *newNode = new Node(name,contact, roll);  //nodes created for name, roll and contact
	if(head == 0 && tail == 0)   //checks if list is empty or not
	{
		head = tail = newNode;   //new node will be created which will point to tail
	}
	else
	{
		tail->next = newNode; //else new node will be pointed as head
		tail = newNode;
	}
}

void Record::addAfter(double existing,string name,int roll,int contact)   //calling function to store record after a specific record
{
	if(head == 0 && tail == 0)
	{
		cout<<"List is empty so there is no existing record found in the List."<<endl;  //checks if list is empty (no record will be inserted)
	}
	else if(tail->Roll == existing)  //else record will be inserted after the existing record
	{
		addToTail(name,roll,contact);  
	}
	else
	{
		Node *currNode = head; // this node will help in finding the existing value
		while(currNode != 0 && currNode->Roll != existing)
		{
			currNode = currNode->next;
		}
		
		if(currNode == 0) // no existing value is found in list
		{
			cout<<"No existing record found."<<endl;
		}
		else
		{ 
			Node *newNode = new Node(name,roll,contact);
			newNode->next = currNode->next;
			currNode->next = newNode;
		}
	}
}

void Record::addSorted(string name,int roll,int contact)  //function to sort the record in an order
    {
    	Node *Null; //null node created 
        Node *temp = Null;
        if(head == Null || head->Roll > roll)  //head is null so roll# will be stored in head
        {
            temp = new Node(name,roll,contact);  //temp node created for name, contact and roll
            temp->Name =name; //temp will store name, roll# and contact
            temp->Roll = roll;
            temp->Contact = contact;
            temp->next = head;
            head = temp;
            return;
        }
        temp = head;
        while( temp->next != Null && temp->next->Roll < roll )    //checks if next node of the temp has smaller roll# then roll# in temp node
        {
            temp = temp->next;  //temp will move to next node
        }
         temp = new Node(name,roll,contact);
         temp->Name =name; 
         temp->Roll = roll;
         temp->Contact = contact;
            
        temp->next =  temp->next;
        temp->next = temp;
}

int Record::findNode(double existing) //calling function to search record in the list
{
	Node *currNode = head; //current node is created which will be equal to head
	int currIndex = 1;  //variable index initialize to 1
	while(currNode != 0 && currNode->Roll != existing) //current node has some value stored in it and its roll# is not same as existing roll#
	{
		currNode = currNode->next; //current node will move to next node
		currIndex++;  //index will increment
	}
	
	if(currNode) return currIndex;
	
	return 0;
}

void Record::deleteNode(double existing)  //calling function to delete a record from the list
{
	Node *prevNode = 0; //node created for previous node and initialized to 0
	Node *currNode = head;
	while(currNode != 0 && currNode->Roll != existing) //when current node has some value stored in it and its roll# is not same as existing roll#
	{
		prevNode = currNode; //previous node will be equal to current node
		currNode = currNode->next;
	}
	
	if(currNode)
	{
		if(prevNode != 0) //if previous node is not equal to 0
		{
			prevNode->next = currNode->next; //previous node and current node will move to next
			cout<<currNode->Roll<<" is deleted from the List."<<endl;
			delete currNode; //deletes the current node
		}
		else
		{
			head = currNode->next; //head will be equal to the next of current node
			cout<<currNode->Roll<<" is deleted from the List."<<endl;
			delete currNode;
		}
	}
	else
	{
		cout<<"Existing record not found in the list."<<endl;
	}
}

void Record::deletefromTail() //calling functon to delete record stored in tail
{
	if(head == 0 && tail == 0)  //checks if list is empty
	{                          //list is empty
		cout<<endl<<"Nothing to delete from Tail from the list.";
	}
	else  //list is not empty
	{
		Node *currNode = head;
		while(currNode->next != tail) //next node of current node is not equal to tail node 
		{
			currNode = currNode->next;
		}
		Node *newNode = tail;
		tail = currNode;
		currNode->next = 0;
		cout<<newNode->Roll<<" is deleted from the List."<<endl;  //deletes a record from the new node
		delete newNode;
	}
}

void Record::deletefromHead()  //calling functon to delete record stored in head
{
	if(head == 0 && tail == 0) //list is empty
	{
		cout<<endl<<"Nothing to delete from Head from the list.";
	}
	else //list is not empty
	{
		Node *newNode = head;
		head = head->next;
		newNode->next = 0;  //next of new node will be equal to 0
		cout<<newNode->Roll<<" is deleted from the List."<<endl;
		delete newNode;
	}
}

void Record::traverseList(void) //calling function to display the list of student records
{
	int num = 0; //variable n declared and initialized to 0 to display total number of nodes
	Node *currNode = head;
	while(currNode != 0) //when current node has some record stored in it
	{
		cout<<endl;
		cout<<currNode->Name<<endl;  //displays name, roll# and contact
		cout<<currNode->Roll<<endl;
		cout<<currNode->Contact<<endl;
		currNode = currNode->next;
		num++; //increments number of nodes until nodes does not points to null
	}
	
	cout<<"Number of Nodes in the List = "<<num<<endl;
}

Record::~Record(void)  //calling destructor
{
	Node *currNode = head;
	Node *nextNode = 0; 
	while(currNode != 0)
	{
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

int main()  //main function to be executed first
{
	cout<<"Student Record Info Program "<<endl<<endl;
	string name;
	int roll,contact;
	double existing;
	Record rec;
	int option;
	do
	{
		cout<<"Press 1 to add first record"<<endl;
		cout<<"Press 2 to add record in the last node"<<endl;
		cout<<"Press 3 to add record after a specific record"<<endl;
		cout<<"Press 4 to display record in sorted form"<<endl;
		cout<<"Press 5 to delete record in the first node"<<endl;
		cout<<"Press 6 to delete record in the last node"<<endl;
		cout<<"Press 7 to delete a specific record"<<endl;
		cout<<"Press 8 to display record"<<endl;
		cout<<"Press 9 to search a record in the list"<<endl;
		cout<<"Press 10 to exit the program"<<endl;
		cout<<"Enter your Option: "<<endl;
		cin>>option;
		if(option == 1)
		{
			cout<<"Enter Name: "<<endl;
			cin>>name;
			cout<<"Enter roll number: "<<endl;
			cin>>roll;
			cout<<"Enter contact: "<<endl;
			cin>>contact;
			rec.addToHead(name,roll,contact);
		}
		else if(option == 2)
		{
			cout<<"Enter Name: "<<endl;
			cin>>name;
			cout<<"Enter roll number: "<<endl;
			cin>>roll;
			cout<<"Enter contact: "<<endl;
			cin>>contact;
			rec.addToTail(name,roll,contact);
		}
		else if(option == 3)
		{
			cout<<"Enter existing record after which you want to add: "<<endl;
			cin>>existing;
			string name;
			int roll,contact;
			cout<<"Enter Name: "<<endl;
			cin>>name;
			cout<<"Enter Roll Number: "<<endl;
			cin>>roll;
			cout<<"Enter Contact: "<<endl;
			cin>>contact;
			rec.addAfter(existing,name,roll,contact);
		}
		else if(option==4)
		{
		    cout<<"Enter Name: "<<endl;
			cin>>name;
			cout<<"Enter roll: "<<endl;
			cin>>roll;
			cout<<"Enter contact: "<<endl;
			cin>>contact;
			rec.addSorted(name,roll,contact);
		}
		else if(option == 5)
		{
			rec.deletefromHead();
		}
		else if(option == 6)
		{
			rec.deletefromTail();
		}
		else if(option == 7)
		{
			cout<<"Enter Roll Number: "<<endl;
			cin>>roll;
			rec.deleteNode(roll);
		}	
		else if(option == 8)
		{
			cout<<endl;
			rec.traverseList();
		}
		else if(option == 9)
		{
			cout<<"Enter roll number that you want to search: "<<endl;
			cin>>roll;
			int index;
			index = rec.findNode(roll);
			cout<<"Roll Number "<<roll<<" is present on location "<<index<<endl;
		}	
	} while(option != 10);
	cout<<"Program Ended! "<<endl;
	return 0;
}
