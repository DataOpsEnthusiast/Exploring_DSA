#include<iostream>
using namespace std;

class DNode
{
private:
	double data;
	DNode *next;
	DNode *prev;
public:
	DNode(){
		next=NULL;
		prev=NULL;
	}
	void setData(double dataa){
		this->data=dataa;
	}
	double getData(){
		return data;
	}
	void setNext(DNode* ptr){
		this->next = ptr;
	}
	DNode* getNext(){
	return next;

	}
	void setPrev(DNode* ptr){
	this->prev = ptr;

	}
	DNode* getPrev(){
	return prev;

	}
};