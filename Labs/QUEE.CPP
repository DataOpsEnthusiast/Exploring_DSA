// Author:-Hamza Mehmood
// Program Title:-

//Preprocessor Directive Section
#include<iostream>


//Standard Allocation
using namespace std;

template <class t>
class templateque
{
private:
t *queuearray;
int queuesize;
int front;
int rear;
int numitems;
public:
templateque(int size)
{
queuearray = new t(size);
queuesize = size;
front=-1;
rear=-1;
numitems=0;


}
~templateque()
{
delete [] queuearray;
}
void enque(t val);
void deque();
void display();
bool isfull();
bool isempty();
void makenull();

};

template <class t>
bool templateque<t>::isfull()
{
if (rear==queuesize-1) // if(numitems == quesize)
{
    return true;
} 
else
{
    return false;
}

}





// Main Function//
int main(){
//Program Statements//

return 0;
}