
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
	void setData(double data){
		this->data=data;
	}
	double getData(){
		return data;
	}
	void setNext(DNode* ptr){
		next = ptr;
	}
	DNode* getNext(){
	return next;

	}
	void setPrev(DNode* ptr){
	prev = ptr;

	}
	DNode* getPrev(){
	return prev;

	}
};