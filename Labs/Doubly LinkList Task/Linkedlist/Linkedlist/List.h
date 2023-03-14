#include<iostream>
#include"Node.h"
using namespace std;

class DoubleLinkList
{
private:
	DNode *head;
	DNode *tail;
public:
	DoubleLinkList();
	void addToHead(double);
	void addToTail(double);
	void addAfter(double, double);
	void addBefore(double, double);
	void deleteFromHead();
	void deleteFromTail();
	void deleteSpecificNode(double);
	void forwardtraversing();
	void reversetraversing();
};