#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int x, y;
	char op;
	cout << "Enter a value for x and y:" << endl;
	cin >> x >> y;
	cout << " What do you want to do with them? \n Chooser from the following: addition (+), subtracton (-), multiplication (*), division (/), or remainder (%): " << endl;
	cin >> op;

	switch (op)
	{
	case '+':
		cout << x + y << endl;
		break;
	case '-':
		cout << x - y << endl;
		break;
	case '*':
		cout << x * y << endl;
		break;
	case '/':
		cout << x / y << endl;
		break;
	case '%':
		cout << x % y << endl;
		break;
	default:
		cout << "Invalid operation!" << endl;

/*Enter a value for x and y:
102
550
 What do you want to do with them?
 Chooser from the following: addition (+), subtracton (-), multiplication (*), division (/), or remainder (%):
%
102

C:\Users\booth\source\repos\Project1\Debug\Project1.exe (process 9636) exited with code 0.
Press any key to close this window . . .*/


	}

	return 0;
}
