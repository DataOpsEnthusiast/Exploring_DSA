#include<iostream>
#include"List.h"
using namespace std;

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