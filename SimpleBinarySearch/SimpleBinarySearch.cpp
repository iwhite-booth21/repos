#include <iostream>
#include <climits>
#include <cstdlib>
int BinarySearching(int A[], int first, int last, int v);

using namespace std;


int BinarySearching(int A[], int first, int last, int v)
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		if (v == A[mid])
		{
			return mid;
		}
		else if (v > A[mid])
		{
			return BinarySearching(A, mid+1, last, v);	//Increement the higher half for recursive call.
		}
		else
		{
			BinarySearching(A, first, mid-1, v);	//Decrement the middle value of the BST in the first half of BST
		}

	}
	else if (first = last) // if the first and last node is the same.
	{
		if (v == A[first]) // if key equals first node
		{

			return first;
		}
		else
		{
			return -1;	//Out of range or non existent
		}


	}

	return -1;	//Terminate Function
}

int main()
{
	
	cout << " How many numbers will you have? : " << endl;
	int N;	// Use N for the last variable and 1 as the first variable in function call
	cin >> N;
	int* myarr;
	myarr = new int[N];
	cout << "Enter " << N << " number of values: " << endl;
	for (int i = 1; i <= N; i++)
	{
		cin >> myarr[i];
	}
	int key;
	cout << " Which number are you looking for? " << endl;
	cin >> key;

	int x = BinarySearching(myarr, 1, N, key);
	cout << x <<endl;
	cout << "This node is located at " << x << "'s position." << endl;

	return 0;
}