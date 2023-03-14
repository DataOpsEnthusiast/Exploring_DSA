// Authors:-Hamza Mehmood(SP-21-110).
// Program Title:-Assignment # 2

// Preprocessor Directive Section
#include <iostream>

// Standard Allocation
using namespace std;

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
	cout << "\t\t\t\t--Assignment # 2--    \n"
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

// Bubble Sort
void bubblesort(int arr[], int size) // Creating Function
{
  
	int size,temp,arr[500];	
	cout << "Enter size Of array max is 500 = ";
	
		cout << "\n\n";
		for (int i = 0; i < size; i++) // Implementing Loop
		{

			cout << "Enter Value at " << i << " index = ";
			cin >> arr[i]; // Getting Values One By One
		}
			cout << "\nUnsorted Array is as Follow:\n";
		for (int j = 0; j < size; j++) // Implementing Loop
		{

			cout<<arr[j]<<"\t";
		}								 
	for (int outer = 0; outer < size - 1; outer++) // Outer Loop For Implementing Each Pass
	{

		for (int inner = 0; inner < size - outer - 1; inner++) // Inner Loop for Implementing and Comparing the Desired Condition on Each Pass
		{

			if (arr[inner] > arr[inner + 1]) // Declaring Condition and comparing Two Adjacent Array Elements
			{
				// Swapping Elements if Array Elements are not in sorted Order
				temp = arr[inner]; //
				arr[inner] = arr[inner + 1];
				arr[inner + 1] = temp;
			}
		}
	}
	cout << "\n\n";

		cout << "Sorted values are as follows:\n" << endl;
		for (int k = 0; k < size; k++)
		{

			cout << arr[k] << "\t";
		}



}

// Selection Sort

void selectionsort(int arr[], int size) // Creating Function
{
	int temp, min;								   // Declaring Temperory Variable for Swapping Purpose and Min Variable for Setting Initial Sorted Array Value
	for (int outer = 0; outer < size - 1; outer++) // Outer Loop For Implementing Each Pass
	{
		// Finding min Value in Unsorted Array
		min = outer;
		for (int inner = outer + 1; inner < size; inner++)
		{
			if (arr[min] > arr[inner])
			{
				min = inner;
			}

		} // Swapping and Placing in Correct Position
		temp = arr[outer];
		arr[outer] = arr[min];
		arr[min] = temp;
	}
}

// insertion sort

void insertionsort(int arr[], int size) // Creating Function
{
	int temp; // Declaring Temperory Variable for Swapping Purpose
	for (int outer = 1; outer < size; outer++)
	{
		temp = arr[outer];
		int inner = outer;
		// Comparing with each element on the left of it until the element smaller then it is found
		while (inner > 0 && arr[inner - 1] >= temp)
		{
			arr[inner] = arr[inner - 1];
			inner--;
		}
		arr[inner] = temp;
	}
}
int main()
{
int size1;
		int values1;
		int arr[values1];
		cout << "Enter size Of array = ";
		cin >> size1;
		//cout << "\n\n";
		for (int i = 0; i < size1; i++) // Implementing Loop
		{

			cout << "Enter Value at " << i << " index = ";
			cin >> arr[i]; // Getting Values One By One
		}
			cout << "\nUnsorted Array is as Follow:\n";
		for (int j = 0; j < size1; j++) // Implementing Loop
		{

			cout<<arr[j]<<"\t";
		}

		//cout << "\n\n";
		bubblesort(arr, size1);

		cout << "Sorted values are as follows:\n" << endl;
		for (int k = 0; k < size1; k++)
		{

			cout << arr[k] << "\t";
		}
    return 0;
	}


