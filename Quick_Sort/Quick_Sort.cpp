#include<iostream>
int Partition(int A[], int p, int r);
void quickSort(int A[], int p, int r);
void printArray(int A[], int N);

using namespace std;

void printArray(int A[], int N) {
	for (int i = 1; i <= N; i++) {		// Ensure that array starts from A[1]
		cout << A[i] << " ";
	}
}



int Partition(int A[], int p, int r) {
	int piv = A[r];			// Pivot of array
	int i = p - 1;			// Left scan
	int j = r;				// Right scan
	while (true) {
		do {
			i++;	
		} while (A[i] < piv);	// Unless position of left scan less than pivot continue
		do {
			j--;
		} while (A[j] > piv);	// Unless position of right scan less than pivot continue
		if (i < j) {
			swap(A[i], A[j]);	// Swap left scan value with the value in right scan
		}
		else {
			swap(A[i], A[r]);	// Swap left scan value with pivot
			return i;			// returns left scan position
		}
		return r;				// Returns new array
	}
}


void quickSort(int A[], int p, int r) {
	if (p < r) {
		int q = Partition(A, p, r);	// Divides the data
		quickSort(A, p, q-1);		// Recursive Call for left scan
		quickSort(A, q + 1, r);		// Adjusted Recursive call for right scan
	}
}





int main() {
	int* numbers;			// Dynamic pointer for array
	int N = 0;				// Increment to use with array at index of 2 (A[1])
	cout << " Enter number of values: " << endl;	
	cin >> N;				// True Array Size
	 
	numbers = new int[N + 1];		// Dynamic Array to encapsulate all elements within
	int i;							// Counter Variable
	cout << "Enter " << N << " number of values: " << endl;
	for (i = 1; i <= N; i++) {
		cin >> numbers[i];		// Populates the array 
	}

	quickSort(numbers, 0, N);	// Sorts Array
	printArray(numbers, N);		// Prints the new Array
	return 0;
}