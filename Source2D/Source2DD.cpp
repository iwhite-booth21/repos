#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
float weeklyAvg(float x, int y[][4], int M);
float totalAvg(float wAvg[], int n);
int main()
{
	int A[7][4];
	float wAvg[4];
	float tAvg;
	ifstream input;
	ofstream output;

	input.open("Rainfall.txt");
	output.open("results'.out");
	if (!input)
	{
		cout << "File is not found";
		exit(0);
	}
	int i, j; //i=row j=col
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 3; j++)input >> A[i][j];
		input >> A[i][j];
	}
	for (j = 0; j <= 3; j++)
	{
		wAvg[j] = weeklyAvg(A, 7, j);
	}
	tAvg = totalAvg(wAvg, 4);
	cout << " Total average = " << tAvg << endl;
	output << " Total average = " << tAvg << endl;
	for (j = 0; j <= 3; j++)
	{
		cout << " For week " << j + 1 << "average = " << wAvg[j] << endl;
	}
}

float weeklyAvg()