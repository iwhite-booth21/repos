#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

	float a, b, c, d, x1, x2;
	cout << " Enter a, b, and c values: ";
		cin >> a >> b >> c;
	d = pow(b, 2) - 4 * a * c;

	if (d >= 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		cout << fixed << setprecision(2);
		cout << "x1 = " << x1 << endl
			<< "x2 = " << x2 << endl;
	}
	else
		cout << "No Real Roots ";
		system("pause");
		return 0;
}