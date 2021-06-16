#include <iostream>
#include <iomanip> //formating puposes
using namespace std;

int main()
{
	cout << fixed << setprecision(2); //Two Decimal points
	char employeeType; // Recieves a character value
	float annualSalary, weeklySalary,
		hours, wageRate{}, overtimeRate; // Number values that can contain decimals
	int count, N; // Maximum number of employees
	cout << "How many employees: ";
	cin >> N;
	count = 0; //Starts at Zero
	repeat: cout << "Enter ther employee type: ";
	cin >> employeeType;
	count++; // Adds one to value

	if (employeeType == 'p')
	{
		cout << "Enter the Annual Salary: ";
		cin >> annualSalary;
		weeklySalary = annualSalary / 52.0;
		cout << "Weekly salary = " << weeklySalary << endl;

	}

	else if (employeeType == 't')
	{
		cout << "Enter hours worked: ";
		cin >> hours;
		cout << "Enter the wage rate and overtime rate: ";
		cin >> wageRate >> overtimeRate;

		if (hours <= 40)
			weeklySalary = hours * wageRate;
		else
			weeklySalary = 40 * wageRate + (hours - 40) * overtimeRate;
			cout << "Weekly salary for the employee = " << weeklySalary << endl;
	}
	else
		cout << "Not a valid employee type " << endl;
	if (count < N) goto repeat;

	system("pause");
	return 0;


};