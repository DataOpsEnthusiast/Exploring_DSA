// Author:-Hamza Mehmood
// Program Title:-

//Preprocessor Directive Section
#include<iostream>
#include "node.h"
class linkedlist
{
private:
    llnode*head;
    llnode*tail;
public:
    linkedlist()
    {head=0;
    tail=0;
    };
    ~linkedlist();

    void addtohead(double element){
llnode *newnode= new llnode(element);
//case 1 if list is empty
if (head==0&&tail==0)
{
    head=tail=newnode;
}
//case 2 if list has values
else
{
    newnode->next=head;
    head=newnode;
}


    }
    void addtotail(double element){
llnode *newnode= new llnode(element);
//case 1 if list is empty
if (head==0&&tail==0)
{
    head=tail=newnode;
}
//case 2 if list has values
else
{
    tail->next=newnode;
    tail=newnode;
    newnode=tail;
}
        
    }
    void addafter(double existing,double element){
    
//case 1 if list is empty
if (head==0&&tail==0)
{
    cout<<"List is empty";
}
//case 2 if list has values
else if(tail->data==existing)
{
    addtotail(element);
 
}
else
{
    llnode *currnode=head;
    while (currnode!=0 && currnode->data!=existing)
    {
        currnode=currnode->next;

    }
    if (currnode==0)
    {
       cout<<"Existing not found";
    }
    else
    {
        llnode *newnode=new llnode(element);
        newnode->next=currnode->next;
        currnode->next=newnode;
    }
    
    
    
}


    }
    void addbefore(double existing,double element){


    }
    void delfromhead(){


    }
    void delfromtail(){


    }
    void delspecificnode(double existing){


    }
    void addsorted(double existing){


    }
    void findnode(double existing){


    }
    void traverse(){


    }
};



//Standard Allocation
using namespace std;

// Main Function//
int main(){
//Program Statements//

return 0;
}