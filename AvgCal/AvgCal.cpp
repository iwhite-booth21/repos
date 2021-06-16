// AvgCal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#define Nmax 200;
float Average(int nums[], int n);
void Avg(int nums[], int n, float & average);

using namespace std;

void Avg(int nums[], int n, float & average) {
	float sum;
	sum = 0;
	int i;
	for (i = 0; i <= n - 1; i++) {
		sum = sum + nums[i];
	}
	average = sum / n;
	cout << "Utilizing the void function we get " << average << endl;

}





float Average(int nums[], int n){
	float avg;
	float sum;
	sum = 0;
	int i;
	for (i = 0; i <= n - 1; i++) {
		sum = sum + nums[i];
	}
	avg = sum / n;
	return avg;
}


int main()
{
	float avg;
	int N;
	int* numbers;
	cout << "enter array size." << endl;
	cin >> N;
	numbers = new int[N];
	int i;
	cout << "Enter " << N << " number of integers" << endl;
	for (i = 0; i <= N-1; i++) {
		cin >> numbers[i];
	}
	float mean_1;
	mean_1 = Average(numbers, N);
	cout << "Using the value return function we have: Average = " << mean_1 << endl;
	
	Avg(numbers, N, avg);  // Using the Void Function variant of Average  
	
	
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
