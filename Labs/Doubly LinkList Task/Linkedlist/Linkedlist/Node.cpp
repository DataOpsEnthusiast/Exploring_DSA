#include<iostream>
#include"Node.h"
using namespace std;


DNode::DNode()
{
	next = NULL;
	prev = NULL;
}
void DNode::setData(double data)
{
	this->data = data;
}
double DNode::getData()
{
	return data;
}
void DNode::setNext(DNode* ptr)
{
	this->next = ptr;
}
DNode* DNode::getNext()
{
	return next;
}
void DNode::setPrev(DNode* ptr)
{
	this->prev = ptr;
}
DNode* DNode::getPrev()
{
	return prev;
}