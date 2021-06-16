#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;


struct Date
{
	string month;
	int day;
	int year;
};

struct Address
{
	int houseno;
	string streetname;
	string streetType;
	string city;
	string state;
	int zip;
};

struct Record
{
	string last;
	string first;
	Date bday; //Data is a struct
	Address address;
	int phoneNo;

};

void Sort(Record records[], int, int option);
void Search(Record records[], int, string bmonth);
void Display(Record records[], int N); //displays all the data
void DisplayRecord(Record records[], int i); // displays the ith record



int main()
{
	Record records[100];
	int option;
	string bmonth;
	int N;
	int sortOption;

	cout << " Give the N amount: " << endl;
	cin >> N;
	
	ifstream input;
	input.open("Text.txt");
	ofstream output;
	output.open("results.txt");

	if (!input)
	{
		cout << "Invalid Data" << endl;
	}

	for (int i = 0; i <= N - 1; i++)
	{
		input >> records[i].first >> records[i].last >> records[i].phoneNo >> records[i].bday.day >> records[i].bday.month >> records[i].bday.year
			>> records[i].address.houseno >> records[i].address.streetname >> records[i].address.streetType
			>> records[i].address.city >> records[i].address.state >> records[i].address.zip;
		
		
			
	}

	cout << "What is your option choice: " << endl;
	cin >> option;

	if (option == 1)
	{
		cout << "Whats your sort option: " << endl;
		cin >> sortOption;
		Sort(records, N, sortOption);
		Display(records, N);
	}
	else if (option == 2)
	{
		string birthmonth;
		cout << "When is your birth month" << endl;
		cin >> birthmonth;
		Search(records, N, birthmonth);
	}
	else
	{
		cout << "Invalid Option" << endl;
	}

	return 0;
}


void Sort(Record records[], int N, int option)
{
	int i, j;
	for (i = 0; i <= N - 2; i++)
	{
		int min = i;
		for (j = i+1; j <= N - 1; j++)
		{
			if (option == 1)
			{
				if (records[j].first < records[min].first)min = j;
			}
			else if (option == 2)
			{
				if (records[j].last < records[min].last)min = j;
			}
			else if (option == 3)
			{
				//Sorting the bday month
				if (records[j].bday.month < records[min].bday.month)min = j;
			}
			else
			{
				cout << "Invalid sorting option, exit progam " << endl;
				
			}
		
		}
		if (min != i) swap(records[i], records[min]);
		
	}
}

void DisplayRecord(Record records[], int i)
{

	
	cout << setw(10) << records[i].first <<" "<< setw(15) << records[i].last <<" "<< setw(10) << records[i].phoneNo <<" " <<setw(2) << records[i].bday.day <<" "<< setw(10) << records[i].bday.month <<" " <<setw(6) << records[i].bday.year <<" " << setw(10) <<
		records[i].address.houseno <<" " << setw(10) << records[i].address.streetname <<" " << setw(10) << records[i].address.city <<" " << setw(10) << records[i].address.state <<" " << setw(10) << records[i].address.zip 
		<< endl;


}

void Display(Record records[], int N)
{
	int i, j;

	ofstream output;
	output.open("dispresults.txt");

	for (i = 0; i <= N - 1; i++)
	{
		cout << setw(10) << records[i].first << " " << setw(15) << records[i].last << " " << setw(10) << records[i].phoneNo << " " << setw(2) << records[i].bday.day << " " << setw(10) << records[i].bday.month << " " << setw(6) << records[i].bday.year << " " << setw(10) <<
			records[i].address.houseno << " " << setw(10) << records[i].address.streetname << " " << setw(10) << records[i].address.city << " " << setw(10) << records[i].address.state << " " << setw(10) << records[i].address.zip
			<< endl;
		output << setw(10) << records[i].first << " " << setw(15) << records[i].last << " " << setw(10) << records[i].phoneNo << " " << setw(2) << records[i].bday.day << " " << setw(10) << records[i].bday.month << " " << setw(6) << records[i].bday.year << " " << setw(10) <<
			records[i].address.houseno << " " << setw(10) << records[i].address.streetname << " " << setw(10) << records[i].address.city << " " << setw(10) << records[i].address.state << " " << setw(10) << records[i].address.zip
			<< endl;
	}
}




void Search(Record records[], int N, string bmonth)
{
	int i;
	for (i = 0; i <= N - 1; i++)
	{
		if (records[i].bday.month == bmonth)
		{
			DisplayRecord(records, i);
		}
	
	}

}


