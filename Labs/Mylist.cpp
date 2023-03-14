#include<iostream>
using namespace std;
class Node{
	public: int Data;
	public: Node *Link;
	public: Node()
	{
	}
};

class LinkedList{
	public: Node *Head;
	public: Node *Current;
	
	public: LinkedList()
	{
		Head = NULL;
	}
	
	public: void Insert(int value)
	{
		if(Head == NULL)
		{
			cout<<"First Node"<<endl;
			Head = new Node;
			Head->Data = value;
			Head->Link = NULL;
		}
		else
		{
			Current = Head;
			while(Current->Link != NULL)
			{
				Current = Current->Link;
			}
			Node *Temp = new Node;
			Temp->Data = value;
			Temp->Link = NULL;
			Current->Link = Temp;
			cout<<"Node Created in the Last"<<endl;
		}
	}
	
};

int main()
{
	LinkedList obj;
	obj.Insert(10);
	obj.Insert(20);
	obj.Insert(30);
	obj.Insert(40);
	obj.Insert(50);
	
	return 0;
}