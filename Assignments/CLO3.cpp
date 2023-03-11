#include<iostream>
using namespace std;
class Node
{
	public:
	string Name;
	double Score;
	int Roll;
	Node* next;
	Node(string nam, double s, int r, Node* n=0) 
	{
		Name=nam;
		Score=s;
		Roll=r;
		next=n;
	}
};
class LinkedList{
	public:
	Node* Head,* Current,* temp, *index=NULL;
		LinkedList()
		{
			Head=NULL;
		};		
void SortedRoll(string name,double score,int roll)
    {
        Current = Head;
        if(Head == NULL || Head->Roll > roll) 
        {
            Current = new Node(name,score,roll);
            Current->next = Head;
            Head = Current;
            return;
        }
        while( Current->next != NULL && Current->next->Roll < roll )
        {
            Current = Current->next;
        }
        temp = new Node(name,score,roll);
        temp->next =  Current->next;
        Current->next = temp;
	}
void minScore()
	{
		Current=Head;
		double min = Current->Score;
		string name = Current->Name;
		while(Current!=NULL)
		{
			if(min>Current->Score)
			{
				min=Current->Score;
				name=Current->Name;
			}
			Current=Current->next;
		}
			cout<<"\n"<<name<<" Have Minimum Score "<<min<<" in DSA Course "<<endl;
	}
void maxScore()
	{
		Current=Head;
		double max = Current->Score;
		string name = Current->Name;
		while(Current!=NULL)
		{
			if(max<Current->Score)
			{
				max=Current->Score;
				name=Current->Name;
			}
			Current=Current->next;
		}
			cout<<"\n"<<name<<" Have Maximum Score "<<max<< " in DSA Course "<<endl;
	}
void SortedScore() 
{  
	Current = Head;
	string Name;
	double Score;
	int Roll;
	temp= new Node(Name,Score,Roll);
    if(Head == NULL) 
	{  
        return;  
    }  
    else 
	{  
        while(Current != NULL) 
		{    
            index = Current->next;  
            while(index != NULL) 
			{   
                if(Current->Score > index->Score) 
				{
					temp->Name=Current->Name;  
					temp->Score=Current->Score;
					temp->Roll=Current->Roll;
						
					Current->Name=index->Name;
					Current->Score=index->Score;
					Current->Roll=index->Roll;
						
					index->Name=temp->Name;
					index->Score=temp->Score;
					index->Roll=temp->Roll;
                }  
				index = index->next; 
            }
			Current = Current->next; 
        }	
	}
} 
void display()
	{
	Current = Head;
		while(Current != 0)
		{
			cout<<endl;
			cout<<"Name :"<<Current->Name<<endl;
			cout<<"Score :"<<Current->Score<<endl;
			cout<<"Roll No :"<<Current->Roll<<endl;
			Current = Current->next;
			cout<<endl;
		}
	}
};
int main()
{
	LinkedList list1;
	int option;
	do
	{
		cout<<"\nWelcome To Student Registration System"<<endl;
		cout<<"\nPRESS 1 TO Enter Student Data";
		cout<<"\nPRESS 2 TO Check Minimum Student Score Of The Student";
		cout<<"\nPRESS 3 TO Check Maximum Student Score Of The Student";
		cout<<"\nPRESS 4 TO Display Students Score Minimum To Maximum";
		cout<<"\nPRESS 5 TO Display Data Of The Students";
		cout<<"\nPRESS 6 TO Exit The Program";
		cout<<"\nEnter your Choice: ";
		cin>>option;
		system("CLS");
		if(option == 1)
		{
			string name;
			int roll,score;
			cout<<"\nEnter Name of Student :";
			cin>>name;
			cout<<"Enter Score of Student :";
			cin>>score;
			cout<<"Enter Roll No of Student :";
			cin>>roll;
			list1.SortedRoll(name,score,roll);
		}
		else if(option == 2)
		{
			list1.minScore();
		}
		else if(option == 3)
		{
			list1.maxScore();
		}
		else if(option == 4)
		{
			list1.SortedScore();
			list1.display();
		}
		else if(option == 5)
		{
			list1.display();
		}
	} while(option != 6);
	cout<<"\nPROGRAM END";
	return 0;
}
