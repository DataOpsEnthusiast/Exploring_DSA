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

//Main Method
int main()
{
	Intro();
	cout << "\n\n";
	cout << "Question 1. Write a program that implements simple array 1-D using all three sorting Algorithm.Take Size and all vales from user.";
	cout << "\n\n";
	cout << "Press 1 for Bubble Sort\nPress 2 for Selection Sort\nPress 3 for Insertion Sort\n";
int choice;
	cout<<"Your Pick = ";
	cin >> choice;
	cout << "\n\n";

	if (choice == 1)
	 {
		 //Bubble Sort
int size,temp,arr[500];	
	cout << "Enter size Of array = ";
	cin>>size;
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

		cout << "Sorted values are as follows:" << endl;
		for (int k = 0; k < size; k++)
		{

			cout << arr[k] << "\t";
		}


	}

	else if (choice == 2)
	{
		// selection sort
		int size;
		int values;
		int arr[values];
		cout << "Enter size Of array = ";
		cin >> size;
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

		cout << "\n\n";
		selectionsort(arr, size);

		cout << "Sorted values are as follows:" << endl;
		for (int k = 0; k < size; k++)
		{

			cout << arr[k] << "\t";
		}
	}

	else if (choice == 3)
	{
		//Insertion sort
	int temp,size,arr[500]; 
	cout << "Enter size Of array = ";
	cin>>size;
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

		cout << "\n\n";
		cout << "Sorted values are as follows:" << endl;
		for (int k = 0; k < size; k++)
		{

			cout << arr[k] << "\t";
		}
	}
	else
	{
		cout<<"Wrong Pick";
	}
	

	return 0;
}
