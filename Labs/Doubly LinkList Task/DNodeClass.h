
class DNode
{
	public:       //These data members are editable by the user
		int value;   //Declare the data part of node where value is stored
		DNode*next; //Declare the next part of node where address of next node is stored
		DNode*prev; //Declare the prev part of node where address of Previous node is stored
		DNode(int d=0, DNode*n=0,DNode*p=0) //Initially data and address are both equal to 0
		{
			value=d;
			next=n;
            prev=p;
			
		}
};
