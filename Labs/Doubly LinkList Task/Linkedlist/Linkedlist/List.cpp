#include<iostream>
#include"List.h"
using namespace std;



DoubleLinkList::DoubleLinkList()
{
	head = NULL;
	tail = NULL;
}
void DoubleLinkList::addToHead(double data)
{
	if(head == NULL)
	{
		DNode *temp = new DNode();
		temp->setData(data);
		head  = temp;
	}
	else
	{
		DNode *temp = new DNode();
		temp->setData(data);
		temp->setNext(head);
		temp->setPrev(NULL);
		head->setPrev(temp);
		head = temp;
	}
}
void DoubleLinkList::addToTail(double data)
{
	if(head == NULL)
	{
		DNode *temp = new DNode();
		temp->setData(data);
		head  = temp;
		tail = head;
	}
	else
	{
		DNode *temp = new DNode();
		temp->setData(data);
		tail->setNext(temp);
		temp->setPrev(tail);
		tail = temp;
	}
}
void DoubleLinkList::addAfter(double existing, double newData)
{
	DNode *temp = head;
	while(temp != NULL)
	{
		if(existing == temp->getData())
		{
			DNode *next = temp->getNext();
			DNode *newNode = new DNode();
			newNode->setData(newData);
			temp->setNext(newNode);
			newNode->setPrev(temp);
			newNode->setNext(next);
			next->setPrev(newNode);
		}

		temp = temp->getNext();
	}
}
void DoubleLinkList::addBefore(double existing, double newData)
{
	DNode *temp = head;
	while(temp != NULL)
	{
		if(existing == temp->getData())
		{
			DNode *prev = temp->getPrev();
			DNode *newNode = new DNode();
			newNode->setData(newData);
			prev->setNext(newNode);
			newNode->setPrev(prev);
			newNode->setNext(temp);
			temp->setPrev(newNode);
		}

		temp = temp->getNext();
	}
}
void DoubleLinkList::deleteFromHead()
{
	if(head != NULL)
	{
		DNode *temp = head;
		head = temp->getNext();
		delete temp;
		head->setPrev(NULL);
	}
}
void DoubleLinkList::deleteFromTail()
{
	if(head != NULL)
	{
		DNode *temp = tail;
		tail = temp->getPrev();
		delete temp;
		tail->setNext(NULL);
	}
}
void DoubleLinkList::deleteSpecificNode(double data)
{
	DNode *temp = head;
	while(temp != NULL)
	{
		if(data == temp->getData())
		{
			DNode *prev = temp->getPrev();
			DNode *next = temp->getNext();
			prev->setNext(next);
			next->setPrev(prev);
			delete temp;
		}

		temp = temp->getNext();
	}
}
void DoubleLinkList::forwardtraversing()
{
	DNode *temp = head;
	while(temp != NULL)
	{
		cout<< temp->getData() << "		" ;

		temp = temp->getNext();
	}

}
void DoubleLinkList::reversetraversing()
{
	DNode *temp = tail;
	while(temp != NULL)
	{
		cout<< temp->getData() << "		" ;

		temp = temp->getPrev();
	}
}

int main()
{
	
	DoubleLinkList list;
	list.addToHead(1);
	list.addToHead(2);
	list.addToHead(3);
	list.forwardtraversing();
	list.reversetraversing();
	list.addToTail(1);
	list.addToTail(2);
	list.addToTail(3);
	list.deleteFromHead();
	
	list.forwardtraversing();
	return 0;
}