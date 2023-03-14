// Author:-Hamza Mehmood
// Program Title:-

//Preprocessor Directive Section
#include<iostream>
#include<iomanip>
#include<cmath>
#include<climits>
#include<complex>
#include<numeric>

//Standard Allocation
using namespace std;
int main(){

// Main Function//
//Program Statements//

	int size,temp,arr[500];	
	cout << "Enter size Of array max is 500 = ";
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

		cout << "Sorted values are as follows:\n" << endl;
		for (int k = 0; k < size; k++)
		{

			cout << arr[k] << "\t";
		}



return 0;
}





