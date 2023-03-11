// Authors:-Hamza Mehmood(SP-21-110).
// Program Title:-Assignment # 1

//Preprocessor Directive Section
#include <iostream>

//Standard Allocation
using namespace std;

void Intro() //Function For Introduction
{
    cout << "\t\t    /\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
         << endl;
    cout << "\t\t      National University of Modern Languages \n"
         << endl;
    cout << "\t\t    \t Software Engineering Department \n"
         << endl;
    cout << "\t\t  \t  Instructor:- Prof.Mohsin Abbas \n"
         << endl;
    cout << "\t\t\t\t--Assignment # 1--    \n"
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

void question_1() //Function For First Question
{
    int choice; //Declaring Decision Variable
    cout << "Enter 1 for 1-D Array or 2 for 2-D Array = ";
    cin >> choice; //Getting User Choice
    cout << "\n";
    if (choice == 1) //Checking  Condition
    {

        int size; //Declaring Variable
        cout << "Enter size Of array = ";
        cin >> size; //Getting size
        int arr[size];
        cout << "\n\n";
        for (int i = 0; i < size; i++) //Implementing Loop
        {

            cout << "Enter Value at " << i << " index = ";
            cin >> arr[i]; //Getting Values One By One
        }
        cout << "\n\n";
        for (int j = 0; j < size; j++) //Implementing Loop
        {
            cout << "Value at " << j << " index is = " << arr[j]; //Printing Values of Array
            cout << endl;
        }
    }
    else if (choice == 2) //Checking  Condition
    {
        {
            int row, col; //Declaring Variable
            cout << "Enter no of Rows = ";
            cin >> row; //Getting no of Rows
            cout << "Enter no of Columns = ";
            cin >> col; //Getting no of Columns
            cout << "\n\n";
            int arr[row][col]; //Declaring Array

            for (int i = 0; i < row; i++) //Implementing outer Loop
            {
                for (int j = 0; j < col; j++) //Implementing inner Loop
                {
                    cout << "Enter " << i << " Row and " << j << " Column Value = ";
                    cin >> arr[i][j]; //Getting Array Values
                }
            }
            cout << "\n\n";
            cout << "Values Are as In Following Order:-" << endl;
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    cout << "Array[" << i << "][" << j << "]=" << arr[i][j] << endl; //Printing Values of Array
                }
            }
        }
    }
}
void question_2() //Function For Second Question
{
    int choice; //Declaring Decision Variable
    cout << "Enter 1 for Binary Search Implementation or 2 for Linear Search Implementation = ";
    cin >> choice; //Getting User Choice
    cout << "\n";
    if (choice == 1) //Checking  Condition
    {

        int mid, left, right, size, numtofind; //Declaring Variables
        cout << "Enter size Of array = ";
        cin >> size; //Getting size
        int arr[size];
        cout << "\n";
        for (int i = 0; i < size; i++) //Implementing Loop
        {

            cout << "Enter Value at " << i << " index = ";
            cin >> arr[i]; //Getting Values One By One
        }
        cout << "\n";
        cout << "Enter Value to be Found = ";
        cin >> numtofind;
        left = 0;             //Setting the Starting Value of Array
        right = size - 1;     //Setting The Ending Value of Array
        while (left <= right) //Implementing looping Condition While Starting value is Less or Equal to Ending Value
        {
            mid = (left + right) / 2; //Finding Mid Value in Array

            //Value will be found If the mid value is equal to the Value to be Found
            if (arr[mid] == numtofind) //
            {
                cout << "\nValue Found";
                break;
            }
            // if the mid value is less then the Value to be Found then the Starting Value will be Incremented by 1.

            else if (arr[mid] < numtofind)
            {
                left = mid + 1;
            }
            // if the mid value is greater then the Value to be Found then the ending Value will be Decremented by 1.
            else if (arr[mid] > numtofind)
            {
                right = mid - 1;
            }
        }
        //Value will be not found If the mid value is equal not to the Value to be Found
        if (arr[mid] != numtofind)
            cout << "\nValue Not Found";
    }

    else if (choice == 2)
    {

        bool check = false; //Initializing Decision Variable
        int size, numtofind;
        cout << "Enter size Of array = ";
        cin >> size; //Getting size
        int arr[size];
        cout << "\n";
        for (int i = 0; i < size; i++) //Implementing Loop
        {

            cout << "Enter Value at " << i << " index = ";
            cin >> arr[i]; //Getting Values One By One
        }
        cout << "\n";
        cout << "Enter Value to be Found = ";
        cin >> numtofind;
        for (int i = 0; i < size; i++)
        { // loop will be implemented for every Iteration of i and will be break if the value of that such ith iteration is equal to the numtofind.
            if (arr[i] == numtofind)
            {
                check = true;
                break;
            }
        }
        if (check == false)
        {
            cout << "Value Not Found";
        }
        else
        {
            cout << "Value Found";
        }
    }
}

int main()
{

    Intro();
    cout << "\n\n";
    cout << "Question 1. Write a program that implements both arrays (1-D & 2-D) but as per choice of user.\nTake size and all values from user and provide proper menu which helps user to understand the flow of program.";
    cout << "\n\n";
    cout << "Question 2. Write a program that implements search operation on simple (1-D) array using both linear and binary search algorithm.\nTake size and all values from user and also provide proper menu which enables user to select the searching algorithm.";
    cout << "\n\n";
    cout << "Press 1 for Question-1 or 2 for Question-2 = ";
    int choice;
    cin >> choice;
    cout << "\n\n";
    if (choice == 1)
    {
        question_1();
    }

    else if (choice == 2)
    {

        question_2();
    }

    return 0;
}
