#include <iostream>
#include "DNodeClass.h"
using namespace std;

class Dlinkedlist
{
private:
	DNode *head; 
	DNode *tail; 
public:
	Dlinkedlist() 
	{
		head = 0;
		tail = 0;
	}
    
    void addToHead(int element)
{
     DNode* newItem =new DNode();
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->value=element;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->next=head;
        newItem->value=element;
        newItem->prev=NULL;
        head->prev=newItem;
        head=newItem;
    }
}
void addToTail(int element)
{
     DNode* newItem=new DNode(element);
    newItem->value=element;
    if(head==NULL)
    {
        head=newItem;
        newItem->prev=NULL;
        newItem->next=NULL;
        tail=newItem;
    }
    else
    {
        newItem->prev=tail;
        tail->next=newItem;
        newItem->next=NULL;
        tail=newItem;
    }
}
void addAfter(int existing, int element)
{
    DNode* newItem =new DNode();
     DNode* temp=head;
    
    if(head==NULL)
    {
        cout<<"could not insert"<<endl;
        return;
    }
    if(head==tail)
    {
        if(head->value!=existing)
        {
            cout<<"could not insert"<<endl;
            return;
        }
        newItem->value=element;
        head->next=newItem;
        newItem->next=NULL;
        head->prev=NULL;
        newItem->prev=head;
        tail=newItem;
        return;
    }
    if(tail->value==element)
    {
        newItem->next=NULL;
        newItem->prev=tail;
        tail->next=newItem;
        tail=newItem;
        return;
    }
    while(temp->value!=existing)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"Could not insert"<<endl;
            cout<<"element not found"<<endl;
            return;
        }
    }

    newItem->next=temp->next;
    newItem->prev=temp;
    newItem->value=element;
    temp->next->prev=newItem;
    temp->next=newItem;
}

 void addBefore(double existing, double newData)
    {

        DNode *temp = head;
        while (temp != NULL)
        {
            if (existing == temp->value)
            {
                DNode *prev = temp->prev;
                DNode *newNode = new DNode();
                newNode->value=newData;
                prev->next=newNode;
                newNode->prev=prev;
                newNode->next=temp;
                temp->prev=newNode;
            }

            temp = temp->next;
        }
    }


void deleteFromHead()
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail)///one element in the list
    {
         DNode* currNode;
        currNode=head;
        head=NULL;
        tail=NULL;
        delete currNode;
        return;
    }
    else
    {
         DNode* currNode=head;
         head=head->next;
         head->prev=NULL;
        delete currNode;
    }
}
void deleteFromTail()
{
    if(head==NULL) 
    return;
    if(head==tail)
    {
        struct DNode* currNode;
        currNode=head;
        head=NULL;
        tail=NULL;
        delete currNode;
        return;
    }
    else
    {
         DNode* currNode=tail;
        currNode=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete currNode;
    }
}
void deleteSpecificItem(int element)
{
     DNode* temp=head;
  
    if(head==tail)
    {
        if(head->value!=element)
        {
            cout<<"could not delete"<<endl;
            return;
        }
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(head->value==element)
    {
        head=head->next;
        head->prev=NULL;
        delete temp;
        return;
    }
    else if(tail->value==element)
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        return;
    }
    while(temp->value!=element)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            cout<<"element not found"<<endl;
            return;
        }
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete temp;
}
void forwardtraverse()
{
     DNode* temp=head;
    
    while(temp!=NULL)
    {
        cout<<"\t"<<temp->value;
        
        temp=temp->next;
    }
  
}
void reversetraverse()
{
    DNode* temp=tail;

    while(temp!=NULL)
    {
        cout<<temp->value<<"\t";
        temp=temp->prev;
    }
    
}

    
    
    };



    
int main()
{


    cout << "**Doubly Linked List**" << endl;
	Dlinkedlist list;
	int choice;
	do
	{
		cout << "\n\t.....Menu......" << endl;
		cout << "\nPress 1: Add to Head" << endl;
		cout << "Press 2: Add to Tail" << endl;
		cout << "Press 3: Add After" << endl;
		cout << "Press 4: Add Before" << endl;
		cout << "Press 5: Delete from Head" << endl;
		cout << "Press 6: Delete from Tail" << endl;
		cout << "Press 7: Delete Specific" << endl;
		cout << "Press 8: Forward Traverse the List" << endl;
		cout << "Press 9: Reverse Traverse the List" << endl;
		cout << "Press 0: Exit" << endl;
		cout << "\nEnter choice of user: ";
		cin >> choice;
        if(choice==1)
        {
            int element;
            cout<<"Enter element_";
            cin>>element;
            list.addToHead(element);
            list.forwardtraverse();
        }
        else if(choice==2)
        {
            int element;
            cout<<"Enter element_";
            cin>>element;
           list.addToTail(element);
            list.forwardtraverse();
        
        }
        else if(choice==3)
        {
            int existing,newitem;
            cout<<"Enter Old Item_";
            cin>>existing;
            cout<<"Enter new Item_";
            cin>>newitem;
            list.addAfter(existing,newitem);
            list.forwardtraverse();
        
        }
        else if(choice==4)
        {
            int existing,newitem;
            cout<<"Enter Old Item_";
            cin>>existing;
            cout<<"Enter new Item_";
            cin>>newitem;
            list.addBefore(existing,newitem);
            list.forwardtraverse();
        
        }
        else if(choice==5)
        {
            list.deleteFromHead();
            list.forwardtraverse();
            
        }
        else if(choice==6)
        {
            list.deleteFromTail();
            list.forwardtraverse();
           
        }
        else if(choice==7)
        {
            int element;
            cin>>element;
            list.deleteSpecificItem(element);
            list.forwardtraverse();
        }
       
        else if(choice==8)
        {
            list.forwardtraverse();
        }
        else if(choice==9)
        {
            list.reversetraverse();
        }
        
        else if(choice==0)
        {
            break;
        }
       
    }while (choice != 0);
return 0;
}