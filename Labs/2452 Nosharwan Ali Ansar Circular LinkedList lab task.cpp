#include<iostream>
using namespace std;

class CNode
{
	public:
		double data;
		CNode *next;
		CNode(double i=0, CNode *n=0)
		{
			data = i;
			next = n;
		}
};


class CLinkedList
{
	private:
		CNode *head;
	public:
		CLinkedList(void) // Constructor
		{
			head = 0;	
		}
		~CLinkedList(void); // Destructor
		void addToHead(double element);
		void addAtLast(double element);
		void addAfter(double existing,double element); 
		void removeFromHead(); 
		void removeSpecificNode(double existing); 
 		void traverseList();
};

void CLinkedList::addToHead(double element)
{
	CNode *newNode = new CNode(element);
	if(head == 0)  // if(head == 0 && tail == 0)
	{
		//LIST IS EMPTY
		head = newNode;
		newNode->next = head;
	}
	else // LIST IS NOT EMPTY
	{
		// 14, 5			newNode = 8		head = 14		8, 14, 5
		newNode->next = head; // 8->14	heaD = 14	5->14
		CNode *ptr = head; // temp node, used to find the last node of the list
		while(ptr->next != head) // 5 = head false
		ptr = ptr->next; // ptr = 5
		head = newNode; // head  = 8
		ptr->next = head;	// 5->8
	}
}

void CLinkedList::addAtLast(double element)
{
	CNode *newNode = new CNode(element);
	if(head == 0)  // if(head == 0 && tail == 0)
	{
		//LIST IS EMPTY
		head = newNode;
		newNode->next = head;
	}
	else // LIST IS NOT EMPTY
	{
		// 14, 5			newNode = 8		head = 14		14, 5, 8
		CNode *ptr = head; // temp node, used to find the last node of the list
		while(ptr->next != head) // 5 = head false
			ptr = ptr->next; // ptr = 5
		ptr->next = newNode;	// 5->8
		newNode->next = head;  // 8->14
	}
}

void CLinkedList::addAfter(double existing,double element) //this functions is used to add value after a specific value/position
{
 	CNode* current;
	CNode* newNode=new CNode(); 
	current=head;  //current node will be at head
	while(current->data!=existing) //while loop (value in current node is not equal to existing value)
	{
		current=current->next;   //value does not match with existing so current node will move to next node  
	}
	newNode->data=element;  
	newNode->next=current->next; //new node will store the address of next node of the current node
	current->next=newNode;
}
 
void CLinkedList::removeFromHead() //this function is used to remove value stored in first node
{
	CNode* ptr=head;  //pointer type node will be at head
	CNode* current=head;
	while(current->next!=head) //next of the current node is not head
	{
 	current=current->next; //so the current node will move to the next node
 	}
 	head=ptr->next;   //ptr will point to next node
	current->next=head;  //current's next will be head now
	cout<<ptr->data<<" is deleted"<<endl; 
	delete ptr; //deletes the ptr value
}

void CLinkedList::removeSpecificNode(double existing) //this function is used to delete a specific value/node
{
	CNode* current;
	CNode* prev;
	current=head;
	while(current->data!=existing) //value in current node does not matches with the existing value
	{
	prev=current;              
	current=current->next; //so current will move to next node
	}
	if(current==head)  //if current node that is to be deleted is at head then remove from head is called
	{
		removeFromHead();
	}
	else
	{			
	prev->next=current->next;  //prev node will now store the address of next node of current node
	cout<<current->data<<" is deleted"<<endl;
	delete current;   //deletes the current node
	}
}


void CLinkedList::traverseList() //function used to display the list
{
	if(head == 0) //if head has no value then list is empty
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		cout<<"\nVALUES IN THE LIST ARE:"<<endl;
		CNode *ptr = head;  //else ptr node is created at head
		do
		{
			cout<<ptr->data<<"\t"; //ptr will display the values of nodes until it reaches head
			ptr = ptr->next;
		} while(ptr != head);
	}
	cout<<endl;

}

CLinkedList::~CLinkedList(void)
{
	CNode *ptr = head;
	CNode *nextNode = 0;
	while(ptr != 0)
	{
		nextNode = ptr->next;
		delete ptr;
		ptr = nextNode;
	}
}


int main()
{
	cout<<" ***** CIRCULAR LINKED LIST PROGRAM ***** "<<endl<<endl;
	CLinkedList list1;
	int option;
	do
	{
		cout<<"\nPRESS 1 TO ADD AT START";
		cout<<"\nPRESS 2 TO ADD AT LAST";
		cout<<"\nPRESS 3 TO ADD VALUE AFTER A SPECIFIC VALUE IN THE LIST";
		cout<<"\nPRESS 4 TO TRAVERSE THE LIST";
		cout<<"\nPRESS 5 TO DELETE VALUE FROM FIRST NODE";
		cout<<"\nPRESS 6 TO DELETE SPECIFIC VALUE";
		cout<<"\nPRESS 7 TO EXIT THE PROGRAM";
		cout<<"\nEnter your Choice: ";
		cin>>option;
		if(option == 1)
		{
			cout<<"\nEnter element you want to add: ";
			double val;
			cin>>val;
			list1.addToHead(val);
		}
		else if(option == 2)
		{
			cout<<"\nEnter element you want to add: ";
			double val;
			cin>>val;
			list1.addAtLast(val);
		}
		else if(option==3)
		{
			cout<<"Enter position after which you want to add "<<endl;
			double position;
			cin>>position;
			cout<<"Enter value "<<endl;
			double val;
			cin>>val;
			list1.addAfter(position, val);
		}
			else if(option == 4)
		{
			list1.traverseList();
		}
		else if(option==5)
		{
			list1.removeFromHead();
		}
		else if(option==6)
		{
			cout<<"Enter value that you want to delete"<<endl;
			double val;
			cin>>val;
			list1.removeSpecificNode(val);
		}
	} while(option != 7);
	cout<<"\nPROGRAM END";
	return 0;
}


