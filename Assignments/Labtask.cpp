// Authors:-Hamza Mehmood(SP-21-110).
// Program Title:-Lab task

// Preprocessor Directive Section
#include <iostream>

// Standard Allocation
using namespace std;

// define size
#define size 15
int stackarray[size];
int top = -1;
void push(int val)
{
    if (top >= size)

    {
        //case 1:Stack Already Full

        cout << "Stack overflow" << endl;
    }
    else
    {
        //case 2:Stack Has Space
        if (top < 0)//user entering very first value
           top = 0;}

        stackarray[top] = val;
        top++;
    }
    void pop()
    {
        //case 1:Stack is Empty
        if (top == -1) //(top<0)
            {cout << "stack underflow" << endl;}
    
    else
    //Stack Has Values
    {
        top--;
    }}
    //Pop Function
    void display()
    {
        //CASE 1: Stack is Empty
        if (top == -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
//Case 2: stack is not empty
            cout << "values in stack are as follows : ";
        }
        for (int i = top - 1; i >= 0; i--)
        {
            cout << stackarray[i] <<"\t";
            
        }
   cout<<"\n"; }

void Intro() // Function For Introduction
{
    cout << "\t\t    /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
         << endl;
    cout << "\t\t      National University of Modern Languages \n"
         << endl;
    cout << "\t\t    \t Software Engineering Department \n"
         << endl;
    cout << "\t\t  \t  Instructor:- Prof.Mohsin Abbas \n"
         << endl;
    cout << "\t\t\t\t--LAB TASK   \n"
         << endl;
    cout << "------------------------------------------------------------------------------\n"
         << endl;
    cout << "\t\t |Name| = Hamza Mehmood(SP-21-110)\n "
         << endl;
    cout << "\t\t      |Roll #| = SP-21-110\n "
         << endl;

    cout << " \\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*\\*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/\n"
         << endl;
}

int main()


{

    Intro();
    cout << "\n\n";
    cout << "\n\n";

   
    cout << "\n\n";

    
        push(14);
        push(5);
        push(12);
  
  display();
  pop();
  display();


 return 0;

    
 } 

