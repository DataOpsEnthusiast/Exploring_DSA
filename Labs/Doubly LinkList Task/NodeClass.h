
class DNode
{
	public:       //These data members are editable by the user
		double data;   //Declare the data part of node where value is stored
		DNode*next; //Declare the next part of node where address of next node is stored
		DNode*prev; //Declare the prev part of node where address of Previous node is stored
		DNode(double d=0, DNode*n=0) //Initially data and address are both equal to 0
		{
			data=d;
			next=n;
			
		}
};
