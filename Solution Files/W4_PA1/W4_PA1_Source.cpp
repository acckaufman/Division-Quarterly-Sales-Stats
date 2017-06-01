#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Division
{
	string name;
	double qtr1;			//All doubles on separate lines for enhanced readability
	double qtr2;
	double qtr3;
	double qtr4;
	double annualSales;
	double qtrSalesAvg;
};

void getDivisionSales(Division&);
void findTotalAndAverageSales(Division&);
void displayCorpInformation(const Division&, const Division&, const Division&, const Division&);

int main()
{
	Division east;
	Division west;
	Division north;
	Division south;

	cout << "Welcome!\n\n";
	cout << "This program will ask you to input division sales for quarters\n"
		<< "1, 2, 3, and 4.  It will then calculate the annual sales for each\n"
		<< "division and the average of the quarter sales.\n\n";

	//Get the division sales information from the user
	cout << "Enter the quarterly sales for the East Division:\n";
	getDivisionSales(east);
	cout << "Enter the quarterly sales for the West Division:\n";
	getDivisionSales(west);
	cout << "Enter the quarterly sales for the North Division:\n";
	getDivisionSales(north);
	cout << "Enter the quarterly sales for the South Division:\n";
	getDivisionSales(south);

	//Calculate the information for the last two members of each struct
	findTotalAndAverageSales(east);
	findTotalAndAverageSales(west);
	findTotalAndAverageSales(north);
	findTotalAndAverageSales(south);

	//Display the total annual sales and average quarterly sales for each division
	displayCorpInformation(east, west, north, south);

	system("pause");

	return 0;
}

void getDivisionSales(Division &div)
{
	cout << "\tFirst quarter: ";
	cin >> div.qtr1;
	while (div.qtr1 < 0)		//Validate input, check for negative numbers
	{
		cout << "\n\tError! You must enter a positive number. Please try again.\n\n";
		cout << "\tFirst Quarter: ";
		cin >> div.qtr1;
	}
	cout << "\tSecond quarter: ";
	cin >> div.qtr2;
	while (div.qtr2 < 0)
	{
		cout << "\n\tError! You must enter a positive number. Please try again.\n\n";
		cout << "\tSecond Quarter: ";
		cin >> div.qtr2;
	}
	cout << "\tThird quarter: ";
	cin >> div.qtr3;
	while (div.qtr3 < 0)
	{
		cout << "\n\tError! You must enter a positive number. Please try again.\n\n";
		cout << "\tThird Quarter: ";
		cin >> div.qtr3;
	}
	cout << "\tFourth quarter: ";
	cin >> div.qtr4;
	while (div.qtr4 < 0)
	{
		cout << "\n\tError! You must enter a positive number. Please try again.\n\n";
		cout << "\tFourth Quarter: ";
		cin >> div.qtr4;
	}
}

void findTotalAndAverageSales(Division& div)
{
	double totalSales = 0;		//Temporary variables to be stored in Division struct after calculation
	double averageSales = 0;

	totalSales = div.qtr1 + div.qtr2 + div.qtr3 + div.qtr4;
	div.annualSales = totalSales;

	averageSales = totalSales / 4;
	div.qtrSalesAvg = averageSales;
}

void displayCorpInformation(const Division& east, const Division& west, const Division& north, const Division& south)
{
	//Screenshot for output requirements only includes total and average sales,
	//but instructions say that output of the program will be all the figures
	//in the structures, so I have included the sales figures input by the user

	cout << endl;
	cout << fixed << showpoint << setprecision(2);	//Set output formatting

	cout << "East Division Sales by Quarter:" << endl;
	cout << "\tQuarter 1: $" << east.qtr1 << endl;
	cout << "\tQuarter 2: $" << east.qtr2 << endl;
	cout << "\tQuarter 3: $" << east.qtr3 << endl;
	cout << "\tQuarter 4: $" << east.qtr4 << endl;
	
	cout << "West Division Sales by Quarter:" << endl;
	cout << "\tQuarter 1: $" << west.qtr1 << endl;
	cout << "\tQuarter 2: $" << west.qtr2 << endl;
	cout << "\tQuarter 3: $" << west.qtr3 << endl;
	cout << "\tQuarter 4: $" << west.qtr4 << endl;

	cout << "North Division Sales by Quarter:" << endl;
	cout << "\tQuarter 1: $" << north.qtr1 << endl;
	cout << "\tQuarter 2: $" << north.qtr2 << endl;
	cout << "\tQuarter 3: $" << north.qtr3 << endl;
	cout << "\tQuarter 4: $" << north.qtr4 << endl;

	cout << "South Division Sales by Quarter:" << endl;
	cout << "\tQuarter 1: $" << south.qtr1 << endl;
	cout << "\tQuarter 2: $" << south.qtr2 << endl;
	cout << "\tQuarter 3: $" << south.qtr3 << endl;
	cout << "\tQuarter 4: $" << south.qtr4 << endl;

	cout << "Total Annual Sales:\n";
	cout << "\tEast Division: $" << east.annualSales << endl;
	cout << "\tWest Division: $" << west.annualSales << endl;
	cout << "\tNorth Division: $" << north.annualSales << endl;
	cout << "\tSouth Division: $" << south.annualSales << endl;
	
	cout << "Average Quarterly Sales:" << endl;
	cout << "\tEast Division: $" << east.qtrSalesAvg << endl;
	cout << "\tWest Division: $" << west.qtrSalesAvg << endl;
	cout << "\tNorth Division: $" << north.qtrSalesAvg << endl;
	cout << "\tSouth Division: $" << south.qtrSalesAvg << endl;
}